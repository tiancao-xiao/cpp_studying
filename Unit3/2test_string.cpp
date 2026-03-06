//test_string.cpp                              
/////////////////////////////////////////////////////////////////////////////
//// 第三章开始逻辑了-有了分歧怎么办
/////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;
int main()
{
	//1 字符串的初始化和赋值
	std::string str1 { "test string 1" }; //未引入头文件，使用std::string
	cout << "str1:" << str1 << endl;
	str1 = "test string 1-2";
	string str2{ str1 };
	cout << "str2:" << str1 << endl;
	string str3;//默认空串
	str3 = str2;
	cout << "str3:" << str3 << endl;
	//2 字符串长度获取 size()直接读取长度，不包括\0
	//capacity() 实际可用的空间
	string str4{ "123456789" };
	cout << "str4.size():" << str4.size() 
		<< endl;
	cout << "str4.capacity() = " <<
		str4.capacity() << endl;

	//3 截断字符串
	//substr 返回的是一个string
	//Off 偏移位置 截断的起始位置 从0开始
	//1是第二字符
	cout << str4.substr(3)<<endl; //从下标3开始
	cout << str4.substr(1, 3) << endl;
	//从第2个字符开始，截取3个字符
	
	//4 字符串判断
	string strif;
	//空串判断
	if (strif.empty())
	{
		cout << "strif empty" << endl;
	}
	if (strif.size() == 0)
	{
		cout << "strif.size() == 0" << endl;
	}
	if (strif == "")
	{
		cout << "strif == " << endl;
	}
	strif = "test";
	if ("test" == strif )
	{
		cout << "strif == test" << endl;
	}
	if ("test1" != strif)
	{
		cout << "strif != test1" << endl;
	}
	string strif2 = "if2";
	if (strif == strif2)
	{
	}


	//5 字符串和数字的转换
	//字符串转化为数字 出错抛异常
	auto i1 = stoi("1234"); // auto 自动推导类型 int, stoi 字符串转化为int
	i1++;
	cout <<"i1 = "<< i1 << endl;
	string sd1 = "123.5";
	double d1 = stod(sd1);  // stod 字符串转化为double, double可以换成auto
	cout << d1 << endl;
	auto f1 = stof("33.1f"); // stof 字符串转化为float
	cout << f1 << endl;
	auto f2 = stof("33.2"); // 33.2 自动识别为double
	cout << f2 << endl;
	cout << stoll("-1231231231233") << endl; // stoll 字符串转化为long long int
	//数字转化为字符

	auto pistr = to_string(3.1415926);
	cout << "pistr = " << pistr << endl;
	cout << to_string(-19998) << endl;

	//6字符串拼接
	string log;
	string txt = "login success!";
	string user = "satoru";
	int thread_id = 1023;
	log = user + ":" + txt + ":" 
		+ to_string(thread_id); // 字符串拼接，不支持整数合并，要先用to_string转化为字符串
	log = "[debug]" + log;
	log += ";";
	cout << log << endl;

	//7查找和替换
	string strfind = "test for find [user] test";
	auto pos = strfind.find("[test]"); // 查找字符串位置，返回位置，没找到返回npos
	string suser = "satoru";
	if (pos == string::npos) // 字符串没找到
	{
		cout << "[test] not find" << endl;
	}
	string key = "[user]";
	pos = strfind.find(key); // 查找字符串位置，返回位置，没找到返回npos
	cout << "pos = " << pos << endl;
	if (pos != string::npos) // 字符串找到
	{
		cout << strfind.substr(pos)<<endl; // 从查找到的位置开始截取字符串
		auto bak = strfind; // 备份原字符串 auto的作用是推导类型
		auto re = strfind.replace(
			pos, // 1 被替换字符的起始位置
			key.size(),// 2 要被替换掉的内容长度
			suser// 3 要替换为的字符串
			);
		cout << bak << endl;
		cout << re << endl;

	}

}
