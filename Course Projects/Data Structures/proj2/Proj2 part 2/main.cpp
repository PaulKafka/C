//TIC TAC TOE GAME
//Toyanne Bennett & Paul Kafka
//Oct 1, 2012
#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <list>


using namespace std;
int main(int argc,char *argv[])
{

	if( argc != 4) 
		{
		cout << argv[0] << "\nInvalid Input" << endl;
		exit(1);
		}
	
	
	//read in from cmd line
	int size_of_array = atoi(argv[1]);
	int marks = atoi(argv[2]);
	char *player = argv[3];
	
	//creates dynamic board
	int** Board = new int*[size_of_array];
	for(int i = 0; i <size_of_array; ++i)
	Board[i] = new int[size_of_array];
	
	int pos_x, pos_y;
		
	/*
	//positions to be marked
	
	
	//Game play function
	int minimax(char player, int** Board);
	void DisplayBoard(int** Board, int size_of_array);
	int ComputerMove(int & bestmove);
	
	
	//first player is X, 2nd player is O
	

	
	//make sure board not fully
	//if full and no winner, then tie.
	
	//huma
	if(player == "h")
	{
	// do human first
	//display board each time it's computer's move
	DisplayBoard(Board);
	
	cout << "Input board positions for x and y sepereated by spaces. ";
	cin << pos_x, pos_y;
	}
	else
	{
		//do computer mode
		//choose best move... 
	}
}


void DisplayBoard(int ** Board, int size_of_array)
{
	//for every box, out top on and bottom until the sqrt of board size
	cout << "-----" << endl;
	9"pfcv 
}

int ComputerMove(int & bestmove)
{}

int HumanMove(int & v)
{}


	while (game isnt over) {		
	//4. Do maximin for best move (creating new gametree)
	minimax(player,board) 
    if(game over in current board position)	//game win = all  the slots are filled
        return winner
    children = all legal moves for player from this board
    if(max's turn) // players turn
        return maximal score of calling minimax on all the children
    else (min's turn) // computers turn
        return minimal score of calling minimax on all the children
	//5. Change player move.
	}
	*/
	
	return 0;
}