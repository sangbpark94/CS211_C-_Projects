#include <iostream>
using namespace std;

int main(){
	int b[8][8]={0},r,c=0,count=0;
    b[0][0]=1;

NC:	c++;
	if(c==8) 
		goto PR; 
	r=-1;

NR: r++;
	if(r==8) 
		goto BT;
	//row test
	for(int i=0; i<c; i++)
		if(b[r][i]==1)
			goto NR;
	//up-diag test
	for(int i=1; (r-i)>=0 && (c-i)>=0; i++)
		if(b[r-i][c-i]==1)
			goto NR;
	//down-diag test
	for(int i=1; (r+i)<8 && (c-i)>=0; i++)
		if(b[r+i][c-i]==1)
			goto NR;
	b[r][c]=1;
	goto NC;

BT: c--;
	if(c==-1)
		return 0;
	r=0;
	while(b[r][c]!=1)
		r++;
	b[r][c]=0;
	goto NR;
	
PR: for(int row=0; row<8; row++){
		for(int column=0; column<8; column++){
		    cout<<b[row][column]<<" ";
		    }
		cout<<endl;
		}
	count++;
	cout<<count<<endl;
	goto BT;
}
