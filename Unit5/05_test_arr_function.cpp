// test_arr_function.cpp
/////////////////////////////////////////////////////////////////////////////
//// 第五章 重复代码太多 我们要分模块了
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

// 数组传参 → 退化为指针！彻底删除 sizeof(datas) 消除警告
int * TestBaseArr(int datas[], int size)
{
    
    cout << "TestBaseArr 内：datas 已退化为指针，无法用sizeof获取数组大小" << endl;
    cout << "TestBaseArr size = " << size << endl;

    return datas;
}

// 数组引用作为参数 → 不会退化！可以安全使用 sizeof
using ArrType = int[10];
ArrType &TestBaseArrRef(int (&datas)[10])
{
    cout << "TestBaseArrRef: 数组真实大小= " << sizeof datas << endl;
    return datas;
}

// vector 值传递（会拷贝）
vector<int> TestVector(vector<int> vdatas)
{
    cout << "===begin TestVector===\n";
    cout << "vdatas :" << vdatas.data() << endl;
    cout << vdatas.size() << endl;
    for (auto& d : vdatas)
        cout << d << " ";
    cout << endl;
    cout << "===end TestVector===\n";
    return vdatas; 
}

// vector 引用传递（无拷贝）
vector<int> TestVectorRef(vector<int> &vdatas)
{
    cout << "===begin TestVectorRef===\n";
    cout << "vdatas :" << vdatas.data() << endl;
    cout << vdatas.size() << endl;
    for (auto& d : vdatas)
        cout << d << " ";
    cout << endl;
    cout << "===end TestVectorRef===\n";
    return vdatas;
}

int main()
{
    int datas[10] = { 1,2,3,4,5 };
    cout << "main 中数组真实大小：" << sizeof datas << endl;

    TestBaseArr(datas, sizeof(datas)/sizeof(int));

    auto &re = TestBaseArrRef(datas);
    cout << "size of return " << sizeof re << endl;

    vector<int> vdatas{ 11,22,33,4,5 };
    cout << "main :" << vdatas.data() << endl;

    auto rdatas = TestVector(vdatas);
    cout << "rdatas :" << rdatas.data() << endl;

    auto mdatas = TestVector(move(vdatas));
    cout << "mdatas :" << mdatas.data() << endl;
    cout << "vdatas 被移动后大小：" << vdatas.size() << endl;

    {
        cout << "------------ref------------\n";
        vector<int> vdatas{ 11,22,33,4,5 };
        cout << "main :" << vdatas.data() << endl;
        auto mdatas = TestVectorRef(vdatas);
        cout << "mdatas :" << mdatas.data() << endl;
        cout << "vdatas :" << vdatas.size() << endl;
    }
}