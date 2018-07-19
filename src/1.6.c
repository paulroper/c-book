#include <stdio.h>

#define LONGEST_WORD 50

int count_stuff(void);
int *count_words(int[]);
void print_histogram(int[]);

/* count digits, white space, others */
int count_stuff()
{
  int c, i, nwhite, nother;
  int ndigit[10];
  nwhite = nother = 0;

  for (i = 0; i < 10; ++i)
  {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF)
  {
    if (c >= '0' && c <= '9')
    {
      ++ndigit[c - '0'];
    }
    else if (c == ' ' || c == '\n' || c == '\t')
    {
      ++nwhite;
    }
    else
    {
      ++nother;
    }
  }

  printf("digits =");

  for (i = 0; i < 10; ++i)
  {
    printf(" %d", ndigit[i]);
  }

  printf(", white space = %d, other = %d\n",
         nwhite, nother);

  return 0;
}

int *count_words(int word_lengths[])
{
  int c, word_length;
  word_length = 0;

  while ((c = getchar()) != EOF)
  {
    if (c != ' ' && c != '\n' && c != '\t')
    {
      ++word_length;
    }
    else if (word_length > 0)
    {
      ++word_lengths[word_length];
      word_length = 0;
    }
  }

  return word_lengths;
}

void print_histogram(int word_lengths[])
{
  printf("Word lengths\n");
  for (int i = 1; i < LONGEST_WORD; ++i)
  {
    printf("Length %d ", i);
    for (int j = 0; j < word_lengths[i]; ++j)
    {
      printf("=");
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  int word_lengths[LONGEST_WORD];
  for (int i = 0; i < LONGEST_WORD; ++i)
  {
    word_lengths[i] = 0;
  }

  print_histogram(count_words(word_lengths));
  return 0;
}
