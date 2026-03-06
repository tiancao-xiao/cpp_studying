// test_for.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第四章批量处理任务开始了
/////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;
int main(int argc,char *argv[],char *env[])
{
	for (int i = 0;/*初始化*/ i < 10 /*条件*/;i++/*迭代*/)
	{

		//true代码块
		cout << "i = " << i << endl;
	}
	//continue break
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			continue;
		cout << i << " ";
		if (i > 50)
			break;
	}
	cout << endl;

	//嵌套for ,尽量不超过三层
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << i << "-" << j << " ";
		}
		cout << endl;
	}
	cout << endl;


	//无限循环
	int index = 0;
	for (;;)
	{
		if (index > 10)break;
		cout << "index:" << index << endl;
		index++;
	}

	for (int i = 0;env[i] != nullptr; i++) //遍历环境变量
	{
		cout << env[i] << endl;
	}
}
