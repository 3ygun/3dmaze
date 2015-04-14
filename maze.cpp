#include <iostream>
using namespace std;


void setupMaze(char[][][]);
void printMaze(char[][][], int[]);

int main(void) {
	char maze[3][3][3];
	int location[3] = {1, 1, 1};

	setupMaze(maze);

	printMaze(maze);



}

// z, y, x

void setupMaze(char maze[][][]) {
	// z, y, x
	// z = 0
	maze[0][0][0] = '+';
	maze[0][0][1] = '-';
	maze[0][0][2] = '+';
	maze[0][1][0] = '-';
	maze[0][1][1] = '-';
	maze[0][1][2] = '-';
	maze[0][2][0] = '+';
	maze[0][2][1] = '-';
	maze[0][2][2] = '+';

	// z = 1
	maze[1][0][0] = '+';
	maze[1][0][1] = ' ';
	maze[1][0][2] = '+';
	maze[1][1][0] = '-';
	maze[1][1][1] = '$';
	maze[1][1][2] = '-';
	maze[1][2][0] = '+';
	maze[1][2][1] = '-';
	maze[1][2][2] = '+';

	// z = 2
	maze[2][0][0] = '+';
	maze[2][0][1] = '-';
	maze[2][0][2] = '+';
	maze[2][1][0] = '-';
	maze[2][1][1] = '-';
	maze[2][1][2] = '-';
	maze[2][2][0] = '+';
	maze[2][2][1] = '-';
	maze[2][2][2] = '+';

}

int printMaze(char maze[][][], int location[]) {
	int winner = 0;
	int dim = 3; // Dimensions of maze

	// Find all of the edges
	// location[] = x, y, z
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
		// xside & zside
		for (int i = 0; i < dim; ++i) {
			// Create x point
			int xz = zmin + i;
			int xy = location[1];
			int xx = xmin;

			// Create z point
			int zz = location[0];
			int zy = ymax - i;
			int zx = xmin;

			cout << ":   ";

			for (int j = 0; j < dim; ++j) {
				

				cout << " " << maze[][]





				xx++;
				zx++;
			}
		}
	}

	return winner;
}