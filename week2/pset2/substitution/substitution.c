#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  const int IDEAL_KEY_LENGTH = 26;
  const int LOWER_A_ASCII_CODE = 97;

  // Verify if inserted the key
  if (argc < 2)
  {
    puts("Insert a key");
    return 1;
  }
  else if (argc > 2)
  {
    puts("Insert just one key");
    return 1;
  }

  string key = argv[1];
  int key_length = strlen(key);

  // Check key length
  if (key_length != IDEAL_KEY_LENGTH)
  {
    puts("Key must have 26 characters length");
    return 1;
  }

  // Check for non-alphabetic characters
  for (int i = 0; i < key_length; i++)
  {
    if (!isalpha(key[i]))
    {
      puts("Key characters must be alphabetic");
      return 1;
    }
  }

  // Check for repeated characters
  for (int i = 0; i < key_length; i++)
  {
    for (int j = 0; j < key_length; j++)
    {
      if (j != i && tolower(key[j]) == tolower(key[i]))
      {
        puts("Key must not have repeated characters (case-insentitive)");
        return 1;
      }
    }
  }

  // Get plaintext
  string ciphertext = get_string("plaintext: ");
  int ciphertext_length = strlen(ciphertext);

  // Encipher
  int charac_ascii_code, charac_alphabet_position;
  for (int i = 0; i < ciphertext_length; i++)
  {
    if (isalpha(ciphertext[i]))
    {
      charac_ascii_code = tolower(ciphertext[i]);
      charac_alphabet_position = charac_ascii_code - LOWER_A_ASCII_CODE;

      if (islower(ciphertext[i]))
      {
        ciphertext[i] = tolower(key[charac_alphabet_position]);
      }
      else
      {
        ciphertext[i] = toupper(key[charac_alphabet_position]);
      }
    }
  }

  // Print ciphertext
  printf("ciphertext: %s\n", ciphertext);

  return 0;
}
