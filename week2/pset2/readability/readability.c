#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main()
{
  const int ASCII_SPACE = 32;
  const int ASCII_EXCLAMATION = 33;
  const int ASCII_PERIOD = 46;
  const int ASCII_QUEST_MARK = 63;

  int letters = 0, words = 0, sentences = 0;

  string text = get_string("Text: ");
  int text_lenght = strlen(text);

  // Calculate number of letters
  for (int i = 0; i < text_lenght; i++)
  {
    if (isalpha(text[i]))
    {
      letters++;
    }
  }

  // Calculate number of words
  for (int i = 0; i < text_lenght; i++)
  {
    if (text[i] == ASCII_SPACE)
    {
      words++;
    }
  }

  // Add one
  words += 1;

  // Calculate number of sentences
  for (int i = 0; i < text_lenght; i++)
  {
    if (text[i] == ASCII_QUEST_MARK || text[i] == ASCII_PERIOD || text[i] == ASCII_EXCLAMATION)
    {
      sentences++;
    }
  }

  // Calculate grade
  const float L = (float)letters / words * 100;
  const float S = (float)sentences / words * 100;
  float index = 0.0588 * L - 0.296 * S - 15.8;
  int grade = roundf(index);

  if (grade < 1)
  {
    puts("Before Grade 1");
  }
  else if (grade >= 16)
  {
    puts("Grade 16+");
  }
  else
  {
    printf("Grade: %d\n", grade);
  }
}
