#ifndef COMMAND_H
#define COMMAND_H

#include <string>

using namespace std;
class Command {
public:
	void showHelp(int num);
	void checkCurrentDir();
	void outputFiles();
	void changeToParentDirectory();
	void changeToSubDirectory(const string& subDirName);
};
#endif 
