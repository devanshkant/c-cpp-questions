#include<iostream>
int tribonacci(int n){
	if(n == 0 || n == 1){
		return n;
	}
	if(n == 2){
		return 1;
	}
	return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}
//tribonacci using DP
int tribonacci_DP(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1 || n == 2){
		return 1;
	}
	int a = 0, b = 1, c = 1, d;
	for(int i = 3; i <= n; ++i){
		d = a + b + c;
		a = b;
		b = c;
		c = d;
	}
	return c;
}
//grid paths
int ways_rec(int **grid, int i, int j){
	if(i==0 && j ==0)
		return 1;
	if(i < 0 || j < 0)
		return 0;
	return ways_rec(grid, i - 1, j) + ways_rec(grid, i, j - 1);
}
int main(){
	// printf("%d\n", tribonacci(10));
	return 0;
}