#include<stdio.h>//the functon：用户每次输入想要生成的随机数的数量，然后对生成的随机数进行排序并输出，排序指针，保留原顺序
#include<ctype.h>
#include<time.h>//提供time() 函数，返回系统此时的时间
#include<stdlib.h>    //提供动态分配内存函数，还提供的定义了exit；还提供了随机数相关的函数
#define QUIT 'q'
int**order_int(int*,int);
int main(void)
{
    int ** pp_ordered;//用来存储已经排序好了的指针
    int i_size;
    printf("please input the quantity you want(q to quit)__\b\b");
    while(scanf("%d",&i_size)!=1&&getchar()!=QUIT){//判断输入是否正确，如果输入不正确，将执行这个while循环处理错误的输入，并提示重新输入
        while(getchar()!='\n')
        continue;
        printf("wrong input!please input carefully a correct figure again(q t oquit):__\b\b");
    }//截至此时，正确的读取了i_size
    int*p_array=(int*) malloc(i_size*sizeof(int));//mallco()函数返回分配的内存的首地址，最好且必要使用前面的强制类型转换把malloc返回的地址转换为匹配的指针类型。如果分配失败会返回NULL
    if(p_array==NULL){//如果分配失败
        puts("memory allocation failed,goodbye!");
        exit(EXIT_FAILURE);//程序异常中止
    }
    srand((unsigned int)time(0));//提供种子，time()前面的强制类型转换是因为time()返回的是time_t类型，而srand接受的参数是unsigned int类型。此处time(0),相当于给time传递的是空指针
    puts("the random is :\n");
    for(int i=0,i_form=0;i<i_size;i++){//注意这里每个变量的作用域，如果要在for()循环内定义一个数据的话，每次进行for()循环的时候都会对这个数据进行定义，所以一定要注意时都需要每次更新这个数据！！小心一点。可以定义在for()循环的条件括号内，这样每次进行循环的时候不会更新这个数据，但是还有一个注意点就是如果在for循环的条件括号里定义了一个变量后，然后又在for循环的块里定义一个同名变量，那么在这个块中，就会隐藏括号条件中的这个同名变量的定义。
        *(p_array+i)=rand()%11;//调用伪随机数函数，并限定产生的随机数范围在0~10
        printf("%-8d",*(p_array+i));
        i_form++;
        if(i_form%10==0)
        printf("\n");
    }
    printf("\n");
    pp_ordered=order_int(p_array,i_size);
    printf("\nnow we have ordered these random in more to less order\n");

    free(p_array);//前面调用了一块动态分配的内存，后面必须释放掉，否则在多次运行该程序后可能造成内存泄漏的事故
    free(pp_ordered);//动态分配的内存的生存期为malloc或calloc分配开始到free释放为止，可以在一个函数中分配，然后在另一个函数中释放，即使退出了那个函数的块，这块内存任然存在
    getchar();
    getchar();
    return 0;
}

int**order_int(int * p_int_arr,int i_size)//p_int_arr为一级指针
{//排序算法
    int**pp_ordered;
    int * p_temp;
    pp_ordered=(int**)malloc(i_size*sizeof(int*));//动态分配一个存储指向int的指针的指针(储存的是指针)
    if(pp_ordered==NULL)//如果malloc分配失败，会返回NULL
    {
        puts("memory allocation failed,goodbye!");
        exit(EXIT_FAILURE);//EXIT_FAILURE表示程序异常中止，EXIT_SUCCESS表示程序正常中止相当于0.
    }
    for(int i_count=0;i_count<i_size;i_count++)//将存储源随机数的数组顺序地址赋值给这个指针数组
        *(pp_ordered+i_count)=(p_int_arr+i_count);
    for(int i_count_1=0;i_count_1<i_size;i_count_1++)//遍历所有数组元素
    for(int i_count_2=i_count_1+1;i_count_2<i_size;i_count_2++){//内层排序循环，将第一层中的元素与其后面的每一个元素作比较
        if(**(pp_ordered+i_count_1)<**(pp_ordered+i_count_2)){
            p_temp=*(pp_ordered+i_count_1);
            *(pp_ordered+i_count_1)=*(pp_ordered+i_count_2);
            *(pp_ordered+i_count_2)=p_temp;
        }
    }
    for(int i_count=0,i_form=0;i_count<i_size;i_count++){
        printf("%-8d",**(pp_ordered+i_count));
        i_form++;
        if(i_form%10==0)
        printf("\n");
    }

    return pp_ordered;
}
