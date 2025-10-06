#include <iostream>
using namespace std;
const int N = 5;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void Reach_The_Meat(int maze[N][N], int i, int j, int sol[2][N * N], int soli, int visited[N][N]) {
    for (int k = 0; k < 4; k++) {
        int ni = i + dy[k];
        int nj = j + dx[k];

        if (ni >= N || nj >= N || ni < 0 || nj < 0 || maze[ni][nj] == 0 || visited[ni][nj])
            continue;

        visited[ni][nj] = 1;
        sol[0][soli] = ni;
        sol[1][soli] = nj;

        Reach_The_Meat(maze, ni, nj, sol, soli + 1, visited);

        if (visited[N - 1][N - 1]) {
            return;
        }
    }
}
int main() {
    int sol[2][N * N];
    int visited[N][N] = {0};
    int maze[N][N] = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1}
    };
    visited[0][0] = 1;
    sol[0][0] = 0;
    sol[1][0] = 0;
    Reach_The_Meat(maze, 0, 0, sol, 1, visited);
    int i = 0;
    if (visited[N - 1][N - 1]) {
        cout << "Lion Reached the Meat: ";
        do {
            cout << "(" << sol[0][i] << "," << sol[1][i] << ") -> ";
            i++;
        } while ((sol[0][i] != N - 1 || sol[1][i] != N - 1) && visited[N - 1][N - 1]);
        cout << "(" << N - 1 << "," << N - 1 << ")";
    } else {
        cout << "Lion Can't reach!";
    }
    return 0;
}
