/* CMD */

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include <Windows.h>

using namespace std;
namespace fs = filesystem;
using namespace fs;

int main() {
	// ������ �Է��� �Է���
	string commandLine;
	string bsPath = "C:/Users/kundr";
	path dirPath = bsPath;

	// exit ��ɾ ������������ ��� ���ư�
	while (1) {
		cout << bsPath << ">";
		getline(cin, commandLine);

		// commandLine ���ڿ��� ������ �������� ���ڿ� �и�
		istringstream iss(commandLine);
		vector<string> tokens;
		string token;
		
		while (iss >> token) {
			tokens.push_back(token);
		}

		// �Է��� ��ɾ ���� �� Unknown command �޽��� ���
		if (tokens.empty()) {
			cout << "Unknown command" << endl;
		}	

		// �Է��� ��ɾ exit �� �� ���α׷� ����
		if(tokens[0] == "exit" || tokens[0] == "EXIT") {
			break;
			exit(0);
		}

		// �Է��� ��ɾ ll �Ǵ� ls �϶� bsPath ��� ���� �ִ� ����, ���ϵ��� ���� 
		if (tokens[0] == "ll" || tokens[0] == "ls") {
			for (const auto& entry : directory_iterator(dirPath)) {
				if (is_regular_file(entry) || !is_regular_file(entry)) {
					cout << entry.path() << endl;
				}
			}
		}

		// �Է��� ��ɾ help �Ǵ� Help �϶� ���� �������� ������
		if (tokens[0] == "help" || tokens[0] == "HELP") {
			if (tokens.size() == 1) {
				cout << "Usage : help/HELP [arg] " << endl;
			}
			else {
				if (tokens[1] == "1") {
					// ���� �߰�
					cout << "help[1/2]" << endl;
				}
				else if (tokens[1] == "2") {
					// ���� �߰�
					cout << "help[2/2]" << endl;
				}
				else {
					cout << "Unknown argument" << endl;
				}
			}
		}

		// �Է��� ��ɾ cd �϶� ���� ���丮�� ��θ� ����
		if (tokens[0] == "cd.." || tokens[0] == "cd../") {
			size_t sl = bsPath.find_last_of('/');

			bsPath = bsPath.substr(0, sl);
			if (bsPath == "C:") {
				bsPath = "C:/";
			}
		}
		else if (tokens[0] == "cd") {
			if (tokens.size() == 1) {
				cout << "Usage : help/HELP [arg] " << endl;
			}
			else {
				if (tokens[1] == "/") {
						bsPath = "C:/";
				}
				else if (tokens[1] == ".." || tokens[1] == "../") {
					size_t sl = bsPath.find_last_of('/');

					bsPath = bsPath.substr(0, sl);
					if (bsPath == "C:") {
						bsPath = "C:/";
					}
				}
				else {
													
				}
			}
		}
		

	}
	return 0;
}
