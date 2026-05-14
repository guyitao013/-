#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
#define MaxSize 10

//创建基底-结构体
typedef struct {
    int top;
    elemtype data[MaxSize];
}stack;

void initStack(stack* S);
int fullStack(stack S);
int emptyStack(stack S);
int lengthStack(stack S);
int getTop(stack S, elemtype* e);
int push(stack* S, elemtype e);
int pop(stack* S, elemtype* e);
void clearStack(stack* S);

int main() {
    stack S;
    elemtype e;
    int ret;

    // 1. 初始化栈
    initStack(&S);
    printf("初始化栈完成\n");
    printf("栈是否为空？%s\n", emptyStack(S) ? "是" : "否");
    printf("栈当前长度：%d\n\n", lengthStack(S));

    // 2. 入栈：压入 5 个元素
    printf("=== 开始入栈 ===\n");
    for (int i = 1; i <= 5; i++) {
        ret = push(&S, i * 10);  // 压入 10, 20, 30, 40, 50
        if (ret == 1) {
            printf("push(%d) 成功，top = %d\n", i * 10, S.top);
        }
        else {
            printf("push(%d) 失败，栈已满\n", i * 10);
        }
    }

    printf("\n当前栈长度：%d\n", lengthStack(S));
    printf("栈是否为空？%s\n\n", emptyStack(S) ? "是" : "否");

    // 3. 获取栈顶元素（不移除）
    printf("=== 查看栈顶 ===\n");
    ret = getTop(S, &e);
    if (ret == 1) {
        printf("当前栈顶元素是：%d\n\n", e);
    }
    else {
        printf("栈为空，无法获取栈顶\n\n");
    }

    // 4. 出栈：弹出所有元素
    printf("=== 开始出栈 ===\n");
    while (emptyStack(S) == 0) {  // 栈非空时继续弹出
        ret = pop(&S, &e);
        if (ret == 1) {
            printf("pop() 成功，弹出元素：%d，剩余元素个数：%d\n", e, lengthStack(S));
        }
        else {
            printf("pop() 失败\n");
        }
    }

    printf("\n栈是否为空？%s\n", emptyStack(S) ? "是" : "否");
    printf("栈当前长度：%d\n\n", lengthStack(S));

    // 5. 尝试在空栈时获取栈顶（演示错误处理）
    printf("=== 空栈时尝试获取栈顶 ===\n");
    ret = getTop(S, &e);
    if (ret == 1) {
        printf("栈顶元素：%d\n", e);
    }
    else {
        printf("获取失败：栈为空，无法获取栈顶元素\n");
    }

    // 6. 重新入栈并清空
    printf("\n=== 重新入栈后清空 ===\n");
    push(&S, 100);
    push(&S, 200);
    printf("入栈两个元素后，栈长度：%d\n", lengthStack(S));

    clearStack(&S);
    printf("清空栈后，栈长度：%d\n", lengthStack(S));
    printf("清空栈后，栈是否为空？%s\n", emptyStack(S) ? "是" : "否");

    return 0;
}



void initStack(stack* S)
{
    S->top = 0;
}
//栈满
int fullStack(stack S)
{
    if (S.top == MaxSize)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//栈空
int emptyStack(stack S)
{
    if (S.top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//获取长度
int lengthStack(stack S)
{
    return S.top;
}
//获取栈顶元素
int getTop(stack S, elemtype* e)
{
    if (emptyStack(S) == 0)
    {
        *e = S.data[S.top - 1];
        return 1;
    }
    else
    {
        return 0;
    }
}
//入栈操作
int push(stack* S, elemtype e)
{
    if (fullStack(*S) == 0)
    {
            S->data[S->top] = e;
            S->top += 1; 
        return 1;
    }
    else
    {
        return 0;
    }
}
//出栈操作
int pop(stack* S, elemtype* e)
{
    if (emptyStack(*S) == 0)
    {
        *e = S->data[S->top - 1];
        S->top = S->top - 1;
        return 1;
    }
    else
    {
        return 0;
    }
}
//清空栈
void clearStack(stack* S)
{
    S->top = 0;
}