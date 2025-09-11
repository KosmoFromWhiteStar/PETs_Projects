#include <iostream>
#include <windows.h>

int main(int argc, char* argv[])
{
    system("cd test_dir");
    system("g++ ./test_dir/main.cpp");
    auto re = WinExec("a.exe", 2);
    std::cout << re << std::endl;
    return 0;
}