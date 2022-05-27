//
// Created by kirill_kazarin on 15.05.22.
//
#include <map>
#include <iostream>


int main(){
    std::string ss("123456");
    auto s1=std::string(ss.crbegin(), ss.crend());
    std::cout << s1;
    return 0;
}