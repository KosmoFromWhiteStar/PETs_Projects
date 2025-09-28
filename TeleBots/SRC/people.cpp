#include "../INCL/people.hpp"


void People::count_size(){
    this->size = id.length() + this->nickname.length() + this->username.length();
    for(auto str : coma)
    {
        this->size += str.length();
    }
}