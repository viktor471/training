#include "variants.h"
#include "open_files.h"

void variant_1()
{
    CREATE_ARRAYS();
{
    // arr - array [3] of arrays [3] of int
    for( int whole_arr1d = 0 ; whole_arr1d < 3; whole_arr1d++  )
        for( int arr_1d_element = 0; arr_1d_element < 3; arr_1d_element++  )
            (  arr[ whole_arr1d ]  )[ arr_1d_element ]
                = whole_arr1d*10 + arr_1d_element;

    // arr - array [3] of arrays [3] of int
    for( int whole_arr1d = 0 ; whole_arr1d < 3; whole_arr1d++  )
        for( int arr_1d_element = 0; arr_1d_element < 3; arr_1d_element++  )
            (  arr[ whole_arr1d ]  )[ arr_1d_element ]
                = whole_arr1d*10 + arr_1d_element;

    // arr2 array [3] of int
    for( int arr_1d_element = 0; arr_1d_element < 3; arr_1d_element++ )
        arr2[ arr_1d_element ] = arr_1d_element;

    // arr3 - pointer to array [3] of int
    for( int arr_1d_element = 0; arr_1d_element < 3; arr_1d_element++ )
        ( *arr3 )[ arr_1d_element ] = arr_1d_element*100;

    // arr4 - pointer to array [3] of arrays [3] of int
    for( int whole_arr1d = 0; whole_arr1d < 3; whole_arr1d++ )
        for( int arr_1d_element = 0; arr_1d_element < 3; arr_1d_element++ )
            (  ( *arr4 )[ whole_arr1d ]  )[ arr_1d_element ]
                =  whole_arr1d*100 + arr_1d_element*10;

    // arr5 - array of pointers to array [3] of int
    for( int pointer_to_array3 = 0; pointer_to_array3 < 3; pointer_to_array3++ )
      for( int arr_1d_element = 0; arr_1d_element < 3; arr_1d_element++ )
         ( *( arr5[ pointer_to_array3 ] ) )[ arr_1d_element ] =
              pointer_to_array3*1000 + arr_1d_element*10;

    // arr6 - pointer to array [3] of arrays [3] of int
    for( int whole_arr1d = 0; whole_arr1d < 3; whole_arr1d++ )
        for( int arr_1d_element = 0; arr_1d_element < 3; arr_1d_element++ )
           ( ( *arr6 )[ whole_arr1d ] )[ arr_1d_element ] =
                whole_arr1d*1000 + arr_1d_element;

    for( int whole_arr1d = 0; whole_arr1d < 3; whole_arr1d++ )
        for( int arr_1d_element = 0; arr_1d_element < 3; arr_1d_element++ )
            ( arr7[ whole_arr1d ] )[ arr_1d_element ] = whole_arr1d*1000 + arr_1d_element*10;
}
    std::fstream& file = Files::getFstream_OutFunction();
    MACROS_FOR_SHOW_ARRAYS_WITHOUT_PASSING_TO_FUNCTION( file );

    func_that_accept_arrays( arr, arr2, arr3, arr4, arr5, arr6, arr7 );
}

void variant_2()
{
    CREATE_ARRAYS2();
{
    typedef  quint16   Whole_arr1d_index;
    typedef  quint16   Arr_1d_element_index;
    typedef  quint16   PointerToArray3;
    typedef  int(     *Int_ptr_to_array     )[3];
    typedef  int       Int3_arr[3];

    // arr - array [3] of arrays [3] of int
    for( Whole_arr1d_index i = 0 ; i < 3; i++  )
        for(  Arr_1d_element_index k = 0 ; k < 3; k++  )
            ( arr[i] )[k] = i*10 + k;

    // arr - array [3] of arrays [3] of int
    for( Whole_arr1d_index i = 0 ; i < 3; i++  )
        for( Arr_1d_element_index k = 0; k < 3; k++  )
            ( arr[i] )[k] = i*10 + k;

    // arr2 array [3] of int
    for( Arr_1d_element_index i = 0; i < 3; i++ )
        arr2[i] = i;

    {
        int* in_arr = *arr3;
        // arr3 - pointer to array [3] of int
        for( Arr_1d_element_index i = 0; i < 3; i++ )
        in_arr[i] = i*100;
    }

    int (&in_arr)[3][3] = *arr4;
    // arr4 - pointer to array [3] of arrays [3] of int
    for( Whole_arr1d_index i = 0; i < 3; i++ )
        for( Arr_1d_element_index k = 0; k < 3; k++ )
             in_arr[i][k] = i*100 + k*10;

    // arr5 - array of pointers to array [3] of int
    for(  PointerToArray3 i = 0; i < 3; i++ )
      for( Arr_1d_element_index k = 0; k < 3; k++ )
         ( *( arr5[ i ] ) )[ k ] = i*1000 + k*10;

    {
    int in_arr[3][3];
    // arr6 - pointer to array [3] of arrays [3] of int
    for( Whole_arr1d_index i = 0; i < 3; i++ )
        for( Arr_1d_element_index k = 0; k < 3; k++ )
           in_arr[i][k] = i*1000 + k;

    memcpy( arr6, &in_arr, sizeof (in_arr) );
    }
}
    std::fstream& file = Files::getFstream_OutFunction();
    MACROS_FOR_SHOW_ARRAYS_WITHOUT_PASSING_TO_FUNCTION( file );

    func_that_accept_arrays( arr, arr2, arr3, arr4, arr5, arr6, arr7 );
}

