/*************************************************************************
> File Name: 03addr.cpp
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月25日 星期二 14时04分47秒
*************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int a[5]={11,22,33,44,55};
	int *p = a;  /*  &a[0]  */
	cout << a[2] << ',' << p[2] << endl;
	cout << *(a+2) << ',' << *(p+2) << endl;
	cout << 2[a] << ',' << 2[p] << endl;
	return 0;
}
