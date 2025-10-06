#include <iostream>
using namespace std;
const int N = 4; 
void Place_Flags(int col[], int diag1[], int diag2[], int row, int count, int &maxFlags) {
    if (row == N) return; 
    for (int j = 0; j < N; j++) {
        if (col[j] || diag1[row - j + N - 1] || diag2[row + j]) continue;
        col[j] = diag1[row - j + N - 1] = diag2[row + j] = 1;
        maxFlags = max(maxFlags, count + 1); 
        Place_Flags(col, diag1, diag2, row + 1, count + 1, maxFlags);
        col[j] = diag1[row - j + N - 1] = diag2[row + j] = 0;
    }
}
int main() {
    int col[N] = {0};
    int diag1[2 * N - 1] = {0}; 
    int diag2[2 * N - 1] = {0}; 
    int maxFlags = 0;
    Place_Flags(col, diag1, diag2, 0, 0, maxFlags);
    cout << "Maximum no. of flags on a " << N << "x" << N << " grid = " << maxFlags << endl;
    return 0;
}
