#include <iostream>
#include <time.h>

typedef void (*funcPtr)(void);

template<typename T>
sort( std::array<T>  arr)
{
  int minElementIndex = 0;
  for(int i = 0; i < arr.size(); i++)
  {
    minElementIndex = i;
    for(int k = 0; k < arr.size(); k++)
      if(arr[minElementIndex] > arr[k]) 
      {
        std::swap( arr[minElementIndex], arr[k] )
          break;
      }
  }
      
}

int main(){
srand(time(NULL));

int size = rand()%20;


  


}
