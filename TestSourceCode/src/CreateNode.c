/*************************************************************************
> File Name: CreateNode.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月24日 星期一 17时41分20秒
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)

struct student
{
	long number;
	char name[20];
	int	 score;
	struct student *next;
};

int count = 0;

/***************************************************/
/* 函数: struct student *Create();                 */
/* 描述: 函数返回一个指向链表首字节的指针          */
/***************************************************/
struct student *create()
{
	struct student *head = NULL, *newp, *tail;

	newp = tail = (struct student *)malloc(LEN);	/* 创建一个新的节点 */
	printf("Please input data:\n");
	scanf("%ld %s %d", &newp->number, newp->name, &newp->score);

	while(newp->number != 0)
	{
		count++;
		if(count == 1)
			head = newp;
		else
			tail->next = newp;
		tail = newp;
		newp = (struct student *)malloc(LEN);
		scanf("%ld %s %d", &newp->number, newp->name, &newp->score);
	}

	tail->next = NULL;
	free(newp);
	return (head);
}

int main()
{
	struct student *p;
	p = create();
	if (p == NULL)
		printf("head address is NULL\n");
	else	
		printf("head address is %p\n", p);
	return 0;
}
