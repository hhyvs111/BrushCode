#include<bits/stdc++.h>
using namespace std;
class A
{
public:

	virtual void f1() {
		cout << "this is A" << endl;
	}	
};

class B
{
public:

	virtual void f1(){
		cout << "this is B" << endl;
	}
};

class C : public A, public B
{
public:
	void f1() {
		cout << "this is AC" << endl;
	}

	void f2(){
		cout << "this is BC" << endl;
	}
	
};

int main(){
	A *a = new C;
	a->f1();

	B *b = (B*)(a);
	b->f1();
	return 0;
}