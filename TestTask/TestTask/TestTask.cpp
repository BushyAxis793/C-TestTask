
#include <fstream>
#include <iostream>
#include <chrono>
#include "Image.h"
#include <memory>




int main()
{
	Image *imageA = new Image();
	Image *imageB = new Image();
	Image *imageC = new Image();


	imageB->CreateImageWithStrips("ImageB.bmp");
	imageA->CreateImageGradient("ImageA.bmp", 255, 0, 0);
	imageC->CreateMixedImage("imageC.bmp", imageB, imageA);
	imageC->WriteImageAsPNG("imageC.bmp");
	imageC->GenerateLogFile(imageA, imageB);
	/*

	
	*
	
	


	

	/* Mierzenie czasu operacji
    
    

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << duration.count() << std::endl;
	*/
	
}


