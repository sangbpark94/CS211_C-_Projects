#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int solution=0;
	int b[8]={0};
	int r,c=0;
	
NC:	c++;
	if(c==8) goto PR;
	b[c]=-1;

NR: b[c]++;
	if(b[c]==8) goto BT;
	for(int i=0; i<c; i++)
		if(b[c]==b[i]||(c-i)==abs(b[c]-b[i])) goto NR;
	goto NC;

BT: c--;
	if(c==-1) return 0;
	goto NR;

PR: for(int i=0; i<8; i++)
		cout<<b[i]<<" ";
	solution++;
	cout<<solution<<endl;
	cout<<endl<<"-----------------------"<<endl;
	goto BT;
}
