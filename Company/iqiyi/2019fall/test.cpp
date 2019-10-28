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

#define sum1(a,b) a+b
template<typename c>
c sum2(c a, c b){
	return a + b;
}

int main(){
	// A *a = new C;
	// a->f1();

	// B *b = (B*)(a);
	// b->f1();

	int a = 1, b = 2;
	cout << sum1(a,b) << endl;
	cout << sum2(a, b) << endl;
	return 0;
}