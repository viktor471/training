#include <iostream>
#include <functional>


using namespace std;

void CallingLambda(const std::function<void(int)>& fn)
{
    fn(3);
}
int main()
{
    std::function<void(int)> lambda{
        [](int displaing_number)
        {
            cout << displaing_number << endl;
        }
    };
    CallingLambda(lambda);
    return 0;
}
