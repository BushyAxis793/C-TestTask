
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

	auto startTime = std::chrono::high_resolution_clock::now();

	imageB->CreateImageWithStrips("ImageB.bmp");
	imageA->CreateImageGradient("ImageA.bmp", 255, 0, 0);
	imageC->CreateMixedImage("imageC.bmp", imageB, imageA);
	imageC->WriteImageAsPNG("imageC.bmp");

	auto stopTime = std::chrono::high_resolution_clock::now();
	
	auto durationTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
	
	imageC->GenerateLogFile(imageA, imageB, durationTime);

	
}


