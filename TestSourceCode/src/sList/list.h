/*************************************************************************
> File Name: list.h
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月26日 星期三 10时57分50秒
*************************************************************************/

/* 要实现的功能 */
/* 数据,创建,插入,删除,查找,修改,清空,遍历,大小,拷贝构造,析构 */

#ifndef		LIST_H
#define		LIST_H
class List
{
	public:

	struct Node
	{
		int data;
		Node *next;  /* 指向下一节点的指针 */
		Node(const int& d, Node *next):data(d), next(next) {}  /* 初始化列表 */
	};  /* 节点内部结构 */

	Node *head;  /* 指向头节点的指针，不是节点 */
	int cnt;  /* 节点个数 */
	
	/* 构造函数 -- 函数名与类名相同*/
	List();

	/* 析构函数 */
	~List();

	/* 返回节点个数 */
	int size();

	/* 插入一个节点到链表尾部 */
	Node *insert();

	/* 遍历节点 */
	void display(Node *head);
};
#endif
