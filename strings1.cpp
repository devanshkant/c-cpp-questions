#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>

bool check_anagram(const std::string &s,const std::string &t){
    /*Another approach can be to sort the strings and if they 
    result in the same string after sorting, then they are anagrams*/
    if(s.size() != t.size()){
        return false;
    }
    std::unordered_map<char, int> mpp1, mpp2;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        mpp1[s[i]]++;
        mpp2[s[i]]++;
    }
    //if the frequency of all the characters in 
    //both the strings is equal then they are anagram
    if(mpp1 == mpp2)
        return true;
    else
        return false;
}
std::string reverse_words(const std::string &s) {
    //create a stack of strings, which would be taking individual words
    std::stack<std::string> st;
    std::string current = "";
    
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' '){
            if (!current.empty()) { // push only non-empty words
                st.push(current);
                current = "";
            }
        } else {
            current += s[i];
        }
    }
    // push last word, because in the above loop 
    //it would not have been encountered given the if-condition
    if (!current.empty()) { 
        st.push(current);
    }

    std::string result = "";
    //until the stack is empty, we add the words from the top to the result string, this way all the words come reversed
    while (!st.empty()) {
        result += st.top();
        st.pop();
        if (!st.empty()) result += " "; // avoid trailing space
    }
    
    return result;
}

int main() {
    std::string input;
    getline(std::cin, input);
    //getline for taking input with white spaces

    
    return 0;
}