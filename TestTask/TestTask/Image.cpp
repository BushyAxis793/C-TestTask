#include "Image.h"


Image::Image()	
{
	std::unique_ptr<Color> color1(new Color());
	std::unique_ptr<Color> color2(new Color(255, 255, 255));

	std::ofstream file("ImageB.bmp", std::ios::binary);

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

Image::Image(uint8_t red, uint8_t green, uint8_t blue)
{
	std::unique_ptr<Color> color(new Color(red, green, blue));
	

	std::ofstream file("ImageA.bmp", std::ios::binary);

	file.write((char*)&bmpHeader, 14);
	file.write((char*)&bmpInfoHeader, 40);

	auto baseColor = color->GetColor();
	

	for (size_t i = 0; i < GetNumberOfPixels(bmpInfoHeader); i++)
	{
		
		//Dodaæ licznik kolorów
		file.write((char*)&baseColor, 3);
		color->SetRedColor(0+i/2);
		baseColor = color->GetColor();
	}

	std::cout << uniqueColorList.size();

	file.close();
}

Image::Image(const Image&)
{
}

Image::~Image()
{
}

void Image::SetColor(float r, float g, float b)
{
	
}

Color Image::GetColor() const
{
	return Color();
}

size_t Image::GetNumberOfPixels(BMPInfoHeader& bmpInfoHeader)
{
	
	return bmpInfoHeader.width * bmpInfoHeader.height; 
}


