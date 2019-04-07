#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(int a, int b){
	string strNum1 = to_string(a);
	string strNum2 = to_string(b);
	return (strNum1 + strNum2)<(strNum2 + strNum1);
}
string PrintMinNumber(vector<int> numbers) {
	string result;
	if (numbers.empty())
		return result;
	sort(numbers.begin(), numbers.end(), compare);
	for (int i = 0; i<numbers.size(); i++)
		result += to_string(numbers[i]);
	return result;
}
int main()
{
	vector<int> num;
	char c;
	string str = "";
	while ((c = getchar()) != '\n')
	{
		if (c >= '0'&&c <= '9')
		{
			str += c;
		}
		else if (c == ' ')
		{
			num.push_back(atoi(str.c_str()));
			str = "";
		}
	}
	num.push_back(atoi(str.c_str()));
	for (auto i : num)
		cout << i << endl;
	string str1 = PrintMinNumber(num);
	cout << str1 << endl;
	long a = atoi(str1.c_str());
	cout << a << endl;
	system("pause");
	return 0;
}