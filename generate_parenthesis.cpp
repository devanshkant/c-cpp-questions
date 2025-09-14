#include <iostream>
using namespace std;

// Recursive function to generate parentheses
void generate(char str[], int pos, int n, int open, int close) {
    // If we filled all 2*n positions → valid combination
    if (close == n) {
        str[pos] = '\0';   // null terminate
        cout << str << endl;
        return;
    }

    // If we can place an opening bracket
    if (open < n) {
        str[pos] = '(';
        generate(str, pos + 1, n, open + 1, close);
    }

    // If we can place a closing bracket
    if (close < open) {
        str[pos] = ')';
        generate(str, pos + 1, n, open, close + 1);
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    char str[100]; // buffer large enough
    generate(str, 0, n, 0, 0);

    return 0;
}
