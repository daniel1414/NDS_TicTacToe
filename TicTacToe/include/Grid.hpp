#pragma once
#include <nds.h>
#include <stdio.h>

class Grid {
private:
	char _grid[3][3];
public:
	Grid();
	void init();
	void print() const;
	bool setTile(u8 y, u8 x, char tile);
	bool check() const;
	bool tie() const;
};