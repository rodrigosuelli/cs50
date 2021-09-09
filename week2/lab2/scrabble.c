#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
  // Get input words from both players
  string word1 = get_string("Player 1: ");
  string word2 = get_string("Player 2: ");

  // Score both words
  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  // TODO: Print the winner
  if (score1 > score2)
  {
    puts("Player 1 wins!");
  }
  else if (score1 < score2)
  {
    puts("Player 2 wins!");
  }
  else
  {
    puts("Tie!");
  }
}

int compute_score(string word)
{
  // TODO: Compute and return score for string
  const int LOWER_A_ASCII_CODE = 97;
  const int LOWER_Z_ASCII_CODE = 122;

  int score = 0;
  int word_length = strlen(word);
  int letter_ascii_code, letter_alphabet_position;

  for (int i = 0; i < word_length; i++)
  {
    letter_ascii_code = tolower(word[i]);
    letter_alphabet_position = letter_ascii_code - LOWER_A_ASCII_CODE;

    if (letter_ascii_code >= LOWER_A_ASCII_CODE && letter_ascii_code <= LOWER_Z_ASCII_CODE)
    {
      score += POINTS[letter_alphabet_position];
    }
  }

  return score;
}
