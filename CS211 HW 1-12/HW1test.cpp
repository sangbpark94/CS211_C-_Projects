#include <iostream>
using namespace std;

bool lastTwoOdd (long x){
	int y = x % 100;
	if((y % 10)%2 == 1 && (y / 10)%2 == 1){return true;}
	else {return false;}
}

int main(){
	long x = 0;
	long square = 0;
	while (!(lastTwoOdd(square))){
		x++;
		square = x*x;
	}
	cout << square << endl;
	return 0;
}
