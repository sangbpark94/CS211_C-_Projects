#include <iostream>
using namespace std;

bool equivalent(int a[], int b[], int n){
	bool match = false;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[((j+i)%n)] == b[j])
				match=true;
			else{
				match=false;
				break;}
		}
		if(match)
			return true;
	}
	return false;
}

int main(){
	int size=5;
	int a[5]={1,2,3,4,5};
	int b[5]={3,4,5,1,2};
	if(equivalent(a,b,size)==1)
		cout<<"true"<<endl;
	else
		cout <<"false"<<endl;
	return 0;
}
