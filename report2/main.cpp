#include "treenode.h"
#include <stdio.h>
#include <windows.h>

void test1(){
    FILE *f = fopen("G:\\data_structure\\report2\\text.txt","r");
    char str[400];
    fgets(str,400,f);
    fclose(f);
}


void test2(){
    printf("please input the absolute path and filename of the text:");
    char filename[1000];
    scanf(" %[^\n]", filename);//获取文件绝对路径
    int ascII[256] = {0};
    count_weight(ascII,filename);
    HTNode hts[1000];
    int n0 = 0;
    create_HTree(hts,ascII,n0);
    Hcode codes[1000];
    create_Hcode(hts,codes,n0);
    compress(codes,filename);
}
int main(){
    pBTNode b = nullptr;
    char str[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    //test1();
    test2();
    // create_tree(b,str);
    // output_tree(b);
    // output_childs(b,'H');
    system("pause");
}