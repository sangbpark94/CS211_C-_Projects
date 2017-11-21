#include<iostream>
#include<fstream>
using namespace std;
int main(){
 ofstream f("outputfile.txt");
 for(int i =0; i<10; i ++){
 for(int j = 0; j< 10; j++)
 f<<"hello"<<" ";
 f<<endl;
 }
 return 0;
}
