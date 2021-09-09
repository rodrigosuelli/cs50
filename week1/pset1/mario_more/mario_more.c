#include <cs50.h>
#include <stdio.h>

int main()
{
  // Get height (between 1 and 8, inclusive)
  int height;
  do
  {
    height = get_int("Height: ");
  } while (height < 1 || height > 8);

  // Print Pyramid Code
  for (int i = 0; i < height; i++)
  {
    // Row
    // Before Spaces
    for (int l = height - 1; l > i; l--)
    {
      printf(" ");
    }
    // Left Pyramid Hashes
    for (int j = 0; j <= i; j++)
    {
      printf("#");
    }
    // Two space gap
    printf("  ");
    // Right Pyramid Hashes
    for (int k = 0; k <= i; k++)
    {
      printf("#");
    }
    // New line break
    printf("\n");
  }
}
