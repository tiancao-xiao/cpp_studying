// test_ptr_ref.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第五章 重复代码太多 我们要分模块了
/////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;
int main()
{
	int x{ 10 };
	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	//int* ptr2;
	//cout << "ptr2 = " << ptr2 << endl;
	int* ptr = nullptr;  //空指针
	int* p { &x }; //变量p存储了x的地址
	cout << "============p============" << endl;
	cout <<"*p = "<< *p << endl; //*p 就是x的值
	cout << "p = " << p << endl; //p存储了x的地址
	cout << "&p = " << &p << endl; //p的地址
	(*p)++; //通过指针修改x的值
	cout << "x = " << x << endl; //x的值增加了1

    //创建了一个整型引用 ref，并将其绑定到变量 x。
    //通过这种方式，ref 可以用来直接操作 x 的值。
    //引用在需要直接修改原始变量而不希望复制变量的情况下非常有用。
	int& ref{ x };//引用必须初始化
	cout << "------ref-------" << endl;
	cout << "ref = " << ref << endl;
	cout << "&ref = " << &ref << endl; //ref的地址就是x的地址
	ref++;
	cout << "x = " << x << endl;
}
