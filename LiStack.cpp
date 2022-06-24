#include<iostream>
using namespace std;


typedef int ElemType;
typedef struct LiStack{
    ElemType data;
    struct LiStack* next; 
}* LiStack;

bool InitLiStack(LiStack LS){
    if(LS == NULL) return false;
    LS = (LiStack)malloc(sizeof(LiStack));
    LS->next = NULL;
    return true;
}

bool Empty(LiStack LS){
    return (LS->next == NULL);
}

bool InsertNextNode(LiStack &p, ElemType x){
    if(p == NULL) return false;
    LiStack node = (LiStack)malloc(sizeof(LiStack));
    node->data = x;
    node->next = p->next;
    p->next = node;
    return true;
}

bool Push(LiStack &LS, ElemType x){
    if(LS == NULL) return false;
    InsertNextNode(LS, x);
    return true;
}

bool DeleteNextNode(LiStack &p){
    if(p == NULL || p->next == NULL) return false;
    LiStack dele = p->next;
    p->next = dele->next;
    free(dele);
    return true;
}

bool Pop(LiStack &LS, ElemType &x){
    if(LS == NULL || LS->next == NULL) return false;
    x = LS->next->data;
    DeleteNextNode(LS);
    return true;
}

void testLiStack(){
    LiStack LS;
    InitLiStack(LS);
    Empty(LS);
    ElemType a = 1;
    Push(LS, a);
    Pop(LS, a);
}
