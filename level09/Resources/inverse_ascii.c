#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  if (argc != 2)
    printf("Give just one token\n");
  else
  {
    for (int i = 0; i < strlen(argv[1]); i++)
      printf("%c", (int)(argv[1][i]) - i);
    printf("\n");
  }
}
