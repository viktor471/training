#include <iostream>

class cl{
public:
    int i;
    int g;
    cl(int i, int g)
    {
        this->i = i;
        this->g = g;
    }
    void remap(int i, int g)
    {
        new (this) cl(i, g);
    }

};
int main()
{
   cl ex(2, 3);

   std::cout << "ex.i " << ex.i << " ex.g " << ex.g << std::endl;
   ex.remap(5,6);

   std::cout << "ex.i " << ex.i << " ex.g " << ex.g << std::endl;
}
