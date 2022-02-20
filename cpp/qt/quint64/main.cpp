//#include <QCoreApplication>
#include <iostream>
#include <QtCore>

using namespace std;

int main(int argc, char *argv[])
{
    quint64 a = 0;
    a--;
    cout << a << endl;
    int deg = 0;
    while ( a/=10 ) deg++;
    cout << "deg" << deg << endl << endl << "==============" << endl;

    a = 0;
    a--;

    deg = 0;

    while (a > 0)
    {
        cout << (a/=10) << endl;
        cout << "deg " << ++deg << endl << endl;
    }
    //return a.exec();
    return 3;
}
