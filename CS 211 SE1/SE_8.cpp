#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

///*

//recursive power, compute x^n

int exp(int x, int n)
{	if(n==0)
		return 1;
	return x*exp(x, n-1);
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<endl<<exp(a,b)<<endl;
	return 0;
}

//*/

/*

//recursive print of a string

void print(char* s){
	if(*s==0)
		return;
	cout<<*s;
	print(s+1);
}

int main(){
	char a[6]="hello";
	print(a);
	return 0;
}

*/

/*

//recursive reverse print of a string

void rev_print(char* s){
	if(*s==0)
		return;
	rev_print(s+1);
	cout<<*s;
}

int main(){
	char a[100];
	cin>>a;
	rev_print(a);
	return 0;
}

*/

/*

//recursive reverse print of an integer

void rev_print(int n){
	if(n/10==0){
		cout<<n%10;
		return;
	}
	cout<<n%10;
	rev_print(n/10);
}

int main(){
	int a;
	cin>>a;
	rev_print(a);
	return 0;
}

*/

/*

//recursive print of an integer

void print(int n){
	if(n/10==0){
		cout<<n%10;
		return;
	}
	print(n/10);
	cout<<n%10;
}

int main(){
	int a;
	cin>>a;
	print(a);
	return 0;
}

*/
