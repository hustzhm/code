/*213. House Robber II (Medium)
题目描述：抢劫一排住户，但是不能抢邻近的住户，求最大抢劫量。区域是一个环形*/
#include<vector>
#include<algorithm>
using namespace std;
int rob(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	if (n == 1) return nums[0];
	return max(subrob(nums, 0, n - 2), subrob(nums, 1, n - 1));
}
int subrob(vector<int>& nums, int first, int last)
{
	int pre1 = 0, pre2 = 0;
	for (int i = first; i <= last; i++)
	{
		int cur = max(pre2 + nums[i], pre1);
		pre2 = pre1;
		pre1 = cur;
	}
	return pre1;
}