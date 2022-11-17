#include "Color.h"

Color::Color()
{
	colorStruct.red = 0;
	colorStruct.green = 0;
	colorStruct.blue = 0;
}

Color::Color(uint8_t blue, uint8_t green, uint8_t red)
{
	colorStruct.blue = blue;
	colorStruct.red = red;
	colorStruct.green = green;
}


Color::ColorStruct Color::GetColor() const
{
	return colorStruct;
}

void Color::SetRedColor(int color)
{
	colorStruct.red = color;
}

Color::~Color()
{
}
