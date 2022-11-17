
#include <fstream>
#include <iostream>
#include <chrono>

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
	uint32_t colorTableEntries = 2;
	uint32_t importantColors = 0;
} bmpInfoHeader;

struct Pixel
{
	uint8_t red = 0;
	uint8_t green = 0;
	uint8_t blue = 0;
} pixel;

#pragma pack (pop)


int main()
{
	std::ofstream file("image.bmp", std::ios::binary);

	file.write((char*)&bmpHeader, 14);
	file.write((char*)&bmpInfoHeader, 40);

	Pixel p1,p2;

	size_t numberOfPixels = bmpInfoHeader.width * bmpInfoHeader.height;

	p1.blue = 255;
	p1.green = 0;
	p1.red = 0;



	size_t numberOfPixelsDividedByTwo = numberOfPixels / 2;
	

	for (size_t i = 0; i < numberOfPixels; i++) 
	{

		if (i % 16 == 0)
		{
			file.write((char*)&p1, 3);

		}
		else
		{
			file.write((char*)&pixel, 3);
		}
		
	}
	/* Dodać konstrukctor domyslny który tworzy imgA
	* i generuje obrazek z czarnym tlem i bialymi liniami.
	* Dodać konstrukctor kopiujący który tworzy obraz z 
	* grafiką jak imgA
	* Dodać kosntruktor pzeciazony, który generuje sam kolor
	*/
	
	std::cout << bmpInfoHeader.colorTableEntries << std::endl;


	file.close();

	/* Mierzenie czasu operacji
    auto start = std::chrono::high_resolution_clock::now();
    

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << duration.count() << std::endl;
	*/
}


