//Eric Wolfe
//800480613
//Lab 2

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"
#include "CVIPgeometry.h"

Image *crop(Image *inputImage, unsigned int offsetX, unsigned int offsetY, unsigned int height, unsigned int width) {
	Matrix *originalImage, *croppedImage;
	unsigned numberBands = getNoOfBands_Image(inputImage);
	for (int i = 0; i < numberBands; i++) {
		originalImage = getBand_Image(inputImage, i);
		croppedImage = crop_Matrix(originalImage, offsetY, offsetX, height, width);
		if (!croppedImage) {
			return 0;
		}
		setBand_Image(inputImage, croppedImage, i);
		delete_Matrix(originalImage);
	}
	return (inputImage);
}