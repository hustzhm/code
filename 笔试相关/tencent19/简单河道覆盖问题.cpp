/*题目描述：给定河道长度L，若干真视守卫n，每个守卫可以侦测到的区域为（xi,yi），求最少需要多少守卫可以覆盖整个河道视野？
测试用例：n=4,L=6 (0,2) (2,4) (3,6) (4,7) 输出：3
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,L;
    cin>>n>>L;
    vector<pair<int,int>>m(n);
    for(int i=0;i<n;i++)
    {
        cin>>m[i].first>>m[i].second;
    }
    auto cmp=[](pair<int,int>a,pair<int,int>b)->bool{return a.first==b.first?a.second>b.second:a.first<b.first;};
    sort(m.begin(),m.end(),cmp);
    bool flag=true;
    int tmp=0,ans=0;
    for(int i=0;tmp<L&&i<n;)
    {
     ++ans;
     int s=tmp;
     for(;m[i].first<=s&&i<n;i++)
     {
        tmp=max(m[i].second,tmp);
     }
     if(tmp==s&&tmp<L){flag=false;break;}
    }
    if(flag) cout<<ans<<endl;
    else cout<<-1<<endl;
}
