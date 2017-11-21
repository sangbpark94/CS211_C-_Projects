//This checkers game assumes that jumping is not required even if it is possible
//Add in 1-8 row and A-H col in PR
//Implement way to determine if player wins (i.e. have a designated count++ for each time ob or xb is removed and if count = 12, end game)
//Implement game reset

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(){

    int i, j, k, l, m, n, p, q, r, s, player = 2, orirow, oricol, desrow, descol;

    typedef char box[5][5];

    box bb, ob, xb, obK, xbK, *board[8][8];

    char option;

    string move, tempmove;

    bool multicap = false;

    //fill in bb = blank box
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            bb[i][j] = ' ';

    //fill in ob = O box
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            ob[i][j] = ' ';    
    ob[1][1] = char(219);
    ob[1][2] = char(219);
    ob[1][3] = char(219);
    ob[2][1] = char(219);
    ob[2][3] = char(219);
    ob[3][1] = char(219);
    ob[3][2] = char(219);
    ob[3][3] = char(219);
        
    //fill in xb = X box
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            xb[i][j] = ' ';
    xb[1][1] = char(219);
    xb[1][3] = char(219);
    xb[2][2] = char(219);
    xb[3][1] = char(219);
    xb[3][3] = char(219);

    //fill in obK = King O box
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            obK[i][j] = ' ';    
    obK[0][0] = char(219);
    obK[0][1] = char(219);
    obK[0][2] = char(219);
    obK[0][3] = char(219);
    obK[0][4] = char(219);
    obK[1][0] = char(219);
    obK[1][4] = char(219);
    obK[2][0] = char(219);
    obK[2][2] = char(219);
    obK[2][4] = char(219);
    obK[3][0] = char(219);
    obK[3][4] = char(219);
    obK[4][0] = char(219);
    obK[4][1] = char(219);
    obK[4][2] = char(219);
    obK[4][3] = char(219);
    obK[4][4] = char(219);
     
    //fill in xbK = King X box
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            xbK[i][j] = ' ';
    xbK[0][0] = char(219);
    xbK[0][4] = char(219);
    xbK[1][1] = char(219);
    xbK[1][3] = char(219);
    xbK[2][2] = char(219);
    xbK[3][1] = char(219);
    xbK[3][3] = char(219);
    xbK[4][0] = char(219);
    xbK[4][4] = char(219);

    //fill board with bb
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            board[i][j] = &bb;

    //add to board ob and xb
    for(i = 0; i < 4; i++)
    {   board[0][2*i]   = &ob;
        board[1][2*i+1] = &ob;
        board[2][2*i]   = &ob;
        board[5][2*i+1] = &xb;
        board[6][2*i]   = &xb;
        board[7][2*i+1] = &xb;}

PR: system("cls");
	//upper border
    cout << char(218);
    for(i = 0; i < 7; i++)
    {   for(j = 0; j < 5; j++)
            cout << char(196);
        cout << char(194);}
    for(k = 0; k < 5; k++)
        cout << char(196);
    cout << char(191) << endl;

    //print board
    for(i = 7; i >= 0; i--)
    {   for(k = 0; k < 5; k++)
            for(j = 0; j < 8; j++)
            {   cout << char(179);
                for(l = 0; l < 5; l++)
                    cout << (*board[i][j])[k][l];
                if(j == 7)
                    cout << char(179) << endl;}
        if(i != 0)
        {   cout << char(195);
            for(m = 0; m < 7; m++)
            {   for(n = 0; n < 5; n++)
                    cout << char(196);
                cout << char(197);}
            for(p = 0; p < 5; p++)
                cout << char(196);
            cout << char(180) << endl;}
            
        //print lower border
        else if(i == 0)
        {   cout << char(192);
            for(q = 0; q < 7; q++)
            {   for(r = 0; r < 5; r++)
                    cout << char(196);
                cout << char(193);}
            for(s = 0; s < 5; s++)
                cout << char(196);
            cout << char(217);}}
        
    cout << endl << endl;
	
    //normal input 
    if(!multicap)
    {   //player flip
        if(player == 1)
            player = 2;
        else if(player == 2)
            player = 1;
        
IN:     cout << "Player " << player << " please input a move: ";
        cin >> move;
        if(move.size() != 5)
IV:     {   cout << endl << endl;
            cout << "That was an invalid move." << endl << endl;
            goto IN;}
        if( (97 > ((int) move[0]) ) || ((int) move[0]) > 104)
            goto IV;
        if( (49 > ((int) move[1]) ) || ((int) move[1]) > 56)
            goto IV;
        if(move[2] != '-') //CHECK IF THIS WORKS!
            goto IV;
        if( (97 > ((int) move[3]) ) || ((int) move[3]) > 104)
            goto IV;
        if( (49 > ((int) move[4]) ) || ((int) move[4]) > 56)
            goto IV;}

	//multicap input
MC: if(multicap)
    {   cout << "Player " << player << " would you like to jump again? (y/n): ";
        cin >> option;
        if(option == 'y')
        {   move[0] = (char) (desrow + 97);
            move[1] = (char) (descol + 49);
            cout << endl << endl;
            cout << "Where would you like to move '" << move[0] << move[1] << "' to?: ";
            cin >> tempmove;
            if(tempmove.size() != 2)
                goto IVC;
            if( (97 > ((int) tempmove[0]) ) || ((int) tempmove[0]) > 104)
                goto IVC;
            if( (49 > ((int) tempmove[1]) ) || ((int) tempmove[1]) > 56)
                goto IVC;
            move[3] = tempmove[0];
            move[4] = tempmove[1];
                        
            goto MA;}

        else if(option == 'n')
        {   multicap = false;
            goto PR;}
        else
IVC:    {   cout << endl << endl;
            cout << "That was an invalid answer." << endl << endl;
            goto MC;}}

MA: //convert input move into rows and columns
    orirow = ( (int) move[1] ) - 49;	
    oricol = ( (int) move[0] ) - 97;
    desrow = ( (int) move[4] ) - 49;
    descol = ( (int) move[3] ) - 97;


	cout << "orirow = " << orirow << endl << "oricol = " << oricol << endl; 
	cout << "desrow = " << desrow << endl << "descol = " << descol << endl;

    //checks if right piece
    if( (player == 1) && (board[orirow][oricol] != &ob) )
		goto IV;
    else if( (player == 2) && (board[orirow][oricol] != &xb) )
		goto IV;
    
    //checks if destination is a blank box
    if(board[desrow][descol] != &bb)
		goto IV; 

    //checks if piece is king
    bool king = false;
    if( (player == 1) && (board[orirow][oricol] == &obK) )
        king = true;
    else if( (player == 2) && (board[orirow][oricol] == &xbK) )
        king = true;

    //checks if destination is valid and moves/captures piece
    if(player == 1)
    {   
		//if original piece isn't king
        if(!king)
        {
            //if moving the piece
            if(!multicap)
            {   
				if( (desrow == (orirow + 1)) && ( (descol == (oricol + 1)) || (descol == (oricol - 1)) ) )
                {   board[orirow][oricol] = &bb;
                    if(desrow == 7)
                        board[desrow][descol] = &obK;
                    else
                        board[desrow][descol] = &ob;
                    goto PR;}}

            // if left direction capture
            else if( (desrow == (orirow + 2)) && (descol == (oricol - 2)) && (board[orirow+1][oricol-1] == &xb) )
            {   board[orirow][oricol] = &bb;
                board[orirow+1][oricol-1] = &bb;
                if(desrow == 7)
                {   board[desrow][descol] = &obK;
                    goto PR;}
                else
                {   board[desrow][descol] = &ob;
/*
                    //check for multiple capture
                    if( (board[desrow+1][descol-1] == &xb) && (board[desrow+2][descol-2] == &bb) )
                    {   multicap = true;
                        goto PR;}
                    else if( (board[desrow+1][descol+1] == &xb) && (board[desrow+2][descol+2] == &bb) )
                    {   multicap = true;
                        goto PR;}
*/
                goto PR;}}

            //if right direction capture
            else if( (desrow == (orirow + 2)) && (descol == (oricol + 2)) && (board[orirow+1][oricol+1] == &xb) )
            {   board[orirow][oricol] = &bb;
                board[orirow+1][oricol+1] = &bb;
                if(desrow == 7)
                {   board[desrow][descol] = &obK;
                    goto PR;}
                else
                {   board[desrow][descol] = &ob;
/*
                //check for multiple capture
                    if( (board[desrow+1][descol-1] == &xb) && (board[desrow+2][descol-2] == &bb) )
                    {   multicap = true;
                        goto PR;}
                    else if( (board[desrow+1][descol+1] == &xb) && (board[desrow+2][descol+2] == &bb) )
                    {   multicap = true;
                        goto PR;}
*/
                goto PR;}}
            
            else goto IV;}
        
        //if original piece is king
        else if(king)
        {
            //if moving the king
            if(!multicap)
            {   if( ( (desrow == (orirow + 1)) || (desrow == (orirow - 1)) ) && ( (descol == (oricol + 1)) || (descol == (oricol - 1)) ) )
                {   board[orirow][oricol] = &bb;
                    board[desrow][descol] = &obK;
                    goto PR;}}

            //if left-up direction capture
            else if( (desrow == (orirow + 2)) && (descol == (oricol - 2)) && (board[orirow+1][oricol-1] == &xb) )
            {   board[orirow][oricol] = &bb;
                board[orirow+1][oricol-1] = &bb;
                board[desrow][descol] = &obK;
/*
                //check for multiple capture
                if( (board[desrow+1][descol-1] == &xb) && (board[desrow+2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow+1][descol+1] == &xb) && (board[desrow+2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol-1] == &xb) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &xb) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/
                goto PR;}

            //if right-up direction capture
            else if( (desrow == (orirow + 2)) && (descol == (oricol + 2)) && (board[orirow+1][oricol+1] == &xb) )
            {   board[orirow][oricol] = &bb;
                board[orirow+1][oricol+1] = &bb;
                board[desrow][descol] = &obK;
/*
                //check for multiple capture
                if( (board[desrow+1][descol-1] == &xb) && (board[desrow+2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow+1][descol+1] == &xb) && (board[desrow+2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol-1] == &xb) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &xb) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/
                goto PR;}

            // if left-down direction capture
            else if( (desrow == (orirow - 2)) && (descol == (oricol - 2)) && (board[orirow+1][oricol-1] == &xb) )
            {   board[orirow][oricol] = &bb;
                board[orirow-1][oricol-1] = &bb;
                board[desrow][descol] = &obK;
/*
                //check for multiple capture
                if( (board[desrow+1][descol-1] == &xb) && (board[desrow+2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow+1][descol+1] == &xb) && (board[desrow+2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol-1] == &xb) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &xb) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/
                goto PR;}

            //if right-down direction capture
            else if( (desrow == (orirow - 2)) && (descol == (oricol + 2)) && (board[orirow+1][oricol+1] == &xb) )
            {   board[orirow][oricol] = &bb;
                board[orirow-1][oricol+1] = &bb;
                board[desrow][descol] = &obK;
/*
                //check for multiple capture
                if( (board[desrow+1][descol-1] == &xb) && (board[desrow+2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow+1][descol+1] == &xb) && (board[desrow+2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol-1] == &xb) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &xb) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/
                goto PR;}
           
            else goto IV;}}

    else if(player == 2)
    {    
        //if original piece isn't king
        if(!king)
        {
            //if moving the piece
            if(!multicap)
            {   if( (desrow == (orirow - 1)) && ( (descol == (oricol + 1)) || (descol == (oricol - 1)) ) )
                {   board[orirow][oricol] = &bb;
                    if(desrow == 0)
                        board[desrow][descol] = &xbK;
                    else
                        board[desrow][descol] = &xb;
                    goto PR;}}

            // if left direction capture
            else if( (desrow == (orirow - 2)) && (descol == (oricol - 2)) && (board[orirow+1][oricol-1] == &ob) )
            {   board[orirow][oricol] = &bb;
                board[orirow-1][oricol-1] = &bb;
                if(desrow == 0)
                {   board[desrow][descol] = &xbK;
                    goto PR;}
                else
                {   board[desrow][descol] = &xb;
/*
                //check for multiple capture
                if( (board[desrow-1][descol-1] == &ob) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &ob) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/
                goto PR;}}

            //if right direction capture
            else if( (desrow == (orirow - 2)) && (descol == (oricol + 2)) && (board[orirow+1][oricol+1] == &ob) )
            {   board[orirow][oricol] = &bb;
                board[orirow-1][oricol+1] = &bb;
                if(desrow == 0)
                {   board[desrow][descol] = &xbK;
                    goto PR;}
                else
                {   board[desrow][descol] = &xb;
/*
                //check for multiple capture
                if( (board[desrow-1][descol-1] == &ob) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &ob) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/
                goto PR;}}
            
            else goto IV;}
        
        //if original piece is king
        else if(king)
        {
            //if moving the king
            if(!multicap)
            {   if( ( (desrow == (orirow + 1)) || (desrow == (orirow - 1)) ) && ( (descol == (oricol + 1)) || (descol == (oricol - 1)) ) )
                {   board[orirow][oricol] = &bb;
                    board[desrow][descol] = &xbK;
                    goto PR;}}

           // if left-up direction capture
            else if( (desrow == (orirow + 2)) && (descol == (oricol - 2)) && (board[orirow+1][oricol-1] == &ob) )
            {   board[orirow][oricol] = &bb;
                board[orirow+1][oricol-1] = &bb;
                board[desrow][descol] = &xbK;
/*
                //check for multiple capture
                if( (board[desrow+1][descol-1] == &ob) && (board[desrow+2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow+1][descol+1] == &ob) && (board[desrow+2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol-1] == &ob) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &ob) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/
                goto PR;}

            //if right-up direction capture
            else if( (desrow == (orirow + 2)) && (descol == (oricol + 2)) && (board[orirow+1][oricol+1] == &ob) )
            {   board[orirow][oricol] = &bb;
                board[orirow+1][oricol+1] = &bb;
                board[desrow][descol] = &xbK;
/*
                //check for multiple capture
                if( (board[desrow+1][descol-1] == &ob) && (board[desrow+2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow+1][descol+1] == &ob) && (board[desrow+2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol-1] == &ob) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &ob) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/
                goto PR;}

            // if left-down direction capture
            else if( (desrow == (orirow - 2)) && (descol == (oricol - 2)) && (board[orirow+1][oricol-1] == &ob) )
            {   board[orirow][oricol] = &bb;
                board[orirow-1][oricol-1] = &bb;
                board[desrow][descol] = &xbK;
/*
                //check for multiple capture
                if( (board[desrow+1][descol-1] == &ob) && (board[desrow+2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow+1][descol+1] == &ob) && (board[desrow+2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol-1] == &ob) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &ob) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/               
                goto PR;}

            //if right-down direction capture
            else if( (desrow == (orirow - 2)) && (descol == (oricol + 2)) && (board[orirow+1][oricol+1] == &ob) )
            {   board[orirow][oricol] = &bb;
                board[orirow-1][oricol+1] = &bb;
                board[desrow][descol] = &xbK;
/*                
                //check for multiple capture
                if( (board[desrow+1][descol-1] == &ob) && (board[desrow+2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow+1][descol+1] == &ob) && (board[desrow+2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol-1] == &ob) && (board[desrow-2][descol-2] == &bb) )
                {   multicap = true;
                    goto PR;}
                else if( (board[desrow-1][descol+1] == &ob) && (board[desrow-2][descol+2] == &bb) )
                {   multicap = true;
                    goto PR;}
*/               
                goto PR;}
           
            else goto IV;}}

	return 0;
}
               


