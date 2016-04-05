#include<iostream>
#define MaxDegree 100

typedef struct Node *PtrNode;

struct Node{
    int Coeffcient;
    int Exponent;
    PtrNode Next;
};
typedef  PtrNode Polynomial;

void ZeroPolynomial(Polynomial Poly);


void AddPolynomial(
                   const Polynomial Poly1,
                   const Polynomial Poly2,
                   Polynomial PolySum
                   );

void MultPolynomial(
                    const Polynomial Poly1,
                    const Polynomial Poly2,
                    Polynomial PolyProd
                    );