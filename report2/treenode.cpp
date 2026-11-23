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
    pBTNode nodes[MaxSize], p = b, r = nullptr;
    int top = 0;
    bool flag = true;
    do
    {
        while (p)
        {
            nodes[top++] = p;//根节点入栈
            p = p->lchild;//向左移动
        }
        flag = true;
        r = nullptr;
        while (top != 0 && flag)//当栈不空且p是栈顶节点时
        {
            p = nodes[top-1];//取栈顶节点
            if (p->rchild == r)//如果右子树已经访问过，则直接输出根节点
            {
                top--; //退栈
                printf("%c",p->val);
                r = p;//标记已访问
            }
            else {//没有被访问过，则转到有子树，回到开头进行操作
                p = p->rchild;
                flag = false;
            }
        }
        
    } while (top > 0);
    printf("\n");
}

void create_TBTNode(pTBTNode &b,char data){
    b = new TBTNode;
    b->val = data;
}

void create_TBT(pTBTNode &b,char *str){
    pTBTNode nodes[MaxSize],p = nullptr;//用nodes和top来模拟栈
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
            create_TBTNode(p,str[i]);
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

pTBTNode pre;
void Thread(pTBTNode &b){
    if (!b) return;
    Thread(b->lchild);//线索化左子树
    if (b->lchild == nullptr)
    {
        b->lchild = pre;//左子树为空，说明已经到达树的最左端，需要连接上前驱节点
        b->lflag = 1;
    }
    if (pre->rchild == nullptr)
    {
        pre->rchild = b;//前驱节点的右子树为空，说明pre指向左子树的最右叶子节点，连接
        pre->rflag = 1;
    }
    pre = b;//pre移动
    Thread(b->rchild);
}

void create_thread(pTBTNode &b){
    pTBTNode root = new TBTNode;
    root->rchild = b;
    root->lflag = 0;root->rflag = 1;
    if (!b)//空树则直接返回空root
    {
        root->lchild = root;
    }
    else 
    {
        root->lchild = b;
        pre = root;
        Thread(b);//中序线索化二叉树
        pre->rchild = root;//线索化完成，最右端叶子节点指向root
        pre->rflag = 1;
        root->rchild = pre;
    }
    b = root;
}

void seek_pre_behind_node(pTBTNode b){
    pTBTNode p = b->lchild;
    if (p == b) {printf("Tree is empty!!");return;}//空树
    if (p->lflag == 1) printf("This root has no pre node");//根节点无左子树
    else {//有左子树
        p = p->lchild;//移动到左孩子
        while (p->rflag == 0)//如果有右孩子，则移动到右孩子，直到到达最右
        {
            p = p->rchild;
        }        
        printf("The node in the front is:%c",p->val);
    }
    p = b->lchild->rchild;//回到根节点
    if (p->rflag == 1) printf("This root has no node behind");//根节点无右子树
    else{
        p = p->rchild;//移动到右孩子
        while (p->lflag == 0)//如果有左孩子，则移动到最左端
        {
            p = p->lchild;
        }
        printf("The node at the behind is:%c",p->val);
    }
}

void count_weight(int ascII[],char *filename){
    // printf("please input the absolute path and filename of the text:");
    // scanf(" %[^\n]", filename);//获取文件绝对路径
    char str[MaxSize];
    FILE *f = fopen(filename,"r");//打开文件
    if (!f)
    {
        printf("file not found");
        return;
    }
    while (fgets(str,MaxSize,f))//读取文件中的字符串
    {
        printf("%s\n",str);//输出原文
        for (size_t i = 0; str[i] != '\0'; i++)
        {
            ascII[str[i]]++;//按ASCII码统计
        }
    }
    fclose(f);
}

void create_HTree(HTNode ht[],int times[],int &n0){
    //int times[256] = {0};//ASCII码的数量，全部置为零
    n0 = 0;
    //count_weight(times);
    int k = 0;
    for (int i = 0; i < 256; i++)//用统计出的数据创建叶子节点
    {
        if (times[i] == 0) continue;//没有出现则跳过
        ht[k].data = i;//因为直接用ASCII编址，所以data直接等于i
        ht[k++].weight = times[i];//赋予权值
        n0++;//记录ht数组的数量
    }
    printf("The sum of charaters is:%d\n",n0);//输出不同字符的个数
    for (int i = n0; i < 2*n0-2; i++)//创建父节点
    {
        int lnode = -1, rnode = -1,min1 = 32767, min2 = 32767;
        for (int j = 0; j < i-1; j++)//寻找权值最小的两个节点
        {
            if (ht[j].parent != -1) continue;//跳过有父节点的叶子
            if (ht[j].weight < min1)//双“指针”寻找最小两节点
            {
                min2 = min1;
                min1 = ht[j].weight;
                rnode = lnode;
                lnode = j;
            }
            else if (ht[j].weight < min2)
            {
                min2 = ht[j].weight;
                rnode = j;
            }
            if (min1 == 1 && min2 == 1)break;
        }
        ht[lnode].parent = i;ht[rnode].parent = i;//寻找完毕，配置节点间关系
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode; ht[i].rchild = rnode;
    }
    
}

void create_Hcode(HTNode ht[],Hcode codes[], int n0){
    for (int i = 0; i < n0; i++)
    {
        int loca = ht[i].data,f = ht[i].parent,self = i;
        Hcode tmp;
        while (f != -1)//一直找直到根节点
        {
            if (self == ht[f].lchild)
                tmp.code[tmp.start++] = 0;//是父节点的左孩子则编码为0
            else 
                tmp.code[tmp.start++] = 1;//反之则为1
            self = f;
            f = ht[f].parent;//双“指针”一起向父节点方向移动
        }
        printf("The frquency and huffman code of charater %c is: %d  ",loca,ht[i].weight);//按报告要求输出字符的哈夫曼编码
        for (int j = tmp.start-1; j >=0; j--)//因为Hcode里的数组存放顺序是倒过来的，所以倒过来输出
        {
            printf("%d",tmp.code[j]);
        }
        printf("\n");
        codes[loca] = tmp;//存入数组
    }
    
}

void compress(Hcode codes[],char *filename){
    printf("The compressed text:\n");
    FILE *res = fopen("compressed.txt","w"), *f = fopen(filename,"r");
    char tmp = fgetc(f);//从原文中得到字符
    while (tmp != '\0')
    {
        for (int i = codes[tmp].start; i >= 0; i--)
        {
            fputc(codes[tmp].code[i],res);//根据字符映射，找到相应的哈夫曼编码，写入文件
            printf("%c",codes[tmp].code[i]);//顺手输出//调试时无输出
        }        
        tmp = fgetc(f);//找下一个字符
    }
    printf("\n");
    fclose(f);fclose(res);
}