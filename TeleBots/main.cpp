#include "Headers.hpp"
using namespace nlohmann;

int main()
{  
    Bot tg;
    std::cout << "Input COma >:";
    std::string coma;
    std::cin >> coma;
    tg.ty_meth(coma);
    std::string fp = ".\\LOG\\"+coma+".json";
    output(fp);
    return 0;
}