/* n个人，m种语言，k种对应关系，使用相同语言的人可以互相交流，求最少需要几台翻译机才能使得所有人都可以交流。*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=10005;
vector<vector<int>>ptol(maxn);//第i个人会哪几种语言
vector<vector<int>>ltop(maxn);//第i种语言有哪些人会
vector<set<int>>an(maxn);//存储可以交流的人所使用的语言
vector<bool>vis(maxn,false);//是否访问过该节点
int ans;
void dfs(int u)
{
    vis[u]=true;
    int len1=ptol[u].size();
    for(int i=0;i<len1;i++)
    {
        int lan=ptol[u][i];
        an[ans].insert(lan);
        int len2=ltop[lan].size();
        for(int j=0;j<len2;j++)
        {
            int p=ltop[lan][j];
            if(vis[p]==false)
            {
                dfs(p);
            }
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        ptol[x].push_back(y);
        ltop[y].push_back(x);
        //cout<<x<<y;
    }
    ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            dfs(i);
            ans++;
        }
    }
    int cnt=0;
    for(int i=0;i<ans;i++)
    {
        if(an[i].size()==0) cnt++;
    }
    if(cnt==ans) ans++;//没人会语言
    cout<<ans-1<<endl;
    return 0;
}


