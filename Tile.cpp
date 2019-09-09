#include "Tile.h"

// output a tile character
ostream & operator << (ostream &out, const Tile &t)
{
  out << t.tile_char;
  return out;
}

// *& is a reference to a pointer
// here t is a reference to Tile*
// read in a tile character, and return in t a Tile object
istream & operator >> (istream &in,  Tile *&t)
{
  // implement this function
  char newC = in.get();
  //cout << "newC " << newC << endl; 
  if (newC == 'S')
  {
    t = new StartingTile();
  }
  else if (newC == 'X')
  {
    t = new EmptyTile();
  }
  else if (newC == 'W')
  {
    t = new WallTile();
  }
  else if (newC == 'E')
  {
    t = new EndingTile();
  }
  else if (newC != 'S' && newC != 'X' && newC != 'W' && newC != 'E')
  {
    t = new NoTile();
  }
  return in;
}
