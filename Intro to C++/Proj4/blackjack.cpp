/* ========================================================================== */
/*	PROGRAM Blackjack: Simplified version of the game

    AUTHOR: <Paul Kafka>
    FSU MAIL NAME: <PLK09d>
    RECITATION SECTION NUMBER: <1>
    RECITATION INSTRUCTOR NAME: <Joshua Lawrence>
    COP 3014 - Spring 2010
    PROJECT NUMBER: 4 
    DUE DATE: Wednesday 3/24/2010
    PLATFORM: Windows OS / Microsoft Visual C++ Express 2008 compiler 

SUMMARY

This program simulates a blackjack game for a total of 20 hands. It keep
track of how many hands the dealer wins, the player wins, and how many 
hands are ties, and print out this information at the end of each hand. 
It also keep track of the total number of chips that the player has won
or lost.

INPUT

No input.

	BAD DATA CHECKING: None

OUTPUT

A title message is printed. Card-by-card description of the game. 
Reports the events of the game as it is played.

ASSUMPTIONS

The randmax function as given will cause everyone to generate the
same random number sequence, every time the program is run.
/* ========================================================================== */


#include <iostream>					// standard I/O library
#include <fstream>					// file I/O library
#include <iomanip>					// output formatting routines
#include <string>					// C++ string class library

using namespace std;

// Global Constants
const int MAX_HANDS = 20;			// max of 20 hands

const int MAX_CARD_SUIT = 4;		// max of 4 card suits
const int MAX_CARD_VALUE = 13;		// max of 13 card values

const int FACE_VALUE = 10;			// face cards worth 10
const int ACE_VALUE = 11;			// ace is worth 11

const int CARD_JACK = 11;			// jack is number 11
const int CARD_QUEEN = 12;          // queen number 12
const int CARD_KING = 13;			// king is number 12
const int CARD_ACE = 1;				// ace is number 1

const char win = 'W';				// Win
const char lose = 'L';				// Lose
const char tie =  'T';				// Tie

// Prototypes
//int randmax(int max);					// generates random
void PrintIntro();						// prints introduction
int CalcBet(char);						// Calculates the bet amount
void InitialDeal(int&, int&, int&);     // initial cards given
int DealCard();							// generates cards dealt						 
void PlayerStrat(int&, int&);			// player strategies
void DealerStrat(int&);					// dealer strategies
void OverallScore(int&, int&, int&,     // prints score summary
				  int&, int&, int&, 
				  char&, int&);        
/* ================================================================ */
int main()  
{	// main function

	// local variables
	char winStatus = 'L';		// win status set to lose
	int bet;					// bet
	int playerHand,				// player's total hand
		dealerHand,				// dealer's total hand
		dealer2ndCard,			// dealer's 2nd card
		wins = 0,				// stores player wins
		loses = 0,				// stores dealer wins
		ties = 0,				// stores games tied
		numChips = 0;			// stores number of chips
/* ================================================================ */

	PrintIntro ();									// print introduction
	cout << endl << endl;

	for (int hand = 0; hand < MAX_HANDS; ++hand)    // counts 20 hands
	{   // start of loop

		bet = CalcBet(winStatus);					// bet set to winstatus
		
		// prints hand, player, and dealer title
		cout << setw (25) << "Hand " << hand+1 << endl 
			<< setw (27) << "-------" << endl;
		cout << "The amount wagered is: " << bet << endl << endl;
		cout << "The initial deal:" << endl << setw (23) 
			 << "Player" << setw (13) << "Dealer" << endl << setw (23) 
			 << "------" << setw (13) << "------" << endl;

		// Dealing of cards
		InitialDeal (playerHand, dealerHand, dealer2ndCard);
		
		// Player strategies
		PlayerStrat(dealer2ndCard, playerHand);
		cout << endl << endl;
		if (playerHand <= 21)					// if playerhand under 21
		{
			// Seperates player and dealer strategies
			cout << "--------------------------------------------\n" << endl;      
		
			//Dealer Strategies
			dealerHand += dealer2ndCard;	// adds dealer's 2nd card to total
			cout << "The dealer has a total of " << dealerHand;
			DealerStrat(dealerHand);
			
			//winstatus
			if (dealerHand < playerHand)	// dealerhand less than playerhand
			{
			if (playerHand > 21)
				winStatus = 'L';
			else
				winStatus = 'W';
			}
			else if (playerHand < dealerHand)	// playerhand less than dealerhand
			{
			if (dealerHand > 21)
				winStatus = 'W';
			else
				winStatus = 'L';
			}
			else
			winStatus = 'T';
		}								// if playerhand busts
		else
			winStatus = 'L';
	
		
		// sperates the strategies and overall score
		cout << endl << endl;
		cout << "--------------------------------------------\n";   

		// calculates and prints overall score
		OverallScore(dealerHand, playerHand, wins, loses, ties, numChips, winStatus, bet);

		// sperates hands
		cout << endl;
		cout << "========================================================\n";
		cout << endl;
	}	// end of loop
  
	               
	cout << endl << endl;
	cout << endl << endl;
	return 0;

} // main function


