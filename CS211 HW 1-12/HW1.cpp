#include <iostream>
using namespace std;

int main(){
	long i=0;
	while(1){
		long x=(i*i);
		int a=x%100;
		if(((a%10)%2==1)&&((a/10)%2==1)){
			cout<<i*i<<endl;
			/*
			cout<<a<<endl;
			cout<<a%2<<endl;
			cout<<(a/10)<<endl;
			cout<<i<<endl;
			*/
			return 0;}
		i++;}
}
