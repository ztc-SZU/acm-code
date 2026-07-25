/*
IncDec Sequence
### 题目描述
给定一个长度为 n 的数列 a₁,a₂,⋯,aₙ，每次操作可以选择一个区间 [l,r]，将区间内的所有数统一加 1 或者统一减 1。

请计算：
1.  让数列中所有数完全相等所需要的最少操作次数
2.  在保证操作次数最少的前提下，最终能得到的相等数列总共有多少种不同的结果

### 输入格式
第一行输入一个正整数 n。
接下来 n 行，每行输入一个整数，第 i+1 行的整数对应数列的第 i 个元素 aᵢ。

### 输出格式
第一行输出最少操作次数。
第二行输出最少操作前提下，最终相等数列的不同结果总数量。

### 输入输出样例
#### 输入 #1
4
1
1
2
2
#### 输出 #1
1
2

### 说明/提示
数据规模与约定：
对于 100% 的测试数据，满足 n ≤ 100000，0 ≤ aᵢ ≤ 2³¹。
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=100010;
typedef long long LL;
LL a[N],b[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
    LL p=0,q=0;
    for(int i=2;i<=n;i++)
    {
        if(b[i]>0) p+=b[i];
        else q+=abs(b[i]);
    }
    cout<<max(p,q)<<endl<<abs(p-q)+1;
    return 0;
}