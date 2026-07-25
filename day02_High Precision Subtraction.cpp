/*
P2142 高精度减法
时间限制: 1.00s    内存限制: 125.00MB

题目描述
给定两个正整数 a,b，求 a−b 的值。

输入格式
输入共两行，每行一个正整数，分别为 a,b。

输出格式
输出一行一个整数，表示 a−b 的值。

如果 a−b<0，请输出负号。

输入输出样例
输入 #1复制运行

2
1
输出 #1复制运行

1
说明/提示
对于 20% 的数据，a,b 在long long类型的存储范围内；
对于 100% 的数据，0<a,b≤10 
10086
*/
#include<bits/stdc++.h>
using namespace std;
const int N=10087;
int A[N],B[N],C[N];
int la,lb,lc;
bool cmp(int A[],int B[])
{
    if(la!=lb) return la>lb;
    for(int i=la-1;~i;i--)
    {
        if(A[i]!=B[i]) return A[i]>B[i];
    }
    return 1;
}
void Sub(int A[],int B[],int C[])
{
    for(int i=0;i<lc;i++)
    {
        if(A[i]<B[i])
        {
            A[i+1]--;
            A[i]+=10;
        }
        C[i]=A[i]-B[i];
    }
    while(lc&&C[lc]==0) lc--;
}
int main()
{
    string a,b;
    cin>>a>>b;
    la=a.size();
    lb=b.size();
    lc=max(la,lb);
    for(int i=la-1;~i;i--) A[la-i-1]=a[i]-'0';
    for(int i=lb-1;~i;i--) B[lb-i-1]=b[i]-'0';
    if(!cmp(A,B)) swap(A,B),cout<<"-";
    Sub(A,B,C);
    for(int i=lc;~i;i--) cout<<C[i];
    return 0;
}