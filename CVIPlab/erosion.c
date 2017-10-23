//Eric Wolfe
//800480613
//Lab 6

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"

Image *erosion(Image *inputImage, byte **structuringElement){
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
                    outputData[r-1][c-1] = (inputData[r-1][c-1] == 1 && structuringElement[0][0] == 1) ? 0 : inputData[r-1][c-1];
                    outputData[r-1][c] = (inputData[r-1][c] == 1 && structuringElement[0][1] == 1) ? 0 : inputData[r-1][c];
                    outputData[r-1][c+1] = (inputData[r-1][c+1] == 1 && structuringElement[0][2] == 1) ? 0 : inputData[r-1][c+1];
                    outputData[r][c-1] = (inputData[r][c-1] == 1 && structuringElement[1][0] == 1) ? 0 : inputData[r][c-1];
                    outputData[r][c] = 255;
                    outputData[r][c+1] = (inputData[r][c+1] == 1 && structuringElement[1][2] == 1) ? 0 : inputData[r][c+1];
                    outputData[r+1][c-1] = (inputData[r+1][c-1] == 1 && structuringElement[2][0] == 1) ? 0 : inputData[r+1][c-1];
                    outputData[r+1][c] = (inputData[r+1][c] == 1 && structuringElement[2][1] == 1) ? 0 : inputData[r+1][c];
                    outputData[r+1][c+1] = (inputData[r+1][c+1] == 1 && structuringElement[2][2] == 1) ? 0 : inputData[r+1][c+1];
                }
            }
        }
    }
    for(int i = 0; i < numberCols; i++){
        outputData[0][i] = inputData[0][i];
        outputData[numberRows-1][i] = inputData[numberRows-1][i];
    }
    for(int i = 0; i < numberRows; i++){
        outputData[i][0] = inputData[i][0];
        outputData[i][numberCols-1] = inputData[i][numberCols-1];
    }
    outputImage = remap_Image(outputImage, CVIP_BYTE, 0, 255);

    return outputImage;
}
