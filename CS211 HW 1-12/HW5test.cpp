//8QueensgoTo.cpp

#include <iostream>
using namespace std;
int main () {

    int b[8][8] = {0}, r, c = 0, count = 0; //b is board
     b[0][0] = 1; //places queen on the first block

	NC: c++;  //columns ++ 
	   if (c==8) goto PRINT;

	    r = -1;
	    NR: r++;
	    if (r==8) goto backtrack;


		//Row Test
		     for (int i = 0; i<c; i++) {
			if (b[r][i] ==1)
			   goto NR; //r++
			   }

		//diagnol up and left
		     for (int i = 1; (r-i) > -1 && (c-i) > -1; i++) {
			if (b[r-i][c-i] ==1){
			    goto NR;
			    }
			}

		//diagnol down and left
		     for (int i = 1; (r+i) < 8 && (c-i) > -1; i++) {
			if (b[r+i][c-i] == 1){
			    goto NR;
			    }
			}

			b[r][c] =1;
			goto NC;

	backtrack: c--;
	   if (c==-1) {
		return 0;
		}
	    r = 0;
		while (b[r][c] !=1) {
		    r++;
		    }
		b[r][c] = 0;
		    goto NR;
	

	PRINT: 
	    for (int row = 0; row <8; row++) {
		for (int column = 0; column <8; column++) {
		    cout << b[row][column]<< " ";
		    }
		    cout<<endl;
		}
		count++;
		cout <<count<<endl;
		
		goto backtrack;
return 0;
	}
