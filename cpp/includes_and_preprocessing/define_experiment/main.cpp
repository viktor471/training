#include <iostream>

using namespace std;

int main()
{
#ifdef __SILENT__

    cout << "silent" << endl;
#endif

#ifdef hh
    cout << "hh" << endl;
#endif
    return 0;
}
