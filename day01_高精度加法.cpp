/*
P1601 高精度加法
题目背景
本题是高精度加法的模板题。

题目描述
给定两个非负整数 a,b，求它们的和。不用考虑负数。

输入格式
输入共两行，每行一个非负整数，分别为 a,b。

输出格式
输出一行一个非负整数，表示 a+b 的值。

输入输出样例
输入 #1复制运行

1
1
输出 #1复制运行

2
输入 #2复制运行

1001
9099
输出 #2复制运行

10100
说明/提示
对于 20% 的测试数据，a,b≤10 
9
 ；
对于 40% 的测试数据，a,b≤10 
18
 ；
对于 100% 的测试数据，0≤a,b≤10 
500
 。
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int A[N],B[N],C[N];
int la,lb,lc;
void Add(int A[],int B[],int C[])
{
    for(int i=0;i<lc;i++)
    {
        C[i]+=A[i]+B[i];
        C[i+1]+=C[i]/10;
        C[i]=C[i]%10;
    }
    if(C[lc]) lc++;
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
    Add(A,B,C);
    for(int i=lc-1;~i;i--) printf("%d",C[i]);
    return 0;
}