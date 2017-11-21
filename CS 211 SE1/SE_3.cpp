#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int col);

int main(){
	int q[8]={0,2,0,0,0,0,0,0};
	cout<<ok(q,2)<<endl;
	q[2]=1;
	cout<<ok(q,2)<<endl;
	q[2]=2;
	cout<<ok(q,2)<<endl;
	q[2]=3;
	cout<<ok(q,2)<<endl;
	q[2]=4;
	cout<<ok(q,2)<<endl;
	return 0;
}

bool ok(int q[], int col){
	for(int i=0; i<col; i++)
	if(q[col]==q[i] || (col-i)==abs(q[col]-q[i]))
		return false;
	return true;
}


