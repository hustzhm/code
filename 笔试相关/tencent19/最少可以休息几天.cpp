/*����������СQ�ڼ�����׼����������������Ϣ�����ǲ����������칤���������ֻ�е���˾Ӫҵʱ�����ܹ���������Ӫҵʱ����ȥ��������һ����Ϣ����������Ϣ���졣
��������������n��ʾ�ż��������ڶ��и�����1��ʾ��˾Ӫҵ��0��ʾ��Ӫҵ��������n������1��ʾ����Ӫҵ��0��ʾ��Ӫҵ��
����������4 ��1 1 0 0����0 1 1 0�� ���Ϊ 2
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
