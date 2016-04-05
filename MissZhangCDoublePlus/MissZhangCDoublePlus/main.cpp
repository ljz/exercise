////
////  main.cpp
////  MissZhangCDoublePlus
////
////  Created by liaojiangzheng on 16/2/26.
////  Copyright © 2016年 hitwh. All rights reserved.
////
//
////#include <iostream>
////#include "header.h"
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
////    test();
//    main_wrapped2();
//    return 0;
//}

#include <iostream>
//#include <time.h>
//#include "polynomial2.h"
#include "bucket.h"
#include "radixsort.h"
using namespace std;
//#define  size 12

int main()
{
    int A[5] = {1000,50,40000,7,3};
    int len = sizeof(A)/sizeof(A[0]);
    cout<<len<<"长度的数组进行排序结果为："<<endl;
    RadixSort(A, len);
//    BuckSort(A, len);
//    Polynomial poly1, poly2, polysum, polymult;
//    poly1 =



//    cout<<size;
//    int x;
//    float y = 3.6;
//    x = 2.9;
//    cout<<char('a' - 32)<<endl;
//    return 0;
//    x*= 2+3;
//    float z = 120.5;
////    z = 1,2,3;
//    x = (int)z;
//    x = (int)y +z;
//    cout<<z<<endl;
//
//    cout<<x<<endl;
//    return 0;
//    time_t biggest = 0x7FFFFFFF;
//    cout<<asctime(gmtime(&biggest));
//    cout<<ctime(&biggest);
//    cout<<tm;
    return 0;
}
