#include <iostream>
#include <cmath>
#include <string>
bool valid(char ch){
    if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
        return true;
    }
    return false;
}
char to_LC(char ch){
    if ((ch>='a' && ch<='z') || (ch>='0' && ch<='9')) return ch;

    else{
        return ch - 'A'+'a';
    }
}
bool check_palindrome(const std::string &st){
    int l=0;
    int h=st.size()-1;
    while(l<=h){
        if(st[l]!=st[h]) return 0;
        
        else {l++; h--;}
    }
    return 1;
}
bool is_palindrome(const std::string &s) {
    //remove useless characters
    std::string temp = "";
    for (int j=0;j<s.length();j++){
        if (valid(s[j]))
            temp += s[j];
    }

    //upper case to lower case
    for (int j = 0;j<temp.length();j++){
        temp[j]=to_LC(temp[j]);
    }
    return check_palindrome(temp);
}

int main() {
    std::string input;
    getline(std::cin, input);
    if(is_palindrome(input)){
        std::cout << "Given string is palindrome" << '\n';
    }
    else{
        std::cout << "Given string is not palindrome" << '\n';
    }
    
    return 0;
}