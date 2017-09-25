//Eric Wolfe
//800480613
//Lab 4

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"
#include <cmath>

float squareRoot(float **image, int r, int c);
float absolute(float **image, int r, int c);

Image *roberts(Image *inputImage, bool flag){
    Image *outputImage;
    float **imageData;
    unsigned int numberRows = getNoOfRows_Image(inputImage);
    unsigned int numberCols = getNoOfCols_Image(inputImage);
    unsigned int numberBands = getNoOfBands_Image(inputImage);
    outputImage = newImage(PGM, GRAY_SCALE, numberBands, numberRows, numberCols, CVIP_FLOAT, REAL);
    for (int bands = 0; bands < numberBands, bands++){
        imageData = getData_Image(outputImage, bands);
        for (int r = 1; r < numberRows-1; r++){
            for (int c = 1; c < numberCols-1; c++){
                if (flag == false){
                    squareRoot(imageData, r, c);
                }
                else{
                    absolute(imageData, r, c);
                }
            }
        }
    }
    outputImage = remap_Image(outputImage, CVIP_BYTE, 0, 255);

    return outputImage;
}

float squareRoot(float **image, int r, int c){
    return sqrt((image[r][c] - image[r-1][c-1])^2 + (image[r][c-1] - image[r-1][c])^2);
}

float absolute(float **image, int r, int c){
    return abs(image[r][c] - image[r-1][c-1]) + abs(image[r][c-1]-image[r-1][c]);
}
