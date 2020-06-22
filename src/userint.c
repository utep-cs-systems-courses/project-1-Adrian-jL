#include <stdio.h>

int main()
{
  char str[100];
  printf("Hello, Place input after the "$" \n");
  printf("$ ");
  fgets(str, 100, stdin);
  printf("%s", str);

  return 0;

