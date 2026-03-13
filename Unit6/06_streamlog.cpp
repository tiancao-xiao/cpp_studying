// streamlog.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第六章 终于做事了，所有的业务都是输入输出
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;

// 获取格式化当前时间（东八区，默认格式：年-月-日 时:分:秒）
static std::string GetNow(
    const char* fmt = "%Y-%m-%d %H:%M:%S",
    int time_zone = 8)
{
    std::time_t unix_sec = std::time(nullptr);
    std::tm tm;
    static const int kHoursInDay = 24;
    static const int kMinutesInHour = 60;
    static const int kDaysFromUnixTime = 2472632;
    static const int kDaysFromYear = 153;
    static const int kMagicUnkonwnFirst = 146097;
    static const int kMagicUnkonwnSec = 1461;
    tm.tm_sec = unix_sec % kMinutesInHour;
    int i = (unix_sec / kMinutesInHour);
    tm.tm_min = i % kMinutesInHour;
    i /= kMinutesInHour;
    tm.tm_hour = (i + time_zone) % kHoursInDay;
    tm.tm_mday = (i + time_zone) / kHoursInDay;
    int a = tm.tm_mday + kDaysFromUnixTime;
    int b = (a * 4 + 3) / kMagicUnkonwnFirst;
    int c = (-b * kMagicUnkonwnFirst) / 4 + a;
    int d = ((c * 4 + 3) / kMagicUnkonwnSec);
    int e = -d * kMagicUnkonwnSec;
    e = e / 4 + c;
    int m = (5 * e + 2) / kDaysFromYear;
    tm.tm_mday = -(kDaysFromYear * m + 2) / 5 + e + 1;
    tm.tm_mon = (-m / 10) * 12 + m + 2;
    tm.tm_year = b * 100 + d - 6700 + (m / 10);
    stringstream ss;
    ss << std::put_time(&tm, fmt);
    return ss.str();
}

// 全局日志流：默认绑定 控制台输出(cout) 的缓冲区
static ostream logstr(cout.rdbuf());

// 切换日志输出目标（核心：修复为 public 接口 rdbuf()）
void SetLogBuf(streambuf* buf)
{
    logstr.rdbuf(buf); // 替换为标准公开接口，修复报错
}

// 日志核心写入函数
void LogWrite(string level, string log, string file, int line)
{
    logstr << GetNow() << " " << level
           << " " << log << " " << file << ":" << line << endl;
}

// 宏定义：简化日志调用，自动填充 级别、文件名、行号
#define LOGDEBUG(s) LogWrite("debug", s, __FILE__, __LINE__)

int main()
{
    // 1. 默认输出：控制台
    LOGDEBUG("test log 001");
    LOGDEBUG("test log 002");

    // 2. 切换输出：字符串缓冲区（内存中）
    stringstream ss;
    SetLogBuf(ss.rdbuf());
    LOGDEBUG("test log 003 stringstream");
    cout << "ss.str():" << ss.str() << endl;

    // 3. 切换输出：文件（追加写入 log.txt）
    ofstream ofs("log.txt", ios::app);
    SetLogBuf(ofs.rdbuf());
    LOGDEBUG("test log 004 ofstream");
    LOGDEBUG("test log 005 ofstream");

    return 0;
}