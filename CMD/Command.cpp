#include <iostream>
#include <string>
#include <iomanip>
#include <filesystem>
#include "Command.h"

using namespace std;
namespace fs = filesystem;
using namespace fs;

void Command::showHelp() {
	cout << "HELP PAGE[1/2]" << endl;
	cout << "help" << "    " << "Show help page" << endl;
	cout << "cc" << "      " << "Show current directory" << endl;
	cout << "clr" << "     " << "Clear console window\n\n";
}

void Command::checkCurrentDir() {
	path currentDir = current_path();
	cout << "[ " << currentDir.string() << " ]" << endl;
}