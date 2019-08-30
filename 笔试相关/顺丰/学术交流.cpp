/* n���ˣ�m�����ԣ�k�ֶ�Ӧ��ϵ��ʹ����ͬ���Ե��˿��Ի��ཻ������������Ҫ��̨���������ʹ�������˶����Խ�����*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=10005;
vector<vector<int>>ptol(maxn);//��i���˻��ļ�������
vector<vector<int>>ltop(maxn);//��i����������Щ�˻�
vector<set<int>>an(maxn);//�洢���Խ���������ʹ�õ�����
vector<bool>vis(maxn,false);//�Ƿ���ʹ��ýڵ�
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
    if(cnt==ans) ans++;//û�˻�����
    cout<<ans-1<<endl;
    return 0;
}


