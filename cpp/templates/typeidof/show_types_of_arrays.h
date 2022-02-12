#include <iostream>

#define SHOW_TYPES_OF_ARRAYS( my_stream )         \
    my_stream << "type    arr           "         \
              << typeid ( arr           ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr[0]        "         \
              << typeid ( arr[0]        ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr[0][0]     "         \
              << typeid ( arr[0][0]     ).name()  \
              << std::endl                        \
              << std::endl;                       \
                                                  \
                                                  \
    my_stream << "type    arr2          "         \
              << typeid ( arr2          ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr2[0]       "         \
              << typeid ( arr2[0]       ).name()  \
              << std::endl                        \
              << std::endl;                       \
                                                  \
                                                  \
    my_stream << "type    arr3          "         \
              << typeid ( arr3          ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr3[0]       "         \
              << typeid ( arr3[0]       ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr3[0][0]    "         \
              << typeid ( arr3[0][0]    ).name()  \
              << std::endl                        \
              << std::endl;                       \
                                                  \
                                                  \
    my_stream << "type    arr4          "         \
              << typeid ( arr4          ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr4[0]       "         \
              << typeid ( arr4[0]       ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr4[0][0]    "         \
              << typeid ( arr4[0][0]    ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr4[0][0][0] "         \
              << typeid ( arr4[0][0][0] ).name()  \
              << std::endl                        \
              << std::endl;                       \
                                                  \
                                                  \
    my_stream << "type    arr5          "         \
              << typeid ( arr5          ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr5[0]       "         \
              << typeid ( arr5[0]       ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr5[0][0]    "         \
              << typeid ( arr5[0][0]    ).name()  \
              << std::endl;   					  \
                                                  \
    my_stream << "type    arr5[0][0][0] "         \
              << typeid ( arr5[0][0][0] ).name()  \
              << std::endl      				  \
              << std::endl;   					  \
                                                  \
                                                  \
    my_stream << "type    arr6          "		  \
              << typeid ( arr6          ).name()  \
              << std::endl;						  \
                                                  \
    my_stream << "type    arr6[0]       "         \
              << typeid ( arr6[0]       ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr6[0][0]    "         \
              << typeid ( arr6[0][0]    ).name()  \
              << std::endl;						  \
                                                  \
    my_stream << "type    arr6[0][0][0] " 		  \
              << typeid ( arr6[0][0][0] ).name()  \
              << std::endl						  \
              << std::endl;						  \
                                                  \
    my_stream << "type    arr7          "    	  \
              << typeid ( arr7          ).name()  \
              << std::endl;						  \
                                                  \
    my_stream << "type    arr7[0]       "         \
              << typeid ( arr7[0]       ).name()  \
              << std::endl;                       \
                                                  \
    my_stream << "type    arr7[0][0]    "         \
              << typeid ( arr7[0][0]    ).name()  \
              << std::endl 						  \
              << std::endl 						  \
              << std::endl
