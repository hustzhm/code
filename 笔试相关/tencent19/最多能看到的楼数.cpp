/*问题描述：给定一组数，记算每个数左右两侧（以此数为起点）最长上升序列的长度和。
测试用例：3 5 4 6 8 输出：4 3 4 2 1 */
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
