// test_enum.cpp
/////////////////////////////////////////////////////////////////////////////
//// 第三章开始逻辑了-有了分歧怎么办
/////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;
enum name
{
	value1,  //默认0
	value2,  //默认1
	value3 = 100,
	value4,  //101
	value5,  //102	
	
	//DEBUG
};
enum Status // 定义一个播放器状态枚举
{
	PLAY,
	PAUSE,
	STOP
};
//C++11 枚举
enum class LogLevel
{
	DEBUG,
	INFO,
	ERROR,
	FATAL
};


int main()
{
	//设置日志显示的最低级别
	LogLevel level{ LogLevel::DEBUG };
	int s = static_cast<int>(level);
	cout << s << endl;
	LogLevel log_level = LogLevel::DEBUG;
	if (level <= log_level)
	{
		cout << "记录日志" << endl;
	}

	name ev1{ value5 };
	cout << "value1 = " << value1 << endl;
	cout << "value4 = " << value4 << endl;
	Status status{ STOP }; //声明了一个名为status的变量，并将其初始化为Status枚举类型中的一个值STOP。
	int var1 = status;
	if (status == 2)
	{
		cout << "2 STOP" << endl;
	}
	status = PLAY;
	if (status == PLAY)
	{
		cout << PLAY<<" PLAY" << endl;
	}
}
