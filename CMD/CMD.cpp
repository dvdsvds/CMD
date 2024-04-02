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

	while(1) { 
		while (1) { 
			string typeCommand;
			cout << "~>";
			getline(cin, typeCommand);

			string setence = typeCommand;
			istringstream iss(typeCommand);

			vector<string> tokens;
			string token;

			while(iss >> token) {
				tokens.push_back(token);
			}

			// Basic commands
			if(!tokens.empty()) {
				if (tokens[0] == "sh" && tokens.size() == 2) { 
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
						cerr << "'" << typeCommand << "' is unknown command. Please try again." << endl;
					}
				}
				else if (tokens[0] == "cw") { 
					cout << "\033[2J\033[H";
				}
				else if (tokens[0] == "exit") {
					exit(0);
				}

				// Commands that is about a file and directory
				else if (tokens[0] == "cc") {  
					c.checkCurrentDir();
				}
				else if (tokens[0] == "of") { 
					c.outputFiles();
				}
				else if (tokens[0] == "cpd") {  
					c.changeToParentDirectory();
				}
				else if (tokens[0] == "csd") {
					if (tokens.size() >= 2) {
						c.changeToSubDirectory(tokens[1]);
					}
					else {
						cerr << "Please type argument" << endl;
					}
				}
			}
		}
	}
	return 0;
}
