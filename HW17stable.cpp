#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int mp[3][3]={0,2,1,
              0,2,1,
              1,2,0};
int wp[3][3]={2,1,0,
              0,1,2,
              2,0,1};

void move(int q[3], int c);
bool ok(int q[], int col);
void print(int q[]);

int main(){
	int q[3];
	move(q,0);
	return 0;
}

void move(int q[3], int c){
	if(c == 3){
		print(q);
		return;
	}
	
	for (int i = 0; i < 3; i++){
		q[c]=i;
		if (ok(q,c))
			move(q,c+1);	
	}
}

bool ok(int q[], int col){
    int i;
    for(i=0; i<col;i++)                    
    {
       if(q[col]==q[i])
       return false;     
    }        
    for(i=0; i<col; i++)                      
    {
       if( ( mp[col][q[i]]<mp[col][q[col]] )&& ( wp[q[i]][col]<wp[q[i]][i]) ) return false;     
       if( ( wp[q[col]][i]<wp[q[col]][col] )&& ( mp[i][q[col]]<mp[i][q[i]]) ) return false;      
    }        
        return true;        
}

   void print(int q[])
    {  
       int i,j;
       cout<<" M "<<"  "<<"  W "<<endl;
       for( i=0;i<3;i++)
       {
          cout<<" "<<i<<"     "<<q[i]<<endl;          
       }
       cout<<endl;
    }

  
