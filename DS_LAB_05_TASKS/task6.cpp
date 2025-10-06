#include <iostream>
using namespace std;
int recursiveArraySum(int *arr[], int sizes[], int dim) {
    static int i = 0;
    if (dim == 0) return 0;
    if (i == sizes[dim - 1]) {
        i = 0;
        return recursiveArraySum(arr, sizes, dim - 1);
    }
    return arr[dim - 1][i++] + recursiveArraySum(arr, sizes, dim);
}
int main() {
    int dim = 3;
    int sizes[dim];
    for(int i=2;i>=0;i--){
        sizes[i]=i+1;
    }
    int **arr = new int *[dim];
    int temp = 1;

    for (int i = 0; i < dim; i++) {
        arr[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++) {
            arr[i][j] = temp++;
        }
    }
    cout << endl << "Array : " << endl;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Total Sum: " << recursiveArraySum(arr, sizes, dim) << endl;
    cout << endl;
    for (int i = 0; i < dim; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
