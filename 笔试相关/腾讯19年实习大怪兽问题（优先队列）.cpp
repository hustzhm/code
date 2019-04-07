/*��������⣺����Ϊ������ֵ����һ�д���ÿֻ���޵�����ֵ���ڶ��д����¸ÿֻ��������Ľ�ң�ֻ��1��2�����������й�����Ҫ�����ٽ������*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<long long> que;
int main()
{
	int n;
	long long*d = new long long[n];
	long long*p = new long long[n];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	long long ans = 0, now = 0;
	for (int i = 0; i < n; i++)
	{
		if (now < d[i] && p[i] == 1)
		{
			++ans;
			now += d[i];
		}
		else if (now >= d[i] && p[i] == 1)
			que.push(d[i]);
		else if (now < d[i] && p[i] == 2)
		{
			if (que.size() == 0 || now + que.top() < d[i])
			{
				ans += 2;
				now += d[i];
			}
			else{
				++ans;
				now += que.top();
				que.pop();
			}
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}