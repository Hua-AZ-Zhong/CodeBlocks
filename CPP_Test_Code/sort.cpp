/**

题目描述：小明有4根木棍,长度分别为a,b,c,d。羊羊家提供改变木棍长度的服务,如果小明支付一个硬币就可以让一根木棍的长度加一或者减一。小明需要用这四根木棍拼凑一个正方形出来,小明最少需要支付多少硬币才能让这四根木棍拼凑出正方形。

输入描述：输入包括一行,四个整数a,b,c,d(1 ≤ a,b,c,d ≤ 10^6), 以空格分割

输出描述：输出一个整数,表示小明最少需要支付的硬币
示例1
输入
4 1 5 4
输出
4

**/

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int arr[4];

int main()
{
    cout<<"Please input four integers:";
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
    cout<<"Before sort: "<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;
    sort(arr,arr+4);   /** 起始位置为第一个元素的地址，结束位置为最后一个元素的下一个地址 **/
    cout<<"After  sort: "<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;

    int CNY=arr[3]*4;
    for(int i=arr[0];i<=arr[3];i++)
    {
        int sum=0;
        sum=abs(arr[0]-i) + abs(arr[1]-i) + abs(arr[2]-i) + abs(arr[3]-i);
        CNY=min(CNY, sum);
        cout<<"current i="<<i<<" sum="<<sum<<" CNY="<<CNY<<endl;
    }
    cout<<"Final CNY="<<CNY<<endl;
}
