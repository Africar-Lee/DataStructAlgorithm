#include<iostream>
using namespace std;
#define MaxNum 10

typedef int ElemType;
typedef struct{
    ElemType data[MaxNum];
    int top;
}SqStack;

void InitSqStack(SqStack &S){
    S.top = -1;
}

bool StackEmpty(SqStack S){
    return (S.top == -1);
}

bool Push(SqStack &S, ElemType x){
    if(S.top == MaxNum-1) return false;
    S.top = S.top + 1;
    S.data[S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x){
    if(StackEmpty(S)) return false;
    x = S.data[S.top];
    S.top = S.top-1;
    return true;
}

bool GetTop(SqStack S, ElemType &x){
    if(StackEmpty(S)) return false;
    x = S.data[S.top];
    return true;
}

void testStack(){
    SqStack S;
    InitStack(S);
    printf("%d", StackEmpty(S));

}