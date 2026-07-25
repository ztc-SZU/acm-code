/*
题目描述  P1249 最大乘积
一个正整数一般可以分为几个互不相同的自然数的和，如 3=1+2，4=1+3，5=1+4=2+3，6=1+5=2+4。

现在你的任务是将指定的正整数 n 分解成若干个互不相同的自然数（也可以不分解，就是这个数字本身）的和，且使这些自然数的乘积最大。

输入格式
只有一个正整数 n，（3≤n≤10000）。

输出格式
第一行是分解方案，相邻的数之间用一个空格分开，并且按由小到大的顺序。

第二行是最大的乘积。

输入输出样例
输入 #1复制

10
输出 #1复制

2 3 5
30
*/
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int n;
int used[10005];
const int N=100005;
int A[N],C[N];
int la,lc;
string mul(string s,int a)
{
    memset(A,0,sizeof(A));
    memset(C,0,sizeof(C));
    la=s.size();
    lc=la+5;
    for(int i=la-1;~i;i--) A[la-1-i]=s[i]-'0';
    for(int i=0;i<la;i++)
    {
        C[i]=A[i]*a;
    }
    for(int i=0;i<lc;i++)
    {
        C[i+1]+=C[i]/10;
        C[i]=C[i]%10;
    }
    while(lc&&C[lc]==0) lc--;
    string ref="";
    for(int i=lc;~i;i--)
    {
        ref+=C[i]+'0';
    }
    return ref;
}
int main()
{
    cin>>n;
    int k=n,id;
     string cj="1";
    for(int i=2;i<=n;i++)
    {
        k=k-i;
        used[i]=1;
        if(k<0)
        {
            id=i;
            used[i]=0;
            k=k+i;
            break;
        }
    }
    if(k>id-2)
    {
        used[2]=0;
        id=2+k;
        used[id]=1;
    }
    else{
        used[id]=1;
        used[id-k]=0;
    }
    for(int i=2;i<=id;i++)
    {
        if(used[i]==1)
        {
            cout<<i<<" ";
            cj=mul(cj,i);
        }
    }
    cout<<endl;
    cout<<cj;
    return 0;
}