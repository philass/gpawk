#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

const std::string USAGE="usage: awk [-f progfile | 'prog'] [file ...]";

int main(int argc, char** argv) {
	bool fromFile = false;
	if (argc == 1) {
		std::cout << USAGE << std::endl;
		return 0;
	} 
	if (strcmp(argv[1], "-f")) {
		fromFile = true;
	}
	char* program = fromFile ? argv[2] : argv[1];
	const char* text;
	if (fromFile) {
		// Get contents from specified file
		char* fileName = argv[3];
		std::ifstream in(fileName);
		std::string contents((std::istreambuf_iterator<char>(in)), 
				    std::istreambuf_iterator<char>());
		text = contents.c_str();
	} else {
		// Otherwise text is passed as a command line arguement
		text = argv[2];
	}
}
