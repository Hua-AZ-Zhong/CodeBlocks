#include <stdio.h>
#include <string.h>

//介绍常量指针和指向常量的指针
int main()
{
    char array_A[10]={0};
    char array_B[20];
    char * const point_A = array_A;   //常量指针，指针变量的值不可以修改，指向的内容可以修改
    memcpy(point_A,"hello",5);
    puts(point_A);
    printf("add A is %p, point A is %p\n", array_A, point_A);
    int num1=1;
    int num2=2;
    const int *point_NUM = &num1;
    //指向常量的指针，指针变量的值可以修改，但是指向的内容不可以修改，指向的内容可以通过自身变量名赋值，但不可以通过指针变量名称赋值
    num1=3;
    point_NUM = &num2;
    num2 = 4;
    printf("%d %d\n",num1,*point_NUM);

    int const * const pb = &num2;  //指向常量的常量指针，均不可修改
    printf("double const *pb is %d\n", *pb);
    //pb = &num1;
    //*pb=num1;
    return 0;
}
