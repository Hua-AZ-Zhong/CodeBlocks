#include "stdafx.h"
#include <iostream>
using namespace std;

int bmain()
{
	bool flag;
	flag=false;
	flag=1024;
	cout<<flag<<endl;
	system("pause");
	cout<<"please input three numbers:";
	int num1=0;
	int num2=0;
	int num3=0;
	cin>>num1>>num2>>num3;
	cout<<num1<<' '<<num2<<' '<<num3<<endl;
	cout<<(num1&&num2)<<endl;
	system("pause");
	return 0;
}