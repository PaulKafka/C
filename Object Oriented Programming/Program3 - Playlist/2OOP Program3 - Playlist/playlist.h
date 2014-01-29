/* File: playlist.h
Author: Paul Kafka
Description: This is the class declaration for playlist.
It will manage a dynamically allocated array of song objects.
*/

#include "song.h"    // include sale class

enum Mode	// The playing modes
{
  NORMAL,
  REPEAT
};

class PlayList
{
	// Used playlist extraction for testing
	friend ostream& operator<<(ostream& n, const PlayList& play);

public:
	PlayList();							// Default Constructor
	~PlayList();						// Destructor (clean up)
	PlayList(const PlayList & I);				// Copy constructor
    PlayList& operator= (const PlayList & D);	// Assignment operator

	// Manipulators
	void AddSong(Song x);		// Add song to playlist
	bool DeleteSong(Song y);	// Delete song from playlist
	void SetMode(Mode a);		// Change the playing mode of the play list. 
								
	// Display
	void ShowAll() const;		// Print all songs in playlist
	void Play();				//This function will play one song from the play list.
								// Not a const function due to change in member data.
	
	PlayList Intersect (const PlayList& P) const;	// Makes a new playlist with all the mutual
													// songs from two playlists with no dupicates

	// overaloaded operators as members
	PlayList operator+ (const PlayList& t) const;	// Adds playlist and playlist
	PlayList operator+ (const Song& t) const;				// Adds song to playlist				 
	PlayList operator- (const Song& t) const;				// Removes song(s) from a playlist
													
private:
	Song* list;			// Pointer to Song List
	void Grow();		// Private function that increases array
	void Shrink();		// Private function that decreases array
	int maxSize;		// Stores max size of array
	int currentSize;	// Stores current size of array
	Mode style;			// Stores Mode type
	int playmark;		// Keeps track for the play()
	bool firstTime;		// Used for the play()
};