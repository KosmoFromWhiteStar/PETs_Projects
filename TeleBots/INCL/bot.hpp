#pragma once
#include <string>
#include "Headers.hpp"


struct People;

class Bot{
private:
    std::string url_token;
    bool webhook = false;

    /// @brief key - id, Valeu - Entity
    std::map<std::string, People> peoples;
public:
    Bot() : Bot(std::string {"./CONF/bot_api_token.txt"}){};
    Bot(std::string path);
    void get_Update();
    void save(const std::string& responce, const std::string& method);
    std::string get_Responce(const std::string& met);
    void send_msg(const std::string msg);
    void sendDice(const People& p);
    void save_People();
    void read_People();
    ///
    /// Parse comma form Updates json file
    ///
    std::string parser_comands(const std::string& file_path  = ".\\LOG\\getUpdates.json");
    int ty_meth(const std::string& coma );
    int query_();
};