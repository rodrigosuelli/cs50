#include <stdio.h>
#include <cs50.h>

int main(void)
{
  // Get user input (his name)
  string name = get_string("What is your name?\n");
  printf("Hello, %s!\n", name);
}
