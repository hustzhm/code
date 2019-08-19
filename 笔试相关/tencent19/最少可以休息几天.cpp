/*问题描述：小Q在假期中准备工作、锻炼、休息。但是不能连续两天工作或锻炼。只有当公司营业时，才能工作；健身房营业时才能去健身。给定一组信息，求最少休息几天。
输入描述：整数n表示放假天数，第二行个数，1表示公司营业，0表示不营业；第三行n个数，1表示健身房营业，0表示不营业。
测试用例：4 （1 1 0 0）（0 1 1 0） 输出为 2
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>x(n);
    vector<int>y(n);
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++)cin>>y[i];
    vector<vector<int>>dp(n+1,vector<int>(3,0));
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=min(dp[i-1][0]+1,min(dp[i-1][1]+1,dp[i-1][2]+1));
        if(x[i-1]==1) dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        else dp[i][1]=n;
        if(y[i-1]==1) dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        else dp[i][2]=n;
    }
    cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<endl;
}
