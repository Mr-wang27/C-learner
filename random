#include<stdio.h>
#include<stdlib.h>//提供int rand(void),void srand(unsigned int seed)函数原型，和malloc和calloc和free函数原型
#include<time.h>//提供time()函数原型

void circle(int *);

int main(void)
{
    int guess;
    int random;//随机数
    srand((unsigned int)time(0));//在调用rand函数前种植种子，time()函数的返回值是size_t类型，而srand函数的参数是unsigned int类型，所以前面用强制类型转换。time()函数接受的是一个指针，系统的时间就会存储在这个指针的位置上，当然也可以传递一个空指针(0),此时仅仅表示返回系统的时间，并不会存储其值
    random=rand()%7;//这里对rand函数做求模运算是为了限制获得的随机数的范围，这样会使随机数的范围限制在0~(7-1)=6内
    if(scanf("%d",&guess)==1){
    while(guess!=random)
    circle(&guess);
    printf("you must have looked up the operation instration!\n");
    }
    else{
        printf("as your terrible input,the program was force to stop now!\n");
        exit(EXIT_FAILURE);//这个exit()定义在sttdlib.h里，通常exit()是用于和malloc或者calloc分配内存失败的时候使用的，用于终止程序。其中的内容有：EXIT_FAILURE表示程序异常终止，EXIT_SUCCESS(相当于0)表示普通的程序中止。这两个东西也同样是被定义在stdlib.h中
    }//用于这里使用了exit(EXIT_FAILURE)，是程序异常终止，所以程序运行到这行代码的时候就会停止，不会再往后运行，所以黑框框会立马消失，所以看不到(没有时间，来不及看，但是它确实输出了)上面的那行printf输出
    getchar();
    getchar();
    return 0;
}

void circle(int * p_guess)
{
    printf("bad luckly,your guess is flase,please guess again\n");
    scanf("%d",p_guess);
}
