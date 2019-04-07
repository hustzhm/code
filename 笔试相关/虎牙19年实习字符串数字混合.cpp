#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int> num;
	char c;
	string str = "";
	int sum = 0;
	while ((c = getchar()) != '\n')
	{
		if (c== '\n'){ num.push_back(atoi(str.c_str())); }
		if ((c >= '0'&&c <= '9') || (c == '-'))
		{
			str += c;
		}
		else { 
			num.push_back(atoi(str.c_str()));
			str = ""; 
			continue;
		}
		
	}
	for (auto i : num)
	{
		cout << i << endl;
		sum += i;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}