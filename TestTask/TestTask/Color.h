#pragma once
class Color
{
public:
	Color();
	Color(float red, float green, float blue);
	Color GetColor() const;
	~Color();
private:
		float r;
		float g;
		float b;
	
};

