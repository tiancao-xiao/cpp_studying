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
    //创建一个文件流对象wfs，并以输出模式（ios::out）和二进制模式（ios::binary）打开文件testfile。
    fstream wfs(testfile, ios::out | ios::binary);
    //wfs.open(testfile, ios::out | ios::binary);
    wfs << "1234567890\n";
    wfs.close(); //关闭文件流对象wfs，释放与文件相关的资源。
    ofstream ofs; //app追加写入
    //以追加模式（ios::app）和二进制模式（ios::binary）打开文件testfile。
    ofs.open(testfile, ios::app | ios::binary); 
    //使用输出运算符<<将字符串"ABCDEFGHIJ\n"写入文件流对象ofs中，并使用flush刷新缓冲区，确保数据立即写入文件。
    ofs << "ABCDEFGHIJ\n" << flush; 
    ofs.write("1234", 4);



}
