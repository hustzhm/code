/*64. Minimum Path Sum (Medium)
[[1,3,1],
[1,5,1],
[4,2,1]]
Given the above grid map, return 7. Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.*/
#include<vector>
#include<algorithm>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> sum(m, vector<int>(n, grid[0][0]));
	for (int i = 1; i<m; i++)
		sum[i][0] = sum[i - 1][0] + grid[i][0];
	for (int j = 1; j<n; j++)
		sum[0][j] = sum[0][j - 1] + grid[0][j];
	for (int i = 1; i<m; i++)
	for (int j = 1; j<n; j++)
		sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
	return sum[m - 1][n - 1];

}