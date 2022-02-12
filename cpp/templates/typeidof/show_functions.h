#ifndef SHOW_FUNCTIONS_H
#define SHOW_FUNCTIONS_H

#include "show_types_of_arrays.h"
#include "show_sizes_of_arrays.h"
#include "show_content_of_arrays.h"
#include "open_files.h"

#define MACROS_FOR_SHOW_ARRAYS_WITHOUT_PASSING_TO_FUNCTION( my_stream ) \
    SHOW_TYPES_OF_ARRAYS  ( my_stream ); \
    SHOW_SIZES_OF_ARRAYS  ( my_stream ); \
    SHOW_CONTENT_OF_ARRAYS( my_stream )

static std::fstream& inFunc = Files::getFstream_InFunction();

void show_types_of_arrays   ( int arr [3][3],
                              int arr2[3],
                              int (*arr3)[3],
                              int ((*arr4)[3])[3],
                              int ( *arr5[3] )[3],
                              int ( *arr6 )[3][3],
                              int  **arr7,
                              std::fstream& my_stream );

void show_content_of_arrays(  int arr [3][3],
                              int arr2[3],
                              int (*arr3)[3],
                              int ((*arr4)[3])[3],
                              int ( *arr5[3] )[3],
                              int ( *arr6 )[3][3],
                              int **arr7,
                              std::fstream& my_stream );

void show_sizes_of_arrays(    int arr [3][3],
                              int arr2[3],
                              int (*arr3)[3],
                              int ((*arr4)[3])[3],
                              int ( *arr5[3] )[3],
                              int ( *arr6 )[3][3],
                              int **arr7,
                              std::fstream& my_stream );

void func_that_accept_arrays( int arr [3][3],
                              int arr2[3],
                              int (*arr3)[3],
                              int ((*arr4)[3])[3],
                              int ( *arr5[3] )[3],
                              int ( *arr6 )[3][3],
                              int **arr7,
                              std::fstream& my_stream = inFunc );


#endif // SHOW_FUNCTIONS_H
