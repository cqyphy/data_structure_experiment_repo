#pragma once
#define Maxsize 1000

//定义链表
struct ListNode
{
    int val = 0;
    struct ListNode *next = nullptr;
} ;

void createnode(ListNode* &h,int data);
void dropnode(ListNode*pre,ListNode *p);//链表的基本操作

//双向链表（用于实现栈和队列的链式储存结构）
struct two_way_ListNode
{
    int val = 0;
    struct two_way_ListNode *pre = nullptr;
    struct two_way_ListNode *next = nullptr;
};

//定义栈
typedef struct 
{
    two_way_ListNode *top = nullptr;
}Stack;
//栈的基本操作
void init_stack(Stack *s);
void stack_push(Stack *s, int data);
int stack_pop(Stack *s);
bool stack_empty(Stack *s);

//定义队列
typedef struct 
{
    two_way_ListNode *h;
    two_way_ListNode *end;
}Queue;
//队列的基本操作
void init_queue(Queue *q);
void queue_push(Queue *q, int a);
int queue_pop(Queue *q);

typedef struct 
{
    int x;
    int y;
    int di;
}Box;

typedef struct 
{
    Box data[Maxsize];
    int top = 0;
}BoxSt, *BStptr;

void BSt_push(BoxSt *p, Box a);
void BSt_pop(BoxSt *p);
bool BSt_empty(BoxSt *p);
Box BSt_gettop(BoxSt *p);