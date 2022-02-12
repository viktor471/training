
#define CREATE_ARRAYS()                                                        \
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
      reinterpret_cast<  int(*)[3]  >(  new ( int[3]  ) {} ),                  \
      reinterpret_cast<  int(*)[3]  >(  new ( int[3]  ) {} ),                  \
      reinterpret_cast<  int(*)[3]  >(  new ( int[3]  ) {} ),                  \
    };                                                                         \
                                                                               \
    int ( *arr6 )[3][3] = reinterpret_cast< int(*)[3][3] >( new ( int[3][3] ) {} );\
    int **arr7 = new int*[3] { new int[3] {} , new int[3] {} , new int[3] {} }


#define CREATE_ARRAYS2()                                                   	 \
    int arr[3][3] {};													  	 \
    int arr2[3] {};		    						     					 \
    int (*arr3)[3] = reinterpret_cast <int(*)[3]>(new(int[3]) {} );		     \
                                                                             \
    int ((*arr4)[3])[3] = reinterpret_cast<int(*)[3][3]>(new(int[3][3]) {} );\
                                                                             \
    int (*arr5[3])[3];								 					     \
                                                                             \
    for( int i = 0; i < 3; i++ )                                             \
        arr5[i] = reinterpret_cast<int(*)[3]>(new(int[3]) {} );   		     \
                                                                             \
    int ( *arr6 )[3][3] = reinterpret_cast<int(*)[3][3]>(new(int[3][3]) {} );\
    int **arr7 = new int*[3] { new int[3] {} , new int[3] {} , new int[3] {} };

