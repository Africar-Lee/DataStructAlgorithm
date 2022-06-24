#include"common.h"
#define MaxSize 10;
typedef struct{
    ElemType data[MaxSize];
    int front, rear;
}SqQuene;

void InitSqQuene(SqQuene &Q){
    Q.front = 0;
    Q.rear = 0;
}

bool EmptySqQuene(SqQuene Q){
    return (Q.front == Q.rear);
}

bool EnQuene(SqQuene &Q, ElemType x){
    if((Q.rear+1)%MaxSize == Q.front) return false;//队列已满的判断，若队尾指针的后一个位置等于对头指针，那就说明队列已满
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1)%MaxSize;
    return true;
}

bool DeleQuene(SqQuene &Q, ElemType &x){
    if(EmptySqQuene(Q)) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int LengthSqQuene(SqQuene Q){
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}

void testQuene(){
    SqQuene Q;
    InitSqQuene(Q);
}