#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[8], int c);

int main(){
	int q[8]={0,2,0,0,0,0,0,0};
	cout<<ok(q,2)<<endl;
	q[2]=1;
	cout<<ok(q,2)<<endl;
	q[2]=2;
	cout<<ok(q,2)<<endl;
	q[2]=3;
	cout<<ok(q,2)<<endl;
	return 0;
}

bool ok(int q[8], int c)
{
	int a[8][5]={
		{-1},
		{0, -1},
		{0, -1},
		{0, 1, 2, -1},
		{0, 1, 3, -1},
		{ 1, 4, -1},
		{ 2, 3, 4, -1},
		{3, 4, 5, 6, -1},
	};
	for(int i=0; i<c ;i++)
		if(q[i]==q[c]) return false;
	for(int i=0; a[c][i]!=-1; i++)
	     if(abs(q[c]-q[a[c][i]])==1) return false;
	return true;
}
