#include <iostream>

using namespace std;

void curly(int cocount)
{
    if( cocount > 3 )
    {
        throw std::runtime_error("curly: invalid cocount number");
    }

    cout << "Got cocount " << cocount << endl;
}

void moe(int ccount)
{
    for (int c = 0; c < ccount; c++)
        curly(c);
}

class LarryCo {
public:
    LarryCo(void) { cout << "Setting up for Larry function..." << endl; }
    ~LarryCo(void) { cout << "Cleaning up after Larry function..." << endl; }
};

void larry(void) {
    LarryCo cleaner;
    moe(6);
}


int main()
{
    try
    {
        cout << "About to run the three stooges..." << endl;
        larry();
        cout << "I guess they are not so stupid! \n" << endl;
    }
    catch ( std::exception &e )
    {
       cout << "Caught exception: " << e.what() << endl;
    }
    return 0;
}
