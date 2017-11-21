#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
int main(){
 ifstream f("outputfile.txt");
 string line;
 while(!f.eof()){
 getline(f,line);
 string arr[10];
 int i = 0;
 stringstream ssin(line);
 while (ssin.good() && i < 10){
 ssin >> arr[i];
++i;
 }
 for(i = 0; i < 10; i++)
 cout << arr[i] << " || ";
 cout << endl;
 }
 return 0;
}
