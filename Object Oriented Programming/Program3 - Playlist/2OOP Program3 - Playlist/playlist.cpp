/* File: playlist.cpp
Author: Paul Kafka
Description: This is the class definition for playlist.
It will manage a dynamically allocated array of song objects.
*/

#include <iostream>
#include "playlist.h"

using namespace std;

PlayList::PlayList()
// Default Constructor
{
	currentSize = 0;					// presets currentSize to 0
	maxSize = currentSize+5;			// presets maxSize to 0
	playmark=0;							// Used for play()
	list = new Song[maxSize];			// allocates new Song array of objects
	style = NORMAL;						// Starts the mode off at NORMAL
	firstTime = true;					// Used for play()
}

PlayList::~PlayList()
// Destructor
{
	// Deallocated  array 
	if (list !=0)
		delete [] list;
}
PlayList::PlayList(const PlayList & I)
// Copy constructor.
{
	currentSize = I.currentSize;
	list = new Song[currentSize+1];
	for (int i=0; i<currentSize; i++)
		list[i] = I.list[i];
}

PlayList& PlayList::operator= (const PlayList & D)
// Assignment operator
{
	if (this !=  &D)
	{
		delete[] list;
		currentSize = D.currentSize;
		list = new Song[currentSize+1];
		for (int i=0; i<currentSize; i++)
			list[i] = D.list[i];
	}
	return *this; 
}
void PlayList::Grow()
// Increases array when needed
{
   maxSize = currentSize + 5;				// Determine a new size.
   Song* newList = new Song[maxSize];		// Allocate a new array.
	
   for (int i = 0; i < currentSize; i++)	// Copy each entry into
	newList[i] = list[i];					// the new array.
		
   delete [] list;							// Remove the old array
   list = newList;							// Point old name to new array.
   
   cout << "List Grow\n";			// used to test functionality
}

void PlayList::Shrink()
// Decreases array when needed
{
   maxSize = currentSize + 5;				// Determine a new size.
   Song* newList = new Song[maxSize];		// Allocate a new array.
	
   for (int i = 0; i < currentSize; i++)	// Copy each entry into
	 newList[i] = list[i];					// the new array.
		
   delete [] list;							// Remove the old array
   list = newList;							// Point old name to new array.
	
   cout << "List Shrink\n";			// used to test functionality
}
void PlayList::AddSong(Song x)
// Adds a song to Playlist
{
	if (currentSize == maxSize)		// if size is too small
		Grow();						// send to Grow function

	list[currentSize++] = x;		// send data to Song class
}
void PlayList::ShowAll() const
// Prints all the songs in the playlist
{
	if (currentSize == 0)
	{
		cout << "No songs have been added";
		return;
	}

	for (int i=0; i < currentSize; i++)		// Display sales using loop
		cout << list[i] << "\n";
}

bool PlayList::DeleteSong(Song y)
// Deletes a song from the playlist
{
	bool deleted = false;	// Flag

	if (currentSize == 0)	// No songs in list
		return false;

	else
	{
		// Go through songs using loop
		for (int i=0; i < currentSize; i++)		
		{
			if (y == list[i])
			{
				// Delete multiple copies
				for (int j = i + 1; j < currentSize; j++)
						list[j - 1] = list[j];
					
				currentSize--;		// fix currentSize
				deleted = true;		// flag a success
			}
		}
		if (maxSize >currentSize +5)	// if size is too big, 
			Shrink();					// send to shrink function
	}	

	if (deleted == true)
		return true;		// Delete success
	else
		return false;		// Delete failure
}
void PlayList::SetMode(Mode a)
// Change the playing mode of the play list. 
// Normal or REPEAT 
{style = a;}

void PlayList::Play()		
// This function will play one song from the play list.
// Depends on the Mode
{
	// First time playing
	if (firstTime == true)
	{
		cout << list[0];	// Print first song
		playmark++;		
		firstTime = false;	// Flag that first time is over
	}
	
	else if (playmark <currentSize)
	{
		if (style == NORMAL)
		{
			cout << list[playmark]; 
			playmark++;
		}

		else if (style == REPEAT)
			cout << list[playmark];		// Doesnt increment the playmark
	}

	else	// Finished all songs (restart)
	{
		playmark =0;		// Restarts play mark
		cout << list[0];	// Print first song
		playmark++;
	}
}
PlayList PlayList::Intersect(const PlayList& P) const
// Takes two playalist objects and makes a new playlist 
// with all the mutual songs from both with no repeats
{
	PlayList r; 
	int tracker=0;
	
	// Search through playlist1
	for (int i=0; i < P.currentSize; i++)
	{	// Search through playlist2
		for (int j=0; j< currentSize; j++)
		{	
			// Find mutual songs
			if (P.list[i] == list[j])
			{	// Add them to new playlist
				r.list[tracker] = P.list[i];	
				r.currentSize++;
				tracker++;
			}
		}
	}

	// Remove duplicates
	for (int k=0; k < r.currentSize; k++)	
	{
		for (int x=1; x < r.currentSize; x++)
		{
			if (r.list[k] == r.list[x])
				r.DeleteSong(r.list[x]);
		}
	}

	return r;  // returns playlist
}
PlayList PlayList::operator+(const PlayList& t) const
//concatenation of the two playlist objects passed in by the caller.
{
   PlayList x; 		

	// add both playlists
	for (int i = 0; i < currentSize; i++)		// 1st Playlist
		x.AddSong(list[i]);

	for (int i = 0; i < t.currentSize; i++)		// 2nd Playlist
		x.AddSong(t.list[i]);

	x.currentSize = t.currentSize + currentSize;  
  
	// Used for testing
   /*for (int i = 0; i < x.currentSize; i++)		
		cout << x.list[i] << "\n"; */

	return x;  // returns playlist
}
PlayList PlayList::operator+(const Song& t) const
// Playlist will be a concatenation of all songs in the caller's 
{
   PlayList x;

   // New playlist with old songs
   for (int i = 0; i < currentSize; i++)
	   x.list[i] = list[i];
 
   x.currentSize = currentSize;
  
   x.list[x.currentSize++] = t;		// Adds song.. could have said x.AddSong(t);
  
   // Used for testing
   /*for (int i = 0; i < x.currentSize; i++)
	   cout << x.list[i];*/

   return x;	// returns playlist
}
PlayList PlayList::operator-(const Song& t) const
// Used to remove song from playlist for a new playlist
{
   PlayList x;

   // New playlist with old songs
   for (int i = 0; i < currentSize; i++)
	   x.list[i] = list[i];

   x.currentSize = currentSize;

   x.DeleteSong(t);		// Remove song and its dupicates

   // Used for testing
   /*for (int i = 0; i < x.currentSize; i++)
	   cout << x.list[i];*/

   return x;	// returns playlist
}
ostream& operator<<(ostream& n, const PlayList& play)
// Playlist extraction used for testing
// The same algorythem as the ShowAll() function
{
 	if (play.currentSize == 0)
	{
		n << "No songs have been added";
		return n;
	}

	for (int i=0; i < play.currentSize; i++)
		n << play.list[i] << "\n";

  return n;
}