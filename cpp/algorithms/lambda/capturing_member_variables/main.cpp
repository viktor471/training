#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class oddCounter
{
    // tracks the count of odd numbers encountered
        int mCounter = 0;
public:
        int getCount() { return mCounter; }

        void update(std::vector<int> &vec)
        {
            // Capturing member variables by values will not work
            // will result in compile error
          /*  std::for_each(vec.begin(), vec.end(), [mCounter](int element) mutable
                                                  {
                                                        if(element%2)
                                                            mCounter++;
                                                  }) */
           std::for_each(vec.begin(), vec.end(),
                         [this](int element) mutable
                         {
                                if(element%2) mCounter++;
                         });
        }

};

int main()
{
   std::vector<int> vec = {12, 3, 2, 1, 8, 9, 0, 2, 3, 9, 7};

   oddCounter counterObj;

   counterObj.update(vec);

   int count = counterObj.getCount();

   cout << "Counter: " << count << endl;
    return 0;
}
