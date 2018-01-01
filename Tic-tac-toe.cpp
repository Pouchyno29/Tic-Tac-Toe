/**
    Programmer  :   Stanley
    Class       :   ET-575 Introduction to C++ Programming Design and Implementation
    Semester    :   Spring 2017
    Professor   :   Trowbridge
    Exam        :   Spring 2017 Final Exam
**/

#include <iostream>
#include <cstdlib>

using namespace std;

//The dimension of the board.
const int GRIDSIZE = 3;

void populate(char board[GRIDSIZE][GRIDSIZE]);
void output(char board[GRIDSIZE][GRIDSIZE]);
bool isValidCoordinate(char board[GRIDSIZE][GRIDSIZE], int &posY, int &posX);
bool isValidLocation(char board[GRIDSIZE][GRIDSIZE], int &posY, int &posX);
void requestCoordinates(char board[GRIDSIZE][GRIDSIZE], int &posY, int &posX);
void updateBoard(char board[GRIDSIZE][GRIDSIZE], char playerMark, int posY, int posX);
bool checkRows(char board[GRIDSIZE][GRIDSIZE]);
bool checkColumns(char board[GRIDSIZE][GRIDSIZE]);
bool checkDiagonal(char board[GRIDSIZE][GRIDSIZE]);
void menu(char board[GRIDSIZE][GRIDSIZE]);
void checkGame(char board[GRIDSIZE][GRIDSIZE], char playerMark);

int main()
{
    cout << "+-------------------+" << endl;
    cout << "|     TIC-TAC-TOE   |" << endl;
    cout << "+-------------------+" << endl;

    char board[GRIDSIZE][GRIDSIZE];

    menu(board);

    return 0;
}

//This function populate each element in the array with a ( _ ) .
void populate(char board[GRIDSIZE][GRIDSIZE]){

    for(int y = 0; y < GRIDSIZE; y++){
        for(int x = 0; x < GRIDSIZE; x++){
            board[y][x] = '_';
        }
    }

}

//This function Print out the board on the console.
void output(char board[GRIDSIZE][GRIDSIZE]){

    for(int y = 0; y < GRIDSIZE; y++){
            cout << "\t";
            for(int x = 0; x < GRIDSIZE; x++){
                cout << board[y][x] << " ";
            }
            cout << endl;
        }

}

//This function check if a valid coordinate is entered for X or O.
bool isValidCoordinate(char board[GRIDSIZE][GRIDSIZE], int &posY, int &posX){

    if( (posX >= 0) && (posX < GRIDSIZE) && (posY >= 0) && (posY < GRIDSIZE) ){
        return true;
    }
    return false;
}

//This function check if a the coordinate is empty ( _ ) or has an X or an O.
bool isValidLocation(char board[GRIDSIZE][GRIDSIZE], int &posY, int &posX){

    if( board[posY][posX] == '_'){
        return true;
    }
    return false;
}

//This function request two numbers to form the coordinate for X or O.
void requestCoordinates(char board[GRIDSIZE][GRIDSIZE], int &posY, int &posX){

    do{
        //Ask the current user player for y and X coordinate.
        cout << "Enter a value for Y-coordinate: ";
        cin >> posY;
        cout << "Enter a value for X-coordinate: ";
        cin >> posX;

        //Check if the Y and X values are valid.
        bool coordinate = isValidCoordinate(board, posY, posX);

        //If the coordinate is valid
        if(coordinate == true){
            //Then check if the location on the array is empty.
            bool location = isValidLocation(board, posY, posX);
                //If the location is empty
                if(location == true){
                    //Get out of the loop
                   break;
                }
                else{
                    //If the location is not empty, let the player knows
                    cout << endl;
                    cout << "Location is not empty, chose a different location!" << endl;
                    //Then pause the game and wait for any key press to continue.
                    system("Pause");
                    cout << endl;
                }
        }else{
            //If the coordinate is not valid, let the current player knows
            cout << endl;
            cout << "The values are out of range!" << endl;
            //Then pause the game and for any key press to continue.
            system("Pause");
            cout << endl;
        }

    }while(true);

}

//This function updated the board with an X or O after a valid coordinate is entered.
void updateBoard(char board[GRIDSIZE][GRIDSIZE], char playerMark, int posY, int posX){

        //Insert the player's mark in the array at location (Y,X)
        board[posY][posX] = playerMark;

}

//This function check if there is any row of X or O in the board.
bool checkRows(char board[GRIDSIZE][GRIDSIZE]){
    //Create a variable to count how many X found in each row.
    int x_count = 0;

    for(int y = 0; y < GRIDSIZE; y++){
        x_count = 0; //reset the X counter for the next row.
        for(int x = 0; x < GRIDSIZE; x++){
            //add one to the X counter each time an X is found.
           if(board[y][x] == 'X'){
             x_count += 1;
           }

        }
        //If 3 X's are found in one row
        if(x_count == 3){
            return true;//then, stop searching for more X.
        }

    }

    //Create a variable to count how many O found in each row.
    int o_count = 0;

    for(int y = 0; y < GRIDSIZE; y++){
        o_count = 0; //reset the O counter for the next row.
        for(int x = 0; x < GRIDSIZE; x++){
            //add one to the O counter each time an O is found.
           if(board[y][x] == 'O'){
             o_count += 1;
           }

        }
        //If 3 O's are found in one row
        if(o_count == 3){
            return true;//then, stop searching for more O.
        }

    }
 //Return false if there are no row with 3 X's or O's.
 return false;
}

