#include "polynomial.h"
#include <iostream>
using namespace std;

void ZeroPolynomial(Polynomial Poly)
{
    //
    for(int i = 0; i <MaxDegree+1; i++)
    {
        Poly->CoeffArray[i] = 0;
    }
}

void AddPolynomial(
                   const Polynomial Poly1,
                   const Polynomial Poly2,
                   Polynomial PolySum
                   )
{
    ZeroPolynomial(PolySum);
    PolySum->HighPower = Poly1->HighPower > Poly2->HighPower?Poly1->HighPower:Poly2->HighPower;
    //这里不需要判断最高位是否超出范围，因为这个不是这里应该考虑的。如果超出，那说明传入的数据本来就有问题，与Add无关。


    for(int i = 0; i< PolySum->HighPower; i++)
    {
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
    }
}

void MultPolynomial
(
 const Polynomial Poly1,
 const Polynomial Poly2,
 Polynomial PolyProd
 )
{
    ZeroPolynomial(PolyProd);//这里是容易漏掉的，一定要记住这一步。
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
    //这里必须要考虑是否Exceeded array size,自己思考。
    if (PolyProd->HighPower > MaxDegree)
    {
        cout<<"Exceeded array size";
    }
    for(int i = 0; i < Poly1->HighPower; i++)
    {
        for (int j = 0; j < Poly2->HighPower; j++)
        {
            PolyProd->CoeffArray[i+j] = Poly1->CoeffArray[i]*Poly2->CoeffArray[j];
        }
    }
}
