#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define LENGTH 100000
#define SIZE 10
#define QUIT 'q'

char get_choose(void);//获取一个正确的输入菜单功能,并能处理错误的输入
char*s_gets(char*,int);//获取字符串函数
void function_a(char**,int);//实现a功能，第二个参数是输入的指针数组的长度
void function_b(char**,int);//实现b功能
void function_c(char**,int);//实现c功能
void function_d(char**,int);//实现d功能

int main(void)
{
    char menu;
    int i_count;//用于控制读取字符的循环次数的控制,同时i_count也记录了用户输入的字符串数量
    char*p_str[SIZE];//指针数组，用于存储多个字符串的地址
    char str[SIZE][LENGTH];// 用于存储输入的字符串

    printf("please enter 10 strings or if you want to stop input,please use EOF to stop:\n");
    for(i_count=0;(i_count<SIZE)&&(p_str[i_count]=s_gets(*(str+i_count),LENGTH))!=NULL;i_count++)//这里体现了c语言的逻辑表达式的一个特点，逻辑表达式从左到有执行，当遇到一个判断可以确定整个表达式的真假时便不在继续执行后边的逻辑表达式
        continue;//这里会先判断i_count是否小于SIZE，如果执行到i_count等于SIZE时，便不会再给p_str[SIZE+1]赋值，从而避免了占用未分配空间的情况，因为这种情况是未定义的
    printf("please choose a function to achieve(e to quit):\n");
    printf("a:print the source string in input order\nb:print the string by ASCII vaule's order\n");
    printf("c:print the string by length increment order\nd:print the string by that in string the length of the first word\n");
    printf("q:q to quit\n");
    while((menu=get_choose())!=QUIT){
        switch(menu){
        case 'a':function_a(p_str,i_count);
            break;
        case 'b':function_b(p_str,i_count);
            break;
        case 'c':function_c(p_str,i_count);
            break;
        case 'd':function_d(p_str,i_count);
            break;
        default:printf("very good,you found a bug that i had not found!\n");
        }
    printf("please choose a function to achieve again(e to quit):\n");
    printf("a:print the source string in input order\nb:print the string by ASCII vaule's order\n");
    printf("c:print the string by length increment order\nd:print the string by that in string the length of the first word\n");
    printf("q:q to quit\n");
    }
    puts("Done");

    getchar();
    getchar();
    return 0;
}

void function_a(char**str,int i_str_l)//打印源字符串
{
    int i_count_4;//用于控制给指针数组赋值的循环
    int i_count;
    char*p_str_a[i_str_l];//指针数组，用于存储形参中的指针，目的是为了避免打乱形参中的顺序，在这个副本中对其进行操作
    for(i_count_4=0;i_count_4<i_str_l;i_count_4++)//strcpy(p_str_a,str);将str数组中的指向各个字符串的指针赋值给p_str_a；,这里是有问题的，str为二级指针，而p_str时一级指针，并且即使*str后，还是会有指针类型不兼容的问题。而且这个指针数组本身便不能给指针数组赋值，因为strcpy()是字符串赋值函数，是对字符串进行操作的函数，暂时还是只能有for循环一次给每个元素赋值
        *(p_str_a+i_count_4)=*(str+i_count_4);
    for(i_count=0;i_count<i_str_l;i_count++)
    puts(*(p_str_a+i_count));
}

void function_b(char**str,int i_str_l)//以ASCII中的顺序打印字符串
{

    int i_count_3;//控制输出字符串的循环
    int i_count_1,i_count_2;//这两个分别用于控制外层循环和内层循环
    char*p_temp;//用于排序交换指针时，暂时存储其中的一个指针
    char*p_str_b[i_str_l];//指针数组，用于存储形参中的指针，目的是为了避免打乱形参中的顺序，在这个副本中对其进行操作
    int i_count_4;//用于控制给指针数组赋值的循环
    for(i_count_4=0;i_count_4<i_str_l;i_count_4++)//strcpy(p_str_a,str);将str数组中的指向各个字符串的指针赋值给p_str_a；,这里是有问题的，str为二级指针，而p_str时一级指针，并且即使*str后，还是会有指针类型不兼容的问题。而且这个指针数组本身便不能给指针数组赋值，因为strcpy()是字符串赋值函数，是对字符串进行操作的函数，暂时还是只能有for循环一次给每个元素赋值
        *(p_str_b+i_count_4)=*(str+i_count_4);
    for(i_count_1=0;i_count_1<i_str_l-1;i_count_1++)//排序算法   
    for(i_count_2=i_count_1+1;i_count_2<i_str_l;i_count_2++)
    if(strcmp(*(p_str_b+i_count_1),*(p_str_b+i_count_2))>0){  //char*p_temp;
        p_temp=*(p_str_b+i_count_1);                    //p_temp=*(p_str_b+i_count_1);这里好像有问题，这个p_temp指针未初始化，不知道他是指向那个位置的(其会随机指向一个位置)，这样操作可能会更改电脑进程程序的数值，是非常危险的。必须且只能解引用已经初始化的指针
        *(p_str_b+i_count_1)=*(p_str_b+i_count_2);
        *(p_str_b+i_count_2)=p_temp;
    }
    for(i_count_3=0;i_count_3<i_str_l;i_count_3++)
    puts(*(p_str_b+i_count_3));
}

