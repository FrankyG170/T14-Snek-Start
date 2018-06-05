#include "Board.h"
#include <assert.h>



Board::Board(Graphics & gfx)
	:
	gfx (gfx)
{
	width = gfx.ScreenWidth / dimension;
	height = gfx.ScreenHeight / dimension;
}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}


int Board::GetGridHeight() const
{
	return height;
}

int Board::GetGridWidth() const
{
	return width;
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return 
		loc.x >= 0 && loc.x <= width - 1
		&&
		loc.y >= 0 && loc.y <= height - 1;
}
