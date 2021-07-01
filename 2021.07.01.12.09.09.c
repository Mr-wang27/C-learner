#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>// 提供malloc，calloc，free，exit的函数原型，定义了：EXIT_FAILURE:为程序异常中止。EXIT_SUCCESS：程序普通中止
#define SIZZE_WORD 20//一个单词的长度
int main(void)
{
    int i_size;//存储需要输入的单词数
    char**PP_str;//（二级指针）存储每个单词的指针
    char temp[SIZZE_WORD];//用于暂时存储单词

    printf("please input a quantity you want to memory size:__\b\b");
    while(scanf("%d",&i_size)!=1&&i_size>=0){//输入不正确的话
        printf("your input is terrible!please input a number(>0):__\b\b");
        while(getchar()!='\n')//处理剩余的输出
        continue;
    }//截至此处，正确获取i_size
    PP_str=(char**)malloc(i_size*sizeof(char*));//前面强制类型转换为指向指针的指针，是一个指针一维数组，标记！记得后面释放调用的动态内存，避免内存泄漏
    if(PP_str==NULL){//如果内存分配失败，将返回NUKLL
        printf("memory allocation failed!goodbye!");
        exit(EXIT_FAILURE);//程序异常中止
    }//截至此处动态内存分配成功，下面部分开始设计循环分配适应的内存存储单词，并将每个单词的指针传递给pp_str；
    for(int i_count_1=0;i_count_1<i_size;i_count_1++){
        int i_size_word;// 这个变量每次执行for()循环的时候都会被重新定义一次 //存储每个单词的长度，然后加一，用加1后的数据给malloc分配内存，最后加一是为了多分配一个字节，给存储空字符
        scanf("%s",temp);
        i_size_word=strlen(temp);
        *(PP_str+i_count_1)=(char*)malloc((i_size_word+1)*sizeof(char));//pp_str一级解引用之后为指向char的指针，所以后面强制类型转换为char*，后面的加1是为了多一个字节存储空字符
        strcpy(*(PP_str+i_count_1),temp);//字符串赋值函数，这里不用担心越界问题，因为前面测试过第二个参数的长度，然后给第一个参数动态分配了刚刚狗的内存//strncpy函数的第三个参数可以指定想要赋值的位数，相对安全一些
    }//截至此处，所有的单词的指针都被存储。下面设计循环输出每个单词
    if(ispunct(*(*(PP_str+i_size-1)+strlen(*(PP_str+i_size-1))-1)))//检测最后一个单词的最后一个字符是否为标点符号，如果是就将这个标点符号改为空子符
    *(*(PP_str+i_size-1)+strlen(*(PP_str+i_size-1))-1)='\0';
    for(int i_count_2=0;i_count_2<i_size;i_count_2++){
        puts(*(PP_str+i_count_2));
    }

    getchar();
    getchar();
    return 0;

}
