#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
//创建结构体
typedef struct QNode
{
	elemtype data;
	struct QNode* next;
}QNode, * QueuePtr;
//创建队头队尾的结构体
typedef struct
{
	QueuePtr front, rear;
}LinkQueue;

// 函数声明
LinkQueue initQueue();
int enterQueue(LinkQueue* Q, elemtype e); 
int outQueue(LinkQueue* Q, elemtype* e);

int main()
{
	LinkQueue Q;
	elemtype e;
	int i;

	// 初始化队列
	Q = initQueue();

	// 入队5个元素
	printf("入队：");
	for (i = 1; i <= 5; i++)
	{
		enterQueue(&Q, i);  
		printf("%d ", i);
	}

	// 出队所有元素
	printf("\n出队顺序：");
	while (outQueue(&Q, &e))
	{
		printf("%d ", e);
	}

	return 0;
}

//初始化
LinkQueue initQueue()
{
	LinkQueue Q;
	QueuePtr q = (QueuePtr)malloc(sizeof(QNode));  
	q->next = NULL;
	Q.front = q;
	Q.rear = q;
	return Q;
}

//入队
int enterQueue(LinkQueue* Q, elemtype e)  
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (s == NULL)
	{
		return 0;
	}
	else
	{
		s->data = e;
		s->next = NULL;
		Q->rear->next = s;
		Q->rear = s;
		return 1;  
	}
}

//出队
int outQueue(LinkQueue* Q, elemtype* e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
	{
		return 0;
	}
	else
	{
		p = Q->front->next;
		*e = p->data;
		if (Q->rear == p)
		{
			Q->rear = Q->front;
			Q->front->next = NULL;
		}
		else
		{
			Q->front->next = p->next;
		}
		free(p);
		return 1;
	}
}