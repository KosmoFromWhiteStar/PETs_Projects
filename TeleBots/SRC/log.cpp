#include "../INCL/log.h"

void output(const std::string& file_path){
    std::ifstream file(file_path);
    nlohmann::json js;
    file >> js;
    std::cout << "---------------\t[" << file_path << "] \t---------------\n";
    std::cout << js.dump(4) << std::endl;
    std::cout << "---------------\tEND OF [" << file_path << "] \t---------------\n";
}

void output_msg(const std::string& path){
        for (const auto & entry : std::filesystem::directory_iterator(path)){
            if( entry.path().extension() == ".json"){
                output(entry.path().string());
                //std::filesystem::remove(entry.path());
            }
        }
}