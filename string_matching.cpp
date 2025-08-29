#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

// 1) Naive (Brute-force)
// Time: O(n*m)  Space: O(1)
int naiveSearch(const string &text, const string &pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();
    if (m == 0) return 0; // convention: empty pattern found at 0
    if (m > n) return -1;

    for (int i = 0; i <= n - m; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) { ok = false; break; }
        }
        if (ok) return i;
    }
    return -1;
}

// 2) Rabin-Karp (rolling hash) 
// Average: O(n + m). Worst-case O(n*m) with many collisions.
// Space: O(1)
int rabinKarpSearch(const string &text, const string &pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();
    if (m == 0) return 0;
    if (m > n) return -1;

    const long long mod = 1000000007LL; // large prime
    const long long base = 256LL;       // alphabet base (bytes)
    long long patternHash = 0;
    long long windowHash = 0;
    long long power = 1; // base^(m-1) % mod

    // prepare power = base^(m-1)
    for (int i = 0; i < m - 1; ++i) {
        power = (power * base) % mod;
    }

    // initial hashes
    for (int i = 0; i < m; ++i) {
        patternHash = (patternHash * base + (unsigned char)pattern[i]) % mod;
        windowHash  = (windowHash  * base + (unsigned char)text[i]) % mod;
    }

    // slide window
    for (int i = 0; i <= n - m; ++i) {
        if (patternHash == windowHash) {
            // possible match -- verify to avoid false positive from hash collision
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) { match = false; break; }
            }
            if (match) return i;
        }
        // compute next window hash
        if (i < n - m) {
            long long left = (unsigned char)text[i];
            long long right = (unsigned char)text[i + m];
            windowHash = (windowHash - (left * power) % mod + mod) % mod; // remove leftmost char
            windowHash = (windowHash * base + right) % mod;               // add new char
        }
    }
    return -1;
}

// 3) KMP (Knuth-Morris-Pratt)
// Time: O(n + m), Space: O(m)
vector<int> buildLPS(const string &pat) {
    int m = (int)pat.size();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // try shorter prefix
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
    return lps;
}

int kmpSearch(const string &text, const string &pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();
    if (m == 0) return 0;
    if (m > n) return -1;

    vector<int> lps = buildLPS(pattern);
    int i = 0; // index for text
    int j = 0; // index for pattern
    while (i < n) {
        if (text[i] == pattern[j]) {
            ++i; ++j;
            if (j == m) {
                return i - j; // match found at i-j
            }
        } else {
            if (j != 0) {
                j = lps[j - 1]; // fall back in pattern
            } else {
                ++i; // move in text
            }
        }
    }
    return -1;
}

// ---------------------- Helper to print result ----------------------
void printResult(const string &method, int idx) {
    if (idx >= 0) cout << method << ": Found at index " << idx << '\n';
    else cout << method << ": Not found\n";
}

int main() {
    string text = "hello world";
    string pattern = "world";

    int idx1 = naiveSearch(text, pattern);
    int idx2 = rabinKarpSearch(text, pattern);
    int idx3 = kmpSearch(text, pattern);

    printResult("Naive", idx1);
    printResult("Rabin-Karp", idx2);
    printResult("KMP", idx3);

    // Additional quick tests (uncomment to try)
    // cout << naiveSearch("aaaaab", "aab") << endl;

    return 0;
}
