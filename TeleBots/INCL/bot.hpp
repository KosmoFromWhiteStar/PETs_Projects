#pragma once
#include <string>
#include "Headers.hpp"


class Bot{
private:
    std::string url_token;
    
public:
    Bot(std::string path);
    void get_Update();
    void save(const std::string& responce);

};