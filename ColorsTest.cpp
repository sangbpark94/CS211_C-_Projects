#include <iostream>
#include <windows.h>
using namespace std;

int main(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	cout << " " << char(219) << endl;
	SetConsoleTextAttribute(h, 5 | FOREGROUND_INTENSITY);
	cout << "Hello World" << endl;
	return 0;
}
