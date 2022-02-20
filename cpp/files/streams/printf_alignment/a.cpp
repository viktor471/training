#include <stdio.h>
#include <stdint.h>
#include <string.h>

void centerText( const char *text, int fieldWidth)
{
  uint16_t padLen = (fieldWidth - strlen(text))/2;
  printf("%*s %s %*s", padLen,"", text, padLen,"");
}

int main()
{
  centerText( "hello", 28);
  printf("|");
  printf("\n");
  centerText( "Hello my friend", 28);
  printf("|");
  printf("\n");
}
