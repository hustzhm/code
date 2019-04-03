/*�����ַ�����������[]�ڲ���Ԫ�ؽ���չ�������磺3[x]չ��Ϊxxx��*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string expressionExpand(string &s)
{
	if (s.empty())
		return s;
	string res;
	stack<char> sk;
	for (auto c : s)
	{
		if (c == ']')
		{
			string dup;
			while (sk.top() != '[')
			{
				dup = sk.top() + dup;
				sk.pop();
			}
			sk.pop();
			string num = "";
			while(!sk.empty() && isdigit(sk.top()))
			{
				num = sk.top() + num;
				sk.pop();
			}
			int cnt = stoi(num);
			string str = "";
			while (cnt > 0)
			{
				str += dup;
				--cnt;
			}
			for (auto c: str)
				sk.push(c);
		}
		else
		{
			sk.push(c);
		}
	}
	while(!sk.empty())
	{
		res = sk.top() + res;
		sk.pop();
	}
	return res;
}

int main()
{
	string s;
	while (cin >> s)
		cout << expressionExpand(s) << endl;
	return 0;
}
