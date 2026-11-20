#include "treenode.h"
#include <stdio.h>
#include <algorithm>
#define MaxSize 1000

void create_node(pBTNode &b,char data){
    b = new BTNode;
    b->val = data;
}

pBTNode seek_node(pBTNode tree_root,char data){
    if (!tree_root) return nullptr;
    else if (tree_root->val == data) return tree_root;//递归出口
    else {//如果根节点不是要找的节点，则从左右子树中找
        pBTNode tmp = nullptr;
        tmp = seek_node(tree_root->lchild,data);//先找左子树
        if (tmp) return tmp;//找到则返回
        return seek_node(tree_root->rchild,data);//未找到再从右子树找
    }
}

void create_tree(pBTNode &b,char* str){
    pBTNode nodes[MaxSize],p = nullptr;//用nodes和top来模拟栈
    int top = 0, l_or_r = 0;//0代表左，1代表右
    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
        case '('://左括号则入栈
            nodes[top++] = p;
            l_or_r = 0;//表示入栈的是左孩子
            break;
        case ')':
            top--;//右括号则出栈
            break;
        case ',':
            l_or_r = 1;//逗号则表明当前根节点的左子树已创建完毕，转换为创建右子树
            break;
        default:
            create_node(p,str[i]);
            if (!b){
                b = p;
            }
            else {
                switch (l_or_r)//根据标识来划分该连到左子树还是右子树
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
    printf("%c",b->val);//输出根节点
    if (b->lchild || b->rchild)
    {
        printf("(");//有孩子，则输出括号
        output_tree(b->lchild);//输出左孩子
        if (b->rchild) printf(",");//有右孩子才输出逗号
        output_tree(b->rchild);
        printf(")");
    }
    //printf("\n");
}

void output_childs(pBTNode b,char data){
    pBTNode p = seek_node(b,data);//先找到对应的节点
    if (p)
    {
        if (p->lchild || p->rchild) {//有孩子才输出
            printf("The childs of this node is:\n(");
            if (p->lchild) printf("%c",p->lchild->val);
            if (p->rchild) printf(",%c",p->rchild->val);
            printf(")\n");
        }
        else printf("This node has no childs\n");//告知没有孩子
    }
}

int count_nodes(pBTNode b){
    if (!b) return 0;
    int count_ = 1;
    count_ += count_nodes(b->lchild);//数左子树结点数
    count_ += count_nodes(b->rchild);//数右子树结点数
    return count_;//返回总结点数
}

int count_leaves(pBTNode b){
    if (!b) return 0;//树为空，则无节点
    if (!b->lchild && !b->rchild) return 1;//无左右子树则返回1
    int count_ = 0;//有左右子树，则数左右子树的叶子
    count_ += count_leaves(b->lchild);
    count_ += count_leaves(b->rchild);
    return count_;
}

int count_high(pBTNode b){
    if (!b) return 0;//根节点为空，则高度为0
    int count_ = 1;//不为空则高度至少为1
    int l = count_high(b->lchild), r = count_high(b->rchild), tmp = l>r?l:r;//找左右子树高度，返回最大的高度
    return (count_ += tmp);
}

void recursive_preOrder(pBTNode b){
    if (!b) return;
    printf("%c",b->val);//根节点
    recursive_preOrder(b->lchild);//访问左子树
    recursive_preOrder(b->rchild);//访问右子树
}

void recursive_inOrder(pBTNode b){
    if (!b) return;
    recursive_inOrder(b->lchild);//访问左子树
    printf("%c",b->val);//根节点
    recursive_inOrder(b->rchild);//访问右子树
}

void recursive_postOrder(pBTNode b){
    if (!b) return;
    recursive_postOrder(b->lchild);//访问左子树
    recursive_postOrder(b->rchild);//访问右子树
    printf("%c",b->val);//根节点
}

void unrecursive_preOrder(const pBTNode b){
    pBTNode root = b;
    while (root)
    {
        if (root->lchild)//如果有左子树，开始行动
        {//1.寻找左子树的最右侧节点
            pBTNode mostright = root->lchild;
            while (mostright->rchild && mostright->rchild != root)
            {
                mostright = mostright->rchild;
            }
            //2.建立索引或输出
            if (mostright->rchild == root)//如果左子树的最右侧节点指向根，说明索引已建立，且左子树已完成遍历
            {
                mostright->rchild = nullptr;//断开索引
                root = root->rchild;//向右移动
            }
            else {//如果没有指向根，说明第一次经过
                printf("%c",root->val);//按照根左右顺序，访问根节点
                mostright->rchild = root;
                root = root->lchild;
            }
        }
        else {
            printf("%c",root->val);
            root = root->rchild;
        }
    }
    
}

void unrecursive_inOrder(const pBTNode b){//使用时间复杂度不变但空间复杂度更优(O(1))的Morris遍历
    pBTNode root = b;
    while (root)
    {
        if (root->lchild)//如果有左子树，开始行动
        {
            //1.寻找左子树的最右侧节点
            pBTNode most_right = root->lchild;
            while (most_right->rchild && most_right->rchild != root)
            {
                most_right = most_right->rchild;
            }
            //2.建立索引或输出
            if (most_right->rchild == root)//如果左子树的最右侧节点指向根，说明索引已建立，且左子树已完成遍历
            {
                printf("%c",root->val);//按照“左根右”顺序，输出根
                most_right->rchild = nullptr;//断开线索
                root = root->rchild;//向右移
            }
            else {//如果没有指向根，说明第一次经过
                most_right->rchild = root;//建立索引
                root = root->lchild;//向左移动
            }
        }
        else {//没有左子树，说明已到达叶节点或可能还有右子树
            printf("%c",root->val);//于是直接输出根节点
            root = root->rchild;//去右子树（若root是叶节点，那么这个节点的右孩子必定在上面环节中建立了索引，指向了父节点，相当于返回父节点）
        }
    }

}

void unrecursive_postOrder(const pBTNode b){

}
