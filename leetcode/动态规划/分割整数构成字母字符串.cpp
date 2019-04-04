/*91. Decode Ways (Medium)
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int numDecodings(string s) {
	int n = s.size();
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = s.at(0) == '0' ? 0 : 1;
	for (int i = 2; i <= n; i++)
	{
		string str = s.substr(i - 1, 1);
		int one = atoi(str.c_str());
		//cout << one << endl;
		if (one != 0) dp[i] += dp[i - 1];
		//cout << dp[i] << endl;
		if (s.at(i - 2) == '0') continue;
		str = s.substr(i - 2, 2);
		int two = atoi(str.c_str());
		//cout << two << endl;
		if (two <= 26) dp[i] += dp[i - 2];
		//cout << dp[i] << endl;
	}
	return dp[n];
}
