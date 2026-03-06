// test_switch.cpp 
#include <iostream>
using namespace std;
enum class Status
{
	PLAY,
	STOP,
	PAUSE
};
int main()
{
	//switch ( 条件 ) 语句
	int x{ 0 };
	cin >> x;
	switch (x)  //判断x值满足哪个条件,
				//直接跳转到相应的条件代码
				//运行到switch代码结束或者break
	{
	case 0:
		cout << "case 0\n";
		break;
	case 1:
		{
			int x1{ 100 };
			cout << "begin 1 "<< x1 << endl;
			cout << "case 1\n";
			break;
		}
	case 2:
		cout << "case 2\n";
		break;
	default:
		cout << "default\n"; //前面条件都不满足,进入
	}

	Status status{ Status::PLAY };
	switch (status)
	{
	case Status::PLAY:
		cout << "Play" << endl;
		break;
	case Status::STOP:
		cout << "STOP" << endl;
		break;
	case Status::PAUSE:
		cout << "PAUSE" << endl;
		break;
	default:
		break;
	}


}
