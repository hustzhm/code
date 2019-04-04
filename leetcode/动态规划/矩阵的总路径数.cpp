/*62. Unique Paths (Medium)
统计从矩阵左上角到右下角的路径总数，每次只能向右或者向下移动。
*/
#include<vector>
using namespace std;
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, 1));
	for (int i = 1; i<m; i++)
	for (int j = 1; j<n; j++)
		dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	return dp[m - 1][n - 1];
}