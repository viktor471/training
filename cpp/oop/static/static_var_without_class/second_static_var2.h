
#ifndef SECOND_STATIC_VAR2_H
#define SECOND_STATIC_VAR2_H

#include <iostream>

    static int i;

    void show_second_static(){
        std::cout << i << std::endl;
    }

    void change_second_static(int _i)
    {
        i = _i;
    }
#endif // SECOND_STATIC_VAR2_H
