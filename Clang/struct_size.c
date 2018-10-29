#include <stdio.h>

struct A{
    int a;
    char b;
};

struct B{
    int a;
    double e;
    char b;
    double d;
    char c;
} BB;

typedef struct C{
    char a;
    double b;
    char c[6];
    int e[5];
    struct B arr[3];
    int d[3];
} CC;

typedef union {
    long i;
    int k[5];
    char c;
} DATE;
struct data{
    int cat;
    DATE cow;
    double dog;
} too;

int main()
{
    printf("%d %d %d %d %d %d\n",sizeof(char),sizeof(short),sizeof(int),sizeof(long),sizeof(float),sizeof(double));
    printf("size of A is %d\n",sizeof(struct A));
    printf("size of B is %d\n",sizeof(BB));
    printf("size of C is %d\n",sizeof(CC));
    printf("size of union is %d, size of too is %d\n",sizeof(DATE),sizeof(too));
    return 0;
}
