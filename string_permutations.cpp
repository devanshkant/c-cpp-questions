#include <iostream>
#include <cstring> 
using namespace std;

// Swap helper
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

// Recursive function
void permute(char str[], int l, int r) {
    if (l == r) {
        cout << str << endl;
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);          // fix one character
        permute(str, l + 1, r);        // permute the rest
        swap(str[l], str[i]);          // backtrack
    }
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    int n = strlen(str);
    permute(str, 0, n - 1);

    return 0;
}
