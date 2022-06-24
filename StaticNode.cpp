#include<iostream>
#include<vector>
using namespace std;
#define MaxSize 20;

typedef int ElemType;

typedef struct Node{
    ElemType data;
    int next;
}SLinkList[MaxSize];

bool InitSLinkList(SLinkList &L){
    L->next = -1;
}

int GetElem(SLinkList L, int i){
    int j = 1;
    int target = L->next;
    while(j < i){
        target = L[target].next;
        ++j;
    }
    return j;
}