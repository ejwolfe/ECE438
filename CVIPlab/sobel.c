//Eric Wolfe
//800480613
//Lab 4

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"

float verticalEdge(byte **image, int r, int c);
float horizontalEdge(byte **image, int r, int c);
float edgeMagnitude(float s1, float s2);

Image *sobel(Image *inputImage){
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
				outputData[r][c] = edgeMagnitude(verticalEdge(inputData, r, c), horizontalEdge(inputData, r, c));
            }
        }
    }
    outputImage = remap_Image(outputImage, CVIP_BYTE, 0, 255);

    return outputImage;
}

float verticalEdge(byte **image, int r, int c){
    return (image[r-1][c-1]*-1) + (image[r-1][c] * -2) + (image[r-1][c+1] * -1)
    + (image[r+1][c-1] * 1) + (image[r+1][c] * 2) + (image[r+1][c+1] * 1);
}

float horizontalEdge(byte **image, int r, int c){
    return (image[r-1][c-1]* -1) + (image[r][c-1] * -2) + (image[r+1][c-1] * -1)
    + (image[r-1][c+1] * 1) + (image[r][c+1] * 2) + (image[r+1][c+1] * 1);
}

float edgeMagnitude(float s1, float s2){
    return sqrt((s1*s1) + (s2*s2));
}
