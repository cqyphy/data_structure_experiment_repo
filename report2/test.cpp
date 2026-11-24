#include "test.h"
#include "treenode.h"
#include <stdio.h>
char str[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";

void BTree_basic_algorithm(){
    pBTNode b = nullptr;
    create_tree(b,str);//创建二叉树
    output_tree(b);//输出二叉树
    output_childs(b,'H');//输出H节点的左右孩子节点
    count_nodes(b);//树节点个数
    count_leaves(b);//叶子节点个数
    count_high(b);//树高度
    //递归遍历
    recursive_preOrder(b);//前序
    recursive_inOrder(b);//中序
    recursive_postOrder(b);//后序
    //非递归
    unrecursive_preOrder(b);//前序
    unrecursive_inOrder(b);//中序
    unrecursive_postOrder(b);//后序
}

void thread_BTree(){
    pTBTNode b = nullptr;
    create_TBT(b,str);//创建线索二叉树
    create_thread(b);//线索化
    seek_pre_behind_node(b);//输出根节点的前驱和后继
}

void huffman_tree(){
    printf("please input the absolute path and filename of the text:");
    char filename[1000];
    scanf(" %[^\n]", filename);//获取文件绝对路径
    int ascII[256] = {0};//对各字符统计的数组
    count_weight(ascII,filename);//统计各字符出现的次数
    HTNode hts[1000];//哈夫曼树数组
    int n0 = 0;//叶子节点个数
    create_HTree(hts,ascII,n0);//创建哈夫曼树
    Hcode codes[1000];//储存各字符的哈夫曼编码
    create_Hcode(hts,codes,n0);//根据哈夫曼树创建编码
    char *compressed_filename = "compressed.txt";
    compress(codes,compressed_filename);//压缩到文件
    decompress(hts,compressed_filename,n0);//解压缩
}