//This function check if there is any column of X or O in the board.
bool checkColumns(char board[GRIDSIZE][GRIDSIZE]){
    //Create a variable to count how many X found in each column.
    int x_count = 0;

    for(int x = 0; x < GRIDSIZE; x++){
        x_count = 0;//reset the X counter for the next column.
        for(int y = 0; y < GRIDSIZE; y++){
            //add one to the X counter each time an X is found.
           if(board[y][x] == 'X'){
             x_count += 1;
           }

        }
        //If 3 X's are found in one column
        if(x_count == 3){
            return true; //then, stop searching for more X.
        }

    }

    //Create a variable to count how many o found in each column.
    int o_count = 0;

    for(int x = 0; x < GRIDSIZE; x++){
            o_count = 0;//reset the o counter for the next column.
        for(int y = 0; y < GRIDSIZE; y++){
            //add one to the O counter each time an O is found.
            if(board[y][x] == 'O'){
             o_count += 1;
           }

        }
        //If 3 O's are found in one column
        if(o_count == 3){
            return true;//then, stop searching for more O.
        }
    }
 //Return false if there are no column with 3 X's or O's.
 return false;
}

//This function check if there is any diagonal of X or O in the board.
bool checkDiagonal(char board[GRIDSIZE][GRIDSIZE]){

        //Check the first diagonal for 3 X's.
    if( (board[0][2] == 'X') && (board[1][1] == 'X') && (board[2][0] == 'X') ){
        return true;
        //Check the first diagonal for 3 O's.
    }else if( (board[0][2] == 'O') && (board[1][1] == 'O') && (board[2][0] == 'O') ){
        return true;
        //Check the second diagonal for 3 X's.
    }else if( (board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X') ){
        return true;
        //Check the second diagonal for 3 O's.
    }else     if( (board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O') ){
        return true;
    }

//return false if 3 X's or 3 O's are not found from either diagonal.
return false;
}

//This function check if anyone of the player(X or O)won the game then, reset the board for the next game.
void checkGame(char board[GRIDSIZE][GRIDSIZE], char playerMark){

    //Create a row variable to hold the value of the checkRows function.
    bool rows = checkRows(board);
    //Create a column variable to hold the value of the checkColumns function.
    bool columns = checkColumns(board);
    //Create a diagonal variable to hold the value of the checkDiagonal function.
    bool diagonals = checkDiagonal(board);

    //If one of the 3 values above are true then, the current player won the game.
    if( (rows == true) || (columns == true)  || (diagonals == true)){

        //Showed which player won.
        cout << "Player " << playerMark << " has won!!!" << endl;

        //Pause the game and wait for the current player to press any key to continue.
        system("Pause");

        //Clear the screen for the next game.
        system("CLS");

        //Print out the title of the game to the screen.
        cout << "+-------------------+" << endl;
        cout << "|     TIC-TAC-TOE   |" << endl;
        cout << "+-------------------+" << endl;

        //Reset the board for the next game.
        populate(board);

        //Print out the board to the screen for the next game to start.
        output(board);
    }

}

//This function combine all the other function together to make the game works.
void menu(char board[GRIDSIZE][GRIDSIZE]){

    int posY = 0;
    int posX = 0;
    bool coordinate = false;
    bool location = false;
    char playerMark;
    int option = 0;

    //Populate the board with ( _ )when the game starts.
    populate(board);

    //Print out the board on the screen.
    output(board);

    int previousPlayer;
    int currentPlayer;

    //loop as long as any of the players does not enter 3.
	while(option != 3){

            cout << endl;

            //Show a menu of option
			cout << "1. Play X" << endl;
			cout << "2. Play O" << endl;
			cout << "3. End game" << endl;
			cout << "Enter a number (from 1 to 3): ";
			cin >> option; //Take input from user (1 - 2 or 3).

                //Examine the option chosen
                switch(option){

                    case 1://If the current user chose 1.
                        playerMark = 'X';//Then it is player X.
                        requestCoordinates(board, posY, posX); //Request a location from the board to insert the X.
                        cout << endl;//Skip a line to make the screen clean.
                        updateBoard(board, playerMark, posY, posX);//Updated the board with the X using the coordinate.
                        output(board);//Print out the new updated board to the screen.
                        checkGame(board, playerMark);//Check if player X won the game.
                        break;
                     case 2://If the current user chose 1.
                        playerMark = 'O';//Then it is player O.
                        requestCoordinates(board, posY, posX); //Request a location from the board to insert the X.
                        cout << endl;//Skip a line to make the screen clean.
                        updateBoard(board, playerMark, posY, posX);//Updated the board with the X using the coordinate.
                        output(board);//Print out the new updated board to the screen.
                        checkGame(board, playerMark);//Check if player X won the game.
                        break;
                     case 3://If any of the players enter 3
                         //Then let the player knows the game will end.
                        cout << "End the game" << endl;
                        break;
                     default: //If any of the player enter any number other than 1-2 or 3
                         //Let the player knows it is a wrong value.
                        cout << "Wrong value. Enter a number (from 1 to 3): " << endl;
                        system("Pause");//Pause the game and wait for the current player to press any key to continue.
                        cout << endl << endl; //skip 2 lines.
                }

	   }
}