void variant_3()
{
    CREATE_ARRAYS();
{
    typedef  int(     *Int_ptr_to_array     )[3];
    typedef  int* 	   Pointer_to_element;

    // arr - array [3] of arrays [3] of int
    int i = 0, k = 0;
    for(  int (*in_arr)[3] = arr; in_arr < &arr[3]; in_arr++, i++  )
        for(  int* element_arr = in_arr[0] ; element_arr < in_arr[3]; element_arr++, k++  )
             (*element_arr) = i*101 + k*10;

    i = 0, k = 0;
    for(  Int_ptr_to_array in_arr = arr; in_arr < &arr[3]; in_arr++, i++ )
        for(  Pointer_to_element element_arr = in_arr[0] ; element_arr < in_arr[3]; element_arr++, k++  )
             (*element_arr) = i*101 + k*10;

    // arr2 array [3] of int
    i = 0;
    for( Pointer_to_element element_arr = arr2; element_arr < &arr2[3]; element_arr++, i++ )
        (*element_arr) = i;

        // arr3 - pointer to array [3] of int
    i = 0;
    for( Pointer_to_element element = *arr3 ; element < arr3[3]; element++, i++ )
      (*element) = i*100;

    // arr4 - pointer to array [3] of arrays [3] of int
    for( Int_ptr_to_array in_arr = *arr4; in_arr < &((*arr4)[3]); in_arr++, i++ )
        for( Pointer_to_element element = in_arr[0]; element <= in_arr[3]; k++ )
             *element = i*100 + k*10;

    // arr5 - array of pointers to array [3] of int
    Int_ptr_to_array in_arr;
    Pointer_to_element element;
    i = 0, k = 0;
    for(  in_arr = arr5[0]; in_arr <= arr5[2]; in_arr++, i++ )
      for( element = *in_arr; element < *in_arr + 3;  element++, k++)
         *element = i*1000 + k*10;

    // arr6 - pointer to array [3] of arrays [3] of int
        for( in_arr = *arr6, i = 0, k = 0; in_arr <= *arr6 + 2; in_arr++, i++ )
        for( element = *in_arr; element <= *in_arr + 2; element++, k++ )
           *element = i*1000 + k;

}
    std::fstream& file = Files::getFstream_OutFunction();
    MACROS_FOR_SHOW_ARRAYS_WITHOUT_PASSING_TO_FUNCTION( file );

    func_that_accept_arrays( arr, arr2, arr3, arr4, arr5, arr6, arr7 );
}

void variant_4()
{
    CREATE_ARRAYS2();
{
    typedef  quint16   Whole_arr1d_index;
    typedef  quint16   Arr_1d_element_index;
    typedef  quint16   PointerToArray3;
    typedef  int(     *Int_ptr_to_array     )[3];
    typedef  int       Int3_arr[3];

    // arr - array [3] of arrays [3] of int
    for( Whole_arr1d_index i = 0 ; i < 3; i++  )
        for(  Arr_1d_element_index k = 0 ; k < 3; k++  )
            *( *( arr + i ) + k ) = i*10 + k;

    // arr2 array [3] of int
    for( Arr_1d_element_index i = 0; i < 3; i++ )
        *( arr2 + i ) = i;

    // arr3 - pointer to array [3] of int
    for( Arr_1d_element_index i = 0; i < 3; i++ )
        *( ( *arr3 ) + i ) = i;

    // arr4 - pointer to array [3] of arrays [3] of int
    for( Whole_arr1d_index i = 0; i < 3; i++ )
        for( Arr_1d_element_index k = 0; k < 3; k++ )
            *( *( ( *arr4 ) + i ) + k ) = i*100 + k*10;

    // arr5 - array of pointers to array [3] of int
    for(  PointerToArray3 i = 0; i < 3; i++ )
      for( Arr_1d_element_index k = 0; k < 3; k++ )
         *( **( arr5 + i ) + k ) = i*1000 + k*10;

    // arr6 - pointer to array [3] of arrays [3] of int
    for( Whole_arr1d_index i = 0; i < 3; i++ )
        for( Arr_1d_element_index k = 0; k < 3; k++ )
            *( *( ( *arr6 ) + i ) + k ) = i*1000 + k;

}
    std::fstream& file = Files::getFstream_OutFunction();
    MACROS_FOR_SHOW_ARRAYS_WITHOUT_PASSING_TO_FUNCTION( file );

    func_that_accept_arrays( arr, arr2, arr3, arr4, arr5, arr6, arr7 );
}

