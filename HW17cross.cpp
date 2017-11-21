#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void move(int q[8], int c);
bool ok(int q[8], int c);
void print(int q[]);

int main(){
	int q[8];
	move(q,0);
	return 0;
}

void move(int q[8], int c){
	if(c == 8){
		print(q);
		return;
	}
	
	for (int i = 0; i < 8; i++){
		q[c]=i;
		if (ok(q,c))
			move(q,c+1);	
	}
}

bool ok(int q[8], int c)
{
int a[8][5]=
{
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
if(q[i]==q[c])
return false;
for(int i=0; a[c][i]!=-1; i++)
{
if ( abs( q[c] - q[ a[c][i] ] )==1 )
return false;
}
return true;
}

void print(int q[]){
static int count =0;
cout<< ++ count<<endl<<endl;
for(int i=0; i<8; i++)
cout<<q[i]<<" ";
cout<<endl<<endl;
} 
