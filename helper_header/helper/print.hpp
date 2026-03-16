


#ifndef PRINT_H
#define PRINT_H

namespace print {
    //
    // print
    //
    template<typename T>
    void print(T head) {
        std::cout << head;
    }

    template<typename T, typename... Tail>
    void print(T head, Tail... tail) {
        std::cout << head << ' ';
        print(tail...);
    }

    //
    // println
    //
    template<typename T>
    void println(T head) {
        std::cout << head << std::endl;
    }

    template<typename T, typename... Tail>
    void println(T head, Tail... tail) {
        std::cout << head << ' ';
        print(tail...);
        std::cout << std::endl;
    }

};

#endif