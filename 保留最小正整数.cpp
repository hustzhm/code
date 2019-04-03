/*给定一个字符串，其中包含m个正整数，删除其中的n个数，使得保留的正整数最小。
思路：贪心算法。从左到右遍历，删除遇到的第一个左边比右边大的数，循环n次。*/
#include <iostream>
#include <string>
using namespace std;

string deletenum(string &str, int k)

{
	string::iterator start;
	bool flag;
	for (int i = k; i > 0; --i)
	{
		flag = 0;
		for (start = str.begin(); start < str.end() - 1; ++start)
		{
			if (*start > *(start + 1)) // 每次删除第一个比下一个数字大的数
			{
				str.erase(start);
				flag = 1;
				break;
			}
		}
		if (!flag) //如果所有数字递增，则删除最后几个数字直接返回
		{
			str.erase(str.end() - i, str.end());
			break;
		}
	}
	if (str[0] =='0') return "0";
	return str;
}


int main()
{
	string m;
	int n;
	while (cin >> m >> n)
	{
		cout << deletenum(m,n) << endl;
	}
	return 0;
}
