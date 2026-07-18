/*
P1480 A/B Problem（高精度除法Ⅰ）
时间限制: 1.00s    内存限制: 128.00MB

题目描述
输入两个整数 a,b，输出它们的商。

输入格式
两行，第一行是被除数，第二行是除数。

输出格式
一行，商的整数部分。

输入输出样例
输入 #1复制运行

10
2
输出 #1复制运行

5
说明/提示
0≤a≤10 
5000
 ，1≤b≤10 
9
*/
#include<bits/stdc++.h>
using namespace std;
const int N=105001;
int b,la,lc;
int A[N],C[N];
void div(int A[],int b,int C[])
{
    long long r=0;
    for(int i=la-1;~i;i--)
    {
        r=r*10+A[i];
        C[i]=r/b;
        r=r%b;
    }
    while(lc&&C[lc]==0) lc--;
}
int main()
{
    string a;
    cin>>a>>b;
    la=a.size();
    lc=la;
    for(int i=la-1;~i;i--) A[la-i-1]=a[i]-'0';
    div(A,b,C);
    for(int i=lc;~i;i--) cout<<C[i];
    return 0;
}