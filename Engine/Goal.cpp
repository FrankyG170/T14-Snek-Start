#include "Goal.h"
#pragma once

Goal::Goal(std::mt19937 & rng, const Board & brd, const Snake & snek)
{
	Respawn(rng, brd, snek);
}

void Goal::Respawn(std::mt19937 & rng, const Board & brd, const Snake & snek)
{
	std::uniform_int_distribution<int>xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int>yDist(0, brd.GetGridHeight() - 1);
	
	
	Location newLoc;

	do 
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	}
	// If the generated goal is in the snek, regenerate it with new random distributions until it is not
	while (snek.IsInTile(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board & brd)
{
	brd.DrawCell(loc, c);
}

const Location & Goal::Getlocation() const
{
	return loc;
}
