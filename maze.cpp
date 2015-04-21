#include <iostream>
#include <iomanip>
using namespace std;

#define theDim 3
#define thePlayer '$'

void setupMaze(char[][theDim][theDim]);
void setupLocation(int[]);
int printMaze(char[][theDim][theDim], int[]);
void updateMaze(char[][theDim][theDim], int[], char);

int main(void) {
	char maze[theDim][theDim][theDim];				// z, y, x
	int location[theDim];
	int win = 0;
	char move = 'q';

	// Now setup the maze
	setupMaze(maze);
	setupLocation(location);

	// Print the instructions
	cout << ": This is the 2D 3D Maze on Next Gen Command Line!" << endl;
	cout << ":  By David Soller" << endl;
	cout << ":" << endl;
	cout << ": Controls are:" << endl;
	cout << ":   u = up     ( +z  change )" << endl;
	cout << ":   d = down   ( -z  change )" << endl;
	cout << ":   i = in     ( +y  change )" << endl;
	cout << ":   o = out    ( -y  change )" << endl;
	cout << ":   r = right  ( +x  change )" << endl;
	cout << ":   l = left   ( -x  change )" << endl;
	cout << ":   q = quit   (  to  exit  )" << endl;
	cout << ":" << endl;

	// Prompt the user to continue
	cout << ": Press a key to continue (q to Quit) ";
	cin >> move;

	// Try to escape the maze
	while(move != 'q') {
		// Print the current maze
		win = printMaze(maze, location);

		// Determine whether another move needs to be made
		if (!win) {
			// Prompt for next move
			cout << ": Choose move  ";
			cin >> move;

			// Act upon the choosing move
			if (move != 'q') {
				updateMaze(maze, location, move);
			}
		} else {
			// They won! So tell them
			cout << ": You escaped the maze! Congratulations!" << endl;
			cout << ":  Press q to Quit or another key to play again?  ";
			cin >> move;

			// Playing again?
			if (move != 'q') {
				// Reset <(*.*<)
				setupMaze(maze);
				setupLocation(location);
			}
		}
	}
}



void setupMaze(char maze[][theDim][theDim]) {
	// z, y, x
	// z = 0
	maze[0][0][0] = '+';
	maze[0][0][1] = '+';
	maze[0][0][2] = '+';
	maze[0][1][0] = '+';
	maze[0][1][1] = '+';
	maze[0][1][2] = '+';
	maze[0][2][0] = '+';
	maze[0][2][1] = '+';
	maze[0][2][2] = '+';

	// z = 1
	maze[1][0][0] = '+';
	maze[1][0][1] = ' ';
	maze[1][0][2] = '+';
	maze[1][1][0] = '+';
	maze[1][1][1] = thePlayer;
	maze[1][1][2] = '+';
	maze[1][2][0] = '+';
	maze[1][2][1] = '+';
	maze[1][2][2] = '+';

	// z = 2
	maze[2][0][0] = '+';
	maze[2][0][1] = '+';
	maze[2][0][2] = '+';
	maze[2][1][0] = '+';
	maze[2][1][1] = '+';
	maze[2][1][2] = '+';
	maze[2][2][0] = '+';
	maze[2][2][1] = '+';
	maze[2][2][2] = '+';
}

void setupLocation(int location[]) {
	location[0] = 1;
	location[1] = 1;
	location[2] = 1;
}

