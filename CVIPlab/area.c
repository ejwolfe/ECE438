//Eric Wolfe
//800480613
//Lab 3

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"

Image *area(Image *inputImage) {
	byte **image;
	int area = 0;
	double rsum = 0.0, csum = 0.0;
	unsigned int numberRows = getNoOfRows_Image(inputImage);
	unsigned int numberCols = getNoOfCols_Image(inputImage);
	image = getData_Image(inputImage, 0);
	for (int r = 0; r < numberRows; r++) {
		for (int c = 0; c < numberCols; c++) {
			if (image[r][c] == 255) {
				area++;
				rsum += r;
				csum += c;
			}
		}
	}
	rsum = (1.0 / area)*rsum;
	csum = (1.0 / area)*csum;
	printf("Area: %d\n", area);
	printf("Center: ( %d , %d )\n", (int)rsum, (int)csum);
	return inputImage;
}