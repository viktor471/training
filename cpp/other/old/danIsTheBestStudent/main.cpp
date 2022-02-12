#include <iostream>
#include <string_view>
#include <array>
#include <algorithm>

//using namespace std;

typedef  struct Student{
        std::string_view name;
        int value;
} Student;

int main()
{

    std::array<Student, 8> Students = {
        {
            {"Mark", 8},
            {"Anton", 9},
            {"Isaac", 10},
            {"Marta", 7},
            {"Franz", 6},
            {"Erich", 9},
            {"Edgar", 11},
            {"Henry", 10}
        }
    };

    auto lambda{
        [](Student a, Student b){
            return a.value < b.value;
        }
    };
    auto best{
        std::max_element(Students.begin(), Students.end(), lambda)
    };
    std::cout << best->name << std::endl;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
