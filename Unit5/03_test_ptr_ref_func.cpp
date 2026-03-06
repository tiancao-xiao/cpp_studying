// test_ptr_ref_func.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第五章 重复代码太多 我们要分模块了
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

// 指针和引用作为参数，减少复制，不修改原变量
// 定义一个函数，参数为两个整型指针
// const int* x：const修饰指针指向的内容，不能通过*x修改原变量值（指针本身可指向其他地址）
void TestParaPtr(const int* x, const int* y)
{
    cout << "TestParaPtr " << *x << " " << *y << endl;
    cout << "指针地址：" << x << ":" << y << endl;
}

// 定义一个函数，参数为两个整型引用
// const int& x：const修饰引用绑定的变量，不能通过该引用修改原变量值（引用本身绑定后不可改绑定对象）
void TestParaRef(const int& x, const int& y)
{
    cout << "TestParaRef " << x << " " << y << endl;
    cout << "引用绑定变量的地址：" << &x << ":" << &y << endl;
}

// 指针作为参数，通过指针修改原变量，实现返回多个值
void GetPosPtr(int* x, int* y)
{
    *x = 800;  // 通过指针解引用修改原变量值
    *y = 600;
}

// 引用作为参数，通过引用修改原变量，实现返回多个值
void GetPosRef(int& x, int& y)
{
    x = 640;   // 引用是变量别名，直接修改原变量值
    y = 480;
}

// 指针作为返回值：返回静态变量的地址
// 函数返回值为int*，表示返回指向int类型的指针
int* GetPosPtrRet()  
{
    // static静态变量：仅初始化一次，生命周期贯穿整个程序，函数调用结束不销毁
    static int pos{ 0 };
    cout << "GetPosPtrRet pos: " << pos << endl;
    return &pos;  // 返回静态变量pos的地址（指针）
}

// 引用作为返回值：返回静态变量的引用
// 函数返回值为int&，表示返回int类型的引用（变量的别名）
int& GetPosRefRet()  
{
    static int pos{ 0 };
    cout << "GetPosRefRet pos: " << pos << endl;
    return pos;  // 返回静态变量pos的引用（无需加&，引用本身就是别名）
}

int main()
{
    int x{ 99 };
    cout << "初始x = " << x << endl;
    int y{ 88 };
    
    // 测试指针参数：需传入变量地址，const保证不修改原变量
    TestParaPtr(&x, &y);
    // 测试引用参数：直接传入变量，引用绑定到该变量，const保证不修改原变量
    TestParaRef(x, y);

    // 测试指针参数返回多个值：通过指针修改原变量x、y
    GetPosPtr(&x, &y);
    cout << "GetPosPtr修改后 x = " << x << ", y = " << y << endl;
    // 测试引用参数返回多个值：通过引用修改原变量x、y
    GetPosRef(x, y);
    cout << "GetPosRef修改后 x = " << x << ", y = " << y << endl;

    // 测试返回指针：获取静态变量的指针
    auto r1 = GetPosPtrRet();  // r1是int*类型，指向静态变量pos
    (*r1) += 10;               // 通过指针修改静态变量pos的值（0→10）
    cout << "r1指向的值 = " << *r1 << endl;
    GetPosPtrRet();            // 再次调用，打印pos=10（static变量不重新初始化）

    // 测试返回引用：获取静态变量的引用（注意auto&才是引用，auto是拷贝）
    auto& r2 = GetPosRefRet(); // r2是int&类型，绑定到静态变量pos
    r2 += 20;                  // 修改原静态变量pos的值（0→20）
    cout << "r2绑定的值 = " << r2 << endl;
    GetPosRefRet();            // 再次调用，打印pos=20（static变量不重新初始化）

    // r3前没有&，是拷贝，不能修改原变量的值
    auto r3 = GetPosRefRet();  // r3是int&类型，绑定到静态变量pos
    r3 += 30;                   // 修改原静态变量pos的值（20→30）
    cout << "r3绑定的值 = " << r3 << endl;
    GetPosRefRet();            // 再次调用，打印pos=30（static变量不重新初始化）

    return 0;
}