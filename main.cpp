#include "Program/Program.h"

int main(int argc, char* argv[]) {
	//ignores anything that could be left in the stream
	cin.sync(); 
	
	Program program;
	program.run();
	return 0;
}

