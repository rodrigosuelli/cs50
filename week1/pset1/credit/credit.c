#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  long card_number = get_long("Card Number: ");

  int card_length = floor(log10(labs(card_number))) + 1;

  int i = 0;
  int mult = 0, even_sum = 0, odd_sum = 0;
  int card_last_digit;
  int first_digit, second_digit;
  while (card_number > 0)
  {
    card_last_digit = card_number % 10;

    if (i % 2 == 1)
    {
      mult = card_last_digit * 2;
      while (mult > 0)
      {
        odd_sum += mult % 10;
        mult /= 10;
      }
    }
    else
    {
      even_sum += card_last_digit;
    }

    if (i == card_length - 2)
    {
      second_digit = card_last_digit;
    }
    else if (i == card_length - 1)
    {
      first_digit = card_last_digit;
    }

    card_number /= 10;
    i++;
  }

  int total_sum = even_sum + odd_sum;
  if (total_sum % 10 == 0)
  {
    int starting_digits = first_digit * 10 + second_digit;

    if ((starting_digits == 34 || starting_digits == 37) && card_length == 15)
    {
      puts("AMEX");
    }
    else if ((starting_digits >= 51 && starting_digits <= 55) && card_length == 16)
    {
      puts("MASTERCARD");
    }
    else if (starting_digits == 40 && (card_length == 13 || card_length == 16))
    {
      puts("VISA");
    }
    else
    {
      puts("Unknown brand");
    }
  }
  else
  {
    puts("INVALID");
  }
}
