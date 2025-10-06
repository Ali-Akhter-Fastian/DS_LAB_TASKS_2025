#include <iostream>
using namespace std;
bool hasDuplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true; 
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {20, 12, 12, 15, 2, 10, 1, 13, 9, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasDuplicates(arr, n)) {
        cout << "Array contains duplicates" << endl;
    } else {
        cout << "Array does not contain duplicates" << endl;
    }

    return 0;
}