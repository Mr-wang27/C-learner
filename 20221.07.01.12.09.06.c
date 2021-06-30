#include<stdio.h>//测试随机数函数的随机性
#include<stdlib.h>//用户指定要生成的随机数数量(会检测输入是否正确且有效)，和测试次数(会检测输入是否有效且正确)，并自主输入不同的种子(该程序会检测输入的种子是否正确且有效，若无效，会请求再次输入)，每次输入种子之后会统计并输出0~10出现的次数和所有测试后的总数
#define QUIT 'q'
void repeat_int(int*,int);

int sum_count[11]={0};//内部链接的静态变量       //

int main(void)
{
    unsigned int* ui_last_seed;//记录上次的种子
    unsigned int ui_test_times;//测试次数
    unsigned int ui_seed;//种子
    int i_size;
    for(int i=0;i<11;i++)
    printf("%-8d",*(sum_count+i));
    printf("\n");
    printf("please input the quantity you want:____\b\b\b\b");
    while(scanf("%d",&i_size)!=1||i_size<0){//输入不正确的话
    //这里这个是scanf()函数和getchar()函数连用，是利用了scanf()函数的特性，如果scanf()函数没有读取到想要读取的类型的数据，就会将这个数据返回给缓冲区，然后重新请求一个输入，这是如果能让scnaf()函数中止读取就能进行getchar()函数判断是否需要退出了！
        while(getchar()!='\n')//处理改行剩余的输出
        continue;
        printf("wrong input!please input carefully correct figure:____\b\b\b\b");
    }//截至此处，已经正确读取了i_size
    int*p_array=(int*)malloc(i_size*sizeof(int));//分配动态内存，前面的强制转换类型在c中可以不写，但是建议而且最好写上，因为这样可以更加明确你的指针的类型是否匹配，而且在c++中这个强制类型转化是必须写的，为了兼容性最好写上
    if(p_array==NULL){//malloc()函数分配内存失败则会返回NULL
        puts("memory allocation failed!goodbye!");
        exit(EXIT_FAILURE);
    }//截至此处，内存分配成功，下面的部分开始获取测试次数
    printf("please input the quantity you want to test:__\b\b");
    while(scanf("%d",&ui_test_times)!=1||ui_test_times<0){//这里即使你输入负数，由于ui_tese_times是无符号整型类型，所以你即使输入负数，仍然可能会因为计算机的位操作原因，赋值给ui_test_times一个正整数(具体的位操作有点忘了，而且在C Primary Plus的第十五章有讲解)，如果想获得和前面的i_size一样的检测效果，可以将ui_test__times的类型改为int类型就好了
        while(getchar()!=1)
        continue;
        printf("wrong input!please input carefully correct figure:____\b\b\b\b");
    }//截至此处，ui_test_times获取成功
    ui_last_seed=(unsigned int*)malloc(ui_test_times*sizeof(unsigned int));
    if(ui_last_seed==NULL){
        puts("memory allocation failed!goodbye!");
        exit(EXIT_FAILURE);
    }//截至此处，分配内存成功下面开始设计循环测试
    for(int i_count_1=0;i_count_1<ui_test_times;i_count_1++){//循环开始进行测试
        int i_flag_1=1;//作为退出获取种子的循环的标志
        printf("please input the different seed every times:__\b\b");
        for(;i_flag_1;){
            //int i_flag_2=1;//作为判断获取的种子是否与之前的种子重复的判断的标志     //未被使用，可以删去
            while(scanf("%u",&ui_seed)!=1){
                while(getchar()!='\n')
                continue;
                printf("wrong input!please input carefully correct figure:____\b\b\b\b");
            }//截至此处，种子获取成功，下面开始判断种子是否与之前的不同
            for(int i_count_2=0;i_count_2<=i_count_1;i_count_2++){
                if(*(ui_last_seed+i_count_2)==ui_seed){
                    i_flag_1=1;
                    printf("the seed have already appeared,please inout another different seed:__\b\b");//因为运行到这里，前面出现的那个种子被获取之后，缓存区里剩下了一个'\n',所以这里要回归上面的循环，而上面的循环scanf()会跳过前面所有的空白，然后读取数据
                    break;//这里真的不明白为什么执行了if语句，之后还要执行后面的else语句
                    //好像明白了，虽然在执行if语句的那个循环(即是有相同的种子的那个循环)执行了i_flag_1=1;但是由于这个for循环会遍历ui_last_seed的所有数据，所以后面的种子会与这次测试获取的种子不一样，所以后面的循环还是会执行else语句，把i_flag_1赋值为1，所以会跳过获取正确种子的循环，直接把这个重复的种子也拿来用，所以正确的做法是当执行一次if语句的时候就跳出这个判断是否重复的循环，再次进入获取种子的循环
                    //或者将这个判断是否重复的循环的结束条件改为当这个种子遇到了与其一样的种子的时候就结束
                }
                else
                i_flag_1=0;//这个开关标志还有有很大作用的，主要适用于判断何时退出获取正确且有效的种子的循环的。
            }//截至此处，成功的获取到了一个与之前不同的种子
        }
        *(ui_last_seed+i_count_1)=ui_seed;//把获取成功的种子存储起来，用来判断每次获取的种子是否一致
        srand(ui_seed);//将获取的种子赋值给该种字函数
        for(int i_count_3=0;i_count_3<i_size;i_count_3++)//逗号表达式的值是其最左边表达式的值
            *(p_array+i_count_3)=rand()%11;//生成在0~10之间随机数        
        repeat_int(p_array,i_size);
    }

    printf("now we have already test the randomness of the rand function!\n");
    free(p_array);//千万不要忘记释放内存啊，第一次写这个程序的时候就忘记！！！！！
    free(ui_last_seed);//要是忘记了，可是会造成很严重的后果的！！或造成内存泄漏的后果，程序会异常中断
    getchar();
    getchar();
    return 0;
}

