#include <iostream>
#include <cmath>
#include <string>
void rectangle(int l, int b){
    for(int i = 0; i < b; ++i){
        for(int j = 0; j < l; ++j){
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}
void half_pyramid(int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <=i; ++j){
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}
void half_pyramid_with_numbers(int n){
    for(int i =0; i < n; ++i){
        for(int j = 0; j <=i ; ++j){
            std::cout << j + 1 << " ";
        }
        std::cout << '\n';
    }
}
void half_pyramid_3(int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            std::cout << i + 1 << " ";
        }
        std::cout << '\n';
    }
}
void inverted_half_pyramid(int n){
    for(int i = 0; i < n; ++i){
        for(int j = n; j > i; --j){
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}
void inverted_half_pyramid_with_numbers(int n){
    for(int i = 0; i < n; ++i){
        for(int j = n; j > i; --j){
            std::cout << n + 1 - j << " ";
        }
        std::cout << '\n';
    }
}
void pyramid(int N){
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j =0; j<N-i-1; j++)
        {
            std::cout <<" ";
        }
       
        // For printing the stars in each row
        for(int j=0;j< 2*i+1;j++){
            
            std::cout<<"*";
        }
        
        // For printing the spaces after the stars in each row
         for (int j =0; j<N-i-1; j++)
        {
            std::cout <<" ";
        }
        
        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        std::cout << '\n';
    }
}
void inverted_pyramid(int n){
    for (int i = 0; i < n; i++) {
        // Left triangle
        for (int j = 0; j < i; j++) 
            std::cout << " ";   
        for (int j = i; j < n; j++) 
            std::cout << "* "; 

        // Gap between triangles
        for (int j = 0; j < 2 * i; j++) 
            std::cout << " ";

        // Right triangle
        for (int j = i; j < n; j++) 
            std::cout << "* ";

        std::cout << '\n';
    }
}
int main() {
    
    // rectangle(5,5);
    // inverted_half_pyramid_with_numbers(7);
    inverted_pyramid(9);
    return 0;
}