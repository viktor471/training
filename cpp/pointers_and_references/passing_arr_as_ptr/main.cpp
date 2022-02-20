#include <iostream>


void func(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

}
int main()
{
    int arr[10];

    int *arr2 = new int;

    func(arr, 1);

    func(arr2, 1);

    return 0;
}
