// testclass.cpp 
/////////////////////////////////////////////////////////////////////////////
//// 七 想要写成符合人类的思维的代码 -面向对象
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//两个npc npc有血量和名字
//处理npc被攻击
string npc1_name = "npc1";
int npc1_health = 100;

string npc2_name = "npc2";
int npc2_health = 100;

void AtackNpc1(int atk)
{
    npc1_health -= atk;
    cout << npc1_name << " was attacked!  "
        << "-" << atk << endl;
}

void AtackNpc2(int atk)
{
    npc2_health -= atk;
    cout << npc2_name << " was attacked!  "
        << "-" << atk << endl;
}

vector<string> npcs_name;
vector<int> npcs_health;
void AtackNpc(int index, int atk)
{
    npcs_health[index] -= atk;
    cout << npcs_name[index] << " was attacked!  "
        << "-" << atk << endl;
}

class Npc
{
public:
    string name_; //成员变量名称一般后面加"-"
    //成员变量可以直接赋值，构造函数会把这个值赋给成员变量
    int health_ = 100; //每一个Npc对象都有一个health_成员变量，初始值为100
    void Atack(int atk)
    {
        health_ -= atk;
        cout << name_ << " was attacked!  "
            << "-" << atk << endl;
    }
};

//类型名称 首字母大写，每个单词首字母大小
// 类型是名词
class MyClass
{
public:
    //成员变量声明
    int x{0}; //定义一个成员变量x，类型为int，初始值为0
    int y{0};
    char name[16]{"myclass name"};
    void TestIn(int v) //内联函数，函数体直接写在类定义中，编译器会自动将其作为内联函数处理
    {
        //普通成员函数可以访问私有的静态成员变量
        count ++;
        //this指针 当前类对象的地址
        cout << "this addr = " << (long long)this << endl;
        x += v;
        y += v;
        cout << "inline: " << "x = " << x << ", y = " << y << endl;
        cout << this->name << endl; //通过this指针访问成员变量
        cout << "name: " << name << endl;
        /*
        this->TestOut(20); //通过this指针调用成员函数
        TestOut(30); //直接调用成员函数，编译器会自动将this指针作为隐式参数传递
        (*this).TestOut(40); //通过解引用this指针调用成员函数
        */
    }
    static int GetCount() //公共静态成员函数，提供访问私有静态成员变量的接口
    { 
        return count; 
    }
    void TestOut(int v); //成员函数声明，函数体在类定义外部实现

    //静态成员变量声明
    static int size; //静态成员变量，属于类而不是对象，所有对象共享同一个静态成员变量

    static void TestStatic()
    {
        //没有this指针 不能访问非静态成员变量
        count++; //可以访问静态成员变量
        //x++; //错误，不能在静态成员函数中访问非静态成员
        cout << "Test Static" << endl;

    }

    //静态成员函数应用场景1 单件模式 类的对象只存在一份
    static MyClass& Instance()
    {
        static MyClass mc; //局部静态变量，第一次调用Instance函数时创建，之后每次调用都返回同一个对象的引用
        return mc;
    }

    //静态成员函数应用场景2 成员函数封装成普通函数
    //静态成员函数没有this指针，可以作为普通函数使用，传入对象作为参数
    static void RunStatic(MyClass& obj) //静态成员函数，参数为MyClass对象的引用
    {
        obj.Run(); //通过对象调用私有成员函数，静态成员函数可以访问私有成员
    }

private: //访问说明符
//public 公开，类外可以访问
//private 私有，只有(静态)成员函数可以访问
static int count; //私有静态成员变量，只有MyClass的成员函数可以访问
void Run() { cout << "MyClass Run" << endl; } //私有成员函数，只有MyClass的成员函数可以调用

};

int MyClass::size{0}; //静态成员变量定义，必须在类定义外部进行定义和初始化
int MyClass::count{0};

void MyClass::TestOut(int v) //成员函数定义，使用"类名::函数名"的方式实现
{
    x += v;
    y += v;
    cout << "out: " << "x = " << x << ", y = " << y << endl;
    cout << "name: " << name << endl;
}

int main()
{
    MyClass::Instance().TestOut(100);

    //私有private不可访问
    //MyClass::count++; //错误，不能在类外访问私有静态成员变量
    MyClass mc;
    cout << "count = " << MyClass::GetCount() << endl; //通过公共静态成员函数访问私有静态成员变量
    mc.TestIn(0);
    cout << "count = " << MyClass::GetCount() << endl; //通过公共静态成员函数访问私有静态成员变量
    MyClass::size++;
    cout << "MyClass::size = " << MyClass::size << endl;
    cout << "mc.size = " << mc.size << endl; //通过对象访问静态成员变量，编译器会自动转换为类名访问
    MyClass::RunStatic(mc); //通过静态成员函数调用私有成员函数，参数为对象
    MyClass::TestStatic(); //调用静态成员函数


    MyClass mcf; 
    mcf.TestOut(10);
    mcf.TestIn(20);
    cout << "mcf addr = " << (long long)&mcf << endl;
    

    MyClass mc1; //栈区对象
    cout << sizeof(mc1) << "|" << sizeof(MyClass) << endl; //4+4+16=24
    cout << "mc1.name = " << mc1.name << endl;
    cout << "mc1.x = " << mc1.x << endl;

    MyClass* mc2 = new MyClass; //堆区对象指针
    mc2 -> x =100; //通过指针访问成员变量，使用"->"运算符
    cout << "mc2->x = " << mc2->x << endl;
    cout << "(*mc2).x = " << (*mc2).x << endl; //通过指针访问成员变量，使用"*"运算符解引用
    delete mc2; //释放动态分配的内存

    MyClass* mc3 = &mc1; //指针指向栈区对象
    cout << "mc3->x = " << mc3->x << endl; //通过指针访问成员变量
    cout << "(*mc3).x = " << (*mc3).x << endl; //通过指针访问成员变量
    //delete mc3; //错误，不能删除指向栈区对象的指针，可能会导致程序崩溃
    

    //自定义类型赋值
    MyClass mc4;
    mc1.x = 99;
    mc4 = mc1; //类对象之间可以直接赋值，编译器会自动生成一个默认的赋值运算符函数，逐个成员变量进行赋值
    cout << "mc4.x = " << mc4.x << endl;

    AtackNpc1(10);
    AtackNpc2(20);

    //push_back 向vector容器末尾添加元素
    npcs_name.push_back("vector npc1"); //vector容器存储npc
    npcs_health.push_back(100); //vector容器存储npc的血量
    npcs_name.push_back("vector npc2");
    npcs_health.push_back(100);
    AtackNpc(0, 30);
    AtackNpc(1, 40);

    Npc npc1;
    npc1.name_ = "class npc1"; //类对象的成员变量赋值
    Npc npc2;
    npc2.name_ = "class npc2";
    npc1.Atack(50); //类对象调用成员函数
    npc2.Atack(60);

    return 0;
}