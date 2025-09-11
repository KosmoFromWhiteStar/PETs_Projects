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


std::string Bot::get_Responce(const std::string& met){
    std::string url = this->url_token + "/" + met;
    cpr::Response r = cpr::Get(
        cpr::Url{url});
    return r.text;
}

void Bot::get_Update(){
    save(this->get_Responce("getUpdates"), "getUpdates");
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


std::string Bot::parser_comands(const std::string& file_path){
    std::ifstream file(file_path);
    if(!file.is_open())
    {
        std::cerr << "File isn't open\n";
        return {};
    }
    js json;
    file >> json;
    for(int i = 0; i < json["result"].size(); i++)
    {
        if(json["result"][i]["message"].contains("entities"))
            std::cout << json["result"][i]["message"]["text"] << std::endl;
    }
    return {};
}

int Bot::ty_meth(const std::string& coma ){
    auto txt = this->get_Responce(coma);
    save(txt, coma);
    return 0;
}