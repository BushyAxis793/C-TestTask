#pragma once
#include <cstdint>
class Color
{
private:
	struct ColorStruct
	{
		uint8_t red = 0;
		uint8_t green = 0;
		uint8_t blue = 0;
	} colorStruct;
public:
	Color();
	Color(uint8_t, uint8_t, uint8_t);
	ColorStruct GetColor() const;
	void SetRedColor(int);
	~Color();
	
};

