#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1,2,3,4};

    std::vector<int>::iterator it = std::find(vec.begin(), vec.begin() + 1, 3);

    if(it == vec.end())
        std::cout << "no" << std::endl;
    if(it == (vec.begin() + 1))
        std::cout << "yes" << std::endl;

    return 0;
}
