#include <iostream>
#include <iomanip>
using namespace std;


void setupMaze(char[][3][3]);
int printMaze(char[][3][3], int[]);

int main(void) {
	char maze[3][3][3];				// z, y, x
	int location[3] = {1, 1, 1};
	int win = 0;
	char move;

	while(!win) {
		setupMaze(maze);

		win = printMaze(maze, location);
		cin >> move;
	}
}



void setupMaze(char maze[][3][3]) {
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
	maze[1][1][1] = '$';
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

int printMaze(char maze[][3][3], int location[]) {
	int winner = 0;
	int dim = 3; 	// Dimensions of maze
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
		cout << "winner! \n \n";
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
		cout << ":    Current position in ( z, y, x) is @(" << cz << ", " << cy << ", " << cx << ")" << endl;
		cout << ":    Get to +-" << hdim << " on any axis to escape!" << endl;
		cout << ":" << endl;
		cout << ":    X      Z" << endl;



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

		// Spacer
		cout << ":" << endl;
		cout << ":           Y" << endl;

		for (int i = 0; i < dim; ++i) {
			// Create y point
			int yz = zmin + i;
			int yy = ymin;
			int yx = location[2];

			// Print y row points
			for (int b = 0; b < dim; ++b) {
				cout << maze[yz][(yy + b)][yx];
			}

			// End row
			cout << endl;
		}
	}

	return winner;
}