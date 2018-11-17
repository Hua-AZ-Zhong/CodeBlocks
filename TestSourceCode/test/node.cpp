/*************************************************************************
> File Name: node.cpp
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月24日 星期一 17时25分26秒
*************************************************************************/

#include <iostream>
using namespace std;

typedef char T;

struct Node
{
	T data;
	Node* next;
};

int main()
{
	Node a={'A'},b={'B'},c={'C'},d={'D'},e={'E'};
	a.next = &c; c.next = &b; b.next = &e;
	e.next = &d; Node* p = &a;

	while(p!=NULL)
	{
		cout << p->data;
		p = p->next;          /*  (*p).next;  */
	}

#if 0
	cout << p->data;          /* A */
	p = (*p).next;            /* p = &c; */

	cout << p->data;          /* C */
	p = (*p).next;	          /* p = &b; */

	cout << p->data;	      /* B */
	p = (*p).next;	          /* p = &e; */

	cout << p->data;          /* E */
	p = (*p).next;	          /* p = &d; */

	cout << p->data;          /* D */
	p = (*p).next;	          /* p = NULL; */

	cout << p->data;          /* 段错误 */

	cout << endl;
#endif
	
	cout << endl;
	return 0;
}
