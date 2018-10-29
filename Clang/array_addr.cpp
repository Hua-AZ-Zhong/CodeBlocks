#include <iostream>

using namespace std;

int main ()
{
    int  var1;
    char var2[6]="hello";
    long var3[10]={1,2,3,4,5,6,7,8,9,9};

    cout << "var1 address: ";
    cout << &var1 << endl;

    /** C++中输出char型数组的数组名，直接输出数组内容 **/
    /** 数组名前面加&符号，才能输出数组首地址 **/
    cout << "var2 address: ";
    cout << var2 <<" "<< &var2 << endl;

    /** C++中输出除char型数组以外的数组名，输出数组首地址，加&符号执行结果同样是地址 **/
    cout << "var3 address: ";
    cout << var3 <<" "<< &var3 << endl;

   return 0;
}
