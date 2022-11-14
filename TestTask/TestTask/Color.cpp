#include "Color.h"

Color::Color()
	:r(0),g(0),b(0)
{

}

Color::Color(float red, float green, float blue)
	:r(red), g(green),b(blue)
{
}

Color Color::GetColor() const
{
	return Color();//chyba zmienic
}

Color::~Color()
{
}
