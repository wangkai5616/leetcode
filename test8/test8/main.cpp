#include<iostream>
#include<memory>
using namespace std;
struct Node
{
	Node(int value)
		:_value(value)
	{
		cout << "Node()" << endl;
	}
	~Node()
	{
		cout << "~Node()" << endl;
	}
	shared_ptr<Node> _prev;
	shared_ptr<Node> _next;
	int _value;
};
void Test2()
{
	shared_ptr<Node> sp1(new Node(1));
	shared_ptr<Node> sp2(new Node(2));
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	sp1->_next = sp2;
	sp2->_prev = sp1;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}

int main()
{
	Test2();
	system("pause");
	return 0;
}





