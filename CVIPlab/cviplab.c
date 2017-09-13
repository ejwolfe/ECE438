/* =========================================================================
*
*   Computer Vision and Image Processing Lab - Dr. Scott Umbaugh SIUE
*
* =========================================================================
*
*             File Name: CVIPlab.c
*           Description: This  is the skeleton program for the Computer Vision
*			 and Image Processing Labs
*   Initial Coding Date: April 23, 1996
*   Last update Date: August 30, 2017
*   .NET version:     September 21, 2006
*           Portability: Standard (ANSI) C
*             Credit(s): Scott Umbaugh, Zhen Li, Kun Luo,Dejun Zhang,Wenjun(Evan) Bian, Rohini Dahal, Norsang Lama
*                        Southern Illinois University Edwardsville
*  Copyright (C) 2004 Scott Umbaugh and SIUE
*
*  Permission to use, copy, modify, and distribute this software and its
*  documentation for any non-commercial purpose and without fee is hereby
*  granted, provided that the above copyright notice appear in all copies
*  and that both that copyright notice and this permission notice appear
*  in supporting documentation.  This software is provided "as is"
*  without express or implied warranty.
*
****************************************************************************/

/*
** include header files
*/

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"
//#include "CVIPview.h"

#define CASE_MAX 20

/* Put the command here, as VIDEO_APP, to run your image acquisition
application program */

#define VIDEO_APP "explorer.exe"

/*
** function declarations
*/
Image *zoom_Setup(Image *inputImage);
Image *crop_Setup(Image *inputImage);
Image *threshold_Setup(Image *inputImage);
Image *input();
/*
** start main funct
*/
void main_cviplab() {
	IMAGE_FORMAT  format;     	/* the input image format */
	Image	  *cvipImage; 	/* pointer to the CVIP Image structure */
	Image	  *cvipImage1; 	/* pointer to the CVIP Image structure */
	char	  *outputfile;	/* output file name */
	int		  choice;
	CVIP_BOOLEAN  done = CVIP_NO;

	
	print_CVIP("\n\n\n\n***************************************");
	print_CVIP("****************************  ");
	print_CVIP("\n*\t\t Computer Vision and Image Processing Lab\t  *");
	print_CVIP("\n*\t\t\t Eric Wolfe \t\t  *");
	print_CVIP("\n******************************************");
	print_CVIP("*************************\n\n\n");

	while (!done) {
		print_CVIP("\t\t0.\tExit \n");
		print_CVIP("\t\t1.\tGrab and Snap an Image  \n");
		print_CVIP("\t\t2.\tThreshold Operation\n");
		print_CVIP("\t\t3.\tImage Crop\n");
		print_CVIP("\t\t4.\tImage Zoom\n");
		print_CVIP("\t\t5.\tImage Rotate\n");
		print_CVIP("\n\nCVIPlab>>");


		/*
		** obtain an integer between 0 and CASE_MAX from the user
		*/
		choice = getInt_CVIP(10, 0, CASE_MAX);

		switch (choice) {

		case 0:
			done = CVIP_YES;
			break;

		case 1:
			if (ShellExecute(NULL, "Open", VIDEO_APP, NULL, NULL, SW_SHOW) <= 32)
				print_CVIP("Error while running Video Program");
			break;

		case 2:
			/*Get the input image */
			cvipImage = input();
			if (cvipImage == NULL)
			{
				error_CVIP("main", "could not read input image");
				break;
			}

			/* calls the threshold function */
			cvipImage = threshold_Setup(cvipImage);
			if (!cvipImage)
			{
				error_CVIP("main", "threshold fails");
				break;
			}

			/*
			** display the resultant image
			*/
			
			view_Image(cvipImage, "threshold");
		
			delete_Image(cvipImage);

			break;
		
		case 3:
			/*Get the input image */
			cvipImage = input();
			if (cvipImage == NULL)
			{
				error_CVIP("main", "could not read input image");
				break;
			}

			cvipImage = crop_Setup(cvipImage);
			if (!cvipImage) {
				error_CVIP("main", "crop fails");
				break;
			}
			
			view_Image(cvipImage, "crop");
			
			delete_Image(cvipImage);

			break;

		case 4:
			/*Get the input image */
			cvipImage = input();
			if (cvipImage == NULL)
			{
				error_CVIP("main", "could not read input image");
				break;
			}

			cvipImage = zoom_Setup(cvipImage);
			if (!cvipImage) {
				error_CVIP("main", "zoom fails");
				break;
			}

			view_Image(cvipImage, "crop");

			delete_Image(cvipImage);

			break;

		case 5:
			/*Get the input image */
			cvipImage = input();
			if (cvipImage == NULL)
			{
				error_CVIP("main", "could not read input image");
				break;
			}

			view_Image(cvipImage, "crop");

			delete_Image(cvipImage);

			break;

			default:
			print_CVIP("Sorry ! You Entered a wrong choice ");
			break;
		}
	}
}
/*
** end of the function main
*/


