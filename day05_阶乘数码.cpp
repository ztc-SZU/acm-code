/*
题目描述
P1591 阶乘数码
求 n! 中某个数码出现的次数。

输入格式
第一行为 t(t≤10)，表示数据组数。接下来 t 行，每行一个正整数 n(n≤1000) 和数码 a。

输出格式
对于每组数据，输出一个整数，表示 n! 中 a 出现的次数。

输入输出样例
输入 #1复制

2
5 2
7 0
输出 #1复制

1
2
*/
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int N=10005;
int A[N],C[N];
int la,lc;
string mul(string s,int b)
{
    string res="";
    la=s.size();
    lc=la+5;
    memset(A,0,sizeof(A));
    memset(C,0,sizeof(C));
    for(int i=la-1;~i;i--) A[la-i-1]=s[i]-'0';
    for(int i=0;i<la;i++)
    {
        C[i]=A[i]*b;
    }
    for(int i=0;i<lc;i++)
    {
        C[i+1]+=C[i]/10;
        C[i]=C[i]%10;
    }
    while(lc&&C[lc]==0) lc--;
    for(int i=lc;~i;i--)
    {
        res+=C[i]+'0';
    }
    return res;
}
int main()

{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        char a;
        cin>>n>>a;
        int cnt=0;
        string cj="1";
        for(int i=1;i<=n;i++)
        {
            cj=mul(cj,i);
        }
        for(auto i:cj)
        {
            if(i==a) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}