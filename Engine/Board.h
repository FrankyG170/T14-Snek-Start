#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetGridHeight() const;
	int GetGridWidth() const;
	bool IsInsideBoard(const Location& loc)const;
private:
	static constexpr int dimension = 20;
	const int width;
	const int height;
	Graphics& gfx;
};