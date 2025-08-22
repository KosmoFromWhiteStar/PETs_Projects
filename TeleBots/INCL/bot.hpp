#pragma once
#include <string>
#include "Headers.hpp"


class Bot{
private:
    std::string url_token;
    
public:
    Bot() : Bot(std::string {"./CONF/bot_api_token.txt"}){};
    Bot(std::string path);
    void get_Update();
    void save(const std::string& responce, const std::string& method);
    void get_Responce();
    void send_msg(const std::string msg);
    void sendDice();
};