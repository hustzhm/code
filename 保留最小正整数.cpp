/*����һ���ַ��������а���m����������ɾ�����е�n������ʹ�ñ�������������С��
˼·��̰���㷨�������ұ�����ɾ�������ĵ�һ����߱��ұߴ������ѭ��n�Ρ�*/
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
			if (*start > *(start + 1)) // ÿ��ɾ����һ������һ�����ִ����
			{
				str.erase(start);
				flag = 1;
				break;
			}
		}
		if (!flag) //����������ֵ�������ɾ����󼸸�����ֱ�ӷ���
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
