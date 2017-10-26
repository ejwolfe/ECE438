//Eric Wolfe
//800480613
//Lab 6

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"

Image *erosion(Image *inputImage, int structuringElement[][3]){
    Image *outputImage;
	byte **inputData;
    byte **outputData;
    unsigned int numberRows = getNoOfRows_Image(inputImage);
    unsigned int numberCols = getNoOfCols_Image(inputImage);
    unsigned int numberBands = getNoOfBands_Image(inputImage);
    outputImage = new_Image(inputImage->image_format, inputImage->color_space, numberBands, numberRows, numberCols, getDataType_Image(inputImage), getDataFormat_Image(inputImage));
	for (int band = 0; band < numberBands; band++) {
		inputData = getData_Image(inputImage, band);
		outputData = getData_Image(outputImage, band);
		for (int r = 1; r < numberRows-1; r++){
			for (int c = 1; c < numberCols-1; c++){
						if (inputData[r - 1][c - 1] == (byte)0 && structuringElement[0][0] == 1) {
							outputData[r][c] = (byte)0;
						}
						else if (inputData[r - 1][c] == (byte)0 && structuringElement[0][1] == 1) {
							outputData[r][c] = (byte)0;
						}
						else if (inputData[r - 1][c + 1] == (byte)0 && structuringElement[0][2] == 1) {
							outputData[r][c] = (byte)0;
						}
						else if (inputData[r][c-1] == (byte)0 && structuringElement[1][0] == 1) {
							outputData[r][c] = (byte)0;
						}
						else if (inputData[r][c] == (byte)0 && structuringElement[1][1] == 1) {
							outputData[r][c] = (byte)0;
						}
						else if (inputData[r][c+1] == (byte)0 && structuringElement[1][2] == 1) {
							outputData[r][c] = (byte)0;
						}
						else if (inputData[r+1][c - 1] == (byte)0 && structuringElement[2][0] == 1) {
							outputData[r][c] = (byte)0;
						}
						else if (inputData[r + 1][c] == (byte)0 && structuringElement[2][1] == 1) {
							outputData[r][c] = (byte)0;
						}
						else if (inputData[r + 1][c + 1] == (byte)0 && structuringElement[2][2] == 1) {
							outputData[r][c] = (byte)0;
						}
						else {
							outputData[r][c] = (byte)255;
						}
			}
		}
	}

    return outputImage;
}