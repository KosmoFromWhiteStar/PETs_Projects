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
    this->get_Update();
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
    std::ofstream file("./LOG/" + method + ".json");
    file << responce;
    file.close();
    
}

void Bot::send_msg(const std::string msg){
    std::string url = this->url_token + "/sendMessage";

    for(auto p : peoples){
    cpr::Response r = cpr::Post(
        cpr::Url{url}, cpr::Payload{{"chat_id", p.second.id }, {"text", msg}});
    save(r.text, "msg_report");
    }
}

void Bot::sendDice(const People& p){
    std::string url = this->url_token + "/sendDice";
    cpr::Response r = cpr::Post(cpr::Url{url}, cpr::Payload{{"chat_id", p.id}, {"emoji", "🎰"}});
    save(r.text, "sendDice");
}

void Bot::save_People(){
    std::ofstream file;
    file.open(".\\LOG\\people.data", std::ofstream::binary | std::ofstream::app);
    for(auto& pp : peoples)
    {
        pp.second.count_size();
        //Size of Person
        file.write(std::to_string(pp.second.size).c_str(), sizeof(size_t));
        //Save ID
        file.write(pp.first.c_str(), sizeof(pp.first.c_str()));
        //Save USername
        file.write(pp.second.username.c_str(), sizeof(pp.second.username.c_str()));
        //Save nickname
        file.write(pp.second.nickname.c_str(), sizeof(pp.second.nickname.c_str()));
        //
        file.write(std::to_string(pp.second.coma.size()).c_str(), sizeof(std::to_string(pp.second.coma.size()).c_str()));
        for(auto& coma : pp.second.coma)
        {
            for(int i = 0 ; i < coma.length(); i++){
                file.write(&(coma[i]), 1);
            }
        }
    }
    file.close();
    std::cout << "Save people done\n";
}

void Bot::read_People()
{
    std::ifstream file;
    file.open(".\\LOG\\people.data", std::ofstream::binary);
    if(!file.is_open())
    {
        std::cout << "File isnt open";
    }
    char sz[sizeof(size_t)];
    file.read(sz, sizeof(size_t));
    std::cout << sz << " -- Size \n";
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
        if(json["result"][i]["message"].contains("entities")){

            People person;
            int64_t str = json["result"][i]["message"]["from"]["id"];
            person.id = std::to_string(str);
            if(peoples.count(person.id) == 0){
                person.nickname = json["result"][i]["message"]["from"]["first_name"];
                person.coma.push_back(json["result"][i]["message"]["text"]);
                person.username = json["result"][i]["message"]["from"]["username"];
                peoples.insert(std::make_pair(person.id, person));
           }else{
                peoples.find(person.id)->second.coma.push_back(json["result"][i]["message"]["text"]);
            }

        }
    }

    std::cout << "----- Persons\n";
    for(auto& p : peoples)
    {
        p.second.count_size();
        std::cout << p.second;
    }
    return{};
}

int Bot::ty_meth(const std::string& coma ){
    auto txt = this->get_Responce(coma);
    save(txt, coma);
    return 0;
}