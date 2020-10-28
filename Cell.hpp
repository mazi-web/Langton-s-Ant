#ifndef HAVEYOUSEENTHSISNAIL_CELL
#define HAVEYOUSEENTHSISNAIL_CELL

#include <string>
#include <string.h>
#include <stdlib.h>

// Declare an enumaration data type to store the Cell's color
enum CellColor { white, black };

// Declare the Cell Class
class Cell {
public:
	// Declare default constructor to initialize color to white
	Cell();
	// Declare member function getter for the color (get_color). Returns CellColor
	CellColor get_color();
	// Declare a member to flip the color (change_color)
	void change_color();
	// Declare a member to print the string for this color.
	// white = "0", black = "1"
	std::string get_color_string();

private:
	// Declare the color of this cell (color) as type CellColor
	CellColor color;
};
Cell::Cell() {
	Cell::color = white;
}
CellColor Cell::get_color() {
	switch (Cell::color) {
	case white:
		return white;
		break;
	case black:
		return black;
	}
}
void Cell::change_color() {
	switch (Cell::color) {
	case white:
		Cell::color = black;
		break;
	case black:
		Cell::color = white;
	}
}
std::string Cell::get_color_string() {
	switch (Cell::color) {
	case white:
		return "0";
		break;
	case black:
		return "1";
	}
}
#endif
