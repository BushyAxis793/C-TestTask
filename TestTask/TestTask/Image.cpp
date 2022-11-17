#include "Image.h"

Image::Image(int width, int height)
	: m_width(width), m_height(height)
{
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

void Image::ExportImage(const char* imageName)
{
	std::ofstream image(imageName);

	image << "P3" << std::endl;
	image << m_width << " " << m_height;
	image << "255" << std::endl;

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			int r = j % 255;
			int g = i % 255;
			int b = i % 255;

			image << r << " " << g << " " << b << std::endl;
		}
	}

	//system('open'+imageName);
}
