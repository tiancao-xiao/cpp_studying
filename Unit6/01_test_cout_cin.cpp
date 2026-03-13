// test_cout_cin.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 第六章 终于做事了，所有的业务都是输入输出
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
int main()
{
    //cout标准输出 ostream stdout 1
    cout << "test cout" << endl;
    cout << 100 << endl; //默认十进制输出
    cout << oct << 100 << endl; //八进制
    cout << 100 << endl; //仍然是八进制
    cout << hex << 100 << endl; //16进制
    cout << 100 << endl; //仍然是16进制
    cout << dec << 100 << endl; //10进制
    cout << true << ":" << false << endl; //默认输出1和0
    cout << boolalpha; //设置boolalpha后，true输出true，false输出false
    cout << true << ":" << false << endl;
    //cout 无格式输入
    cout.put('A').put('B');
    cout.put('C');
    cout.put(68); //ASCII码68对应字符D
    cout.write("123", 3); //输出"123"
    string str = "teststring";
    //cout.write(str.c_str(), str.size())的作用是将字符串str的内容写入到标准输出流cout中。
    //str.c_str()返回一个指向字符串内容的指针，str.size()返回字符串的长度。
    //这样，cout.write()函数会将字符串的内容按照指定的长度写入到输出流中。
    //在这个代码中，cout.write(str.c_str(), str.size())会将字符串"teststring"写入到标准输出流cout中，
    //并且不会自动添加换行符。
    cout.write(str.c_str(), str.size()); 
    cout << flush; //刷新缓冲区
    cout << endl;
    //cerr标准错误输出 无缓冲 stderr 2
    // test_cout_cin.exe >1.txt
    //test_cout_cin.exe 1>1.txt 2>2.txt
    //test_cout_cin.exe >log.txt 2>&1   
    cerr << "test cerr 001\n" ;
    cerr << "TEST CERR 002\n";

}