#include "treenode.h"
#include <stdio.h>
#define MaxSize 1000

void create_node(pBTNode &b,char data){
    b = new BTNode;
    b->val = data;
}

pBTNode seek_node(pBTNode tree_root,char data){
    if (!tree_root) return nullptr;
    else if (tree_root->val == data) return tree_root;
    else {
        pBTNode tmp = nullptr;
        tmp = seek_node(tree_root->lchild,data);
        if (tmp) return tmp;
        return seek_node(tree_root->rchild,data);
    }
}

void create_tree(pBTNode &b,char* str){
    pBTNode nodes[MaxSize],p = nullptr;
    int top = 0, l_or_r = 0;//0代表左，1代表右
    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
        case '(':
            nodes[top++] = p;
            l_or_r = 0;
            break;
        case ')':
            top--;
            break;
        case ',':
            l_or_r = 1;
            break;
        default:
            create_node(p,str[i]);
            if (!b){
                b = p;
            }
            else {
                switch (l_or_r)
                {
                case 0:
                    nodes[top-1]->lchild = p;
                    break;
                case 1:
                    nodes[top-1]->rchild = p;
                    break;
                default:
                    break;
                }
            }
            break;
        }
    }
    
}

void output_tree(pBTNode b){
    if (!b) return;
    printf("%c",b->val);
    if (b->lchild)
    {
        printf("(");
        output_tree(b->lchild);
        if (b->rchild) printf(",");
        output_tree(b->rchild);
        printf(")");
    }
    printf("\n");
}

void output_childs(pBTNode b,char data){
    pBTNode p = seek_node(b,data);
    if (p)
    {
        printf("The childs of this node is:\n");
        if (p->lchild) {
            printf("(%c",p->lchild->val);
            if (p->rchild) printf(",%c",p->rchild->val);
        }
        printf(")");
    }
}

int count_nodes(pBTNode b){
    int count_ = 0;
    if (!b) return count_;
    count_++;
    count_ += count_nodes(b->lchild);
    count_ += count_nodes(b->rchild);
    return count_;
}