#include "bot.hpp"


Bot::Bot(std::string path){
    std::ifstream file("./CONF/bot_api_token.txt");
    if(!file.is_open()){
        std::cout << "Bot api token isnt find\n";
        exit(1);
    }

}
void Bot::get_Update(){
    std::string url = this->url_token + "getUpdates";
    cpr::Response r = cpr::Get(
        cpr::Url{url});
    
}

void save(const std::string& responce, std::string method){
    std::ofstream file("./LOG/"+method + ".json");
    file << responce;
    file.close();
}