int printMaze(char maze[][theDim][theDim], int location[]) {
	int winner = 0;
	int dim = theDim; 	// Dimensions of maze
	int hdim = 1;	// Half of the Dimension

	// Find all of the edges
	// location[] = z, y, x
	int zmin = location[0] - 1;
	int zmax = location[0] + 1;
	int ymin = location[1] - 1;
	int ymax = location[1] + 1;
	int xmin = location[2] - 1;
	int xmax = location[2] + 1;

	// Check for winner
	if (((zmin < 0) || (ymin < 0) || (xmin < 0)) || ((zmax >= dim) || (ymax >= dim) || (xmax >= dim))) {
		winner = 1;
	} else {
		/*
		 *	Print current location stuff
		 */
		// Current location
		int cz = location[0] - hdim;
		int cy = location[1] - hdim;
		int cx = location[2] - hdim;

		// Print the header
		cout << ":" << endl;
		cout << ": Current position in ( z, y, x) is @(" << cz << ", " << cy << ", " << cx << ")" << endl;
		cout << ": Get to +-" << hdim << " on any axis to escape!" << endl;
		cout << ":" << endl;
		cout << ":    Y      Z" << endl;



		/*
		 *	Print Orthographic projection for z, y, x sides
		 */
		// xside & zside >> single row at a time
		for (int i = 0; i < dim; ++i) {
			// Create x point
			int xz = zmin + i;
			int xy = location[1];
			int xx = xmin;

			// Create z point
			int zz = location[0];
			int zy = ymax - i;
			int zx = xmin;

			// Print spacer
			cout << ":    ";

			// Print x row points
			for (int b = 0; b < dim; ++b) {
				cout << maze[xz][xy][(xx + b)];
			}

			// Print z row points
			cout << "    ";
			for (int b = 0; b < dim; ++b) {
				cout << maze[zz][zy][(zx + b)];
			}

			// End row
			cout << endl;
		}

		// Spacer & Headers
		cout << ":" << endl;
		cout << ":   / \\     X" << endl;
 
		for (int i = 0; i < dim; ++i) {
			// Create y point
			int yz = zmin + i;
			int yy = ymin;
			int yx = location[2];

			// Print diagram top & row start
			cout << ": ";
			if ( i==0 ) {
				cout << " / Z \\ ";
			} else if ( i==1 ) {
				cout << "|\\ Z /|";
			} else { // ( i==2 )
				cout << "| \\ / |";
			}
			cout << "   ";

			// Print y row points
			for (int b = 0; b < dim; ++b) {
				cout << maze[yz][(yy + b)][yx];
			}

			// End row
			cout << endl;
		}

		// Print bottom of diagram
		cout << ": |YY|XX|" << endl;
		cout << ":  \\ | / " << endl;
		cout << ":   \\|/  " << endl;
		cout << ":" << endl;
	}

	return winner;
}

void updateMaze(char maze[][theDim][theDim] , int location[], char move) {
	int z = location[0];
	int y = location[1];
	int x = location[2];
	int n = 0;

	// See what their move was
	switch (move) {
		case 'u':
			// Calculate the new coordinate
			n = z + 1;

			// Move the player if possible
			if (maze[n][y][x] != '+') {
				// It's possible update everything
				maze[n][y][x] = thePlayer;
				maze[z][y][x] = ' ';
				location[0] = n;
			} else {
				// Invalid move hit a wall
				cout << ":  Invalid move: " << move << endl;
			}

			break;
		case 'd':
			// Calculate the new coordinate
			n = z - 1;

			// Move the player if possible
			if (maze[n][y][x] != '+') {
				// It's possible update everything
				maze[n][y][x] = thePlayer;
				maze[z][y][x] = ' ';
				location[0] = n;
			} else {
				// Invalid move hit a wall
				cout << ":  Invalid move: " << move << endl;
			}

			break;
		case 'i':
			// Calculate the new coordinate
			n = y + 1;

			// Move the player if possible
			if (maze[z][n][x] != '+') {
				// It's possible update everything
				maze[z][n][x] = thePlayer;
				maze[z][y][x] = ' ';
				location[1] = n;
			} else {
				// Invalid move hit a wall
				cout << ":  Invalid move: " << move << endl;
			}

			break;
		case 'o':
			// Calculate the new coordinate
			n = y - 1;

			// Move the player if possible
			if (maze[z][n][x] != '+') {
				// It's possible update everything
				maze[z][n][x] = thePlayer;
				maze[z][y][x] = ' ';
				location[1] = n;
			} else {
				// Invalid move hit a wall
				cout << ":  Invalid move: " << move << endl;
			}

			break;
		case 'r':
			// Calculate the new coordinate
			n = x + 1;

			// Move the player if possible
			if (maze[z][y][n] != '+') {
				// It's possible update everything
				maze[z][y][n] = thePlayer;
				maze[z][y][x] = ' ';
				location[2] = n;
			} else {
				// Invalid move hit a wall
				cout << ":  Invalid move: " << move << endl;
			}

			break;
		case 'l':
			// Calculate the new coordinate
			n = x - 1;

			// Move the player if possible
			if (maze[z][y][n] != '+') {
				// It's possible update everything
				maze[z][y][n] = thePlayer;
				maze[z][y][x] = ' ';
				location[2] = n;
			} else {
				// Invalid move hit a wall
				cout << ":  Invalid move: " << move << endl;
			}

			break;
		default:
			cout << "ERROR: Bad move choice" << endl;
			break;
	}
}