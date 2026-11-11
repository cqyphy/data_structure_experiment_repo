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