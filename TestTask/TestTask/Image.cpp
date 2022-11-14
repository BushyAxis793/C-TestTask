#include "Image.h"

Image::Image(int width, int height)
	: m_width(width), m_heigth(height)
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

void Image::ExportImage(const char* imageName) const
{
	std::ofstream image(imageName +'.ppm');

	
}
