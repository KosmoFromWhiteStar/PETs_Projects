#pragma once 
#include "Headers.hpp"

struct People{
    size_t size = 0;
    std::string id;
    std::string username;
    std::string nickname;
    std::vector<std::string> coma;
    void count_size();
    friend std::ostream& operator<<(std::ostream& os, People _Self)
    {
        os << "Size \t#>" << _Self.size << "\nID \t#> " << _Self.id << "\nUsername \t#> " << _Self.username
        << "\nNickname \t#> " << _Self.nickname << std::endl;
        for(int i = 0; i < _Self.coma.size(); i++){
            os << "Coma \t# " << i << " > " << _Self.coma[i] << std::endl;
        }
        return os;
    }
};