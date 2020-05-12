#pragma once
#include <nds.h>
#include <stdio.h>

struct Position {
	u8 x, y;
};

class Player {
private:
	u8 _number;
	char _sign;
	u8 _score;
	bool checkX(u8& posX, u32 touchX) const;
	bool checkY(u8& posY, u32 touchY) const;
public:
	Player(u8 number, char sign) : _number(number), _sign(sign), _score(0) {}
	inline char getSign() const { return _sign; }
	inline u8 getNumber() const { return _number; }
	inline u8 getScore() const { return _score; }

	void score() { _score++; }
	Position move() const;
};