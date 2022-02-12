#include <iostream>
#include <string_view>
#include <array>
#include <functional>

    using namespace std;
int main()
{
    std::string sought;
    cout << "Enter sought: ";
    cin >> sought;

    std::string existing;
    cout << "enter existing: ";
    cin >> existing;

   auto lambda{
    [](string a, string b)
       {
           cout << "a: " << a << endl;
           cout << "b: " << b << endl;
           if(a.find(b) != std::string_view::npos) return "yes";
           else return "now";
       }
   };

   cout << lambda(existing, sought) << endl;
 /*
   auto lambda2{
    [](string a, string b)
       {
           cout << "a: " << a << endl;
           cout << "b: " << b << endl;
           return a.find(b) != std::string_view::npos;
       }
   };
*/
   std::array<string, 8> arr{
           "good",
           "day",
           "now",
           "ready",

           "to",
           "go",
           "help",
           "great"
   };
   auto lambda3{
       [sought](string str){
           return str.find(sought) != std::string_view::npos;
       }
   };

   auto found{
      std::find_if(
                  arr.begin(),
                  arr.end(),
                  [sought](std::string_view str){ return str.find(sought) != std::string::npos; }
                // 	lambda3(std::string_view str)
                  )
   };

    cout << *found << " found" << endl;
    return 0;
}
