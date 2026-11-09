#include "funtions.h"//里面函数的实现
#include <stdio.h>
#include <stdlib.h>

void init_insert_datas(ListNode *h){
    ListNode *p = h, *tmp = nullptr;
    for (int i = 0; i < 10; i++)
    {
        int a = (rand()+100)%1000;//生成100~999的随机数
        createnode(tmp,a);
        p->next = tmp;
        p = p->next;//尾插法
    }
    
}

void outputList(ListNode *h){
    ListNode *p = h->next;
    if (!p)
    {
        printf("List is empty");//当p为空时，表示链表为空
    }
    while (p) //当p不为空时循环
    {
        printf("%d ",p->val);
        p = p->next;
    }
    
}

int seek_list_num(ListNode *h, int num){
    ListNode *p = h->next;
    int location = 1;
    if (!p) {printf("List is empty");return location;}//当链表为空则直接返回
    while (p)
    {
        if (p->val == num) return location;//找到指定数字，返回位置
        p = p->next;//若找不到，则p往后移动
        location++;
    }
    if (!p) printf("Number not founded");//此时p为空表明已到链表末尾，找不到对应数字
    return location;
}

void insert_data(ListNode *h, int loca, int data){
    ListNode *p = h, *tmp = nullptr;
    for (int i = 0; i < loca-1; i++)//寻找合适位置
    {
        if (!p && i != loca-2)//如果指定位置不合法，则退出
        {
            printf("illegal location");
            return;
        }
        p = p->next;//位置合法，p往后移动
    }
    createnode(tmp,data);//p到正确位置的前一个，创建新节点
    tmp->next = p->next;
    p->next = tmp;//插入新节点
    outputList(h);//输出整个链表
}

void delete_node_by_val(ListNode *h,int val){
    ListNode *p = h->next, *pre = h;
    if (!p) {printf("List is empty");return ;}//当链表为空则直接返回
    while (p)
    {
        if (p->val == val) {dropnode(pre,p);outputList(h);return;}//找到指定数字
        p = p->next;//若找不到，则p和pre往后移动
        pre = pre->next;
    }
    if (!p) printf("Number not founded");//此时p为空表明已到链表末尾，找不到对应数字
}

void reverse__output(ListNode *h){
    ListNode *pre = nullptr, *p = h->next;//双指针法翻转链表
    while (p)
    {
        ListNode *nexttmp = p->next;//临时指针储存后续结点
        p->next = pre;//将p的next指向前一个结点
        pre = p;
        p = nexttmp;//指针的移动
    }
    h->next = pre;
    outputList(h);
}

void insert_datas_to_stack(Stack *s){
    for (int i = 0; i < 10; i++)
    {
        int a = (rand()+100)%1000;//生成100~999的随机数
        stack_push(s,a);//存入栈
    }
}

void output_stack(Stack *s){
    while (s->top->pre)
    {
        int data = stack_pop(s);
        printf("%d ",data);
    }
    
}

void insert_datas_to_queue(Queue *q){
    for (int i = 0; i < 10; i++)
    {
        int a = (rand()+100)%1000;//生成100~999的随机数
        queue_push(q,a);
    }
}

void output_queue(Queue *q){
    two_way_ListNode *p = q->h->next;
    while (p)
    {
        printf("%d ",p->val);
        p = p->next;
    }
    
}

void reverse_pop_to_output_queue(Queue *q){
    q->h->next = q->end;
    q->end->next = q->h;//先将头结点的next指向尾结点，尾结点的next指向头，为后面尾结点移动并改变pre和next提供统一样式
    while (q->end->pre != q->h)
    {
        two_way_ListNode *tmp = q->end->next;
        q->end->next = q->end->pre;
        q->end->pre = tmp;//以上三行进行链表结点的next和pre的转换，等效于swap(q->end->next,q->end->pre)
        q->end = q->end->next;//移动队列的尾指针
    }
    q->end->next = nullptr;//完成翻转
    while (q->h != q->end)//开始输出
    {
        int a = queue_pop(q);
        printf("%d ",a);
    }
    
}

void init_and_sort_list(ListNode* h) {
    init_insert_datas(h);//输入数字
    int n;
    printf("please input a num to sort the list:");
    scanf("%d", &n);
    ListNode* p = h->next, * bigger_h = new ListNode, *q = bigger_h, *smaller = h;//用h和bigger_h作为两个链表的头结点
    h->next = nullptr;
    while (p)//p不为空时，遍历原链表
    {
        ListNode* nextTemp = p->next; 
        p->next = nullptr;
        if (p->val < n)//p中的值小于输入值，将结点尾插到h头结点形成的链表
        {
            smaller->next = p;
            smaller = smaller->next;
        }
        else//大于或等于，尾插到bigger_h
        {
            q->next = p;
            q = q->next;
        }
        p = nextTemp;
    }
    smaller->next = bigger_h->next;//遍历完成后，将两个链表合并
    delete bigger_h;
}

bool judging_parentheses(char s[]){
    Stack sta;
    init_stack(&sta);
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')//左括号则入栈
        {
            stack_push(&sta,s[i]);
        }
        else //右括号
        {
            if (stack_empty(&sta))//若栈空，则是不合法嵌套
            {
                delete sta.top;
                return false;
            }
            else stack_pop(&sta);//不空，退栈
        }
    }
    bool res = stack_empty(&sta);//遍历完成，若栈空则表示合法
    delete sta.top; 
    return res;
}

void all_paths_of_maze(int maze[][col],int start_x,int start_y, int end_x, int end_y){
    BoxSt stack;
    BStptr p = &stack;
    Box e;
    e.x = start_x;  e.y = start_y  ;  e.di = -1;
    BSt_push(p,e);//将初始点位入栈
    maze[start_x][start_y] = -1;
    while (!BSt_empty(p))
    {
        e = BSt_gettop(p);//取栈顶元素
        int x = e.x, y = e.y ,di = e.di;
        if (x == end_x && y == end_y)//到终点则输出
        {
            printf("The path of maze is:");
            for (int i = 0; i < p->top; i++)
            {
                printf("(%d,%d) ",p->data[i].x,p->data[i].y);
                if ((i+1)%7 == 0)
                {
                    printf("\n");
                }
            }
            printf("\n");//每条路径输出完换行，避免下一条路径接在同一行
            BSt_pop(p);//终点回溯
            maze[x][y] = 0;
            continue;
        }
        bool found = false;
        while (di < 3 && !found)//寻找周围可走的格子
        {
            di++;x = e.x; y = e.y;
            bool is_move = true;
            switch (di)
            {
            case 0://向上：行号x减1
                if (x-1 >= 0) x--;
                else is_move = false;
                break;
            case 1://向右：列号y加1
                if (y+1 < col) y++;
                else is_move = false;
                break;
            case 2://向下：行号x加1
                if (x+1 < col) x++;
                else is_move = false;
                break;
            case 3://向左：列号y减1
                if (y-1 >= 0) y--;
                else is_move = false;
                break;
            default:
                break;
            }
            found = is_move && (maze[x][y] == 0);
        }
        if (found)//找到格子
        {
            p->data[p->top-1].di = di;//栈顶的方向置为di
            e.x = x;
            e.y = y;
            e.di = -1;//设置新的入栈元素
            BSt_push(p,e);//入栈
            maze[x][y] = -1;
        }
        else {//没找到则回溯
            BSt_pop(p);//退栈
            maze[e.x][e.y] = 0;
        }
    }
    
}