#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    bool is_exit{ false };
    while (!is_exit)
    {
        string input;       // 用户输入的完整命令
        std::cout << "xshell>>";
        std::getline(cin, input);  // 读取整行输入

        // 使用 stringstream 解析命令和参数
        stringstream ss(input);
        vector<string> tokens;
        string token;

        while (ss >> token)
        {
            tokens.push_back(token);
        }

        if (tokens.size() > 0)
        {
            if (tokens[0] == "ls")
            {
                string execcmd = "dir";
                for (size_t i = 1; i < tokens.size(); ++i)
                {
                    execcmd += " " + tokens[i];
                }
                system(execcmd.c_str());
            }
            else if (tokens[0] == "exit" || tokens[0] == "quit")
            {
                is_exit = true;
                continue;
            }
            else
            {
                cerr << "命令 " << tokens[0] << " 不支持!" << endl;
            }
        }
    }
    return 0;
}
