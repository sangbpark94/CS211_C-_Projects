#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
	
	ifstream f("HW.txt");
	string line;
	int linenum=1;
	int arr[20];
	
	while(!f.eof()){
		
		getline(f,line);
		stringstream ssin(line);
		int i=0,sum=0,max=0,min=0;
		float median=0;
		
		while(ssin.good() && i<20){
			ssin>>arr[i];
			i++;
		} 
		
		//Calling sort function to sort the array
		
		sort(arr,arr+20);
		
		//Finding sum, max, min, and median
		
		for(i=0; i<20; i++)
			sum+=arr[i];
		
		min=arr[0];
		max=arr[19];
		median=(float)(arr[9]+arr[10])/2;
		
		//Printing
		
		if(linenum>9) cout<<"Line ";
		else cout<<"Line  ";
		cout<<linenum<<":  ";
		cout<<"Sum= "<<sum;
		if(sum>999) cout<<"  ";
		else cout<<"   ";
		cout<<"Max= "<<max<<"  ";
		cout<<"Min= "<<min;
		if(min>9) cout<<"  ";
		else cout<<"   ";
		cout<<"Median= "<<median<<endl;
		
		linenum++;
			
		/*
		
		//Displays array line
		
		cout<<endl;
		for(int k=0; k<20; k++)
			cout<<arr[k]<<" ";
		cout<<endl<<endl;
		
		*/
			
	}
		
	return 0;
	
}
