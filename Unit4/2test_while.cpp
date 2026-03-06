// test_while.cpp
/////////////////////////////////////////////////////////////////////////////
//// 第四章批量处理任务开始了
/////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;
int main()
{
	/*
	项目实战 支持ls的shell
	实现一个在windows上支持ls命令的shell
	使用cin接收用户输入
	使用system调用dir命令模拟ls
	支持ls不传参数和传递参数
	用户输入exit和quit退出
*/
	{
		bool is_exit{ false };
		while (!is_exit)
		{
			string cmd;		//用户输入的命令分类
			string execcmd; //执行的命令
			std::cout << "xshell>>";
			std::cin >> cmd;
			if (cmd == "ls")
			{
				execcmd = "dir";
				string arg;
				if (std::cin.rdbuf()->in_avail() > 1)
				{//缓冲区有内容,不只有\n
					std::cin >> arg;
					execcmd += " " + arg;
				}
				system(execcmd.c_str());
			}
			else if (cmd == "exit" || cmd == "quit")
			{
				is_exit = true;
				continue;
			}
			else
			{
				cerr << "命令" << cmd << "不支持!" << endl;
			}

		}
	}
	return 0;

	//system 执行系统命令
	//system("cd");

	string cmd = "dir";
	//system(cmd.c_str());
	//接收用户输入的命令,再用system执行
	cout << ">>";
	cin >> cmd;
	
	cout << "in_avail=" << cin.rdbuf()->in_avail() << endl;
	if (cin.rdbuf()->in_avail() > 1)
	{//缓冲区有内容,不只有\n
		string tmp;
		cin >> tmp;
		cmd += " " + tmp;
	}
	cout << "cmd:" << cmd << endl;
	system("pause");

	//return 0;


	int index{ 0 };
	
	//无限循环
	while (1)
	{
		index++;
		if (index % 2 == 0)
			continue;
		if (index > 10)
			break;
		cout << index << " ";
	}
	cout << endl;
	bool is_exit{ false };
	index = 0;
	while (!is_exit)
	{
		index++;
		if (index > 10)
			is_exit = true;
		cout << index << " ";
	}
	cout << endl;
	index = 0;
	while (index++ < 10)
		cout << index << " ";
	cout << endl;
	index = 0;
	while (++index < 10)
		cout << index << " ";
	cout << endl;

	index = 0;
	while (int i = ++index) 
	{
		cout << index << " ";
		if (i > 10)break;
	}
	cout << endl;
}
