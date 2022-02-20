#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int MIN = 0;
int MAX = 100;
int MAX_ELEMENTS = 5000;

class Histogram
{

private:
  std::vector<double> _columns;
  std::vector<double> _borders;

  double _max_value;
  double _min_value;
  uint16_t _numbers_amount;

public:
  Histogram( std::vector<double> &numbers, uint16_t columns = 20 ):
    _numbers_amount(0)
  {
    std::sort(numbers.begin(), numbers.end());
    _min_value = numbers.front();
    _max_value = numbers.back();

//    for( size_t i = 0; i < numbers.size(); i++ )
//      std::cout << "numbers.at(" << i << ") " << numbers.at(i) << std::endl;

    std::cout << "_max_value: " << _max_value << std::endl;
    std::cout << "_min_value: " << _min_value << std::endl;

    _columns.resize(columns);
    double border = _min_value;
    double step   = ( _max_value - _min_value ) / columns;

    for( uint16_t i = 0; i < columns; i++ )
    {
      _borders.push_back(border);
      border += step;
    }

//    for( uint16_t i = 0; i < columns; i++ )
//      std::cout << "_borders.at("
//                << i
//                << ")"
//                << _borders.at(i)
//                << std::endl;

    for( uint16_t i = 0; i < numbers.size(); i++ )
      changeHistogram(numbers.at(i));
  }

  void changeHistogram(double value)
  {
    size_t index = static_cast<double>( value - _min_value ) /
                   ( _max_value - _min_value ) * _columns.size();

//    std::cout << "index " << index << std::endl;

    if( index == _columns.size() )
      index--;

    _columns.at(index)++;
    _numbers_amount++;
  }

  void print()
  {
    for( size_t i = 0; i < _columns.size(); i++ )
    {
      _columns.at(i) = ( static_cast<double>(_columns.at(i))/_numbers_amount ) * 900;
//      std::cout << "_columns[" << i << "] " << _columns[i] << std::endl;
      std::cout << std::fixed
                << std::setw(20)
                << _borders.at(i)
                << " "
                << std::string(_columns[i], '*')
                << '\n';
    }

    uint16_t min_column_amount = *std::min_element(_columns.begin(), _columns.end());
    uint16_t max_column_amount = *std::max_element(_columns.begin(), _columns.end());
    double   min_all = static_cast<double>(min_column_amount)/_numbers_amount;
    double   max_all = static_cast<double>(max_column_amount)/_numbers_amount;

    std::cout << "min/all: " << min_all << "\n";
    std::cout << "max/all: " << max_all << "\n";
    std::cout << "delta:   " << ( max_all - min_all ) << "\n" << std::endl;

  }

  void load_vector( std::vector<double>& numbers )
  {
    for( size_t i = 0; i < numbers.size(); i++ )
    {
//      std::cout << "numbers.at("
//                << i
//                << ")"
//                << numbers.at(i) << std::endl;

      changeHistogram(numbers.at(i));
    }
  }

};

int main()
{

  // Инициализация ГПСЧ
  srand(time(NULL));

  // Массивы для хранения получившихся выборок
  std::vector<double> vec_1;
  vec_1.reserve(MAX_ELEMENTS);
  std::vector<double> vec_2;
  vec_1.reserve(MAX_ELEMENTS/6);

  // Промежуточная ячейка для хранения случайных чисел
  double rand_value = 0;

//  srand(1531);

  // Заполнение массивов псевдослучайными числами
  for( int i = 0; i < MAX_ELEMENTS; i++)
  {
      rand_value = rand()*static_cast<double>(MAX)/RAND_MAX;
//      std::cout << "rand_value " << rand_value << std::endl;
    if( i%6 != 0)
      vec_1.push_back(rand_value);
    else
      vec_2.push_back(rand_value);
  }

//  for( int i = 0; i < MAX_ELEMENTS; i++)
//  {
//      rand_value = rand()*static_cast<double>(MAX)/RAND_MAX;
//      vec_1.push_back(rand_value);
//  }

//  for( int i = 0; i < MAX_ELEMENTS/3; i++)
//  {
//      rand_value = rand()*static_cast<double>(MAX)/RAND_MAX;
//      vec_2.push_back(rand_value);
//  }

  Histogram hist_1(vec_1);
  Histogram hist_2(vec_2);

//  std::cout << "vector that consists of " << ( (int)vec_1.size() ) << std::endl;
  hist_1.print();
//  std::cout << "vector that consists of " << ( (int)vec_2.size() ) << std::endl;
  hist_2.print();
  return 0;
}