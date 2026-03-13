// test_stringstream.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第六章 终于做事了，所有的业务都是输入输出
/////////////////////////////////////////////////////////////////////////////a

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    {
        //stringstream 单行读取
        string data = "test1 test2 test3\ntest4 test5 test6\ntest7 test8 test9";
        string line;
        stringstream ss(data); //创建一个字符串流对象ss，并将字符串data作为输入数据传递给它。
        for (;;)
        {
            getline(ss, line);
            cout << "line:" << line << endl;
            if (ss.eof())break; //eof()函数用于检查输入流是否已经到达文件末尾（End Of File）。当输入流中的所有数据都被读取完毕后，eof()函数会返回true。
        }

        
    }
    {
        //stringstream 格式输入
        string data = "test1 test2 test3";
        stringstream ss(data); //创建一个字符串流对象ss，并将字符串data作为输入数据传递给它。
        string tmp;
        //使用输入运算符>>从字符串流ss中读取数据，并将其存储在变量tmp中。
        //每次调用ss >> tmp都会从字符串流中读取一个单词（以空格为分隔符），并将其赋值给tmp。
        ss >> tmp; cout << tmp << ","; 
        ss >> tmp; cout << tmp << ",";
        ss >> tmp; cout << tmp << ",";
        cout << endl;
       

        
    }

    //stringstream 基础用法
    {
        stringstream ss;
        ss << "test stringstream:" << 100; //使用输出运算符<<将字符串和整数写入字符串流ss中。
        ss << true; //将布尔值true写入字符串流ss中。即:使ss中的内容变为"test stringstream:1001"，其中1表示布尔值true。
        cout << ss.str() << endl; //使用str()成员函数获取字符串流ss中的内容，并将其输出到标准输出流cout中。
        cout << endl;

        ss << boolalpha; //设置boolalpha后，布尔值将以true或false的形式输出，而不是默认的1或0。
        ss << hex; //设置hex后，整数将以十六进制的形式输出，而不是默认的十进制。
        ss << "\n" << false << 100 << endl; //使用输出运算符<<将换行符、布尔值false和整数100写入字符串流ss中。
        cout << ss.str() << endl; //此时，ss中的内容变为"test stringstream:1001\nfalse64"
        cout << endl;

        ss << noboolalpha; //设置noboolalpha后，布尔值将以默认的1或0的形式输出，而不是true或false。
        ss << dec; //设置dec后，整数将以十进制的形式输出，而不是十六进制。
        ss << "\n" << false << 100 << endl; //使用输出运算符<<将换行符、布尔值false和整数100写入字符串流ss中。
        cout << ss.str() << endl; //此时，ss中的内容变为"test stringstream:1001\nfalse64\n\n0100"
        ss.str("");//清空
        cout << ss.str() << endl;
    }
}