/*��Ŀ�����������ӵ�����L��������������n��ÿ������������⵽������Ϊ��xi,yi������������Ҫ�����������Ը��������ӵ���Ұ��
����������n=4,L=6 (0,2) (2,4) (3,6) (4,7) �����3
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