void function_c(char**str,int i_str_l)//按长度递增顺序打印字符串
{
    char*p_temp;//用于排序交换指针时，暂时存储其中的一个指针
    int i_count_1,i_count_2,i_count_3;//分别控制内层，外层循环和输出打印的循环；
    char*p_str_c[i_str_l];//指针数组，用于存储形参中的指针，目的是为了避免打乱形参中的顺序，在这个副本中对其进行操作
    int i_count_4;//用于控制给指针数组赋值的循环
    for(i_count_4=0;i_count_4<i_str_l;i_count_4++)//strcpy(p_str_a,str);将str数组中的指向各个字符串的指针赋值给p_str_a；,这里是有问题的，str为二级指针，而p_str时一级指针，并且即使*str后，还是会有指针类型不兼容的问题。而且这个指针数组本身便不能给指针数组赋值，因为strcpy()是字符串赋值函数，是对字符串进行操作的函数，暂时还是只能有for循环一次给每个元素赋值
        *(p_str_c+i_count_4)=*(str+i_count_4);
    for(i_count_1=0;i_count_1<i_str_l-1;i_count_1++)//排序算法
    for(i_count_2=i_count_1+1;i_count_2<i_str_l;i_count_2++)
    if(strlen(*(p_str_c+i_count_1))>strlen(*(p_str_c+i_count_2))){
        p_temp=*(p_str_c+i_count_1);                    //p_temp=*(p_str_b+i_count_1);这里好像有问题，这个p_temp指针未初始化，不知道他是指向那个位置的(其会随机指向一个位置)，这样操作可能会更改电脑进程程序的数值，是非常危险的。必须且只能解引用已经初始化的指针
        *(p_str_c+i_count_1)=*(p_str_c+i_count_2);
        *(p_str_c+i_count_2)=p_temp;
    }
    for(i_count_3=0;i_count_3<i_str_l;i_count_3++)
    puts(*(p_str_c+i_count_3));
}

void function_d(char**str,int i_str_l)//按字符串中第一个单词的长度打印字符串
//思路，使用strchr()函数查找到每个字符串的第一个空格的指针，然后用这个这个指针减去该字符串开始的指针，就是第一个单词的字符数，然后再排序即可，或者不排序，找到第一个单词字符数较小的那个字符串后直接输出也可以，这样也就不需要输出字符串的那个循环了
{
    char*p_temp;//用于排序交换指针时，暂时存储其中的一个指针
    char*p_str_d[i_str_l];//指针数组，用于存储形参中的指针，目的是为了避免打乱形参中的顺序，在这个副本中对其进行操作
    int i_count_1,i_count_2,i_count_3;//分别控制内层，外层循环和输出打印的循环；
    int i_count_4;//用于控制给指针数组赋值的循环
    for(i_count_4=0;i_count_4<i_str_l;i_count_4++)//strcpy(p_str_a,str);将str数组中的指向各个字符串的指针赋值给p_str_a；,这里是有问题的，str为二级指针，而p_str时一级指针，并且即使*str后，还是会有指针类型不兼容的问题。而且这个指针数组本身便不能给指针数组赋值，因为strcpy()是字符串赋值函数，是对字符串进行操作的函数，暂时还是只能有for循环一次给每个元素赋值
        *(p_str_d+i_count_4)=*(str+i_count_4);
    for(i_count_1=0;i_count_1<i_str_l-1;i_count_1++)//排序算法
    for(i_count_2=i_count_1+1;i_count_2<i_str_l;i_count_2++)
    if((strchr(*(p_str_d+i_count_1),' ')-(*(p_str_d+i_count_1)))>(strchr(*(p_str_d+i_count_2),' ')-(*(p_str_d+i_count_2)))){
        p_temp=*(p_str_d+i_count_1);                    //p_temp=*(p_str_b+i_count_1);这里好像有问题，这个p_temp指针未初始化，不知道他是指向那个位置的(其会随机指向一个位置)，这样操作可能会更改电脑进程程序的数值，是非常危险的。必须且只能解引用已经初始化的指针
        *(p_str_d+i_count_1)=*(p_str_d+i_count_2);
        *(p_str_d+i_count_2)=p_temp;
    }
    for(i_count_3=0;i_count_3<i_str_l;i_count_3++)
    puts(*(p_str_d+i_count_3));
}

char get_choose(void)//获取一个正确的输入菜单功能,并能处理错误的输入
{
    char*p_invalid;//处理溢出的或无效的所有输出
    char ch;
    while(scanf("%c",&ch)!=1&&(ch<='a'||ch>='e')){//这里存在一个典型的以忽略的问题！！就是假如当你输入了a然后按下enter键后，缓冲区里有两个字符一个a，一个'\n'，第一次会读取a，然后循环该get_choose函数会返回a，但是紧接着的第二调用，该函数会直接读取缓冲区里的'\n'，不会给你输入的机会，然后执行后续操作。所以这里一定要记得处理掉后续的'\n'字符，可以用一个getchar()消化掉这个'\n'。或者直接while(getchar()!'\n') continue;处理后续字符，也同样会消化掉'\n',并且这样还会处理该行的后续输入，即只读取该行输出的第一个字符
       puts(gets(p_invalid));//这里的p_invalid未被初始化，但是我们使用他的目的是为了处理溢出或无效的所有输入，所以用gets(p_invalid)将剩余的所有输入全部存储，然后输出\n
       printf("please input a to e,and please input again(e to quit):");
    }
    while(getchar()!='\n')
    continue;
    return ch;
}

char*s_gets(char*str,int n)//基于fgets()的自定义输入字符串的函数
{
    char*p_temp;
    //char*ret_val;//用于判断fgets()是否正确读取字符串；fgets()函数在读取错误或遇到EOF时返回NULL，其他情况返回第一个字符的指针
    p_temp=fgets(str,n,stdin);
    if(p_temp){
        p_temp=strchr(str,'\n');
        if(p_temp)
        *p_temp='\0';
        else
        while(getchar()!='\n')
        continue;
        return str;
    }
    else 
    return p_temp;
}
