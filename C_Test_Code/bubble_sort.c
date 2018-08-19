#include <stdio.h>

/** 重新学习冒泡排序 **/
/** 每一次外层循环完成后，最大的数已排列在最末尾，所以内层循环的次数越来越少 **/
/** 通过设置flag，如果某次内外循环完成后，没有执行数据交换，则退出循环 **/
void bubble_sort(int *array, int number);

int main()
{
    int num[10]={0,2,1,8,7,6,5,3,4,9};
    printf("Before sorting, the array is ");
    for(int i=0;i<10;i++)
    {
        printf("%5d", num[i]);
    }
    printf("\n");
    bubble_sort(num,10);
    printf("After sorting, the array is  ");
    for(int i=0;i<10;i++)
    {
        printf("%5d", num[i]);
    }
    printf("\n");
    return 0;
}

void bubble_sort(int *array, int number)
{
    int out_loop=0;     /** 外层循环，循环次数为待排序的数据量减一 **/
    int inner_loop=0;   /** 内层循环，每一次的循环次数为待排序的数据量减一再减去当前外层循环计数 **/
    int flag=0;         /** 是否有数据交换的标识，用于提前结束循环，节约时间开销 **/

    for(out_loop=0;out_loop<number - 1; out_loop++)
    {
        flag=0;  /** 外层循环开始时，初始化flag值 **/
        for(inner_loop=0;inner_loop<number - 1 - out_loop;inner_loop++)
        {
            //printf("out_loop is %d, inner_loop is %d\n", out_loop, inner_loop);
            if(*(array+inner_loop)>*(array+inner_loop+1))
            {
                //printf("Swap is executed\n");
                *(array+inner_loop) = *(array+inner_loop) + *(array+inner_loop+1);
                *(array+inner_loop+1) = *(array+inner_loop) - *(array+inner_loop+1);
                *(array+inner_loop) = *(array+inner_loop) - *(array+inner_loop+1);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("No data exchanged, out_loop execute number is [%d]\n", out_loop+1);
            break;
        }
    }
}
