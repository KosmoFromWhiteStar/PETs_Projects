#include <iostream>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <fstream>

using namespace nlohmann;

int main()
{  
    std::ifstream file;
    file.open("./Conf/bot_api_token.txt");
    if(!file.is_open()){
        printf("File isnt open\n");
        return -1;
    }
    char str[1000];
    
    file.read(str, 1000);
    std::string url = "";
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        url += str[i];
    }
    std::cout << url << std::endl;
    std::string method = "";
    std::cin >> method;
    url += "/" + method;
    cpr::Response r = cpr::Get(
        cpr::Url{url});
    std::string out_path = "LOG/" + method + ".json";
    std::ofstream out_file(out_path);
    out_file << r.text;
    std::cout << r.text;
    out_file.close();
    file.close();
    return 0;
}