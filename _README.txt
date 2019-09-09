Noah Urbanovsky
126006965
Section 511
AtomicBois123323
atomicbois123323@tamu.edu

I certify that I have listed all the sources that I used to develop the solutions/code to the submitted work.

	On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.

Noah Urbanovsky             11-28-18

Description: This program aims to play a maze game using a text file with a maze typed in.  The program reads the input file and creates a 2D vector that holds a series of Tiles, each representing different spaces of the maze:
	S = starting tile (where players start)
	X = empty tile (available to move on)
	W = wall tile (a wall; cannot move onto this spot)
	E = ending tile (the goal; first one here wins)
Every turn, the game reads the player's direction choice through input (up-down-left-right, or u-d-l-r).  It then determines if the next spot in that direction is open (i.e. not a wall or out-of-bounds).  If it is, the position of that player is updated.  It then prints out the newly-updated maze with the new positions of the players.  Once a player has reached the ending tile, they win and the game ends.


Class Structure Chart: On a separate word doc, for ease of reading

Testing for correctness: In order to test the maze boundaries and walls, I tried moving the players into them in every direction (u,d,l,r) to make sure the program wouldn't crash.  In the event that a player tried to move to a wall space or out of bounds, I gave a warning of "Invalid Movement" and kept them in their original position, then moved to the next player.  I tested using two different sized mazes: the maze given from the assignment and the following maze:

S X X X X X
X X W X X E
S W X X W X
S X X X X E

This allowed me to test walls from every angle and test to make sure different sizes of mazes work fine.  I also tested typing in other random words and letters to make sure the program doesn't crash.  Instead, it just ends the player's turn with no movement.  

Other Notes:  I created an additional Tile subclass, the NoTile, to accomodate for spaces and newlines.  When this type of tile is found by the maze creator or maze printer, it doesn't print anything in its place, allowing for a correct maze.  I did this because originally, the maze would create a duplicate of the previous tile where the space or newline was in the input.





