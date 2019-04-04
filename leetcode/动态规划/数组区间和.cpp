/*303. Range Sum Query - Immutable (Easy)
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
*/
#include<iostream>
#include<vector>
using namespace std;
class NumArray {
public:

	NumArray(vector<int> &nums) {
		p.push_back(0);
		for (int &i : nums)
		{
			p.push_back(p.back() + i);
		}

	}

	int sumRange(int i, int j) {
		return p[j + 1] - p[i];

	}
private:
	vector<int> p;

};