/*
** The following function reads in the image file specified by the user,
** stores the data and other image info. in a CVIPtools Image structure,
** and displays the image.
*/

Image* input() {
	char  		*inputfile;
	Image		*cvipImage;

	/*
	** get the name of the file and stores it in the string 'inputfile '
	*/
	print_CVIP("\n\t\tEnter the Input File Name:  ");
	inputfile = getString_CVIP();

	/*
	** creates the CVIPtools Image structure from the input file
	*/
	cvipImage = read_Image(inputfile, 1);
	if (cvipImage == NULL) {
		error_CVIP("init_Image", "could not read image file");
		free(inputfile);
		return NULL;
	}

	/*
	** display the source image
	*/
	view_Image(cvipImage, inputfile);

	/*
	**IMPORTANT: free the dynamic allocated memory when it is not needed
	*/
	free(inputfile);

	return cvipImage;
}


/*
** The following setup function asks the threshold value from the user. After
** it gets the threshold value, it will call the threshold_Image() function.
*/

Image *threshold_Setup(Image *inputImage) {
	unsigned int 	threshval;      /* Threshold value */

									/*
									** Gets a value between between 0 and 255 for threshsold
									*/
	print_CVIP("\n\t\tEnter the threshold value:  ");
	threshval = getInt_CVIP(10, 0, 255);

	return threshold_lab(inputImage, threshval);
}

Image *crop_Setup(Image *inputImage) {
	unsigned int offsetX, offsetY, width, height;

	width = getNoOfCols_Image(inputImage);
	height = getNoOfRows_Image(inputImage);

	print_CVIP("\n\t\tEnter the offset for x: ");
	offsetX = getInt_CVIP(10, 0, width);
	print_CVIP("\n\t\tEnter the offset for y: ");
	offsetY = getInt_CVIP(10, 0, height);
	print_CVIP("\n\t\tEnter the height of the new image: ");
	height = getInt_CVIP(10, 0, height - offsetY);
	print_CVIP("\n\t\tEnter the width of the new image: ");
	width = getInt_CVIP(10, 0, width-offsetX);

	return crop(inputImage, offsetX, offsetY, height, width);
}

Image *zoom_Setup(Image *inputImage) {
	unsigned int r, c, width, height, zoomFactor;

	width = getNoOfCols_Image(inputImage);
	height = getNoOfRows_Image(inputImage);

	print_CVIP("\n\t\tEnter the offset for r: ");
	r = getInt_CVIP(10, 0, width);
	print_CVIP("\n\t\tEnter the offset for c: ");
	c = getInt_CVIP(10, 0, height);
	print_CVIP("\n\t\tEnter the height of the new image: ");
	height = getInt_CVIP(10, 0, height - r);
	print_CVIP("\n\t\tEnter the width of the new image: ");
	width = getInt_CVIP(10, 0, width - c);
	print_CVIP("\n\t\tEnter the zoom factor of the new image: ");
	width = getInt_CVIP(10, 0, 10);
	
	return zoom(inputImage, r, c, height, width, zoomFactor);
}
