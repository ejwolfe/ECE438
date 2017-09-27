//Eric Wolfe
//800480613
//Lab 4

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"

float squareRoot(byte **image, int r, int c);
float absolute(byte **image, int r, int c);

Image *roberts(Image *inputImage, boolean flag){
    Image *outputImage;
	byte **inputData;
    float **outputData;
    unsigned int numberRows = getNoOfRows_Image(inputImage);
    unsigned int numberCols = getNoOfCols_Image(inputImage);
    unsigned int numberBands = getNoOfBands_Image(inputImage);
    outputImage = new_Image(PGM, GRAY_SCALE, numberBands, numberRows, numberCols, CVIP_FLOAT, REAL);
	for (int bands = 0; bands < numberBands; bands++) {
        inputData = getData_Image(inputImage, bands);
        outputData = getData_Image(outputImage, bands);
        for (int r = 1; r < numberRows-1; r++){
            for (int c = 1; c < numberCols-1; c++){
                if (flag == 0){
                    outputData[r][c] = squareRoot(inputData, r, c);
                }
                else{
                    outputData[r][c] = absolute(inputData, r, c);
                }
            }
        }
    }
	outputImage = remap_Image(outputImage, CVIP_BYTE, 0, 255);

    return outputImage;
}

float squareRoot(byte **image, int r, int c){
	float a = image[r][c] - image[r - 1][c - 1];
	float b = image[r][c - 1] - image[r - 1][c];
    return sqrt((a*a) + (b*b));
}

float absolute(byte **image, int r, int c){
	float a = abs(image[r][c] - image[r - 1][c - 1]);
	float b = abs(image[r][c - 1] - image[r - 1][c]);
    return a + b;
}
