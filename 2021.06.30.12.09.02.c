#include<stdio.h>
#include<stdlib.h>//提供malloc和calloc和free函数原型
int i_use_count;//全局变量(外部链接的今天变量)，具有文件作用的变量如果没有被赋值，那么将会被自动赋值0；
void use(void);
int main(void)
{
    int i_count;
    printf("please input the usage times you want:__\b\b");
    if(scanf("%d",&i_count))//scanf()读取错误或者遇到文件末尾会返回EOF，EOF通过宏定义在stdio.h中，EOF为0；
    for(int i=0;i<i_count;i++)
    use();

    getchar();
    getchar();
    return 0;
}

void use(void)
{
    i_use_count++;
    printf("this is %d times call the function!\n",i_use_count);
}
