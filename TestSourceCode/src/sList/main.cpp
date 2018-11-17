/*************************************************************************
> File Name: SingleList.cpp
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月25日 星期二 10时07分16秒
*************************************************************************/

#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	List testList;
	int nReturnCode;
	nReturnCode = testList.size();
	cout << "当前节点数 = " << nReturnCode << endl;

	List::Node *p;
	p = testList.insert();
	if(p == NULL)
		cout << "The First Node don't be Created ! Head Address = " << p << endl;
	else
		cout << "The First Node Create Successfully! Head Address = " << p << endl;

	nReturnCode = testList.size();
	cout << "当前节点数 = " << nReturnCode << endl;
	testList.display(p);
	nReturnCode = testList.size();
	cout << "当前节点数 = " << nReturnCode << endl;

	cout << "未完待续" << endl;
	return 0;
}
