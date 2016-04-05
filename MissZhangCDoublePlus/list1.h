#ifndef _LIST_H
#define _LIST_H

struct Node;

typedef int ElementType;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;

List MakeEmptyList1(List L);

int IsEmptyList1(List L);
int IsLast1(Position Pos, List L);
Position Find1(ElementType x, List L);
void Delete1(ElementType x, List L);
void Insert1(ElementType x, List L, Position Pos);
Position FindPrevious1(ElementType x, List L);

void DeleteList1(List L);

Position Header1(List L);
Position First1(List L);
Position Advance1(List L);
ElementType Retrieve1(Position P);

 









#endif
