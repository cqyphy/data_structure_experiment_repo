#pragma once

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
