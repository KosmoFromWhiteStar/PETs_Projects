#include <iostream>
#include <windows.h>

int main(int argc, char* argv[])
{
    system("cd");
    system("cmake -S .\\test_dir -B .\\test_dir\\build");
    system("cmake --build .\\test_dir\\build");
    system(".\\test_dir\\build\\vuild.exe");
    return 0;
}