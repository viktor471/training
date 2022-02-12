#include <algorithm>
#include <iostream>
#include <QVector>

typedef QVector<char> Char_vect;
typedef QVector<char>::Iterator Iter;

void itHas(Char_vect vector, char symb)
{
    Iter it = std::find(vector.begin(), vector.end(), symb);
    if(it == vector.end())
       std::cout << "no" << std::endl;
    else
        std::cout << "yes" << std::endl;

}
int main(int argc, char *argv[])
{

    Char_vect let;
    let.insert(0, 'a');
    let.insert(1, 'b');
    itHas(let, 'c');
}
