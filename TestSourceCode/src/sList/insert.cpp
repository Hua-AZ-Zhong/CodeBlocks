/*************************************************************************
> File Name: insert.cpp
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月26日 星期三 10时40分58秒
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

/* 插入一个节点到链表尾部 */
List::Node* List::insert()
{
    Node *head = NULL, *newp, *tail;
    newp = tail = (Node *)malloc(sizeof(Node *));
    cout << "Please input data:" << endl;
    cin >> newp->data;
    cout << "Input Data Completed !" << endl;

    while(newp->data != 0)
    {   
        cnt++;
        if(cnt == 1)
            head = newp;
        else
            tail->next = newp;
        tail = newp;
        newp = (Node *)malloc(sizeof(Node *));
        cin >> newp->data;
    }   

    tail->next = NULL;
    free(newp); 
    free(tail); 

    return (head);
}
