/*打怪兽问题：输入为两组数值，第一行代表每只怪兽的武力值，第二行代表贿赂每只怪兽所需的金币（只有1和2），求打败所有怪兽需要的最少金币数。*/
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