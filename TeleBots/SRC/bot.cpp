#include "../INCL/bot.hpp"


Bot::Bot(std::string path){
    std::ifstream file(path);
    if(!file.is_open()){
        std::cout << "Bot api token isnt find\n";
        file.close();
        return;
    }
    char str[1000];
    file.read(str, 1000);
    std::string url = "";
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        url_token += str[i];
    }
    file.close();
    std::cout << url_token << std::endl;
}

void Bot::get_Update(){
    std::string url = this->url_token + "/getUpdates";
    cpr::Response r = cpr::Get(
        cpr::Url{url});
    save(r.text, "getUpdates");
}

void Bot::save(const std::string& responce, const std::string& method){
    std::ofstream file("./LOG/"+method + ".json");
    file << responce;
    file.close();
}

void Bot::send_msg(const std::string msg){
    std::string url = this->url_token + "/sendMessage";
    cpr::Response r = cpr::Post(
        cpr::Url{url}, cpr::Payload{{"chat_id", "1282744798"}, {"text", msg}});
    save(r.text, "msg_report");
}


void Bot::sendDice(){
    std::string url = this->url_token + "/sendDice";
    cpr::Response r = cpr::Post(cpr::Url{url}, cpr::Payload{{"chat_id", "1282744798"}, {"emoji", "🎰"}});
    save(r.text, "sendDice");
}