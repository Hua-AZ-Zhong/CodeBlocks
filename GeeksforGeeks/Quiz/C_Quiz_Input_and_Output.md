# C Quiz之Input and Output

1、Predict the output of following program?

```C
#include "stdio.h"
int main()
{
    char arr[100];
    printf("%d", scanf("%s", arr));
    /* Suppose that input value given for above scanf is "GeeksQuiz" */
    return 1;
}
```

* A、9
* B、1
* C、10
* D、100

2、Predict output of the following program

```C
#include <stdio.h> int main()
{
    printf("\\new_c_question\\by");
    printf("\\rgeeksforgeeks");
    getchar();
    return 0;
}
```

* A、ew_c_question
</br>&emsp;&nbsp; geeksforgeeks
* B、1
* C、10
* D、Depends on terminal configuration

```C
#include <stdio.h>
int main()
{
    printf(" "GEEKS %% FOR %% GEEKS"");
    getchar(); return 0;
}
```

```C
#include <stdio.h>
// Assume base address of "GeeksQuiz" to be 1000
int main()
{
    printf(5 + "GeeksQuiz");
    return 0;
}
```

Predict the output of the below program:

```C
#include <stdio.h>
int main()
{
    printf("%c ", 5["GeeksQuiz"]);
    return 0;
}
```

Predict the output of below program:

```C
#include <stdio.h>
int main()
{
    printf("%c ", "GeeksQuiz"[5]);
    return 0;
}
```
