#include<iostream>
#include<string>
using namespace std;
struct Test {
	typedef int foo;
};

template <typename T>
void f(typename T::foo) { cout << "hello" << endl; } // Definition #1

template <typename T>
void f(T) { cout << "hello" << endl; }               // Definition #2

int main(void)
{
	f<Test>(10); // Call #1.
	f<int>(10);  // Call #2. Without error (even though there is no int::foo) thanks to SFINAE.
	system("pause");
	return 0;
}

