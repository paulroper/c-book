#include <stdio.h>

double fahrenheit_to_celsius(double);
double celsius_to_fahrenheit(double);

double fahrenheit_to_celsius(double fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}

double celsius_to_fahrenheit(double celsius)
{
  return (celsius * 1.8) + 32.0;
}

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300; doubleing-point version */
int main(int argc, char const *argv[])
{
  double fahr, celsius;
  double lower, upper, step;
  lower = 0;   /* lower limit of temperatuire scale */
  upper = 300; /* upper limit */
  step = 20;   /* step size */
  fahr = lower;

  /* 1-3 */
  printf("Fahrenheit Celsius\n");
  while (fahr <= upper)
  {
    printf("%3.0f %6.1f\n", fahr, fahrenheit_to_celsius(fahr));
    fahr = fahr + step;
  }

  printf("\n");
  celsius = lower;

  /* 1-4 */
  printf("Celsius Fahrenheit\n");
  while (celsius <= upper)
  {
    printf("%3.0f %6.1f\n", celsius, celsius_to_fahrenheit(celsius));
    celsius = celsius + step;
  }
}
