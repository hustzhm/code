#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	vector<vector<int> > dp(n + 1, vector<int>(sum / 2 + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= sum / 2; ++j)
		{
			if (j >= a[i - 1])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	bool flag = (sum - 2 * dp[n][sum / 2] == 0);
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}
