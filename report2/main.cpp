#include "treenode.h"
#include <stdio.h>
#include <windows.h>

int main(){
    pBTNode b = nullptr;
    char str[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    create_tree(b,str);
    output_tree(b);
    output_childs(b,'H');
    system("pause");
}