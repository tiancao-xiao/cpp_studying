// testfstream.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第六章 终于做事了，所有的业务都是输入输出
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    string testfile = "testfile.txt";
    //out 写入文件 binary二进制处理\r\n不处理
    //输出默认清空文件的原内容
    fstream wfs(testfile, ios::out | ios::binary);
    //wfs.open(testfile, ios::out | ios::binary);
    wfs << "1234567890\n";
    wfs.close();
    ofstream ofs; //app追加写入
    ofs.open(testfile, ios::app | ios::binary);
    ofs << "ABCDEFGHIJ\n" << flush;
    ofs.write("1234", 4);
    ofs.close();

    //读取文件
    fstream rfs(testfile, ios::in | ios::binary);
    if (!rfs.is_open())
    {
        cerr << "open file " << testfile << " failed!" << endl;
        return -1;
    }
    char buf[4090]{ 0 };
    rfs.read(buf, sizeof(buf) - 1);
    cout << "rfs.gcount()  = "<<rfs.gcount() << endl;
    cout << "-----------------------\n";
    cout << buf << endl;
    cout << "-----------------------\n";
    rfs.close();

    //获取文件大小 ios::ate文件尾部
    //tellg 读取文件指针位置
    ifstream ifs(testfile, ios::ate);
    cout << testfile << " filesize=" << ifs.tellg()<< endl;
    
    //读取文件更改后内容
    string line;
    for (;;)
    {
        getline(ifs, line);
        //cout << ifs.rdstate() <<endl;
        if(!line.empty())
            cout << "line:"<<line << endl;
        ifs.clear();
    }


}
