// implementation of MazeGame functions

#include "MazeGame.h"

MazeGame::MazeGame(string filename)
{
  save_out.open(out_name);
  ifstream in;
  in.open(filename);
  if (!in) {
    cerr << "Wrong maze tiles file: " + filename << endl;
    throw IncorrectFile();
  }
  save_out << "Maze tiles file: " << filename << endl << endl;
  in >> maze;
}

MazeGame::~MazeGame()
{
  save_out.close();
}

void MazeGame::start_game(istream & is)
{
  // implement this function
  Position pos;
  for (int i = 0; i < maze.get_tiles().size(); i++)
  {
    for (int j = 0; j < maze.get_tiles().at(i).size(); j++)
    {
      pos = Position(i,j);
      if (maze.get_tiles().at(i).at(j)->tile_char == 'S')
      {
        players.push_back(new MazePlayer(pos));
      }
    }
  }
  print_maze();
  update_loop(is);
}

// Important: if you use cout << something
// do the same with save_out << something
// Otherwise, the file output.txt would be incorrect
void MazeGame::update_loop(istream & is)
{
  //cout << "in update " << endl;
  int pnum = 0; // player's number
  string dir;
      
  for(auto player : players) {
    pnum++;
    // implement code here      
    cout << "Player " << pnum << " position: (" << player->get_position().row << " , " << player->get_position().col << ")\n";
    cout << "Move #" << player->move_number() << ": ";
    cin >> dir;
    cout << endl;

    save_out << "Player " << pnum << " position: (" << player->get_position().row << " , " << player->get_position().col << ")" << endl;
    save_out << "Move #" << player->move_number() << ": ";
    save_out << dir << endl << endl;

    if(maze.can_move_to_tile(player->take_turn(dir,0)))
    {
      player->set_position(player->take_turn(dir,1));
      if (maze.get_tiles().at(player->get_position().row).at(player->get_position().col)->tile_char == 'E')
      {
        cout << "Player " << pnum << " wins!" << endl;
        save_out << "Player " << pnum << " wins!" << endl;
        save_out.close();
        exit(0);
      }
    }

    else
    {
      cout << "Invalid Move\n";
    }

    print_maze();
  }

  update_loop(is);
}

void MazeGame::print_maze()
{
  vector<string> grid;
  for(auto row : maze.get_tiles()) {
    string tiles = "";
    for(auto t : row) {
      if (t->tile_char != ' ') {
          tiles += t->tile_char;
      }
    }

    grid.push_back(tiles);
  }

  for(auto player : players)
    grid[player->get_position().row][player->get_position().col] = 'P';

  cout << " ";
  save_out << " ";
  
  for(int i = 0; i < grid[0].size(); i++) {
    cout << i;
    save_out << i;
  }

  cout << endl;
  save_out << endl;
  
  for(int i = 0; i < grid.size(); i++) {
    cout << i << grid[i] << endl;
    save_out << i << grid[i] << endl;
  }
}

