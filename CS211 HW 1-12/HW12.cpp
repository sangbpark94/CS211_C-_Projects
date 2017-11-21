#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
bool check(int q[],int col);
void print(int q[]);
int main(){
 int i,j,k,l;
 typedef char box[5][7];
 box bb,wb,bq,wq,*board[8][8];
 //fill in bb=black box and wb=whitebox and fill in bq=blackqueen and wq=whitequeen
 for(i=0;i<5;i++)
 for( j=0;j<7;j++)
 {wb[i][j]=' ';
 wq[i][j]=' ';
 bq[i][j]=char(219);
 bb[i][j]=char(219);
 }
 wq[1][1]=char(219);
 bq[1][1]=' ';
 wq[1][3]=char(219);
 bq[1][3]=' ';
 wq[1][5]=char(219);
 bq[1][5]=' ';
 for(i=2;i<=3;i++)
 for(j=1;j<=5;j++)
 {wq[i][j]=char(219);
 bq[i][j]=' ';
 }
 
 	int q[8],c=0;
	bool new_col=true;
	q[0]=0;
	while(c>=0){
		if(new_col){
			q[c]=0;
			new_col=false;
		}
		else q[c]++;
		if(q[c]>=8){
			c--;
			continue;
		}
		if(check(q,c)){
			if(c==7) print(q);
			
			else{
				c++;
				new_col=true;
			}
		}
	}
 
 
 
 
 
}

bool check(int q[],int col){
	for(int i=0; i<col; i++){

		if((q[i]==q[col])||((col-i)== abs(q[col]-q[i]))) return false;
	}
	return true;
}
void print(int q[]){
	 
int i,j,k,l;	 
 typedef char box[5][7];
 box bb,wb,bq,wq,*board[8][8];
 //fill in bb=black box and wb=whitebox and fill in bq=blackqueen and wq=whitequeen
 for(i=0;i<5;i++)
 for( j=0;j<7;j++)
 {wb[i][j]=' ';
 wq[i][j]=' ';
 bq[i][j]=char(219);
 bb[i][j]=char(219);
 }
 wq[1][1]=char(219);
 bq[1][1]=' ';
 wq[1][3]=char(219);
 bq[1][3]=' ';
 wq[1][5]=char(219);
 bq[1][5]=' ';
 for(i=2;i<=3;i++)
 for(j=1;j<=5;j++)
 {wq[i][j]=char(219);
 bq[i][j]=' ';
 }	
	
	static int count=0;
	cout<<"Solution # " << ++count<<endl;
	
 //fill board with pointers to bb and wb in alternate positions
 for(i=0;i<8;i++)
 for(j=0;j<8;j++)
 if((i+j)%2==0)
 board[i][j]=&wb;
 else
 board[i][j]=&bb;
 
 //fill board with pointer to bq and wq in q's positions
 for(int c=0;c<8;c++){
 if(board[c][q[c]]==&wb)
 board[c][q[c]]=&wq;
 else
 board[c][q[c]]=&bq;
}
 // print the board via the pointers in array board
 // first print upper border
 cout<<" ";
 for(i=0;i<7*8;i++)
 cout<<'_';
 cout<<endl;
 // now print the board
 for(i=0;i<8;i++)
 for(k=0;k<5;k++)
 {cout<<" "<<char(179); //print left border
 for(j=0;j<8;j++)
 for(l=0;l<7;l++)
 cout<<(*board[i][j])[k][l];
 cout<<char(179)<<endl; // at end of line print bar and then newline
 }
 //before exiting print lower border
 cout<<" ";
 for(i=0;i<7*8;i++)
 cout<<char(196);
 cout<<endl;
 //system("pause");
 
}

