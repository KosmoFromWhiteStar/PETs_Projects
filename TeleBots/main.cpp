#include "Headers.hpp"
using namespace nlohmann;

int main()
{  
    Bot tg;
    tg.parser_comands();
    tg.save_People();
    tg.read_People();
    return 0;
}