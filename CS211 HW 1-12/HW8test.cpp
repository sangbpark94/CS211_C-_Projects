
#include <iostream>
#include <cstdlib>
#include <cmath>
 using namespace std;
 bool ok( int q[8], int c )
 {
    int a[][5] =
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
		for ( int i = 0 ; i < c ; i++ )
			if ( q[i] == q[c] )
				return false;
	    for ( int i = 0 ; a[c][i] != -1 ; i++ )
		{
	     if ( abs( q[c] - q[ a[c][i] ] )==1 )
			 return false;
		 }
		 return true;
		 }
		 void backtrack(int &col){
			 --col;
			 if(col == -1){
				 exit(1);
				 }
			}
		 void print(int q[]){
			 static int count =0;
			 cout << "Solution #" << ++count << ": ";
			 cout << endl;
			 cout << "  " <<q[0]+1 <<"  "<<q[1]+1<< ' '<< endl;
			 cout << q[2]+1 <<" "<<q[3]+1 <<"  "<<q[4]+1<<" "<<q[5]+1<< ' '<< endl;
			 cout << "  " <<q[6]+1 <<"  "<<q[7]+1<< ' '<< endl;
			 }
			 int main(){
				 int q[8], c = 0;
				 bool from_backtrack=false;
				 while(true){
					 while(c<8){
					 if(!from_backtrack)
						 q[c] = -1;
					 from_backtrack = false;
					 while(q[c]<8){
						 q[c]++;
						 if(q[c] == 8){
							 backtrack(c);
							 continue;
							 }
							 if ( ok(q,c) ) break;
							 }
							 c++;
							 }
							 print(q);
							 backtrack(c);
							 from_backtrack = true;
							 }
							 }
