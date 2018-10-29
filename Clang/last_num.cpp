/**

爱奇艺2018秋季校招C++工程师（第三场）

编程题 第3题

题目名称：最后一位
时间限制：3000ms

题目描述：
小明选择了一个正整数X,然后把它写在黑板上。然后每一天他会擦掉当前数字的最后一位,直到他擦掉所有数位。
在整个过程中,小明会把所有在黑板上出现过的数字记录下来,然后求出他们的总和sum.
例如X = 509, 在黑板上出现过的数字依次是509, 50, 5, 他们的和就是564.
小明现在给出一个sum,小明想让你求出一个正整数X经过上述过程的结果是sum.

输入描述：输入包括正整数sum(1 ≤ sum ≤ 10^18)

输出描述：输出一个正整数,即满足条件的X,如果没有这样的X,输出-1。

示例1
输入
564
输出
509

**/

#include <cstdio>
#include <iostream>
using namespace std;

long long sum;

long long ANS(long long x)
{
    long long ans=0;
    while(x!=0)
    {
        ans+=x;
        x/=10;
    }
    return ans;
}

long long CUL(long long x)
{
    long long ans=1;
    while(ANS(ans*10)<=x)
        ans*=10;
    long long anss=ans;
    while(ANS(ans+anss)<=x)
        ans+=anss;
    return ans;
}

int main()
{
    cout<<"please input a sum: ";
    cin>>sum;
    long long ans=0;
    while(sum-ANS(ans))
    {
        long long temp=CUL(sum-ANS(ans));
        ans+=temp;
        if(temp<10 && sum - ANS(ans)!=0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
