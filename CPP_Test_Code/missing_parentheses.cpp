/**

爱奇艺2018秋季校招C++工程师（第三场）

编程题 第2题

题目名称：缺失的括号
时间限制：3000ms

题目描述：一个完整的括号字符串定义规则如下:
1、空字符串是完整的。
2、如果s是完整的字符串，那么(s)也是完整的。
3、如果s和t是完整的字符串，将它们连接起来形成的st也是完整的。
例如，"(()())", ""和"(())()"是完整的括号字符串，"())(", "()(" 和 ")"是不完整的括号字符串。
小明有一个括号字符串s,现在需要在其中任意位置尽量少地添加括号,将其转化为一个完整的括号字符串。请问小明至少需要添加多少个括号。

输入描述：输入包括一行,一个括号序列s,序列长度length(1 ≤ length ≤ 50). s中每个字符都是左括号或者右括号,即'('或者')'.

输出描述：输出一个整数,表示最少需要添加的括号数

示例1
输入
(()(()
输出
2

**/

#if 0  /** 错误的算法 **/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string arr;
    cout<<"Please enter some '(' & ')' in a string:";
    cin>>arr;
    cout<<"String is: "<<arr<<endl;
    int left=0;
    int right=0;
    int sum=0;
    int i=0;
    for(i=0;i<arr.size();i++)
    {
        if(arr[i]=='(')
            left++;
        else if(arr[i]==')')
            right++;
    }
    sum =  abs(left - right);
    cout<<"final sum is "<<sum<<endl;
    return 0;
}
#endif

#if 1
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
string s;
int main()
{
    cout<<"please enter string: ";
    cin>>s;
    int k1=0,k2=0,maxx=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            k1++;
        if(s[i]==')')
            k2++;
        maxx=max(maxx,k2-k1);
        cout<<"current k1="<<k1<<" k2="<<k2<<" maxx="<<maxx<<endl;
    }
    int ans=maxx;
    k1=k2=maxx=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='(')
            k1++;
        if(s[i]==')')
            k2++;
        maxx=max(maxx,k1-k2);
        cout<<"current k1="<<k1<<" k2="<<k2<<" maxx="<<maxx<<endl;
    }
    ans+=maxx;
    cout<<ans<<endl;
    return 0;
}
#endif
