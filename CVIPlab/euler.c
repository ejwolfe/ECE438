//Eric Wolfe
//800480613
//Lab 2

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"

int convexities(byte **image, int r, int c);
int concavities(byte **image, int r, int c);

Image *euler(Image *inputImage){
    byte **image;
    int concavitiesSum = 0, convexitiesSum = 0;
    unsigned int numberRows = getNoOfRows_Image(inputImage);
    unsigned int numberCols = getNoOfCols_Image(inputImage);
    image = getData_Image(inputImage, 0);
	for (int r = 1; r < numberRows - 1; r++) {
		for (int c = 1; c < numberCols - 1; c++) {
			concavitiesSum += concavities(image, r, c);
			convexitiesSum += convexities(image, r, c);
		}
	}
    printf("The number of convexities: %d\n", convexitiesSum);
    printf("The number of concavities: %d\n", concavitiesSum);
    printf("The Euler number: %d\n", (convexitiesSum-concavitiesSum));
	return inputImage;
}

int convexities(byte **image, int r, int c){
    if (image[r][c] == 255 && image[r][c-1] == 0 && image[r-1][c] == 0 && image[r-1][c-1] == 0){
        return 1;
    }
    return 0;
}

int concavities(byte **image, int r, int c){
    if (image[r][c] == 255 && image[r][c-1] == 255 && image[r-1][c] == 255 && image[r-1][c-1] == 0){
        return 1;
    }
    return 0;
}
