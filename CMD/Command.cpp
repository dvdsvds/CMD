#include <iostream>
#include <string>
#include <iomanip>
#include <filesystem>
#include "Command.h"

using namespace std;
namespace fs = filesystem;
using namespace fs;

void Command::showHelp(int num) {
	
	if (num == 0) { // show all commands
		cout << "SH  " << "      " << "SHOW HELP PAGE." << endl;
		cout << "CLR " << "      " << "CLEAR CONSOLE WINDOW." << endl;
		cout << "EXIT" << "      " << "EXIT PROGRAM." << endl;
		cout << "CC  " << "      " << "SHOW CURRENT DIRECTORY." << endl;
		cout << "OF  " << "      " << "FILES OUTPUT OF CURRENT DIRECTORY" << endl;
	}

	else if (num == 1) { // show basic commands
		cout << "SH  " << "      " << "SHOW HELP PAGE." << endl;
		cout << "CLR " << "      " << "CLEAR CONSOLE WINDOW." << endl;
		cout << "EXIT" << "      " << "EXIT PROGRAM." << endl;
	}

	else if(num == 2) { // show commands that is about file and directory
		cout << "CC  " << "      " << "SHOW CURRENT DIRECTORY." << endl;
		cout << "OF  " << "      " << "FILES OUTPUT OF CURRENT DIRECTORY" << endl;
		cout << " " << "      " << " " << endl;
		cout << " " << "      " << " " << endl;
	}

	 
}

void Command::checkCurrentDir() {
	path currentDir = current_path();
	cout << "[ " << currentDir.string() << " ]" << endl;
}

void Command::outputFiles() {
	string currentDir = ".";
	for (const auto& entry : directory_iterator(currentDir)) {
		cout << entry.path().string() << endl;
	}
}