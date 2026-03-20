// test_class_constructor.cpp
/////////////////////////////////////////////////////////////////////////////
//// 七 想要写成符合人类的思维的代码 -面向对象
/////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;

class MyClass
{
    public:
    //构造函数，函数名与类名相同，没有返回值，可以有参数，可以重载
    MyClass()
    //2 构造函数的成员初始化器列表  优先级最低
        :begin_{2}, //成员变量begin初始化为2，优先级高于默认成员初始化器
        name_{"myclass"} //成员变量name初始化为"myclass"

    {
        //3 构造函数中赋值  优先级最高
        name_ = name_ + to_string(index_); //成员变量name加上被转换为字符串的index的值
        cout << "Create MyClass" << index() 
        << " " << name_ << endl;
    }
    //析构函数，函数名与类名相同，前面加~，没有返回值，没有参数，不能重载
    ~MyClass()
    {
        cout << "Drop MyClass" << index() 
        << " " << name_ << endl;
    }
    int index(){return index_;} //成员函数，返回成员变量index的值
    void set_index(int i) {index_ = i;}  //成员函数，设置成员变量index的值
private: //不要开放任何成员变量到public
    //1 默认成员初始化器  优先级最低
    string name_; //成员变量name，默认初始化为空字符串
    int begin_{ 1 }; //成员变量begin，默认初始化为1
    int index_{begin_ + count_++}; //成员变量index，默认初始化为0
    static int count_; //静态成员变量count，所有对象共享，必须在类外定义和初始化
};
int MyClass::count_{0}; //静态成员变量count的定义和初始化


//MyClass mcg; //全局对象，程序结束时才会调用析构函数，输出"Drop MyClass"一次

int main()
{
    cout << "begin main" << endl;
    //////////////////////////////////////////////////////////
    //对象成员变量初始化
    {
        MyClass mcarr[3]; //创建一个MyClass类型的数组，包含3个元素，每个元素都会调用构造函数，输出"Create MyClass"三次
    } //出了作用域，mcarr数组中的三个对象会被销毁，调用析构函数，输出"Drop MyClass"三次

    //////////////////////////////////////////////////////////
    //堆区动态内存构造析构测试
    /*
    cout << "堆区动态内存构造析构测试" << endl;
    {
        //创建动态对象
        MyClass* mcp1 = new MyClass(); //对象创建时会调用构造函数，输出"Create MyClass"
        delete mcp1; //对象销毁时会调用析构函数，输出"Drop MyClass"  只释放空间不改变指针的值
        mcp1 = nullptr; //指针清空用nullptr
        delete mcp1; //指针已经清空，delete不会调用析构函数，不会输出"Drop MyClass"

        auto mcp2 = new MyClass; //内存泄漏
        //程序退出会释放，但不调用析构函数

    }
    */
    
    //////////////////////////////////////////////////////////
    //栈区构造析构测试
    /*
    static MyClass mcs; //静态对象，程序结束时才会调用析构函数，输出"Drop MyClass"一次

    MyClass mc1; //对象创建时会调用构造函数，输出"Create MyClass"
    MyClass mc2; //对象创建时会调用构造函数，输出"Create MyClass"
    getchar(); //等待输入，按回车继续 会发现没有调用析构函数
    //出了作用域，mc1和mc2会被销毁，调用析构函数，输出"Drop MyClass"两次
    */
    

    return 0;
}