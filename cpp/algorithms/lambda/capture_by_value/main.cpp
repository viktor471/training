#include <iostream>

using namespace std;

int main()
{
    int ammo = 10;
    int *ptr = &ammo;
    auto shoot{
        [ammo](){
            //--ammo; std::cout << "Pew " << ammo << " shot(s) left.\n";
        }
    };

    // вызов лямбды
    shoot();

    auto shoot2{
        [ammo]() mutable {
            --ammo;

            std::cout << "Pew! " << ammo << "shot(s) left.\n";
        }
    };

    shoot2();
    shoot2();

    std::cout << "without lambda ammo: " << ammo << endl;

    auto shoot3{
        [ptr](){
            //*ptr = *ptr - 1;
            --(*ptr);
            cout << "ptr in shoot3: " << *ptr << endl;
        }
    };

    shoot3();
    std::cout << "ammo after shoot3: " << ammo << endl;

    ammo++; //--------- !!!!!!!!!!!!!!!!!!! возвращение ammo к прошлому значению !!!!!!!!!!!!!!!!!! --------------

    auto shoot4{
        [&ammo]()
        {
            --ammo;
            std::cout << "ammo in shoot4: " << ammo << endl;
        }
    };

    shoot4();

    cout << "ammo out of shoot4: " << ammo << endl;
   int a = 5;
    auto shoot5{
        [ammo, a](){
            cout << "ammo: " << ammo << endl;
            cout << "a: " << a << endl;
            int g = a + ammo;
            cout << "int g = a + ammo" << endl;
            cout << "g: " << g << endl;
        }
    };

    shoot5();

   typedef class my_class{
     public:
        my_class(){
            cout << "constructor:" << endl;
        }
        ~my_class(){
            cout << "destructor: " << endl;
        }
    } My_class;
   My_class c;
    auto shoot6{
        [c](){
           cout << "shoot6" << endl;
        }
    };

    cout << "call of shoot6" << endl;
    shoot6();
    shoot6();

    return 0;

}
