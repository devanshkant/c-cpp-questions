#include <iostream>
using namespace std;

int towerOfHanoi(int n, char from, char to, char aux) {
    // base case
    if (n == 0) return 0;

    // moving n-1 disks from source to auxiliary
    int moves1 = towerOfHanoi(n - 1, from, aux, to);

    // moving the nth disk from source to destination
    cout << "Move disk " << n << " from " << from << " -> " << to << endl;

    // moving n-1 disks from auxiliary to destination
    int moves2 = towerOfHanoi(n - 1, aux, to, from);

    // total moves = moves before + this move + moves after
    return moves1 + 1 + moves2;
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    int totalMoves = towerOfHanoi(n, 'A', 'C', 'B');
    cout << "\nTotal moves = " << totalMoves << endl;

    return 0;
}
