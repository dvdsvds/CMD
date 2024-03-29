/* CMD */

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

#include "Command.h"

using namespace std;
namespace fs = filesystem;
using namespace fs;

int main() {
	Command c;
	cout << "[File Manage Program]\n\n";
	cout << "If you want to view help, type 'sh' command and view it" << endl;
	// start console
	while(1) {

		// start type command
		while (1) {
			string typeCommand;
			cout << ">";
			getline(cin, typeCommand);

			string setence = typeCommand;
			istringstream iss(typeCommand);

			vector<string> tokens;
			string token;

			while(iss >> token) {
				tokens.push_back(token);
			}

			// Basic command
			
			if(!tokens.empty()) {
				if (tokens[0] == "sh" && tokens.size() == 2) { // sh(show help) : show help
					if (tokens[1] == "0") {
						c.showHelp(0);
					}
					else if (tokens[1] == "1") {
						c.showHelp(1);
					}
					else if (tokens[1] == "2") {
						c.showHelp(2);
					}
					else {
						cout << "'" << typeCommand << "' is unknown command. Please try again." << endl;
					}
				}
				else if (tokens[0] == "clr") { // clear : clear console window
					cout << "\033[2J\033[H";
				}
				else if (tokens[0] == "exit") {
					exit(0);
				}

				// The command that is about a file and directory
				else if (tokens[0] == "cc") { // cc(check current dirctory) : show current directory 
					c.checkCurrentDir();
				}
				else if (tokens[0] == "of") { // of(output files) : files output of current directory
					c.outputFiles();
				}
				else if (tokens[0] == "cd") { // cd(change directory) : change directory
					
				}
			}
		}
	}

	
	return 0;
}
