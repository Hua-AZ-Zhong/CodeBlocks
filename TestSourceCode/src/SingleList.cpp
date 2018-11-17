/*************************************************************************
> File Name: SingleList.cpp
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月25日 星期二 10时07分16秒
*************************************************************************/

/* 要实现的功能 */
/* 数据,创建,插入,删除,查找,修改,清空,遍历,大小,拷贝构造,析构 */

#include <iostream>
#include <cstdlib>
using namespace std;

typedef int T;

class List
{
	public:

	struct Node
	{
		T data;
		Node *next;  /* 指向下一节点的指针 */
		Node(const T& d, Node *next):data(d), next(next) {}  /* 初始化列表 */
	};  /* 节点内部结构 */

	Node *head;  /* 指向头节点的指针，不是节点 */
	int cnt;  /* 节点个数 */
	
	/* 构造函数 -- 函数名与类名相同*/
	List(): head(), cnt() {}  /* 初始化列表 & 零初始化 */

	/* 析构函数 */
	~List() {}

	int size()
	{
		return cnt;
	}

	/* 插入一个节点到链表尾部 */
	Node *insert()
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

	void display(Node *head)
	{
		Node *p = head;

		while(p != NULL)
		{
			cout << "data = " << p->data << endl;
			p = p->next;
		}
	}
};

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
