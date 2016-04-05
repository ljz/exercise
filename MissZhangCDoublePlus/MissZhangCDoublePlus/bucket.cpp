#include "bucket.h"

void BuckSort(int data[], int N)
{
    int M = 100;
    int A[M];
    for(int j = 0; j< M; j++)
    {
        A[j] = 0;
    }
    for(int i = 0; i< N; i++)
    {
        cout<<"原始数据是"<<data[i]<<"对应的数据为："<<A[data[i]]<<endl;
        A[data[i]] += 1;
    }


    for(int j = 0; j< M; j++)
    {
        if (A[j] == 1)
        {
            cout<<j<<endl;
        }
    }
}
