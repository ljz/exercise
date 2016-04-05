#ifndef _LIST_H
#define _LIST_H

struct Node;

typedef int ElementType;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;

List MakeEmptyList(List L);

int IsEmptyList(List L);
int IsLast(Position Pos, List L);
Position Find(ElementType x, List L);
void Delete(ElementType x, List L);
void Insert(ElementType x, List L, Position Pos);
Position FindPrevious(ElementType x, List L);

void DeleteList(List L);

Position Header(List L);
Position First(List L);
Position Advance(List L);
ElementType Retrieve(Position P);











#endif
