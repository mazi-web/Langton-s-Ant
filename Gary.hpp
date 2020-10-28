#ifndef HAVEYOUSEENTHSISNAIL_GARY
#define HAVEYOUSEENTHSISNAIL_GARY

#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "Cell.hpp"

enum orientation { up, right, down, left };
class Gary {
public:
	Gary(unsigned int x);
	std::vector<unsigned int> position;
	orientation orient;
	unsigned int boardsize;
	unsigned int get_row();
	unsigned int get_col();
	orientation get_orientation();
	std::string get_orientation_string();
	void move(Cell*);
};
Gary::Gary(unsigned int x) {
	Gary::position.resize(2);
	Gary::position = { x / 2, x / 2 };
	Gary::orient = up;
	Gary::boardsize = x;
}
unsigned int Gary::get_row() {
	return Gary::position[0];
}
unsigned int Gary::get_col() {
	return Gary::position[1];
}
orientation Gary::get_orientation() {
	return Gary::orient;
}
std::string Gary::get_orientation_string(){
	switch (Gary::orient) {
	case up:
		return "up";
		break;
	case right:
		return "right";
		break;
	case down:
		return "down";
		break;
	case left:
		return "left";
		break;
	}
}
void Gary::move(Cell* box) {
	if (box->get_color() == white) {
		switch (Gary::orient) {
		case up:
			Gary::orient = right;
			break;
		case right:
			Gary::orient = down;
			break;
		case down:
			Gary::orient = left;
			break;
		case left:
			Gary::orient = up;
			break;
		}
	}
	else if (box->get_color() == black) {
		switch (Gary::orient) {
		case up:
			Gary::orient = left;
			break;
		case right:
			Gary::orient = up;
			break;
		case down:
			Gary::orient = right;
			break;
		case left:
			Gary::orient = down;
			break;
		}
	}
	else{}
	box->change_color();
	switch (Gary::orient) {
	case up:
		if (Gary::get_row() == 0) {
			Gary::position[0] = Gary::boardsize - 1;
		}
		else {
			Gary::position[0] = Gary::position[0] - 1;
		}
		break;
	case down:
		if (Gary::get_row() == Gary::boardsize - 1) {
			Gary::position[0] = 0;
		}
		else {
			Gary::position[0] = Gary::position[0] + 1;
		}
		break;
	case right:
		if (Gary::get_col() == Gary::boardsize - 1) {
			Gary::position[1] = 0;
		}
		else {
			Gary::position[1] = Gary::position[1] + 1;
		}
		break;
	case left:
		if (Gary::get_col() == 0) {
			Gary::position[1] = Gary::boardsize - 1;
		}
		else {
			Gary::position[1] = Gary::position[1] - 1;
		}
		break;
	}

}

#endif