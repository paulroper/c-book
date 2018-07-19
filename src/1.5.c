#include <stdio.h>

int count_input(void);
int replace_blanks(void);
int replace_tabs_backspaces(void);

int count_input()
{
  int c, lines, spaces, tabs;

  lines = 0;
  spaces = 0;
  tabs = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      ++lines;
    }
    else if (c == ' ')
    {
      ++spaces;
    }
    else if (c == '\t')
    {
      ++tabs;
    }
  }

  printf("Lines: %d\n", lines);
  printf("Spaces: %d\n", spaces);
  printf("Tabs: %d\n", tabs);

  return 0;
}

int replace_blanks()
{
  int current_char;

  while ((current_char = getchar()) != EOF)
  {
    if (current_char == ' ')
    {
      while ((current_char = getchar()) == ' ')
        ;
      putchar(' ');
    }

    putchar(current_char);
  }

  return 0;
}

int replace_tabs_backspaces()
{
  int current_char;

  while ((current_char = getchar()) != EOF)
  {
    if (current_char == '\t')
    {
      putchar('\\');
      putchar('t');
    }
    else if (current_char == '\b')
    {
      putchar('\\');
    }

    putchar(current_char);
  }

  return 0;
}

int main(int argc, char const *argv[])
{
  int current_char;

  while ((current_char = getchar()) != EOF)
  {
    putchar(current_char);

    while ((current_char = getchar()) != ' ')
    {
      if (current_char == EOF)
      {
        break;
      }

      putchar(current_char);
    }

    putchar('\n');
  }

  return 0;
}
