/*��������������һ����������ÿ�����������ࣨ�Դ���Ϊ��㣩��������еĳ��Ⱥ͡�
����������3 5 4 6 8 �����4 3 4 2 1 */
#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    int n;
    cin>>n;
    stack<int> st;
    vector<int>l(n);
    vector<int>r(n);
    vector<int>w(n);
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        if(st.empty()) st.push(w[i]);
        else
        {
            while(!st.empty()&&st.top()<=w[i])
            {
                st.pop();
            }
            st.push(w[i]);
        }
        l[i]=st.size();
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty()) st.push(w[i]);
        else
        {
            while(!st.empty()&&st.top()<=w[i])
            {
                st.pop();
            }
            st.push(w[i]);
        }
        r[i]=st.size();
    }
    for(int i=0;i<n;i++)
    {
        int res=l[i]+r[i]-1;
        cout<<res<<" ";
    }
    cout<<endl;

 }
