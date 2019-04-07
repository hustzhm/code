/*找硬币问题：n种不同面值的硬币，用尽量少的数量，组合出包含1到m的所有面值，求硬币数量。*/
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, amount;
	cin >> n >> amount;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if (a[0] != 1) return -1;
		int cnt = 0, sum = 0;
		int cur = 0;
		while (sum <amount)
		{
			while (cur < n-1&&sum >= a[cur + 1]-1)
			{
				++cur;
			}
			sum += a[cur];
			++cnt;
		}
		cout << cnt << endl;
	system("pause");
	return 0;
}