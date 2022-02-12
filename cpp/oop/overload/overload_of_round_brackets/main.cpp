#include <iostream>
#include <cassert>
#include <string.h>

using namespace std;

class Matrix
{
private:
    double data[5][5];
public:
    Matrix()
    {
        //for(int row =0; row < 5; ++row)
        //    for(int col=0; col < 5; ++col )
        //        data[row][col] = 1;
        //for(int i = 0; i < 25; i++) cout << ((double*)data)[i] << " ";
        //cout << endl;
        memset(data, 0, sizeof(data));
    }
    double& operator()(int row, int col);
    void operator()();
    const double& operator()(int row, int col) const; //для константных объектов
};

int main()
{
    Matrix matrix;
    matrix(2,3) = 3.5;
   cout<<matrix(2,3) << endl;
   matrix();
   for(int i = 0; i < 5; i++) for (int k = 0; k < 5; k++) cout << matrix(i,k) << " ";
   cout << endl;

    return 0;
}

void Matrix::operator()(){
    memset(data, 0, sizeof(data));
}
double &Matrix::operator()(int row, int col)
{
   assert(col >= 0 && col < 5);
   assert(row >= 0 && row < 5);
   return data[row][col];
}

const double &Matrix::operator()(int row, int col) const
{
   assert(col >= 0 && col < 5);
   assert(row >= 0 && row < 5);
   return data[row][col];
}
