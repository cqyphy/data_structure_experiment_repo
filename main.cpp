#include "linklist.h"
#include "funtions.h"
#include <windows.h>
#include <stdio.h>
int main(){
    int maze[col][col] = {
        {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
        {1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
        {1,0,1,1,1,1,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
        {1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
    };
    //all_paths_of_maze(maze,1,1,8,8);
    shortest_path_of_maze(maze,1,1,8,8);
    system("pause");
    /*ListNode *h;
    createnode(h,0);
    init_insert_datas(h);
    printf("The nodes of the list is:\n");
    outputList(h);
    printf("please input the num you want to seek:");
    int a;
    scanf("%d",&a);
    seek_list_num(h,a);*/
}