/* ====================Function Definitions=============================== */


void PrintIntro() // returns title
{  // print intro

	// This function takes no input from the caller. It prints
	// an introduction title.
	// Called By: main

	cout << setw (20) << "*********************************\n"
		 << setw (25) << "B L A C K J A C K\n"
		 << setw (25) << "S I M U L A T O R\n"
		 << setw (20) << "*********************************\n";
	return;
} // print intro

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

void OverallScore(int& dealerHand, int& playerHand, int& wins, int& loses, 
				  int& ties, int& numChips, char& winStatus, int& bet)
{
	// This function takes no input from the caller. It 
	// calculates and counts the wins, loses, ties, and
	// number of chips. Then it prints the results.
	// Called By: main

	// print the score of hand
	if (winStatus == 'L')
	{
		cout << "The player has lost this hand." << endl;
		loses += 1;					// add a loss
		numChips += (-1 * bet);		// substracts a chip if lose
	}
	else if (winStatus == 'W')
	{
		cout << "The player has won this hand." << endl;
		wins += 1;					// add a win
		numChips += (1 * bet);		// add a chip if won
	}
	else
	{
		cout << "This hand was a tie." << endl << endl;
		ties += 1;					// add a tie
	}
	

	// print the overall score
	cout << "Overall Scores:" << endl << endl 
		 << "The player has won " << wins << " game(s)" << endl 
		 << "The dealer has won " << loses << " game(s)" << endl
		 << "There have been " << ties << " tie game(s)" << endl
		 << "The player has won a total of: " << numChips << " chip(s)" 
		 << endl;
	return;
}
/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

int CalcBet(char winStatus)
{ // calcBet

	// This function takes the winStatus from caller. It then 
	// calculates and returns the bet amount for the next hand.
	// Called By: main

	//local variable
	int betAmt = 1;

	if (winStatus == 'W')
		betAmt = 3;
	else if (winStatus == 'T')
		betAmt = 2;
	else 
		betAmt = 1;

	return (betAmt);  
} // calcBet

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void InitialDeal (int& playerHand, int& dealerHand, int& dealer2ndCard)
{  // initialDeal

	// This function takes the playerhand, dealerhand, and dealer2ndcard
	// from caller. It then used the dealcard function to deal each card.
	// First to the player, then dealer, then player, then dealer.
	// Called By: main

		// deals the hand
		cout << setw (17);
		playerHand = DealCard(); cout << setw (7);
		dealerHand = DealCard(); cout << endl;
		cout << setw (17);
		playerHand += DealCard(); cout << setw (7);
		dealer2ndCard = DealCard(); cout << endl << endl;

	return;
}  // initialDeal

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

