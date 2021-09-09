#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int startSize;
  do
  {
    startSize = get_int("Start size?\n");
  } while (startSize < 9);

  int endSize;
  do
  {
    endSize = get_int("End size?\n");
  } while (endSize < startSize);

  int actualSize = startSize;
  int yearsRequired = 0;
  while (actualSize < endSize)
  {
    actualSize = actualSize + (actualSize / 3) - (actualSize / 4);
    yearsRequired++;
  }

  printf("Start size: %i\n", startSize);
  printf("End size: %i\n", endSize);
  printf("Years: %i\n", yearsRequired);
}
