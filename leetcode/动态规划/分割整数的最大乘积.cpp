/*343. Integer Break(Medim)
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int integerBreak(int n) {
	vector<int>dp(n+1,0);
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i / 2; j++)
			dp[i] = max(dp[i], max(j*(i - j), j*dp[i - j]));
	}
	return dp[n];

}