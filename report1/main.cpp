#include "linklist.h"
#include "funtions.h"
#include <windows.h>
#include <stdio.h>

void test_list(){
    //任务（1）
    ListNode *h;
    createnode(h,0);
    init_insert_datas(h);
    printf("The nodes of the list is:\n");
    outputList(h);//任务（2）

    //任务（3）
    printf("please input the num you want to seek:");
    int a;
    scanf("%d",&a);
    int loca = seek_list_num(h,a);//查找功能
    printf("The location is :%d\n",loca);//输出结果

    //任务（4）
    printf("please input the num you want to insert:");
    scanf("%d",&a);
    printf("please input the location you want to insert to:");
    scanf("%d",&loca);
    insert_data(h,loca,a);

    //任务（5）
    printf("please input the num you want to delete:");
    scanf("%d",&a);
    delete_node_by_val(h,a);

    //任务（6）
    printf("The reversed list:\n");
    reverse__output(h);
}

void test_stack(){
    Stack s ;
    init_stack(&s);

    //任务（1）
    insert_datas_to_stack(&s);

    //任务（2）
    printf("The numbers in the stack is:\n");
    output_stack(&s);
}

void test_queue(){
    Queue q;
    init_queue(&q);

    //任务（1）
    insert_datas_to_queue(&q);

    //任务（2）
    printf("The numbers in the queue is:\n");
    output_queue(&q);

    //任务（3）
    printf("The reversed numbers in the stack is:\n");
    reverse_pop_to_output_queue(&q);
}

void test_applications(){
    //任务（1）
    ListNode *h = new ListNode;
    init_and_sort_list(h);
    outputList(h);//输出查看结果

    //任务（2）
    char s[] = "((())";
    printf("parentheses: %s\n",s);
    if (judging_parentheses(s)) printf("true\n");
    else printf("false\n");
    
    //任务（3）（4）
    int maze[col][col] = {
        {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
        {1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
        {1,0,1,1,1,1,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
        {1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
    };
    all_paths_of_maze(maze,1,1,8,8);
    shortest_path_of_maze(maze,1,1,8,8);
}
int main(){
    //test_list();
    //test_stack();
    //test_queue();
    test_applications();
    system("pause");
    
}