#include <iostream>

int main(int argc, char *argv[])
{
  char *a = new char;
  int i = 0;
  while(i < 10000000000)
  {
      printf("%c ", (a + i)[0]);
      i++;
  }
}
