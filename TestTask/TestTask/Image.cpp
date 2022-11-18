#include "Image.h"



Image::Image()	
{
	
}

Image::Image(const Image&)
{
}

Image::~Image()
{
}


void Image::CreateMixedImage(const char* fileName,Image* imageContext, Image* imagePixels)
{
	std::unique_ptr<Color> color2(new Color(255, 255, 255));

	std::ofstream file(fileName, std::ios::binary);

	file.write((char*)&bmpHeader, 14);
	file.write((char*)&bmpInfoHeader, 40);

	 auto firstColor = imagePixels->GetColor();
	 auto secondColor = color2->GetColor();

	for (size_t i = 0; i < GetNumberOfPixels(bmpInfoHeader); i++)
	{
		if (i % 16 == 0)
		{
			file.write((char*)&firstColor, 3);
		}
		else
		{
			file.write((char*)&secondColor, 3);
		}
	}

	file.close();
}

void Image::CreateImageGradient(const char* fileName, uint8_t red, uint8_t green, uint8_t blue)
{
	std::unique_ptr<Color> color(new Color(red, green, blue));


	std::ofstream file(fileName, std::ios::binary);

	file.write((char*)&bmpHeader, 14);
	file.write((char*)&bmpInfoHeader, 40);

	auto baseColor = color->GetColor();


	for (size_t i = 0; i < GetNumberOfPixels(bmpInfoHeader); i++)
	{
		file.write((char*)&baseColor, 3);
		color->SetRedColor(0 + i / 2);
		baseColor = color->GetColor();
	}

	file.close();
}

void Image::CreateImageWithStrips(const char* fileName)
{
	std::unique_ptr<Color> color1(new Color());
	std::unique_ptr<Color> color2(new Color(255, 255, 255));

	std::ofstream file(fileName, std::ios::binary);

	file.write((char*)&bmpHeader, 14);
	file.write((char*)&bmpInfoHeader, 40);

	auto firstColor = color1->GetColor();
	auto secondColor = color2->GetColor();

	for (size_t i = 0; i < GetNumberOfPixels(bmpInfoHeader); i++)
	{
		if (i % 16 == 0)
		{
			file.write((char*)&firstColor, 3);

		}
		else
		{
			file.write((char*)&secondColor, 3);
		}
	}

	file.close();
}

void Image::SetColor(float r, float g, float b)
{
	
}

void Image::WriteImageAsPNG(std::string fileName)
{
	std::ifstream file (fileName, std::ios::binary);
	auto i = fileName.rfind('.', fileName.length());
	fileName.replace(i + 1, fileName.length(), "png");
	
	file.close();
	
	
}

Color Image::GetColor() const
{
	return Color();
}

size_t Image::GetNumberOfPixels(BMPInfoHeader& bmpInfoHeader)
{
	
	return bmpInfoHeader.width * bmpInfoHeader.height; 
}

uint32_t Image::GetColorsQuantity(Image* image)
{
	return image->bmpInfoHeader.width *
		image->bmpInfoHeader.height *
		image->bmpInfoHeader.colorDepth;
}

void Image::GenerateLogFile(Image* image, Image* image2)
{
	std::ofstream logFile("log.txt", std::ios::binary);

	logFile << "Image A colors quantity: " <<GetColorsQuantity(image)<<std::endl;
	logFile << "Image B colors quantity: " << GetColorsQuantity(image2) << std::endl;








}


