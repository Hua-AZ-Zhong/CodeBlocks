#include <stdio.h>

int main()
{
    FILE *fp;
    if((fp=fopen("C:/Users/angel/Documents/CodeBlocks/C_Test_Code/file1.txt","a"))==NULL)
        // or use C:\\Users\\angel\\Documents\\CodeBlocks\\C_Test_Code\\file.txt
    {
        printf("Can not read file!\n");
    }
    else
    {
        printf("Read file successfully!\n");
        fprintf(fp,"hello world!\n");
    }
    fclose(fp);
    return 0;
}
