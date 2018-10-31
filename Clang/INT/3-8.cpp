#include <string>
#include <iostream>
using namespace std;

class Number
{
	public:
		string type;
		// 以下三行为初始化列表
		Number():type("void") {}
		explicit Number(short):type("short") {}
		Number(int):type("int") {}
};

void Show(const Number &n)
{
	cout << n.type << endl;
}

void f()
{
	short s=42 ;
	Show(s) ;
}

int main()
{
	f() ;
}
