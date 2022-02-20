#include <iostream>
#include <QVector>

using namespace std;

int main(int argc, char *argv[])
{
  QVector<int> vec;
  vec.insert(0, 1);
  vec.append(2);

  QVector<int> &ref = vec;

  ref.append(4);
  ref.pop_back();

  QVector<int>::Iterator it;
  for(it = ref.begin(); it < ref.end(); it++)
      cout << *it << endl;
  return 0;
}
