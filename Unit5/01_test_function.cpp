// test_function.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第五章 重复代码太多 我们要分模块了
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
//函数定义
//返回值类型 函数名(形参类型 变量名，。。。){函数代码块}
bool View(int index)
{
	if (index < 0)
		return false;
	cout << "call View(" << index << ")" << endl;
	return true;
}
//函数的参数 0 到多个 
void TestVoid(void)
{
	return; //终止函数的运行
}

auto GetPosX()
{
	return 1.3;
}

void SetSize(int w, int h)
{
	w += 1;
	cout << w << ":" << h << endl;
	cout << (long long)&w << ":"
		<< (long long)&h << endl;
}
//全局变量 进入main函数前申请空间
int gcount = 0;


//静态全局变量 作用域仅限本文件
static int scount = 0;


int TestVer(int x, int y) //局部变量
{
	int tmp = x + y;
	//局部静态变量第一次运行此代码申请空间
	//声明周期 
	// C++11 之前线程不安全 之后安全
	static int count = 0;
	gcount++;//可以访问全局变量
	scount++;
	count++;
	cout << "gcount = " << gcount << endl;
	cout << "scount = " << scount << endl;
	cout << "count = " << count << endl;
	return tmp; //返回值 局部变量
}

int main()
{
	
	auto re = View(1024); //函数内部的打印也会执行
	cout << re << endl;
	int w = 1920;
	int h = 1080;
	cout << (long long)&w << ":" 
		<< (long long)&h << endl;
	SetSize(w, h);
	cout << "w=" << w << " h=" << h << endl;
	auto x = GetPosX();
    cout << "x = " << x << endl;

	{
		TestVer(100, 200);
		TestVer(200, 300);
		auto re = TestVer(300, 400);
		cout << "re = " << re << endl;
	}

	return 0;
}