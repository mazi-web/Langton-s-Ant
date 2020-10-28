#ifndef HAVEYOUSEENTHSISNAIL_BOARD
#define HAVEYOUSEENTHSISNAIL_BOARD

#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Gary.hpp"

class Board {
public:
	Board(unsigned int N);

	void move_gary(unsigned int x);

	void setOutputFilename(std::string outputFile);

	unsigned int bsize;

	std::string output;

	std::ofstream myfileout;
};
Board::Board(unsigned int N) {
	if (N % 2 == 0) {
		std::cout << "Board dimension must be an odd number!! Got " << N << " and adding 1 to equal " << N + 1 << std::endl;
		N = N + 1;
	}
	Board::bsize = N;
	Board::output = "N/A";
}
void Board::setOutputFilename(std::string outputFile) {
	if (strcmp(outputFile.c_str(), "N/A") != 0) {
		myfileout.open(outputFile.c_str());
		/*if (myfileout.is_open()) {
			std::cout << outputFile.c_str() << " is open";
		}*/
		Board::output = outputFile;
	}
}
void Board::move_gary(unsigned int x) {
	std::vector<std::vector<Cell>> board;
	board.resize(bsize);
	for (int i = 0; i < bsize; i++) {
		board[i].resize(bsize);
	}
	Gary G(Board::bsize);
	for (int i = 0; i < x+1; i++) {
		if (strcmp(Board::output.c_str(), "N/A") == 0) {
			std::cout << "[Gary Location] {" << G.get_row() << ", " << G.get_col() << "} [Gary Orientation] " << G.get_orientation_string() << " ";
			for (int k = 0; k < bsize; k++) {
				std::cout << "[Row " << k << "] ";
				for (int j = 0; j < bsize; j++) {
					std::cout << board[k][j].get_color_string() << " ";
				}
			}
			std::cout << std::endl;
		}
		else if (strcmp(Board::output.c_str(), "N/A") != 0) {
			myfileout << "[Gary Location] {" << G.get_row() << ", " << G.get_col() << "} [Gary Orientation] " << G.get_orientation_string() << " ";
			for (int k = 0; k < bsize; k++) {
				myfileout << "[Row " << k << "] ";
				for (int j = 0; j < bsize; j++) {
					myfileout << board[k][j].get_color_string() << " ";
				}
			}
			myfileout << std::endl;
		}
		G.move(&board[G.get_row()][G.get_col()]);
	}
	if (strcmp(Board::output.c_str(), "N/A") != 0) {
		Board::myfileout.close();
	}
}
#endif