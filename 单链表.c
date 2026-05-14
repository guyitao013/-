#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define SUCCESS 1


typedef int elemtype ;
//创建结构体
typedef struct LNode {
	elemtype data;//数据域
	struct LNode* next;//指针域
}LinkNode, * LinkList;

//声明函数
LinkList createList();
int createFromHead(LinkList head);
void printList(LinkList head);  
int lengthLinkList(LinkList head);
LinkNode* getElem(LinkList head, int local);
int deleteLinkList(LinkList head, int i);


//主函数
void main() {
	LinkList L;
	L = createList();
	if (L != NULL) {
		printf("链表创建成功\n");

		int result = createFromHead(L);

		if (result == SUCCESS) {
			printf("数据插入成功\n");
			printList(L);

			// 插入操作
			int pos;
			elemtype val;
			printf("请输入要插入的位置：");
			scanf_s("%d", &pos);
			printf("请输入要插入的值：");
			scanf_s("%d", &val);

			int insertResult = insertLinkList(L, pos, val);
			if (insertResult == SUCCESS) {
				printf("插入成功\n");
				printList(L);
			}
			else {
				printf("插入失败，位置无效\n");
			}

			// 删除操作 ← 加在这里
			int delPos;
			printf("请输入要删除的位置：");
			scanf_s("%d", &delPos);

			int deleteResult = deleteLinkList(L, delPos);
			if (deleteResult == SUCCESS) {
				printf("删除成功\n");
				printList(L);
			}
			else {
				printf("删除失败，位置无效\n");
			}

			int len = lengthLinkList(L);
			printf("链表长度：%d\n", len);
		}
		else {
			printf("数据插入失败\n");
		}
	}
	else {
		printf("链表创建失败\n");
	}
}

//创建头节点
LinkList createList() {
	LinkNode* head;
	head = (LinkNode*)malloc(sizeof(LinkNode));
	if (head != NULL) {
		head->next = NULL;
		return head;
	}
	else {
		return NULL;
	}
}
//头插法
int createFromHead(LinkList head)
{
	LinkNode* s;//指向结构体的首地址
	elemtype e;//定义输入整型
	//如果不按#，则一直循环

	printf("请输入整数（输入-1结束）：\n");

	while (1)
	{
		scanf_s("%d", &e);//输入整数
		if (e == -1) {
			break;
		}
		s = (LinkNode*)malloc(sizeof(LinkNode));//开辟内存空间
		if (s != NULL)
		{
			s->data = e;//把e存到结点数据域中
			s->next = head->next;//
			head->next = s;
		}
		else
		{
			return ERROR;
		}
	}
	return SUCCESS;
}
//打印单链表
void printList(LinkList head) {
	LinkNode* p = head->next;  // 跳过头节点
	printf("链表内容（头插法，逆序）：");
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//获取链表长度
int lengthLinkList(LinkList head)
{
	int len = 0;
	LinkNode* s=head;
	while (s != NULL)
	{
		s = s->next;
		len++;
	}
	return len;
}
//查找第i个
LinkNode* getElem(LinkList head, int local)
{
	int i = 1;
	LinkNode* pre;
	//确定合理范围
	if ((local < 1) || (local > lengthLinkList(head) + 1))//符合任意一个都是超出界限
	{
		return NULL;
	}
	else
	{
		pre = head;
		while (i <= local)
		{
			pre = pre->next;
			i++;
		}
		return pre;
	}
}
//插入
int insertLinkList(LinkList head, int i, elemtype e)
{
	int n = 1;
	LinkNode* j;
	j = head;
	if ((i < 1) || (i > lengthLinkList(head) + 1))
	{
		return ERROR;
	}
	else
	{
		while (n<=i-1)
		{
			j = j->next;
			n++;
		}
		LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = j->next;
		j->next = s;
		return SUCCESS;
	}
}
//删除
int deleteLinkList(LinkList head, int i)
{
	int n = 1;
	LinkNode* j,* s;
	j = head;
	if ((i < 1) || (i > lengthLinkList(head) + 1))
	{
		return ERROR;
	}
	else
	{
		while (n <= i - 1)
		{
			j = j->next;
			n++;
		}
		s = j->next;
		j->next = j->next->next;
		free(s);
		return SUCCESS;
	}
}
