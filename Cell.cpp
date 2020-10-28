#include "Cell.hpp"
#include "Board.hpp"
#include "Gary.hpp"
#include <string>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	unsigned int boardSize;
	unsigned int numberSteps;
	std::string outputFilename;
	if (argc == 4) {
		boardSize = atoi(*(argv + 1));
		numberSteps = atoi(*(argv + 2));
		outputFilename = *(argv + 3);
	}
	else {
		boardSize = atoi(*(argv + 1));
		numberSteps = atoi(*(argv + 2));
		outputFilename = "N/A";
	}
	Board B(boardSize);
	if (strcmp(outputFilename.c_str(), "N/A") != 0) {
		B.setOutputFilename(outputFilename);
	}

	B.move_gary(numberSteps);

	return 0;
}
