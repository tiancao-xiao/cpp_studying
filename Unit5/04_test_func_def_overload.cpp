// test_func_def_overload.cpp
/////////////////////////////////////////////////////////////////////////////
//// 第五章 重复代码太多 我们要分模块了
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

//参数默认值 从右边开始
void TestFuncDec(int x, 
	int y = 200, 
	int z = 300)
{
	cout << "TestFuncDec "
		<< x << "," << y << ","<< z<< endl;

}
//函数声明
void Test(int x = 999);

//函数定义 如果有声明,默认参数只能在声明中定义
void Test(int x)
{
}

//重载函数，函数同名 参数不同类型或者数量
// 替换 __FUNCSIG__ 为 GCC 支持的 __PRETTY_FUNCTION__
void TestOverload(void)
{
	cout << __PRETTY_FUNCTION__ << endl;
}
void TestOverload(int x)
{
	cout << __PRETTY_FUNCTION__ << x << endl;
}
void TestOverload(float x)
{
	cout << __PRETTY_FUNCTION__ <<x<< endl;
}
void TestOverload(int x,int y)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void TestNull(int)
{
	cout << __PRETTY_FUNCTION__ << endl;
}
void TestNull(int *)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
	TestNull(123);
	int* ptr{ 0 };
	TestNull(ptr);
	// TestNull(NULL);  直接删除/注释这行（歧义根源）
	TestNull(nullptr);   //  C++11 标准空指针，无歧义

	TestOverload(1.3f);
	TestOverload((float)1.3);
	TestOverload();
	TestOverload(100);
	TestOverload(1,2);
	TestFuncDec(100);
	TestFuncDec(110,210);
	TestFuncDec(120, 220,320);
}