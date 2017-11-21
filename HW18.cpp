#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

void sort(int arr[20], int K);

int main(){
	
	ifstream f("data.txt");
	string line;
	int skip = 1;
	while(!f.eof()){
		int arr[20];
  		int i = 0;
		int K; //data set number	
		getline(f,line);	
 		stringstream ssin(line);

		//skips first line
 		if(skip == 1){
 			skip = 0;
 			goto bot;
 		}
 		
		while(ssin.good() && i <= 20){
 			if (i == 0){
 				ssin >> K;
 			}
			else
				ssin >> arr[i-1];
			++i;
		}
		
		//calls sort function
		sort(arr,K);

bot:	;
	}
 
 	return 0;
}

void sort(int arr[20], int K){

	int swap = 0;
	int j,temp;
	for(int i = 0; i < 20; i++){
		j = i;
		
		while(j > 0 && (arr[j] < arr[j-1])){
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			swap++;
			j--;
		}
	}
	
	cout << K << " " << swap << endl;
}
	
