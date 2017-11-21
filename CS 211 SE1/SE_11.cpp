#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int number_of_primes(int from, int to){
	int count=0;
	int flag=0;
	for(int n=from; n<=to; n++){
		for(int j=2; j<=(int)ceil(n/2); j++){
			if(n%j==0){
				flag=1;
				break;
			}
		}
		if(flag==0) count++;
		flag=0;
	}
	return count;
}

int main(){
	cout<<number_of_primes(2,10)<<endl;
	cout<<number_of_primes(2,20)<<endl;
	cout<<number_of_primes(0,5)<<endl;
	return 0;
}
