#include <QCoreApplication>
#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int b = 7 + 256;
    char c[4] = {};
    memcpy(c, &b, sizeof (int));

    using std::cerr, std::dec, std::setw, std::setfill, std::hex, std::endl;

    for( int i = 0; i < 4; i++)
    {

                std::cerr << "[" << std::dec << std::setw(2) << std::setfill('0') << i << "] "
                          << std::hex
                          << std::setfill('0')
                          << std::setw(2)
                          << static_cast<int>(
                                      static_cast<unsigned char>(c[i])
                             )
                          << " ";
                     if( !((i + 3)%10)) std::cerr << std::endl;
    }

    std::cerr << std::endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
    return a.exec();
}
