#include <stdio.h>
#include <string.h>
void NONO();
int fun(char *t)
{
    while(*t!='\0' && t <= t + strlen(t) -2)
    {
        if(*t == *(t+1) - 1)
        {
            t++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char s[26];
    printf("Please input a strings contained of alpha characters:");
    gets(s);
    if(fun(s))
    {
        printf("%s is a sequenced string.\n", s);
    }
    else
    {
        printf("%s is not a sequenced string.\n", s);
    }
    /*NONO();*/
}

void NONO()
{
    FILE *fp, *wf;
    int i;
    char s[26], *p;
    fp = fopen("in.dat","r");
    wf = fopen("out.dat","w");
    for(i=0; i<10; i++)
    {
        fgets(s, 26, fp);
	p = strchr(s, '\n');
	if(p)
	{
            *p=0;
	}
	if(fun(s))
	{
            fprintf(wf, "%s\n", s+2);
	}
	else
	{
            fprintf(wf, "%s\n", s);
	}
    }
    fclose(fp);
    fclose(wf);
}
