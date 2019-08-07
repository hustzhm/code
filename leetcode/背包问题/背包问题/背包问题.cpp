#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define NUMBER 1000
//0-1��������������W����Ʒ����N����i����Ʒ������weight[i],��ֵvalue[i]��ÿ����Ʒֻ��һ�����󱳰�������ֵ��
int bag(vector<int>&weight, vector<int>&value, int W, int N)
{
	vector<int>dp(W + 1, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = W; j >= weight[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	return dp[W];
}
//��ȫ����,��������W����Ʒ����N����i����Ʒ������weight[i],��ֵvalue[i]��ÿ����Ʒ���������󱳰�������ֵ��
int fullbag(vector<int>&weight, vector<int>&value, int W, int N)
{
	vector<int>dp(W + 1, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = weight[i]; j<=W ; j++)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	return dp[W];
}
//���ر�������������W����Ʒ����N����i����Ʒ������weight[i],��ֵvalue[i]������Ϊc[i]���󱳰�������ֵ��
int multibag(vector<int>&weight, vector<int>&value, vector<int>&c,int W, int N)
{
	vector<int>dp(W + 1, 0);
	vector<vector<int>>num(NUMBER,vector<int>(2,0));
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		for (int k = 1; k < c[i]; k <<= 1)
		{
			num[index][0] = k*value[i];
			num[index++][1] = k*weight[i];
			c[i] -= k;
		}
		num[index][0] = c[i] * value[i];
		num[index++][1] = c[i] * weight[i];
	}
	for (int i = 0; i < index; i++)
	{
		for (int j = W; j>=num[i][1]; j--)
		{
			dp[j] = max(dp[j], dp[j - num[i][1]] + num[i][0]);
		}
	}
	return dp[W];
}
int main()
{
	vector<int>weight{ 1,2,3,4,5 };
	vector<int>value{ 1,2,3,4,5 };
	vector<int>c{ 1,2,3,4,5 };
	int W = 10, N = 5;
	int res1 = bag(weight, value, W, N);
	cout << res1 << endl;
	int res2 = fullbag(weight, value, W, N);
	cout << res2 << endl;
	int res3 = multibag(weight, value, c, W, N);
	cout << res3 << endl;
	system("pause");
	return 0;
}