void repeat_int(int*p_array,int i_size)
{
    unsigned int count[11]={0};//给第一个元素赋值0，其他为赋值的元素系统均会赋值为0
    for(int i_count_1=0;i_count_1<i_size;i_count_1++){
        switch (*(p_array+i_count_1))
        {
        case 0:
            *(count)+=1;
            break;
        case 1:
            *(count+1)+=1;
            break;
        case 2:
            *(count+2)+=1;
            break;
        case 3:
            *(count+3)+=1;
            break;
        case 4:
            *(count+4)+=1;
            break;
        case 5:
            *(count+5)+=1;
            break;
        case 6:
            *(count+6)+=1;
            break;
        case 7:
            *(count+7)+=1;
            break;
        case 8:
            *(count+8)+=1;
            break;
        case 9:
            *(count+9)+=1;
            break;
        case 10:
            *(count+10)+=1;
            break;
        }
    }//出现的次数统计完毕
    for(int i_count_2=0;i_count_2<11;i_count_2++)
        *(sum_count+i_count_2)+=*(count+i_count_2);//将每次测试出现的次数做一个总和
    printf("%-8d%-8d%-8d%-8d%-8d%-8d%-8d%-8d%-8d%-8d%-8d\n",0,1,2,3,4,5,6,7,8,9,10);
    for(int i_count_3=0,i_form=0;i_count_3<11;i_count_3++){
        printf("%-8d",*(count+i_count_3));
        //i_form++;//这里其实不需要控制输出格式，因为总共就11个需要输出的数据
        //if(i_form/11==0)
        //printf("\n");
    }
    printf("\n");
    for(int i_form=0,i_count_4=0;i_count_4<11;i_count_4++){
        printf("%-8d",*(sum_count+i_count_4));
        //i_form++;//这里其实不需要控制输出格式，因为总共就11个需要输出的数据
        //if(i_form/11==0)
        //printf("\n");
    }
    printf("\n");
}