int DealCard()                                  
{ // dealCard

	// This function takes no input from the caller. It calls the
	// randmax function to output the card suit and card value. It
	// then returns the card value to the caller.
	// Called By: main


	// local variable
	int cardVal,  
		cardSuit;

	// random calc of card val and card suit
	cardVal = randmax(MAX_CARD_VALUE); 
	cardSuit = randmax(MAX_CARD_SUIT);


	switch (cardVal)
	{ // card value calculation
	case CARD_JACK:					// if card is Jack
		cout << "J";
		cardVal = FACE_VALUE;
		break;

	case CARD_QUEEN:				// if card is Queen
		cout << "Q";
		cardVal = FACE_VALUE;
		break;

	case CARD_KING:					// if card is King
		cout << "K";
		cardVal = FACE_VALUE;
		break;

	case CARD_ACE:					// if card is Ace
		cout << "A";
		cardVal = ACE_VALUE;
		break;

	default:
		cout << (cardVal);
	} // card value calculation

	cout << "-";

	switch(cardSuit)
	{ // card suit calculation
	case 1:
		cout <<"Spade";				// output spade
		break;
	case 2:
		cout <<"Heart";				// output heart
		break;
	case 3:
		cout <<"Diamond";			// output diamond
		break;
	case 4:
		cout <<"Club";				// output club
		break;
	}  // card suit calculation

	return (cardVal);   
} // dealCard

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

void PlayerStrat(int& dealer2ndCard, int& playerHand)
{  // playerstrat

	// This function takes dealer2ndcard and the playerhand from the 
	// caller. It calculates the player's strategy. It then returns
	// nothing.
	// Called By: main

	if (dealer2ndCard <= 6)			// if dealer2nd ard is <= to 6
	{
		while (playerHand < 13)		// while playerhand is less than 13
									// keep hitting
		{
		cout << "The player has " << playerHand << ", and decides to hit" << endl;
		cout << "The player receives a "; playerHand += DealCard();
		}
	}
	else if (dealer2ndCard > 6)		// if delaer2ndcard is greater than 6
		while (playerHand < 17)		// while playerhand is less than 17
									// keep hitting
		{
		cout << "The player has " << playerHand << ", and decides to hit" << endl;
		cout << "The player receives a "; playerHand += DealCard();
		}
	if ((playerHand >= 17) && (playerHand < 21))	// bewtween 17 and 21
		cout << "The player has " << playerHand << ", and decides to stand" << endl;
	else if (playerHand > 21)						// playerhand over 21
		cout << "The player has " << playerHand << ", and busts" << endl;
	else if (playerHand == 21)						// playerhand equals 21
		cout << "The player had a total of 21, and decides to stand" << endl;
	else
		cout << "The player has " << playerHand << ", and decides to stand" << endl;
	
	return;
}  // playerstrat
/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

void DealerStrat(int& dealerHand)
{  // dealerstrat

	// This function takes the dealerHand from the caller. It calculates
	// the dealer strategy. It then returns nothing.
	// Called By: main

	if (dealerHand < 16)				// if dealerHand under 16
		{		
			cout << " and must hit " << endl;
			cout << "The dealer receives a ";
			dealerHand += DealCard();	
			cout << " and has a total of " << dealerHand << endl;
			if (dealerHand == 21)       // if dealerhand equals 21
				cout << " and must stand" << endl;
			else if (dealerHand > 21)   // if dealerhand over 21
				cout << "The dealer busts!" << endl;
			else						//  over 16
				cout << " and must stand" << endl;    
		}
	else if (dealerHand == 21)          // dealerhand equals 21
		cout << " and must stand" << endl;
	else if (dealerHand > 21)           // dealerhand over 21
		cout << "The dealer busts!" << endl;
	else								// over 16
		cout << " and must stand" << endl;
	
	return;
}  // dealerstrat

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

int randmax(int max)
{ /* randmax */
static int seed = 2; /* determines sequence of random numbers */
/* initialized to 2 here to meet project */
/* requirements */
seed = (seed * 13077 + 6925) % 32768;
return (static_cast<int> (max * seed / 32768.0 + 1.0));
} /* randmax */

/* ========================================================================== */
/*                           END OF PROGRAM                                   */
/* ========================================================================== */