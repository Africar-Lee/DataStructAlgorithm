#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode* prior, * next;
}DNode, * DLinkList;

bool InitDLinkList(DLinkList &L){
    L = (DNode*)malloc(sizeof(DNode*));
    if(L == NULL) return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

bool Empty(DLinkList L){
    return (L->next == NULL);
}

bool InsertNextDNode(DNode* p, DNode* s){
    if(p == NULL || s == NULL) return false;
    s->next = p->next;
    s->prior = p;
    if(p->next != NULL)
        p->next->prior = s;
    p->next = s;
    return true;
}

bool DeleteNextDNode(DNode* p){
    if(p == NULL || p->next == NULL) return false;
    DNode* dele = p->next;
    p->next = dele->next;
    if(dele->next != NULL)
        dele->next->prior = p;
    free(dele);
    return true;
}

bool DestroyDLinkList(DLinkList &L){
    if(L == NULL) return false;
    DNode* p = L;
    while(p->next != NULL){
        DeleteNextDNode(p);
    }
    free(p);
    return true;
}