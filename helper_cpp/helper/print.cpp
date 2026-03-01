//
// Created by 00077 on 01.03.2026.
//
#include <iostream>

#include "../../helper_header/helper/print.h"

//
// print
//
template<typename T>
void print::print(T head) {
    std::cout << head;
}

template<typename T, typename... Tail>
void print::print(T head, Tail... tail) {
    std::cout << head << ' ';
    print::print(tail...);
}

//
// println
//
template<typename T>
void print::println(T head) {
    std::cout << head << std::endl;
}

template<typename T, typename... Tail>
void print::println(T head, Tail... tail) {
    std::cout << head << ' ';
    print::print(tail...);
    std::cout << std::endl;
}
