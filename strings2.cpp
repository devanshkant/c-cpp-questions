#include <iostream>
#include <cmath>
#include <string>
#include <unordered_set>
std::string remove_duplicates(std::string s){
    std::string result = "";
    std::unordered_set<char> seen;

    for(char c: s){
        if(seen.find(c) == seen.end()){ //if we have not already encountered the character while traversing
            result += c;
            seen.insert(c);
        }
    }
    return result;
}
std::string remove_duplicates_without_set(std::string s){
    //in this approach we use C-styled boolean array instead of a set or vector;
    bool seen[256] = {false};  
    std::string result = "";

    for (char c : s) {
        if (!seen[(unsigned char)c]) {  // check if not seen yet
            result += c;
            seen[(unsigned char)c] = true; // mark as seen
        }
    }
    return result;
}
std::string longest_word(const std::string &s) {
    int n = s.size();
    int start = 0;
    int maxLen = 0;
    int maxStart = 0;

    int i = 0;
    //the loop uses "<= n" to handle the last word without needing an extra check outside the loop.
    //"<n" gives an error
    while (i <= n) {
        if (i == n || s[i] == ' ') {   
            int len = i - start;    //individual word's length
            if (len > maxLen) {
                maxLen = len;
                maxStart = start;
            }
            start = i + 1;  // next word starts after space
        }
        i++;
    }
    
    std::string longest = "";
    for (int j = maxStart; j < maxStart + maxLen; j++) {
        longest += s[j];
    }
    return longest;
}


int main() {
    std::string input;
    getline(std::cin, input);
    
    return 0;
}