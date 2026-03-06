


#ifndef PRINT_H
#define PRINT_H

namespace print {
    // print and println
    // PRINT
    template<typename T>
    static void print(T head);
    template<typename T, typename ... Tail>
    static void print(T head, Tail... tail);
    // PRINTLN
    template<typename T>
    static void println(T head);
    template<typename T, typename ... Tail>
    static void println(T head, Tail... tail);

};

#endif