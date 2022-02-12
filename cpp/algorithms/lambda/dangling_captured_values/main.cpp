#include <iostream>
#include <string>

auto return_lambda_by_val()
{
    std::string hello = "hello";

    return [ hello ]()
    {
        std::cout << "by value:     " << hello << std::endl;
    };
}

auto return_lambda_by_ref()
{
    std::string hello = "hello";

    return [ &hello ]()
    {
        std::cout << "by reference: " << hello << std::endl;
    };

}

int main()
{

/*    auto func = return_lambda_by_ref();
    func();
*/
    auto func2 = return_lambda_by_val();
    func2();

    return 0;
}
