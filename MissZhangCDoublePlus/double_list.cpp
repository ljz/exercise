

#include <iostream>
#include "double_list.h"
using namespace std;
struct Node
{
    ElementType Element;
    Position Next;
    Position Previous;
};

int IsEmptyList(List L)
{
    //  我自己的写法
    //    if(L->Next == NULL)
    //        return true;
    //    return false;
    //书上的写法
    return L->Next == NULL;

}

int IsLast(Position P, List L)
{
//我的写法
//    if (P->Next == NULL)
//        return true;
//    return false;
//书上的写法
    return P->Next == NULL;
}


Position Find(ElementType x, List L)
{
//    Position P;
//    P = L->Next;
//    while(P->Next != NULL && P->Element != x)
//        P = P->Next;
//    return P;
    //我的写法
    //    while(x != L->Element)//⚠️这里应该有一个表头，所以应该不能直接用头来做，应该从下一个开始。
    //    {        L = L->Next;
    //    }
    //    if (L->Next == NULL)
    //        pos = -1;
    //    return pos;

    //书上的写法
    Position Pos;
    Pos = L->Next;
    while(Pos->Next != NULL && Pos->Element != x)
    {
        Pos = Pos->Next;
    }
    return Pos;
}


void Delete(ElementType x, List L)
{
    Position Pre, TmpCell;
    Pre = FindPrevious(x, L);


    if(! IsLast(Pre, L))
    {
        TmpCell = Pre->Next;
        Pre->Next = TmpCell->Next;

        TmpCell->Next->Previous = Pre;

        free(TmpCell);
    }
}



Position FindPrevious(ElementType x, List L)
{
    //我的写法
    //    Position Pre, P;
    //    Pre = L;
    //    P = Pre->Next;
    //
    //    while(P && P->Element != x )
    //    {
    //        Pre = Pre->Next;
    //        P = Pre->Next;
    //    }
    //    if (P != NULL)
    //        return P;
    //    return NULL;
    //书上的写法
    Position P;
    P = L->Next;
    while(P->Next != NULL && P->Next->Element != x)
        P = P->Next;
    return P;
    //我觉得这样有问题，如果x不存在于链表中怎么办？这时候就会返回链表的最后一个节点，这样是不正确的。
    //从上述使用的地方来看，是先用FindPrevious()之后，再判断是否是最后一个节点，所以这里不应该返回－1，而是应该返回最后一个节点，所以我的顾虑是多余的，书上的写法是没有问题的，而且如果是返回空的话，其他地方判断除了判断是否是最后一个节点以外还要判断是否是空节点。这样反而多余，所以如果不存在的话还不如直接返回最后一个节点来的方便。
}


void Insert(ElementType x, List L, Position P)
{
    Position tempCell;//考点0
    //声明这个变量并不会创建该结构，而是声明一个指向一个结构的指针（即给出足够的空间容纳结构可能会使用的地址。）
    tempCell = (Position)malloc(sizeof(struct Node));//考点1
    if(tempCell == NULL)//考点2
        cout<<"分配内存失败";
    //        FatalError("Out of space!!!");
    else
    {
        tempCell->Element = x;//考点2
        tempCell->Next = P->Next;//考点3
        P->Next = tempCell;//考点4，
    }
}



void DeleteList(List L)
{
    Position P;
    Position tempCell;
    P = L->Next;//这一行丢失就会出现P未定义，即指向不可用的内存，

    while( P->Next != NULL)
    {
        tempCell = P;
        P = P->Next;
        free(tempCell);
        
    }
    
}


