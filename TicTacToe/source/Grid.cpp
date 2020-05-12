#include "Grid.hpp"

Grid::Grid() {
	init();
}
void Grid::init() {
	for (u8 y = 0; y < 3; y++) {
		for (u8 x = 0; x < 3; x++) {
			_grid[y][x] = ' ';
		}
	}
}
void Grid::print() const {
	iprintf("\x1b[12;7HY\\X | 1 | 2 | 3 |\n\n");
	for (u8 y = 0; y < 3; y++) {
		iprintf("        %d  | %c | %c | %c |\n\n", y + 1, _grid[y][0], _grid[y][1], _grid[y][2]);
	}
}

bool Grid::setTile(u8 y, u8 x, char tile) {
	if (_grid[y][x] == ' ') {
		_grid[y][x] = tile;
		return true;
	}
	else
		return false;
}
bool Grid::check() const {
	if ((_grid[0][0] == _grid[0][1] && _grid[0][1] == _grid[0][2] && _grid[0][0] != ' ') ||
		(_grid[1][0] == _grid[1][1] && _grid[1][1] == _grid[1][2] && _grid[1][0] != ' ') ||
		(_grid[2][0] == _grid[2][1] && _grid[2][1] == _grid[2][2] && _grid[2][0] != ' ') ||
		(_grid[0][0] == _grid[1][0] && _grid[1][0] == _grid[2][0] && _grid[0][0] != ' ') ||
		(_grid[0][1] == _grid[1][1] && _grid[1][1] == _grid[2][1] && _grid[0][1] != ' ') ||
		(_grid[0][2] == _grid[1][2] && _grid[1][2] == _grid[2][2] && _grid[0][2] != ' ') ||
		(_grid[0][0] == _grid[1][1] && _grid[1][1] == _grid[2][2] && _grid[0][0] != ' ') ||
		(_grid[2][0] == _grid[1][1] && _grid[1][1] == _grid[0][2] && _grid[2][0] != ' '))
		return true;
	else
		return false;
}
bool Grid::tie() const {
	for (u8 y = 0; y < 3; y++) {
		for (u8 x = 0; x < 3; x++) {
			if (_grid[y][x] == ' ')
				return false;
		}
	}
	return true;
}