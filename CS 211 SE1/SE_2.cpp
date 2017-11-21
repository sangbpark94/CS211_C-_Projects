#include <iostream>
using namespace std;

bool leapyear(int y);

int main(){
	cout<<leapyear(16)<<endl;
	cout<<leapyear(800)<<endl;
	cout<<leapyear(200)<<endl;
	return 0;	
}

bool leapyear(int y){
	if((y%100!=0 && y%4==0) || (y%400==0)) return true;
	return false;
}
