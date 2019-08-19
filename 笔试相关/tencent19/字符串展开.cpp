/* AB[3|AC]Õ¹¿ªÎªABACACAC */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        stack<char>q;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=']')q.push(s[i]);
            else
            {
                string tmp;
                while(q.top()!='|')
                {
                    tmp+=q.top();
                    q.pop();
                }
                q.pop();
                int bt=0;
                for(int i=1;q.top()!='[';i++)
                {
                    bt+=(q.top()-'0')*i;
                    q.pop();
                }
                q.pop();
                for(int i=0;i<bt;i++)
                {
                    for(int j=tmp.size()-1;j>=0;j--)
                    q.push(tmp[j]);
                }
            }
        }
    string ans(q.size(),' ');
    for(int i=ans.size()-1;i>=0;i--)
    {
        ans[i]=q.top();
        q.pop();
    }
    cout<<ans<<endl;
}
    return 0;
}
