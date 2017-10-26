//Eric Wolfe
//800480613
//Lab 6

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"

byte runOr(byte a, int b);

Image *dilation(Image *inputImage, int structuringElement[][3]) {
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
		for (int r = 1; r < numberRows - 1; r++) {
			for (int c = 1; c < numberCols - 1; c++) {
				if (inputData[r][c] == (byte)255) {
					outputData[r - 1][c - 1] = runOr(inputData[r - 1][c - 1], structuringElement[0][0]);
					outputData[r - 1][c] = runOr(inputData[r - 1][c], structuringElement[0][1]);
					outputData[r - 1][c + 1] = runOr(inputData[r - 1][c + 1], structuringElement[0][2]);
					outputData[r][c - 1] = runOr(inputData[r][c - 1], structuringElement[1][0]);
					outputData[r][c] = runOr(inputData[r][c], structuringElement[1][1]);
					outputData[r][c + 1] = runOr(inputData[r][c + 1], structuringElement[1][2]);
					outputData[r + 1][c - 1] = runOr(inputData[r + 1][c - 1], structuringElement[2][0]);
					outputData[r + 1][c] = runOr(inputData[r + 1][c], structuringElement[2][1]);
					outputData[r + 1][c + 1] = runOr(inputData[r + 1][c + 1], structuringElement[2][2]);
				}
			}
		}
	}

	return outputImage;
}

byte runOr(byte a, int b) {
	if (a == (byte)0 && b == 0) {
		return (byte)0;
	}
	return (byte)255;
}