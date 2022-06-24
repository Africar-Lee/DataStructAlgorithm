#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode, *LinkList;

bool InitList(LinkList &L){
    L = (LNode*)malloc(sizeof(LNode*));
    if(L == NULL)
        return false;
    L->next = NULL;
    return true;
}

bool Empty(LinkList L){
    return (L->next == NULL);
}


LNode* GetElem(LinkList L, int i){//按位查找
    if(i < 0) return NULL;
    LNode* p = L;
    int j = 0;
    while(p != NULL && j < i){
        ++j;
        p = p->next;
    }
    return p;
}

LNode* LocateElem(LinkList L, ElemType elem){//按值查找
    LNode* p = L->next;
    while(p != NULL && p->data != elem)
        p = p->next;
    return p;
}

int Length(LinkList L){//获取链表长度（头节点不计算在内）
    int length = 0;
    LNode* p = L;
    while(p->next != NULL){
        p = p->next;
        ++length;
    }
    return length;
}



bool InsertNextNode(LNode* p, ElemType elem){
    if(p == NULL) return false;
    LNode* node = (LNode*)malloc(sizeof(LNode*));
    if(node == NULL) return false;//memory lack
    node->data = elem;
    node->next = p->next;
    p->next = node;
    return true;
}

bool InsertPriorNode(LNode*p, ElemType elem){
    if(p == NULL) return false;
    InsertNextNode(p, p->data);
    p->data = elem;
    return true;
}

bool ListInsert(LinkList &L, int i, ElemType elem){
    if(i < 0) return false;//assert valid i
    
    LNode* pre = GetElem(L, i-1);

    InsertNextNode(pre, elem);
    return true;
}


ElemType DeleteNextNode(LNode* p, ElemType elem){
    if(p == NULL || p->next == NULL) return false;
    LNode* dele = p->next;
    p->next = dele->next;
    elem = dele->data;
    free(dele);
    return elem;
}

ElemType ListDelete(LinkList &L, int i, ElemType elem){
    if(i < 0) return false;
    LNode* pre = GetElem(L, i-1);
    elem = DeleteNextNode(pre, elem);
    return elem;
}

ElemType DeleteNode(LNode* p, ElemType elem){//when Node p is the last node, it goes error
    if(p == NULL) return false;
    LNode* dele = p->next;
    p->next = dele->next;
    p->data = dele->data;
    free(dele);
    return true;
}


LinkList List_TailInsert(LinkList &L){//后插建立链表
    int x;              //假设了ElemType是int类型
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;   //r为表尾指针
    scanf("%d", &x);
    while(x != 9999){   //输入9999作为结束
        s = (LNode*)malloc(sizeof(LNode*));
        s->data = x;
        r->next = s;
        r = s;          //r指向新的表尾节点
        scanf("%d", &x);
    }
    r->next = NULL;     //尾节点指针置空
    return L;
}

LinkList List_HeadInsert(LinkList &L){//头插法建立单链表
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while(x != 9999){
        LNode* s = (LNode*)malloc(sizeof(LNode*));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList ReverseList(LinkList &L){
    if(L == NULL || L->next == NULL || L->next->next ==NULL) return NULL;
    LNode* pre = L->next;
    LNode* node = pre->next;
    LNode* n = node->next;
    while(n != NULL){
        pre->next = n;
        node->next = L->next;
        L->next = node;
        node = n;
        n = n->next;
    }
    pre->next = NULL;
    node->next = L->next;
    L->next = node;
    return L;
}


int main(){
    LinkList L = (LNode*)malloc(sizeof(LNode*));
    List_TailInsert(L);
    LNode* p = L->next;
    while(p != NULL){
        cout << p->data << "  ";
        p = p->next;
    }

    printf("\n\n");
    
    ReverseList(L);
    p = L->next;
    while(p != NULL){
        cout << p->data << "  ";
        p = p->next;
    }

    printf("\n");

    return 0;
}

