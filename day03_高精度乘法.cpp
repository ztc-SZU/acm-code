/*
P1303 A*B Problem
时间限制: 1.00s    内存限制: 125.00MB
题目背景
高精度乘法模板题。

题目描述
给出两个非负整数，求它们的乘积。

输入格式
输入共两行，每行一个非负整数。

输出格式
输出一个非负整数表示乘积。

输入输出样例
输入 #1复制运行

1 
2
输出 #1复制运行

2
说明/提示
每个非负整数不超过 10 
2000
*/
#include<bits/stdc++.h>
using namespace std;
const int N=4001;
int A[N],B[N],C[N];
int la,lb,lc;
void mul(int A[],int B[],int C[])
{
    for(int i=0;i<la;i++)
    {
        for(int j=0;j<lb;j++)
        {
            C[i+j]+=A[i]*B[j];
            C[i+j+1]+=C[i+j]/10;
            C[i+j]=C[i+j]%10;
        }
    }
    while(lc&&C[lc]==0) lc--;
}
int main()
{
    string a,b;
    cin>>a>>b;
    la=a.size();
    lb=b.size();
    lc=la+lb;
    for(int i=la-1;~i;i--) A[la-i-1]=a[i]-'0';
    for(int i=lb-1;~i;i--) B[lb-i-1]=b[i]-'0';
    mul(A,B,C);
    for(int i=lc;~i;i--) cout<<C[i];
    return 0;
}