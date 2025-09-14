#include <iostream>
using namespace std;

int n;

// Directions: Down, Right, Up, Left
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};

// Recursive backtracking function
void solveMaze(int maze[100][100], int i, int j, int visited[100][100], char path[], int pos) {
    // If reached destination
    if (i == n - 1 && j == n - 1) {
        path[pos] = '\0'; // terminate string
        cout << path << endl;
        return;
    }

    // Try all 4 directions
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];

        // Check bounds and validity
        if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
            maze[ni][nj] == 1 && !visited[ni][nj]) {

            visited[ni][nj] = 1;            // mark visited
            path[pos] = dir[k];             // add move
            solveMaze(maze, ni, nj, visited, path, pos + 1);
            visited[ni][nj] = 0;            // backtrack
        }
    }
}

int main() {
    cout << "Enter n: ";
    cin >> n;

    int maze[100][100];
    cout << "Enter maze (" << n << "x" << n << ", 1=path, 0=wall):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    int visited[100][100] = {0};
    char path[100]; // store moves

    if (maze[0][0] == 1) {
        visited[0][0] = 1; // start position
        solveMaze(maze, 0, 0, visited, path, 0);
    } else {
        cout << "No path possible (start blocked)." << endl;
    }

    return 0;
}
