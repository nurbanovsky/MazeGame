#include "Maze.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool Maze::can_move_to_tile(Position pos)
{
  // implement this function
  return (pos.row > -1 && pos.col > -1) && (pos.row < tiles.size() && pos.col < tiles[1].size()) && tiles[pos.row][pos.col]->try_walk();
}

bool Maze::is_tile_end(Position pos)
{
  return tiles[pos.row][pos.col]->is_end();
}

// print a maze
ostream & operator << (ostream &out, Maze &m)
{
  for(auto row : m.get_tiles()) {
    for(auto t : row)
      out << *t;
    
    out << endl;
  }

  return out;
}

// read in a maze from input
istream & operator >> (istream &in,  Maze &m)
{
  string row; 
  while(getline(in, row)) {
    
    stringstream ss(row);
    vector<Tile*> tile_row;
    Tile* t;
    while(ss >> t) {
      if(t->tile_char != ' ')
        tile_row.push_back(t);
    }
    
    m.get_tiles().push_back(tile_row);
  }
  
  return in;
}
