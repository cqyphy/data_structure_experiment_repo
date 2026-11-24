#pragma once
#define MaxSize 1000

typedef struct node
{
    char val;
    struct node *lchild = nullptr;
    struct node *rchild = nullptr;
}BTNode, *pBTNode;

void create_node(pBTNode &b,char data);
pBTNode seek_node(pBTNode tree_root,char data);

void create_tree(pBTNode &b,char* str);
void output_tree(pBTNode b);
void output_childs(pBTNode b,char data);
int count_nodes(pBTNode b);
int count_leaves(pBTNode b);
int count_high(pBTNode b);
//递归遍历
void recursive_preOrder(pBTNode b);
void recursive_inOrder(pBTNode b);
void recursive_postOrder(pBTNode b);
//非递归遍历
void unrecursive_preOrder(const pBTNode b);
void unrecursive_inOrder(const pBTNode b);
void unrecursive_postOrder(const pBTNode b);

//线索二叉树
typedef struct node2
{
    char val;
    int lflag = 0, rflag = 0;
    struct node2 *lchild = nullptr;
    struct node2 *rchild = nullptr;
}TBTNode, *pTBTNode;

void create_TBTNode(pTBTNode &b,char data);
void create_TBT(pTBTNode &b,char *str);
void Thread(pTBTNode &b);
void create_thread(pTBTNode &b);
void seek_pre_behind_node(pTBTNode b);

//哈夫曼树
typedef struct 
{
    char data;
    int weight;
    int parent = -1;
    int lchild = -1;
    int rchild = -1;
}HTNode;

typedef struct 
{
    char code[MaxSize];
    int start = 0;
}Hcode;

void count_weight(int ascII[],char *filename);
void create_HTree(HTNode ht[],int times[],int &n0);
void create_Hcode(HTNode ht[],Hcode codes[], int n0);
void compress(Hcode codes[],char *filename);
void decompress(HTNode ht[],char *filename,int n0);