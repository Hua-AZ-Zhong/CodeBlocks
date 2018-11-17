/*************************************************************************
> File Name: list.cpp
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月26日 星期三 10时57分50秒
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;
/* 构造函数 -- 函数名与类名相同*/
List::List(): head(), cnt() {}  /* 初始化列表 & 零初始化 */

/* 析构函数 */
List::~List() {}

/* 返回节点个数 */
int List::size()
{
	return cnt;
}
