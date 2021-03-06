#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//预定义常量
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_SIZE 100

typedef int Status;
typedef char ElemType;

// 0、线性表定义
typedef struct {
    ElemType *elem;
    int length;
} SqList;

// 1、初始化线性表
Status InitList_Sq(SqList &L) {
    L.elem = new ElemType[MAX_SIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

// 2、销毁线性表
void DestroyList(SqList &L) {
    if(L.elem) delete L.elem;
}

// 3、清空线性表
void ClearList(SqList &L) {
    L.length = 0;
}

// 4、求线性表L的长度
int GetLength(SqList &L) {
    return L.length;
}

// 5、判断线性表是否为空
int IsEmpty(SqList &L) {
    if(L.length == 0)
        return 1;
    else
        return 0;
}

// 6、顺序表取值
int GetElem(SqList &L, int i, ElemType &e) {
    if(i < 1 || i > L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}

// 7、按值查找某个元素
int LocateElem(SqList &L, ElemType e) {
    for(int i = 0; i < L.length; i++) {
        if(L.elem[i] == e) return i+1;
    }
    return 0;
}

// 8、在顺序表L的第i个位置插入元素e
Status ListInsert_sq(SqList &L, int i, ElemType e) {
    if(i < 1 || i > L.length + 1)
        return ERROR;
    if(L.length == MAX_SIZE)
        return ERROR;
    for(int j = L.length - 1; j >= i - 1; j--){
        L.elem[j+1] = L.elem[j];
    }
    L.elem[i-1] = e;
    L.length++;
    return OK;
}

// 9、将顺序表L第i位置的元素删除
Status ListDelete_sq(SqList &L, int i){
    if(i<1||i>L.length)
        return ERROR;
    for(int j = i -1;j <L.length -1; j++){
        L.elem[j] = L.elem[j+1];
    }
    L.length--;
    return OK;
}

int main(){
   char sq[11] = "abcdefghij";
    SqList L1;
    L1.elem = sq;
    L1.length = 10;

    int index;
    index = LocateElem(L1, 'j');
    cout <<index <<endl;
}

