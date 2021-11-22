#include <iostream>
#include "strvec.h"

int main() {
    StrVec s;
    s.push_back(std::string("abc"));
    std::cout << *s.begin() << std::endl;
    s.push_back(std::string("efg"));
    for (auto b = s.begin(); b != s.end(); ++b) {
        std::cout << *b << " "; 
    }
    std::cout << std::endl;
    return 0;
}