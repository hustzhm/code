/*413. Arithmetic Slices (Medium)
A = [1, 2, 3, 4]
return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/
#include<vector>
#include<iostream>
using namespace std;
int numberOfArithmeticSlices(vector<int>& A) {
	int n = A.size();
	vector<int>dp(n, 0);
	for (int i = 2; i<n; i++)
	{
		if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2]))
		{
			dp[i] = dp[i - 1] + 1;
		}
	}
	int sum = 0;
	for (int i : dp)
		sum += i;
	return sum;
}