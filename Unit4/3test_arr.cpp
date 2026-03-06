// test_arr.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第四章批量处理任务开始了
/////////////////////////////////////////////////////////////////////////////



#include <iostream>
using namespace std;

int main()
{
	//栈区数组
	{
		//类型 变量名[数组数量]
		int arr1[4]{ 0 }; // 4个元素的数组，每个元素初始化为0

		//c++11 for循环遍历
		for (int a : arr1) //遍历数组，语法是：for (类型 变量 : 数组名)
			cout << a << " ";
		cout << endl;

		arr1[0] = 99; //下标从0
		arr1[2] = 88;
		for (int a : arr1)
			cout << a << " ";
		cout << endl;
		cout << "sizeof(arr1) = " << sizeof(arr1) << endl;
		for (int i = 0; i < sizeof(arr1)/sizeof(int);i++)
		{
			cout << arr1[i] << ",";
		}
		cout << endl;


		int arr2[4]; //未初始化 值不确定
		//c++11 for循环遍历
		for (int a : arr2)
			cout << a << " ";
		cout << endl;

		//栈区数组空间只能用编译时常量
		int size = 5;
		const int csize = 5; // const 变量， 编译时常量， 作用是防止修改变量值
		const int csize2 = size; //运行时常量
		constexpr int cesize = 5; // constexpr 变量， 编译时常量， 作用是防止修改变量值
		int arr3[csize];
		int arr4[cesize];

		//数组的初始化
		int arr5[10] = { 1,2,3,4,5 }; // 10个元素的数组，初始化为1,2,3,4,5， 后面的元素用0填充
		int arr6[] = { 3,4,5,6,7,8 }; // 自动计算元素数量， 等价于int arr6[6] = { 3,4,5,6,7,8 };
		char arr7[] = "test string"; // 自动计算元素数量， 等价于char arr7[11] = "test string";
		cout << "sizeof(arr6) = " << sizeof(arr6) << endl;
		cout << "sizeof(arr7) = " << sizeof(arr7) << endl; // 12， 包含了结尾的\0

		//数组是地址连续的空间
		//数组遍历存放的数组首地址
		cout <<"arr1 = "<< (long long)arr1 << endl;
		cout << "&arr1[0] = " << (long long)&arr1[0] << endl;
		cout << "&arr1[1] = " << (long long)&arr1[1] << endl;
		cout << "&arr1[2] = " << (long long)&arr1[2] << endl;
		cout << "&arr1[3] = " << (long long)&arr1[3] << endl;
		cout << "arr1 + 2 = " << (long long)(arr1 + 2) << endl;
		cout << "arr1 + 3 = " << (long long)(arr1 + 3) << endl;

		cout << "*(arr1 + 2) = " << *(arr1 + 2) << endl; // 88， 相当于arr1[2]



	}
	{
		int arr1[4]{ 0 };
	}

	{//堆区数组
		int* arr1 = new int[4] {0};
		auto arr2 = new int[4] {1, 2, 3, 4};
		cout << "sizeof(arr1) = "<<sizeof(arr1) << endl;
		int size = 10;
		auto arr3 = new int[size] {0};
		for (int i = 0; i < size; i++)
		{
			cout << arr3[i] << "|";
		}
		cout << endl;
		delete[] arr1; arr1 = nullptr; // 释放数组空间
		delete[] arr2; arr2 = nullptr;
		delete[] arr3; arr3 = nullptr;

		int arr5[5] = { 1,2,3,4,5 };
		auto* arr6 = new int[5]; // 动态分配数组， 语法是new 类型[元素数量]
		memcpy(arr6, arr5, sizeof(arr5)); // 拷贝数组，语法是memcpy(目的地址， 源地址， 字节数)，等于arr6 = arr5;
		for (int i = 0; i < 5; i++)
			cout << arr6[i] << "-";
		cout << endl;
		delete[]arr6;
		arr6 = nullptr;



	}
}

