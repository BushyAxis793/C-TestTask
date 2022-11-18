#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include "Color.h"

class Image
{
private:
#pragma pack(push,1)
	struct BMPHeader
	{
		char bitmapSignatureBytes[2] = { 'B','M' };
		uint32_t sizeOfBitmapFile = 54 + 786432;
		uint32_t reservedBytes = 0;
		uint32_t pixelDataOffset = 54;
	} bmpHeader;

	struct BMPInfoHeader
	{
		uint32_t sizeOfHeader = 40;
		uint32_t width = 512;
		uint32_t height = 512;
		uint16_t numberofColorPlanes = 1;
		uint16_t  colorDepth = 24;
		uint32_t compressionMethod = 0;
		uint32_t rawBitmapSize = 0;
		int32_t horizontalResolution = 3780;
		int32_t verticalResolution = 3780;
		uint32_t colorTableEntries = 0;
		uint32_t importantColors = 0;
	} bmpInfoHeader;

#pragma pack (pop)
	std::list<int> uniqueColorList;

public:
	Image();
	Image(const Image&);
	void CreateImageWithStrips(const char*);
	void CreateImageGradient(const char*, uint8_t , uint8_t , uint8_t );
	void CreateMixedImage(const char*,Image*, Image*);
	void WriteImageAsPNG(std::string);
	void GenerateLogFile(Image*,Image*);
	uint32_t GetColorsQuantity(Image*);
	~Image();

	void SetColor(float r, float g, float b);
	Color GetColor() const;
	size_t GetNumberOfPixels(BMPInfoHeader&);


	

};

