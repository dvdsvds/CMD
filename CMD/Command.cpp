#include <iostream>
#include <string>
#include <filesystem>
#include "Command.h"

using namespace std;
namespace fs = filesystem;
using namespace fs;

path currentPath = current_path();

void Command::showHelp(int num) {
	if (num == 0) { // show all commands
		cout << "SH  " << "      " << "SHOW HELP PAGE." << endl;
		cout << "CW  " << "      " << "CLEAR CONSOLE WINDOW." << endl;
		cout << "EXIT" << "      " << "EXIT PROGRAM." << endl;
		cout << "CC  " << "      " << "SHOW CURRENT DIRECTORY." << endl;
		cout << "OF  " << "      " << "FILES OUTPUT OF CURRENT DIRECTORY." << endl;
		cout << "CSD " << "      " << "CHANGE TO SUBDIRECTORY." << endl;
	}
	else if (num == 1) { // show basic commands
		cout << "SH  " << "      " << "SHOW HELP PAGE." << endl;
		cout << "CW  " << "      " << "CLEAR CONSOLE WINDOW." << endl;
		cout << "EXIT" << "      " << "EXIT PROGRAM." << endl;
		cout << " " << "      " << " " << endl;
	}
	else if (num == 2) {

		cout << "CC  " << "      " << "SHOW CURRENT DIRECTORY." << endl;
		cout << "OF  " << "      " << "FILES OUTPUT OF CURRENT DIRECTORY." << endl;
		cout << "CPD " << "      " << "CHANGE TO PARENT DIRECTORY." << endl;
		cout << "CSD " << "      " << "CHANGE TO SUBDIRECTORY." << endl;
	}
}
void Command::checkCurrentDir() {
	cout << "[ " << currentPath.string() << " ]" << endl;
}
void Command::outputFiles() {
	for (const auto& entry : directory_iterator(currentPath)) {
		cout << entry.path().filename().string() << endl;
	}
}
void Command::changeToParentDirectory(){	
	path parentDir = currentPath.parent_path();
	currentPath = parentDir;
	cout << currentPath.string() << endl;
}
void Command::changeToSubDirectory(const string& subDirName){
	path subDirPath = currentPath / subDirName;

	if (exists(subDirPath) && is_directory(subDirPath)) {
		currentPath = subDirPath;
	}
	else {
		cerr << "'" << subDirName << "' is unknown directory" << endl;
	}
	cout << currentPath.string() << endl;
}

