#include <iostream>
#include "radixsort.h"
#include <math.h>
using namespace std;

int GetLong(int n)
{
    int k = 0;
    while(n != 0)
    {
        n = n/10;
        k++;
    }
    return k;
}

//这是数组的实现，不是链表的实现方式。
void RadixSort(int A[], int len)
{
    int sortTimes = 0;
    int tmpLong = 0;
    for (int i = 0; i< len; i++)
    {
        tmpLong = GetLong(A[i]);
        if (sortTimes < tmpLong)
            sortTimes = tmpLong;
    }
    cout<<"需要排序的次数是 ："<<sortTimes<<endl;
    int Count[len+10];
    //j:表示对哪个位进行排序（个位，十位，百位等等）
    for (int j = 0; j < sortTimes; j++)
    {
        //这里是对Count数组进行一个初始化，防止其中一个位排序之后对后面的排序造成干扰
        for (int i = 0; i< len+10; i++)
        {
            Count[i] = -1;
        }

        cout<<"第"<<j+1<<"次排序"<<endl;
        //对一个位进行排序。
        for (int i = 0; i< 9; i++)//i表示的是某个位上的数字
        {
            cout<<"找数字是i＝"<<i<<"的元素"<<endl;
            //循环一次，找到所有对应位是i的元素
            for (int k = 0; k<len; k++)
            {
                int tmp;//tmp表示Count的下表
                int m = pow(10, j);
                tmp = (A[k]/m)%(10);

                if (tmp == i)
                {
                    cout<<"找到了,k="<<k<<",对应的A［k］="<<A[k]<<endl;
                    while (Count[tmp] != -1 and tmp <(len*2))
                    {
                        tmp++;
                    }
                    Count[tmp] = A[k];
                }
            }
        }
        //第j次排序的结果是
//        cout<<j+1<<"次排序的结果是"<<endl;
//        for (int k=0; k < len*2; k++) {
//            if (Count[k]!=-1)
//                cout<<Count[k]<<endl;
//        }

        //将Count的内容写到A数组中
        for(int i = 0; i< len; i++)
        {
            for (int j = i; j < 2*len; j++) {
                if (Count[j] != -1)
                {
                    A[i] = Count[j];
                    break;
                }
            }
        }


    }

    cout<<"排序后的顺序是:"<<endl;
    for (int i = 0; i < len+10; i++) {
        if (Count[i] != -1)
            cout<<Count[i]<<endl;
    }
}