#include <stdio.h>
#include <stdlib.h>

/** 快速排序算法，指定第四个参数，用于自定义的函数 **/
long compare(long *a, long *b)
{
    return (*a-*b);
}

int main()
{
    long arr[4];
    printf("Please input four numbers: ");
    scanf("%ld %ld %ld %ld", arr, arr+1, arr+2, arr+3);
    
    printf("Before qsort: %ld %ld %ld %ld\n", *arr,*(arr+1),*(arr+2),*(arr+3));
    qsort(arr,4,sizeof(arr[0]),compare);
    printf("After  qsort: %ld %ld %ld %ld\n", *arr,*(arr+1),*(arr+2),*(arr+3));
    
    long avg = (arr[1]+arr[2])/2;
    long CNY = 0;
    for(int i=0;i<4;i++)
    {
        CNY+=labs(avg - arr[i]);
    }
    
    printf("CNY = %ld\n", CNY);
    return 0;
}
