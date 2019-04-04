/*279. Perfect Squares (Medium)
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int numSquares(int n) {
	vector<int>dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j * j <= i; j++)
		dp[i] = min(dp[i], dp[i - j * j] + 1);
	return dp[n];

}