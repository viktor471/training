#include <QCoreApplication>
#include <iostream>
#include "variants.h"


int main()
{

    try {
        variant_1();
    }
    catch( Files::file_was_not_opened& e )
    {
        e.what();
    }
    catch(...)
    {
        std::cerr << "hhh" << std::endl;
    }

/*  int    arr  [3][3];
    int    arr2 [3];
    int  (*arr3)[3];
    int ((*arr4)[3])[3];
    int  (*arr5 [3])[3];
    int  (*arr6)[3] [3];
    int  **arr7;

    print << "type arr           "
    print << "type arr[0]        "
    print << "type arr[0][0]     "
    print << "type arr2          "
    print << "type arr2[0]       "
    print << "type arr3          "
    print << "type arr3[0]       "
    print << "type arr3[0][0]    "
    print << "type arr4          "
    print << "type arr4[0]       "
    print << "type arr4[0][0]    "
    print << "type arr4[0][0][0] "

    print << "size arr           "
    print << "size arr[0]        "
    print << "size arr[0][0]     "
    print << "size arr2          "
    print << "size arr2[0]       "
    print << "size arr3          "
    print << "size arr3[0]       "
    print << "size arr3[0][0]    "
    print << "size arr4          "
    print << "size arr4[0]       "
    print << "size arr4[0][0]    "
    print << "size arr4[0][0][0] "

*/

    return 0;
}
