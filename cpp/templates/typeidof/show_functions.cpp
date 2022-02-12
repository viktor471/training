#include "show_functions.h"


void show_types_of_arrays(    int arr [3][3],
                              int arr2[3],
                              int (*arr3)[3],
                              int ((*arr4)[3])[3],
                              int ( *arr5[3] )[3],
                              int ( *arr6 )[3][3],
                              int  **arr7,
                              std::fstream& my_stream )
{
    SHOW_TYPES_OF_ARRAYS( my_stream );
}

void show_content_of_arrays(  int arr [3][3],
                              int arr2[3],
                              int (*arr3)[3],
                              int ((*arr4)[3])[3],
                              int ( *arr5[3] )[3],
                              int ( *arr6 )[3][3],
                              int **arr7,
                              std::fstream& my_stream )

{
    SHOW_CONTENT_OF_ARRAYS( my_stream );
}

void show_sizes_of_arrays(    int arr [3][3],
                              int arr2[3],
                              int (*arr3)[3],
                              int ((*arr4)[3])[3],
                              int ( *arr5[3] )[3],
                              int ( *arr6 )[3][3],
                              int **arr7,
                              std::fstream& my_stream )
{
    SHOW_SIZES_OF_ARRAYS( my_stream );
}

void func_that_accept_arrays( int arr [3][3],
                              int arr2[3],
                              int (*arr3)[3],
                              int ((*arr4)[3])[3],
                              int ( *arr5[3] )[3],
                              int ( *arr6 )[3][3],
                              int **arr7,
                              std::fstream& my_stream )
{
   show_types_of_arrays  ( arr, arr2, arr3, arr4, arr5, arr6, arr7, my_stream );
   show_sizes_of_arrays  ( arr, arr2, arr3, arr4, arr5, arr6, arr7, my_stream );
   show_content_of_arrays( arr, arr2, arr3, arr4, arr5, arr6, arr7, my_stream );
}

