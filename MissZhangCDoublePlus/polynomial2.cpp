#include "polynomial2.h"
#include <iostream>
using namespace std;

void ZeroPolynomial(Polynomial Poly)
{
    //
    for(int i = 0; i <MaxDegree+1; i++)
    {
        Poly->Coeffcient = 0;
        Poly->Exponent = 0;
        Poly->Next = nullptr;
    }
}



void AddPolynomial(
                   const Polynomial Poly1,
                   const Polynomial Poly2,
                   Polynomial PolySum
                   )
{
    ZeroPolynomial(PolySum);
    Polynomial TmpCell1 = Poly1->Next, TmpCell2 = Poly2->Next;

    Polynomial TmpCell, Port;
    Port = PolySum;

    while(! (TmpCell1->Next == nullptr && TmpCell2->Next == nullptr))
    {
        TmpCell = (Polynomial)malloc(sizeof(Polynomial));

        if (TmpCell1->Exponent < TmpCell2->Exponent){
            TmpCell ->Coeffcient = TmpCell1->Coeffcient;
            TmpCell->Exponent = TmpCell1->Exponent;        }
        else if (TmpCell1->Exponent > TmpCell2->Exponent){
            TmpCell ->Coeffcient = TmpCell2->Coeffcient;
            TmpCell->Exponent = TmpCell2->Exponent;
        }
        else{
            TmpCell ->Coeffcient = TmpCell1->Coeffcient + TmpCell2->Coeffcient;
            TmpCell->Exponent = TmpCell1->Exponent;
        }

        Port->Next = TmpCell1;
        Port = Port->Next;
    }
    Port->Next = nullptr;
}

void MultPolynomial
(
 const Polynomial Poly1,
 const Polynomial Poly2,
 Polynomial PolyProd
 )
{
    ZeroPolynomial(PolyProd);//这里是容易漏掉的，一定要记住这一步。

    Polynomial TmpCell1 = Poly1->Next, TmpCell2 = Poly2->Next;

    Polynomial TmpCell, Port;
    Port = PolyProd;

    while(! (TmpCell1->Next == nullptr)){
        while(!(TmpCell2->Next == nullptr))
        {
            TmpCell = (Polynomial)malloc(sizeof(Polynomial));
            TmpCell->Exponent = TmpCell1->Exponent + TmpCell2->Exponent;
            TmpCell->Coeffcient = TmpCell1->Coeffcient*TmpCell2->Coeffcient;
            Port->Next = TmpCell;
            Port = Port->Next;
        }
    }
    Port->Next = nullptr;

    //合并同类项
    Port = PolyProd;
    while(Port->Next != nullptr)
    {
        TmpCell = Port->Next;
        while(TmpCell != nullptr)
        {
            if (TmpCell->Exponent == Port->Exponent)
                Port->Coeffcient += TmpCell->Coeffcient;
            TmpCell = TmpCell->Next;
        }
    }
}
