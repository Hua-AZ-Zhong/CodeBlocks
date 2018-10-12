#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    #if 0
    char a,b;
    scanf("%c%c",&a,&b);
    printf("%02X %02X\n",a,b);
    cin>>a>>b;
    printf("%02X %02X\n",a,b);
    cout<<a<<' '<<b<<endl;
    #endif

    int b=-255;
    printf("%X\n",b);
    cout<<b<<endl;
    cout<<hex<<b<<endl;
    cout<<setiosflags(ios::uppercase)<<b<<endl;
    cout<<setw(10)<<b<<','<<b<<endl;
    cout<<setfill('*')<<setw(10)<<b<<endl;
    cout<<setiosflags(ios::showpos)<<b<<endl;
    return 0;
}
