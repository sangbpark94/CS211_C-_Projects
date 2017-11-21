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
  
void backtrack(int &col){
        col--;
        if(col==-1) exit(1);
       }

   void print(int q[])
    {  
       int i,j;
       cout<<" M "<<"  "<<"  W "<<endl;
       for( i=0;i<3;i++)
       {
          cout<<" "<<i<<"     "<<q[i]<<endl;          
       }
       
    }

    int main()
    {
      int q[3]; 
      q[0]=0;
      int c=1;

      bool from_backtrack=false;
      
      while(1){
        while(c<3){
         if(!from_backtrack)
            q[c]=-1; 
            from_backtrack=false;
              while(q[c]<3){ 
                q[c]++;
                    while(q[c]==3)              
                     { backtrack(c);
                       q[c]++;                          
                     }
                  if(ok(q, c))
                     break;                   
              }
          c++; 
     }
     print(q); 
     system("pause");
     backtrack(c);
     from_backtrack=true;
    }
   
}
             
