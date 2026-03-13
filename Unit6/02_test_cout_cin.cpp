// test_cout_cin.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第六章 终于做事了，所有的业务都是输入输出
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int main()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "请输入数字:" << flush; //flush刷新缓冲区，确保提示信息立即显示
        string line; //定义一个字符串变量line，用于存储用户输入的内容
        int x{ 0 };
        cin >> x;
        //if (cin.rdstate() == std::ios_base::failbit)
        if (cin.fail()) //cin.fail()函数用于检查输入流是否处于失败状态，如果输入失败（例如输入了非数字字符），则返回true。
        {
            cin.clear();// 恢复状态为正常
            getline(cin, line); //读取输入流中的剩余内容并存储到line变量中，以便后续处理或输出。
            cout << "cin fail:" << line << endl;
            
            continue;
        }
        cout << "x=" << x << endl;

    }


    //单个字符输入get
    string cmd; //定义一个字符串变量cmd，用于存储用户输入的命令。
    for (int i = 0; i < 5; i++)
    {
        char c = cin.get(); //cin.get()函数用于从输入流中读取一个字符，并返回该字符的ASCII值。
        //如果输入流中没有更多的字符可供读取，或者发生了输入错误，则返回EOF（End Of File）。
        if (c == '\n' || c == ';')
        {
            cout << "cmd:" << cmd << endl;
            cmd = "";
            continue;
        }
        cmd += c;
        //cout << c << flush;
    }

    //单行输入 getline
    string line;
    getline(cin, line); //getline(cin, line)函数用于从输入流中读取一行文本，并将其存储在line变量中。
    //它会一直读取输入，直到遇到换行符（\n）为止。
    cout << "line:" << line << endl;

    for (int i = 0; i < 3; i++)
    {
        char buf[1024]{ 0 }; //定义一个字符数组buf，大小为1024，并将其初始化为0。
        //这个数组用于存储用户输入的字符串。
        cout << ">>";
        //cin.getline(buf, sizeof(buf) - 1)函数用于从输入流中读取一行文本，并将其存储在buf数组中。
        cin.getline(buf, sizeof(buf) - 1); 
        cout <<"recv:"<< buf << endl;
        if (strstr(buf, "exit"))
        {
            break;
        }
    }
}