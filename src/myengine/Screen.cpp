#include "Screen.h"

namespace myengine
{
	void Screen::setWidth(int w)
	{
		width = w;
	}

	void Screen::setHeight(int h)
	{
		height = h;
	}

	int Screen::getWidth()
	{
		return width;
	}

	int Screen::getHeight()
	{
		return height;
	}
}