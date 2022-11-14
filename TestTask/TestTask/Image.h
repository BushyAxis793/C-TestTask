#pragma once

#include <fstream>
#include <iostream>
#include "Color.h"
class Image
{
public:
	Image(int width, int height);
	Image(const Image&);
	~Image();

	void SetColor(float r, float g, float b);
	Color GetColor() const;

	void ExportImage(const char*)const;

private:
	int m_width;
	int m_heigth;
	

};

