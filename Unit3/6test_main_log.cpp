#include <iostream>
using namespace std;
enum class LogLevel
{
    DEBUG,
    INFO,
    ERROR,
    FATAL
};

int main(int argc, char* argv[])
{
    //用户传递日志的最低显示级别
    //debug < info < error < fatal
    //test_main_log info
    auto logLevel = LogLevel::DEBUG;
    if (argc > 1)
    {
        string levelstr = argv[1]; //获取用户传递的日志级别，levelstr为第一个命令行参数
        if ("info" == levelstr)
        {
            logLevel = LogLevel::INFO;
        }
        else if ("error" == levelstr)
        {
            logLevel = LogLevel::ERROR;
        }
        else if ("fatal" == levelstr)
        {
            logLevel = LogLevel::FATAL;
        }

    }

    
    //测试日志1 debug
    {
        auto level = LogLevel::DEBUG;
        string context = "test log 1";
        if (level >= logLevel)
        {
            string levelstr = "debug";
            switch(level)
            {
                case LogLevel::INFO:
                    levelstr = "info";
                    break;
                case LogLevel::ERROR:
                    levelstr = "error";
                    break;
                case LogLevel::FATAL:
                    levelstr = "fatal";
                    break;
                default:
                    break;
            }

            cout << levelstr << ":" << context << endl;
        }
    }

    //测试日志2 info
    {
        auto level = LogLevel::INFO;
        string context = "test log 2";
        if (level >= logLevel)
        {
            string levelstr = "info";
            switch(level)
            {
                case LogLevel::INFO:
                    levelstr = "info";
                    break;
                case LogLevel::ERROR:
                    levelstr = "error";
                    break;
                case LogLevel::FATAL:
                    levelstr = "fatal";
                    break;
                default:
                    break;
            }

            cout << levelstr << ":" << context << endl;
        }
    }

    //测试日志3 error
    {
        auto level = LogLevel::ERROR;
        string context = "test log 3";
        if (level >= logLevel)
        {
            string levelstr = "error";
            switch(level)
            {
                case LogLevel::INFO:
                    levelstr = "info";
                    break;
                case LogLevel::ERROR:
                    levelstr = "error";
                    break;
                case LogLevel::FATAL:
                    levelstr = "fatal";
                    break;
                default:
                    break;
            }

            cout << levelstr << ":" << context << endl;
        }
    }

    //测试日志4 fatal
    {
        auto level = LogLevel::FATAL;
        string context = "test log 4";
        if (level >= logLevel)
        {
            string levelstr = "fatal";
            switch(level)
            {
                case LogLevel::INFO:
                    levelstr = "info";
                    break;
                case LogLevel::ERROR:
                    levelstr = "error";
                    break;
                case LogLevel::FATAL:
                    levelstr = "fatal";
                    break;
                default:
                    break;
            }

            cout << levelstr << ":" << context << endl;
        }
    }

}