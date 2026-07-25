/*
题目描述  P1009 [NOIP 1998 普及组] 阶乘之和
用高精度计算出 S=1!+2!+3!+⋯+n!（n≤50）。

其中 ! 表示阶乘，定义为 n!=n×(n−1)×(n−2)×⋯×1。例如，5!=5×4×3×2×1=120。

输入格式
一个正整数 n。

输出格式
一个正整数 S，表示计算结果。

输入输出样例
输入 #1复制

3
输出 #1复制

9
说明/提示
【数据范围】

对于 100% 的数据，1≤n≤50。

【其他说明】

注，《深入浅出基础篇》中使用本题作为例题，但是其数据范围只有 n≤20，使用书中的代码无法通过本题。

如果希望通过本题，请继续学习第八章高精度的知识。

NOIP1998 普及组 第二题
*/
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int N=10005;
int A[N],C[N],B[N];
int la,lc,lb;
string add(string a,string c)
{
    string res="";
    memset(A,0,sizeof(A));
    memset(C,0,sizeof(C));
    la=a.size();
    lc=c.size();
    lb=max(la,lc);
    for(int i=la-1;~i;i--) A[la-i-1]=a[i]-'0';
    for(int i=lc-1;~i;i--) C[lc-i-1]=c[i]-'0';
    for(int i=0;i<lb;i++)
    {
        B[i]+=A[i]+C[i];
        B[i+1]+=B[i]/10;
        B[i]=B[i]%10;
    }
    if(B[lb])  lb++;
    for(int i=lb-1;~i;i--)
    {
        res+=B[i]+'0';
    }
    return res;
}
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
        string cj="1";
        string sum="0";
        for(int i=1;i<=n;i++)
        {
            cj=mul(cj,i);
            sum=add(sum,cj);
        }
        
    }
    return 0;
}