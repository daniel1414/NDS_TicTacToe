#include <nds.h>
#include <stdio.h>
#include "Player.hpp"
#include "Grid.hpp"

bool newGame(Grid& g, const Player& p, bool tie = false) {
	if (tie) {
		iprintf("\x1b[8;6HIt's a Tie game!!!\n\n");
	}else 
		iprintf("\x1b[8;8HPlayer %c won!!!\n\n", p.getSign());
	iprintf("\x1b[8CNew Game? (A/B)");
	while (1) {
		scanKeys();
		int keys = keysDown();
		if (keys & KEY_A) { // new game
			iprintf("\x1b[2J");
			iprintf("\x1b[1;5HWelcome to TicTacToe!\n");
			g.init();
			return true;
		}
		else if (keys & KEY_B) {
			return false;
		}
	}
	return false;
}

int main(void) {

	consoleDemoInit();

	iprintf("\x1b[1;5HWelcome to TicTacToe!\n");
	
	Player p1(1, 'X');
	Player p2(2, 'O');
	bool turn1 = true;
	Grid grid;
	Position tempPosition;

	while (1) {
		grid.print();
		iprintf("\x1b[21;1HPlayer %c's score: %d", p1.getSign(), p1.getScore());
		iprintf("\x1b[22;1HPlayer %c's score: %d", p2.getSign(), p2.getScore());

		if (turn1) {
			tempPosition = p1.move();
			if (grid.setTile(tempPosition.y - 1, tempPosition.x - 1, p1.getSign())) {
				turn1 = false;
			}
			grid.print();
			if (grid.check()) {
				p1.score();
				iprintf("\x1b[21;1HPlayer %c's score: %d", p1.getSign(), p1.getScore());
				if (newGame(grid, p1)) 
					continue;
				else 
					return 0;
			}
			if (grid.tie()) {
				if (newGame(grid, p1, true))
					continue;
				else
					return 0;
			}
		}
		if (!turn1) {
			tempPosition = p2.move();
			if (grid.setTile(tempPosition.y - 1, tempPosition.x - 1, p2.getSign())) {
				turn1 = true;
			}
			grid.print();
			if (grid.check()) {
				p2.score();
				iprintf("\x1b[22;1HPlayer %c's score: %d", p2.getSign(), p2.getScore());
				if (newGame(grid, p2))
					continue;
				else
					return 0;
			}
			if (grid.tie()) {
				if (newGame(grid, p2, true))
					continue;
				else
					return 0;
			}
		}
		swiWaitForVBlank();
	}
	return 0;
}