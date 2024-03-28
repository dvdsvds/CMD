/* CMD */

#include <iostream>
#include <string>
#include <filesystem>

#include "Command.h"

using namespace std;
namespace fs = filesystem;
using namespace fs;

int main() {
	Command c;
	cout << "[File Manage Program]\n\n";
	cout << "If you want to view help, type 'help' command and view it" << endl;
	// start console
	while(1) {

		// start type command
		while (1) {
			string typeCommand;
			cout << ">";
			getline(cin, typeCommand);

			// sh(show help) : show help
			if (typeCommand == "sh") {
				c.showHelp();
			}
			// cc(check current dirctory) : show current directory
			else if (typeCommand == "cc") {
				c.checkCurrentDir();
			}
			// clear : clear console window
			else if (typeCommand == "clr") {
				cout << "\033[2J\033[H";
			}
		}
	}

	
	return 0;
}
