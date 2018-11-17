/*************************************************************************
> File Name: display.cpp
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月26日 星期三 10时41分08秒
*************************************************************************/

#include <iostream>
#include "list.h"
using namespace std;

/* 遍历节点 */
void List::display(Node *head)
{
    Node *p = head;

    while(p != NULL)
    {
        cout << "data = " << p->data << endl;
        p = p->next;
    }
}
