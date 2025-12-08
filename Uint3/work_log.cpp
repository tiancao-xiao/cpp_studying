// work_log.cpp 
#include <iostream>
#include <string>
using namespace std;
int main(int argc,char *argv[])
{
    //test_main_log debug "{context} {file}:{line}"
    //test_main_log  debug "<log><context>{context}<contex> <file>{file}</file><line>{line}</line></log>"
    for (int i = 0; i < argc; i++)
        cout << argv[i] << endl;
    string fmt = "{context}-{file}:{line}";
    if (argc > 2)
        fmt = argv[2];
    string log = "test log context 001";
    cout << __FILE__ << ":" << __LINE__ << endl;

    string str = fmt;
    string ckey{ "{context}" };
    auto pos = str.find(ckey);
    if (pos != string::npos)
    {
        str = str.replace(pos,
            ckey.size(),
            log);
    }
    string fkey{ "{file}" };
    pos = str.find(fkey);
    if (pos != string::npos)
    {
        str = str.replace(pos,
            fkey.size(),
            __FILE__);
    }

    string lkey{ "{line}" };
    pos = str.find(lkey);
    if (pos != string::npos)
    {
        str = str.replace(pos,
            lkey.size(),
            to_string(__LINE__));
    }

    cout << "-------------------------- log --------------------------"<<endl;
    cout << str << endl;
}
