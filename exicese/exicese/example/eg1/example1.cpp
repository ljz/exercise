#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mainhead.h"
#define MAXNUM 100

int ReadNum(int rows[])
{
    int i = 0;
    int num;
    while (i < MAXNUM && scanf("%d",&num) && num > 0 ) {
        rows[i] = num;
        i++;
    }
    if (i%2 == 1) {
        printf("必须是成对的数字，你输入的不是i＝ ：%d\n",i);
        return EXIT_FAILURE;
    }
    int ch;
    while ((ch = getchar()) && ch != EOF && ch !='\n') {//清除负数后面的那些内容,getchar()如何判断是不是会车
        printf("\n清除负数后面的那些内容%d\n",ch);
    }
    return i;
}


int Rearrange(char *output, char *input, int rows[], int len)
{
    //整型数组的长度怎么得到？
    printf("\ninput content == %s\n",input);
    int i = 0;
    int start = 0;
    int nchar;
    //    printf("%s",rows);
    for (i = 0; i < len; i += 2) {
        nchar = rows[i+1] - rows[i];
        printf("\nnchar == %d\n",nchar);
        printf("\ni == %d\n",rows[i]);
        printf("\nstart ==%d\n",start);
        strncpy(output+start, input+rows[i], nchar);//这个地方输入和输出的数组坐标不要搞错了
        printf("\noutput == %s\n",output);
        start += nchar;
    }
    //    printf("\noutput content == %s\n",output);
    return 0;
}

int Start_example1(void) {
    int rows[MAXNUM];//行号
    char input[MAXNUM];
    char output[MAXNUM];//输入输出的内容
    printf("请输入需要读入的列数据");
    int num=0;
    num = ReadNum(rows);//nnd，中文和英文的等号都不能混用
    printf("Start string you want to rearrange\n");
    while (fgets(input, MAXNUM, stdin)) {
        Rearrange(output, input, rows, num);
        printf("%s",output);
    }
    return EXIT_SUCCESS;
}


