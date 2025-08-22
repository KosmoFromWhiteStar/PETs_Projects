#include <iostream>
#include <vector>

#ifndef GREETER_H
#define GREETER_H


inline int greetings(){
    std::vector<std::string> com = { {"1. Load core bot\n"},
    {"99. Send Dice"} };
    for(size_t i = 0; i < com.size(); i++)
    {
        std::cout << com[i];
    }
    return 1;
}




#endif