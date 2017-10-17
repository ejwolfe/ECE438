//Eric Wolfe
//800480613
//Lab 6

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"

byte runOr(int a, int b);

Image *dilation(Image *inputImage, byte **structuringElement){
    Image *outputImage;
	byte **inputData;
    byte **outputData;
    unsigned int numberRows = getNoOfRows_Image(inputImage);
    unsigned int numberCols = getNoOfCols_Image(inputImage);
    unsigned int numberBands = getNoOfBands_Image(inputImage);
    outputImage = new_Image(PGM, GRAY_SCALE, numberBands, numberRows, numberCols, CVIP_BYTE, REAL);
	for (int bands = 0; bands < numberBands; bands++) {
        inputData = getData_Image(inputImage, bands);
        outputData = getData_Image(outputImage, bands);
        for (int r = 1; r < numberRows-1; r++){
            for (int c = 1; c < numberCols-1; c++){
				if(inputData[r][c] != 0){

                }
            }
        }
    }
    outputImage = remap_Image(outputImage, CVIP_BYTE, 0, 255);

    return outputImage;
}

byte runOr(int a, int b){
    if(a == 0 && b == 0){
        return 0;
    }
    return 255;
}
