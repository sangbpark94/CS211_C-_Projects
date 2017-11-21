#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	
	ifstream f("data.txt");
	string line;
	
	while(!f.eof()){
		int i = 0;
 		getline(f,line);
 		stringstream ssin(line);
		cout<<"Re-enter while"<<endl;
		while (ssin.good()){
 			ssin >> i;
 			cout << i;
 			system("PAUSE");
		}
	}
	return 0;
}
