#include "stdafx.h"
#include <iostream>
using namespace std;

class Time{
public:
	int hour;
	int minute;
	int second;
public:
	Time(int,int,int);
	void display();
};

void print()
{
	printf("hello world\n");
}

int main()
{
	Time t1(10,13,56);
	int *p1=&(t1.hour);
	cout<<*p1<<endl;
	t1.display();
	Time *p2=&t1;
	p2->display();
	void(Time::*p3)();
	p3=&Time::display;
	(t1.*p3)();
	void(*p4)();

	cout<<print<<endl;
	p4=print;
	(*p4)();

	int a[10]={1,2,3,4,5};
	cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<endl;
	char arr[100]={'A','B','C'};
	int i=0;
	char *p=&arr[4];
	p=arr;
	cout<<*((p++)+0)<<endl;

	int abc[2]={0,0},ii=0,j=0,k=2;
	for(ii=0;ii<k;i++)
	{
		for(j=0;j<k;j++)
		{
			a[j]=a[ii]+1;
		}
	}
	cout<<abc[1]<<endl;
	system("pause");
	return 0;
}

void Time::display()
{
	//cin>>hour;
	//cin>>minute;
	//cin>>second;
	cout<<hour<<':'<<minute<<':'<<second<<endl;
}

Time::Time(int hour,int minute,int second)
{
	Time::hour = hour;
	Time::minute = minute;
	Time::second = second;
	cout<<"constructro called"<<endl;
}