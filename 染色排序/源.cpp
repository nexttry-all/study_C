#include<iostream>
#include<vector>
using namespace std;

void test1() {
	static int count = 0;
	count++;
	double a=static_cast<double>(count)+0.77;
	cout << count << "\n";
	cout << a;
}

//注释

int main() {

	test1();
	return 0;
}
