
#ifndef FIRST_STATIC_VAR_H
#define FIRST_STATIC_VAR_H

#include <iostream>

static int i;

    void show_first_static()
    {
        std::cout << i << std::endl;
    }

    void change_first_static(int _i)
    {
       i = _i;
    }

#endif // FIRST_STATIC_VAR_H
