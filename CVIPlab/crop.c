//Eric Wolfe
//800480613
//Lab 2

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"
#include "CVIPgeometry.h"
#include "CVIPmatrix.h"

Image *crop(Image *inputImage, unsigned int offsetX, unsigned int offsetY, unsigned int height, unsigned int width) {
	byte **image, **tempImage;
	unsigned numberBands = getNoOfBands_Image(inputImage);
	unsigned numberRows = getNoOfRows_Image(inputImage);
	unsigned numberCols = getNoOfCols_Image(inputImage);
	Image *temp = image_allocate(getFileFormat_Image(inputImage), getColorSpace_Image(inputImage), numberBands, height, width, getDataType_Image(inputImage), getDataFormat_Image(inputImage));
	for(int b = 0; b < numberBands; b++) {
		image = getData_Image(inputImage, b);
		tempImage = getData_Image(temp, b);
		for (int r = offsetX, x = 0; r < height+offsetX; r++, x++) {
			for (int c = offsetY, y = 0; c < width+offsetY; c++, y++) {
				tempImage[x][y] = image[r][c];
			}
		}
	}
	return (temp);
}