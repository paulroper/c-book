#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define TRUE 1
#define FALSE 0

int reverse_input(void);
void reverse(char line[], char reversed_line[]);
int trim_input(void);
int is_blank(char line[]);
int trim_line(char line[], char trimmed_line[]);
int get_end_index(char line[]);
int find_longest_line(void);
int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void zero_array(char line[]);

int main(int argc, char const *argv[])
{
  trim_input();
  return 0;
}

int reverse_input()
{
  int len;
  char line[MAXLINE], reversed_line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    reverse(line, reversed_line);
    printf("%s", reversed_line);
  }

  return 0;
}

void reverse(char line[], char reversed_line[])
{
  int j = 0;
  int end_pos = get_end_index(line);

  for (int i = end_pos - 1; i >= 0; i--)
  {
    reversed_line[j] = line[i];
    j++;
  }

  reversed_line[end_pos] = '\n';
  reversed_line[end_pos + 1] = '\0';
}

/* trims lines with trailing whitespace, removes blank lines */
int trim_input()
{
  int len, new_len;
  char line[MAXLINE];
  char trimmed_line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    if (!is_blank(line))
    {
      new_len = trim_line(line, trimmed_line);
      printf("%s", trimmed_line);
    }
  }

  return 0;
}

/* returns TRUE(1) or FALSE(0) */
int is_blank(char line[])
{
  int blank = TRUE;
  for (int i = 0; i < MAXLINE; i++)
  {
    if (line[i] == '\n')
    {
      return blank;
    }
    else if (line[i] != ' ' || line[i] != '\t')
    {
      blank = FALSE;
    }
  }

  return blank;
}

/* trim line and return length of new string */
int trim_line(char line[], char trimmed_line[])
{
  int end_pos = get_end_index(line);
  int new_end_pos = end_pos;
  int trimming = FALSE;

  zero_array(trimmed_line);

  for (int i = end_pos - 1; i >= 0; i--)
  {
    if (line[i + 1] == '\n' && line[i] == ' ')
    {
      trimming = TRUE;
    }

    if ((line[i] == ' ' || line[i] == '\t') && trimming == TRUE)
    {
      /* ignore this character as we're trimming */
    }
    else if (line[i] != ' ' && trimming == TRUE)
    {
      trimming = FALSE;
      new_end_pos = i + 1;

      trimmed_line[i] = line[i];
    }
    else
    {
      trimmed_line[i] = line[i];
    }
  }

  trimmed_line[new_end_pos] = '\n';
  trimmed_line[new_end_pos + 1] = '\0';

  return new_end_pos;
}

/* find the line break in a string and return the index */
int get_end_index(char line[])
{
  for (int i = 0; i < MAXLINE; i++)
  {
    if (line[i] == '\n')
    {
      return i;
    }
  }

  return -1;
}

/* print the longest input line */
int find_longest_line()
{
  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  max = 0;

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    if (len > 80)
    {
      /* A really, really, really, really, really, really, really, really, really, really, long line */
      printf("Line > 80 chars: %s", line);
    }

    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0)
  { /* there was a line */
    int line_length = 0;
    for (int i = 0; i < MAXLINE; ++i)
    {
      if (longest[i] != 0)
      {
        line_length++;
      }
    }

    printf("Found a line! Length is %d\n", max);
    printf("%s", longest);
  }

  return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
  int i;
  char c = ' ';

  for (i = 0; i < lim - 1 && (c = (char)getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }

  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;

  while ((to[i] = from[i]) != '\0')
  {
    ++i;
  }
}

void zero_array(char line[])
{
  for (int i = 0; i < MAXLINE; i++)
  {
    line[i] = 0;
  }
}
