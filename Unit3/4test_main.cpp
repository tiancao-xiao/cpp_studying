// test_main.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第三章开始逻辑了-有了分歧怎么办
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
int main(int argc,char *argv[],char *env[])
{
	//test_main DEBUG  16 3.14
	//访问argv字符串数组中的内容
    //从0开始是第一个字符串
    //第一个参数是执行程序完整路径
	cout << "argc = " << argc << endl;
	cout << "argv[0] = " << argv[0] << endl;
	//第二个参数是用户传递
    // ./test_main debug info
    // test_main debug info
    // test_main.exe debug info
	if (argc > 1)
		cout << argv[1] << endl;
	if (argc > 2)
		cout << argv[2] << endl;
	if (argc > 3)
		cout << argv[3] << endl;
	cout << env[0] << endl;
}

