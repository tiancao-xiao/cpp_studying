// test_vector.cpp 
#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{


	//vector的基础使用
	std::vector<int> vi; //用了using namespace std就不需要std::
	vector<string> vs; 
	vector<float> vf;
	vector<int> vd1(10); //设置数组大小
	//初始化
	vector<int> vd2{ 1,2,3,4,6 }; //vd2 的元素个数为5，初始化为1,2,3,4,6
	vector<string> vs1{ "ss1","ss2","ss3" };

	//增加\删除\修改\查找
	{
		vector<int> datas;
		datas.push_back(10); //结尾处插入内容
		datas.push_back(11);
		datas.push_back(12); //datas为{10,11,12}
		datas[0] = 99; //修改，datas为{99,11,12}

		//三种遍历
		for (int i = 0; i < datas.size(); i++)
			cout << datas[i] << " ";
		cout << "\n";

		//迭代器
		vector<int>::iterator itr = datas.begin(); 
		// vector<int>::iterator itr：声明了一个名为itr的迭代器，该迭代器用于遍历vector<int>类型的容器。
		// datas.begin()：返回一个指向容器datas第一个元素的迭代器。datas是一个vector<int>类型的对象。
		for (auto itr = datas.begin();itr != datas.end();itr++)
		/*
			auto itr = datas.begin()：使用auto关键字自动推导迭代器的类型，
			并初始化为指向容器datas第一个元素的迭代器。
			itr != datas.end()：datas.end()返回一个指向容器datas最后一个元素之后位置的迭代器。
			循环条件是itr不等于datas.end()，即只要itr还没有到达容器的末尾，循环就会继续。
			itr++：每次循环迭代后，迭代器itr会递增到下一个元素。
		*/
			cout << *itr << ",";
			//在循环体内，*itr用于解引用迭代器，获取迭代器所指向的元素的值，
			//并将其输出到标准输出（通常是控制台）。然后输出一个逗号,作为分隔符。

		cout << "\n";
		//c++11 
		for (auto& d : datas)
		/*
		auto& d：auto&关键字用于自动推导变量d的类型，并将其声明为引用类型。
		这样可以避免复制元素，提高效率。
		d的类型会被推导为int&，因为datas是vector<int>类型的容器。
: 		datas：表示循环将遍历datas容器中的每一个元素
		*/
		{
			cout << d << "|"; //使用cout将当前元素d的值输出到标准输出（通常是控制台），并在每个元素后面输出一个竖线|作为分隔符。
		}
		cout << "\n";
	}
	{
		//vector 搜索 删除 插入
		std::vector<int> datas{
			7,2,3,6,5,6,7,8,0,10,
			5,12,3312,334,11 };
		auto f = find(datas.begin(), datas.end(), 5);
		/*
		#include <algorithm> // 必须包含这个头文件
		auto 迭代器 = find(容器起始位置, 容器结束位置, 要查找的值);
		*/
		if (f != datas.end())
		{
			cout << "find " << *f << " in "
				<< f - datas.begin() << endl;
			datas.erase(f); //删除元素
		}
		f = find(datas.begin(), datas.end(), 3312);
		datas.insert(f, 3311); //指定位置插入
		datas.insert(datas.begin() + 2, 99);// 第三个位置插入
		//查找fdata
		int fdata = 6;
		vector<int> datapos;
		for (int i = datas.size() - 1; i >= 0; i--)
		{
			if (datas[i] == fdata)
			{
				datapos.push_back(i);
			}
		}
		for (auto p : datapos)
			cout << p << " ";
		cout << "\n";
		//删除所有找到的fdata
		for (auto p : datapos)
		{
			datas.erase(datas.begin() + p);
		}
		for (auto d :datas)
		{
			cout << d << "-";
		}

		cout << endl;
		//正序
		std::sort(datas.begin(), datas.end());
		for (auto d : datas)
			cout << d << "-";
		cout << endl;

		//倒序
		std::sort(datas.begin(), datas.end(),
			greater<int>());
		for (auto d : datas)
			cout << d << "-";
		cout << endl;
	}

	//////////////////////////////////////////////////////////////////
	//vector的效率 内存
	{
		vector<int> v1;
		vector<int> vdata(10);
		cout << "v1.size()" << v1.size() << endl; //size()存储元素数量
		cout << "vdata.size()" << vdata.size() << endl;

		cout << "v1.capacity():" << v1.capacity() << endl;//实际存储空间
		cout << "vdata.capacity():" << vdata.capacity() << endl;//实际存储空间
		v1.resize(8);	//扩充元素数量 初始化对象
		v1.reserve(16);	//扩充内存数量 只扩充内存
		cout << "v1.size():" << v1.size() << endl;//实际存储空间
		cout << "v1.capacity():" << v1.capacity() << endl;//实际存储空间
		v1.push_back(99);
		for (auto v : v1)
			cout << v << "|";
		cout << endl;
		v1.clear(); //清空元素
		//内存适应元素 有多少元素就分配多少内存
		v1.shrink_to_fit();

		cout << "v1.size():" << v1.size() << endl;//实际存储空间
		cout << "v1.capacity():" << v1.capacity() << endl;//实际存储空间
		cout << "----------------\n";
		int c = 0;
		//元素空间动态变化
		for (int i = 0; i < 200; i++)
		{
			v1.push_back(i);
			if (c != v1.capacity())
			{
				cout << "v1.capacity():" << c << endl;//实际存储空间
			}
			c = v1.capacity();
		}
	}

	//////////////////////////////////////////////////////////////////
	//vector插入元素的效率
	{

		vector<string> vs;
		//结尾处插入元素
		//1"test" 转为string 对象
		//2 vs内部分配string对象空间
		//3 复制一份string存入vs??
		//3 现代版本移动一份存入vs
		vs.push_back(string("test"));
		//1 vs内部分配string对象空间
		//2直接讲string对象创建在分配的空间中
		vs.emplace_back(string("test"));
		vs.push_back("test");
		vs.emplace_back("test");
		vs.emplace_back(); //创建了一个string对象
	}

}
