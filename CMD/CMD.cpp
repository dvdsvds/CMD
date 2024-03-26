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
	// 파일을 입력할 입력줄
	string commandLine;
	string bsPath = "C:/Users/kundr";
	path dirPath = bsPath;

	// exit 명령어가 나오기전까지 계속 돌아감
	while (1) {
		cout << bsPath << ">";
		getline(cin, commandLine);

		// commandLine 문자열을 공백을 기준으로 문자열 분리
		istringstream iss(commandLine);
		vector<string> tokens;
		string token;
		
		while (iss >> token) {
			tokens.push_back(token);
		}

		// 입력한 명령어가 없을 때 Unknown command 메시지 출력
		if (tokens.empty()) {
			cout << "Unknown command" << endl;
		}	

		// 입력한 명령어가 exit 일 때 프로그램 종료
		if(tokens[0] == "exit" || tokens[0] == "EXIT") {
			break;
			exit(0);
		}

		// 입력한 명령어가 ll 또는 ls 일때 bsPath 경로 내에 있는 폴더, 파일들을 나열 
		if (tokens[0] == "ll" || tokens[0] == "ls") {
			for (const auto& entry : directory_iterator(dirPath)) {
				if (is_regular_file(entry) || !is_regular_file(entry)) {
					cout << entry.path() << endl;
				}
			}
		}

		// 입력한 명령어가 help 또는 Help 일때 도움말 페이지를 보여줌
		if (tokens[0] == "help" || tokens[0] == "HELP") {
			if (tokens.size() == 1) {
				cout << "Usage : help/HELP [arg] " << endl;
			}
			else {
				if (tokens[1] == "1") {
					// 내용 추가
					cout << "help[1/2]" << endl;
				}
				else if (tokens[1] == "2") {
					// 내용 추가
					cout << "help[2/2]" << endl;
				}
				else {
					cout << "Unknown argument" << endl;
				}
			}
		}

		// 입력한 명령어가 cd 일때 현재 디렉토리의 경로를 변경
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
