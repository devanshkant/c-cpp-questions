#include <iostream>
using namespace std;

// Swap helper
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Recursive backtracking function
void solve(int nums[], int n, int **ans, int &returnSize, int index) {
    if (index >= n) {
        // allocate one row for this permutation
        ans[returnSize] = new int[n];
        for (int i = 0; i < n; i++) {
            ans[returnSize][i] = nums[i];
        }
        returnSize++;
        return;
    }

    for (int j = index; j < n; j++) {
        swap(nums[index], nums[j]);
        solve(nums, n, ans, returnSize, index + 1);
        // backtrack
        swap(nums[index], nums[j]);
    }
}

// Factorial function to compute n!
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    return fact;
}

// Main permutation function
int** permute(int nums[], int n, int &returnSize) {
    int fact = factorial(n);
    int **ans = new int*[fact];  // allocate row pointers
    returnSize = 0;

    solve(nums, n, ans, returnSize, 0);
    return ans;
}

int main() {
    int n;
    // cout << "Enter size of array: ";
    cin >> n;

    // allocate input array dynamically
    int *nums = new int[n];
    // cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int returnSize;
    int **result = permute(nums, n, returnSize);

    // cout << "All permutations:\n";
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
        delete[] result[i]; // free each row
    }

    delete[] result; // free row pointers
    delete[] nums;   // free input array

    return 0;
}
