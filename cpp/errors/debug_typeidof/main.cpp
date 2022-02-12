#include <iostream>
#include <string>
#include <cstring>


typedef unsigned short quint16;

using namespace std;

int main()
{
    int   arr    [3][3] {};                                                    \
    int   arr2   [3]    {};			    									   \
    int ( *arr3 )[3]          = reinterpret_cast <       int(*)[3]       >     \
                                                 ( new ( int[3]    ) {}  );    \
                                                                               \
    int (  ( *arr4 )[3] )[3]  = reinterpret_cast <       int(*)[3][3]    >     \
                                                 ( new ( int[3][3] ) {}  );    \
                                                                               \
    int ( *arr5[3] )[3]   													   \
    {                                  									       \
      reinterpret_cast<  int(*)[3]  >(  new ( int[3]  ) {} ),
      reinterpret_cast<  int(*)[3]  >(  new ( int[3]  ) {} ),
      reinterpret_cast<  int(*)[3]  >(  new ( int[3]  ) {} ),
    };

    int ( *arr6 )[3][3] = reinterpret_cast< int(*)[3][3] >( new ( int[3][3] ) {} );
    int **arr7 = new int*[3] { new int[3] {} , new int[3] {} , new int[3] {} };

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

    std::cout << "arr           "           \
              <<  arr           		 	\
              << std::endl;            		\
                                            \
    std::cout << "arr[0]        "           \
              <<  arr[0]            		\
              << std::endl;            		\
                                            \
    std::cout << "arr[0][0]     "           \
              <<  arr[0][0]            		\
              << std::endl            		\
              << std::endl;            		\
                                            \
                                            \
    std::cout << "arr2          "           \
              <<  arr2            			\
              << std::endl;            		\
                                            \
    std::cout << "arr2[0]       "           \
              <<  arr2[0]            		\
              << std::endl            		\
              << std::endl;            		\
                                            \
                                            \
    std::cout << "arr3          "           \
              <<  arr3            			\
              << std::endl;            		\
                                            \
    std::cout << "arr3[0]       "           \
              <<  arr3[0]            		\
              << std::endl;            		\
                                            \
    std::cout << "arr3[0][0]    "           \
              <<  arr3[0][0]            	\
              << std::endl            		\
              << std::endl;            		\
                                            \
                                            \
    std::cout << "arr4          "           \
              <<  arr4            			\
              << std::endl;                 \
                                            \
    std::cout << "arr4[0]       "           \
              <<  arr4[0]            	 	\
              << std::endl;            		\
                                            \
    std::cout << "arr4[0][0]    "           \
              <<  arr4[0][0]                \
              << std::endl            		\
              << std::endl;            		\
                                            \
                                            \
    std::cout << "arr5          "           \
              <<  arr5            			\
              << std::endl;            		\
                                            \
    std::cout << "arr5[0]       "           \
              <<  arr5[0]            		\
              << std::endl;            		\
                                            \
    std::cout << "arr5[0][0]    "           \
              <<  arr5[0][0]            	\
              << std::endl;            		\
                                            \
    std::cout << "arr5[0][0][0] "           \
              <<  arr5[0][0][0]            	\
              << std::endl            		\
              << std::endl;            		\
                                            \
                                            \
    std::cout << "arr6          "           \
              <<  arr6            			\
              << std::endl;            		\
                                            \
    std::cout << "arr6[0]       "           \
              <<  arr6[0]            		\
              << std::endl;            		\
                                            \
    std::cout << "arr6[0][0]    "           \
              <<  arr6[0][0]            	\
              << std::endl;            		\
                                            \
    std::cout << "arr6[0][0][0] "           \
              <<  arr6[0][0][0]            	\
              << std::endl            		\
              << std::endl;            		\
                                            \
                                            \
    std::cout << "arr7          "           \
              <<  arr7            			\
              << std::endl;            		\
                                            \
    std::cout << "arr7[0]       "           \
              <<  arr7[0]            		\
              << std::endl;            		\
                                            \
    std::cout << "arr7[0][0]    "           \
              <<  arr7[0][0]            	\
              << std::endl                  \
              << std::endl            		\
              << std::endl;

    cout << "Hello World!" << endl;
    return 0;
}
