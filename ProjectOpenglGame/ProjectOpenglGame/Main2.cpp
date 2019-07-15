
#include <Windows.h>
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <assert.h>
#include <map>
#include <string>

//ASSERTS
     #define DEBUG

	#ifndef DEBUG
	#define ASSERT(x)
	#else
	#define ASSERT(x) \
               if (! (x)) \
                { \
                   std::cout << "ERROR!! Assert " << #x << " failed\n"; \
                   std::cout << " on line " << __LINE__  << "\n"; \
                   std::cout << " in file " << __FILE__ << "\n";  \
                }
#endif


/*
This place is a refresh of important functionality used in video game programming

*/
//namespace StdExample {
	/*
	int APIENTRY WinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR     lpCmdLine,
		int       nCmdShow) {


		MessageBox(NULL, (LPCWSTR)"\tHello World!", (LPCWSTR)"My first windows app", NULL);
		return 0;
	}*/
namespace Main1{
	//example of assert error 
	void TestFunctionError(int number) {
		
		int x = 5;
		std::cout << "First assert: \n";
		ASSERT(x == 5);
		std::cout << "\nSecond assert: \n";
		ASSERT(x != 5);
		std::cout << "\nDone.\n";
	}

	int main() {
		int nbreDeT = 0;

		//use vector instead array always double memory(watch out for memory)
		std::vector<int> PlayerID{1,2,32,1,1};

		std::vector<std::string> str{"Ceci","est","test"};

		//like a list of nodes

		//use a	list wherever you have a group of objects or elements that you plan on adding to or deleting from frequently ex:list of meshe or list of gameobject
		std::list<int> mesh;

		//can be used to assign unique ID for online and that used like a dictionary
		std::map<int, std::string> gameObjects;

		/*
		for (auto it = PlayerID.begin(); it != PlayerID.end(); ++it) {
			std::cout << "player id: " << *it << std::endl;
		}

		for (int i = 0; i < PlayerID.size(); i++) {
			std::cout << "player id 2: " << PlayerID[i] << std::endl;
		}
		*/
		for (int i = 0; i < str.size(); i++) {
			

			for (int j = 0; j < str[i].length(); j++) {
				std::cout << str[i][j] << std::endl;
				if (str[i][j] == 't') {
					nbreDeT++;
				}
			}

		//	std::cout << str[i] << std::endl;
		}

		std::cout << "Nombre de T: " << nbreDeT << std::endl;

		//three type of template class templates, function templates, and variable	templates
		return 0;
	}
}

