// sample main.cpp

#include <iostream>
#include "playlist.h"

using namespace std;

void Yeah(PlayList& play_list)		// add
{
  PlayList x;
  Song s;
  cout << "Enter song\n: ";
  cin >> s;

  x = play_list + s;

   cout << x;
}
void Yep(PlayList& play_list)	// delete
{
  PlayList x;
  Song s;
  cout << "Enter song\n: ";
  cin >> s;

  x = play_list - s;

  cout << x;
}
void Inter(PlayList& play_list)	// Interscect
{
  PlayList x;
  Song s;
  cout << "Enter song\n: ";
  cin >> s;

  x.AddSong(s);

  cout << x.Intersect(play_list);

  //cout << x;
}

void DoAdd(PlayList& play_list)
{
  Song s;
  cout << "Enter song\n: ";
  cin >> s;

  play_list.AddSong(s);
}

void DoDelete(PlayList& play_list)
{
  Song del_song;
  cout << "Enter song to delete\n: ";
  cin >> del_song;

  if(play_list.DeleteSong(del_song))
  {
    cout << "Song successfully deleted\n";
  }
  else
  {
    cout << "No such song exists\n";
  }
}

void DoMode(PlayList& play_list)
{
  bool good;

  do
  {
    good = true;

    cout << "Enter mode:\n"
      << "\tN - Normal\n"
      << "\tR - Repeat\n";

    char m;
    cin >> m;

    switch(toupper(m))
    {
      case 'N':
        play_list.SetMode(NORMAL);
        break;

      case 'R':
        play_list.SetMode(REPEAT);
        break;

      default:
        good = false;
    }
  } while(!good);
}

bool Menu(PlayList& play_list)
{
  bool good;


  do
  {
    good = true;

    cout << "\n\nPlayList Program!\n"
      << "\tA - Add a song\n"
      << "\tD - Delete a song\n"
      << "\tP - Play a song\n"
      << "\tM - Set the mode\n"
      << "\tS - Show all songs\n"
	  << "\tI - Intersect\n"	// added
      << "\tX - Add Playlist\n"	// added
      << "\tZ - Add Song\n"		// added
	  << "\tW - Delete Song\n"	// added
      << "\tQ - Quit\n: ";

    char choice;
    cin >> choice;

    switch(toupper(choice))
    {
    case 'A':
      DoAdd(play_list);
      break;

    case 'D':
      DoDelete(play_list);
      break;

    case 'P':
      play_list.Play( );
      break;

    case 'M':
      DoMode(play_list);
      break;

    case 'S':
      play_list.ShowAll( );
	  //cout << play_list;  // same
      break;

	case 'I':		// Added Intersect
		Inter(play_list);
      break;

	case 'X':		// Added Playlist
		cout << (play_list+play_list);
		//(play_list+play_list).ShowAll();
      break;

	case 'Z':		// Added Songs
		Yeah(play_list);
      break;

	case 'W':		// Delete Songs
		 Yep(play_list);
      break;

  case 'Q':
    return false;

    default:
      good = false;
    }
  } while(!good);

  return true;
}

int main( )
{
  PlayList play_list; 

  while(Menu(play_list))
    ;

  return 0;
}

/*
int main()
{
  PlayList ne,play_list;

  Song s;
  cout << "Enter song\n: ";
  cin >> s;

  play_list.AddSong(s);
  ne.AddSong(s);


 // ne =(play_list + play_list);
  ne = play_list.Intersect(play_list);
  ne.ShowAll();
	
  return 0;
}
*/



