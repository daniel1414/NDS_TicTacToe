#include "Player.hpp"

Position Player::move() const {
	Position position = { 1, 1 };
	int keys;
	
	while (1) {
		iprintf("\x1b[4;5HNew player %c position:\n\n", _sign);
		iprintf("\x1b[9Cy = %d, x = %d\n", position.y, position.x);

		touchPosition touch;
		scanKeys();
		keys = keysDown();

		if (keys & KEY_UP && position.y > 1)
			position.y--;
		if (keys & KEY_DOWN && position.y < 3)
			position.y++;
		if (keys & KEY_RIGHT && position.x < 3)
			position.x++;
		if (keys & KEY_LEFT && position.x > 1)
			position.x--;
		if (keys & KEY_A)
			return position;
		//------------------- touch ------------------//
		if (keys & KEY_TOUCH) {
			touchRead(&touch);
			if (checkX(position.x, touch.px) && checkY(position.y, touch.py))
				return position;
		}
	}
	return position;
}
bool Player::checkX(u8& posX, u32 touchX) const {
	if (touchX > 90 && touchX < 123) {
		posX = 1;
		return true;
	}
	if (touchX > 123 && touchX < 155) {
		posX = 2;
		return true;
	}
	if (touchX > 155 && touchX < 188) {
		posX = 3;
		return true;
	}
	return false;
	
}
bool Player::checkY(u8& posY, u32 touchY) const {
	if (touchY > 107 && touchY < 121) {
		posY = 1;
		return true;
	}
	if (touchY > 126 && touchY < 137) {
		posY = 2;
		return true;
	}
	if (touchY > 143 && touchY < 152) {
		posY = 3;
		return true;
	}
	return false;
}