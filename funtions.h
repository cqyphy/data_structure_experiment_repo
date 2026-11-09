// 本文件用于声明为了实验报告内容要求的函数，每一个函数代表实验指导书中的一个任务
#pragma once
#define col 10 //迷宫的宽
#include "linklist.h"
//线性表的内容
void init_insert_datas(ListNode *h);
void outputList(ListNode *h);
int seek_list_num(ListNode *h, int num);
void insert_data(ListNode *h,int loca, int data);
void delete_node_by_val(ListNode *h,int val);
void reverse__output(ListNode *h);
//栈
void insert_datas_to_stack(Stack *s);
void output_stack(Stack *s);
//队列
void insert_datas_to_queue(Queue *q);
void output_queue(Queue *q);
void reverse_pop_to_output_queue(Queue *q);
//综合应用
void init_and_sort_list(ListNode* h);
bool judging_parentheses(char s[]);
void all_paths_of_maze(int maze[][col],int start_x,int start_y, int end_x, int end_y);
void shortest_path_of_maze(int maze[][col],int start_x,int start_y, int end_x, int end_y);