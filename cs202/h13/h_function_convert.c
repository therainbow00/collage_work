/*
  Programming concept: functions

  Program should:      create functions convert_temperature, convert_distance, convert_weight with each one converting between English and metric units (F and C, miles and km, pounds and kg).  Each function should take two parameters - one is a number and one is the unit converting from (e.g., "F" or "kg").  In main, ask the user for a number, ask the user what unit they want to convert from, use if's to call the appropriate conversion function, and print the result.
 */

#include <stdio.h>

void convert_temperature(float num, char *unit)
{
    if (unit[0] == 'F')
    {
        printf("%f\n", (num * (9.0 / 5.0)) + 32.0);
    }
    else
    {
        printf("%f\n", (num - 32.0) * (5.0 / 9.0));
    }
}

void convert_distance(float num, char *unit)
{
    char response[] = "miles";
    if (strcmp(unit, response) == 0)
    {
        printf("%f\n", num * 1.609344);
    }
    else
    {
        printf("%f\n", num / 1.609344);
    }
}

void convert_weight(float num, char *unit)
{
    char response[] = "pounds";
    if (strcmp(unit, response) == 0)
    {
        printf("%f\n", num * 0.45359237);
    }
    else
    {
        printf("%f\n", num / 0.45359237);
    }
}

int main(int argc, char *argv[]) {
  float num;
  char unit[7], responses[4][7] = {"miles", "km", "pounds", "kg"};
  printf("Number please (floating point): ");
  scanf("%f", &num);

  printf("Convert from what (choices are F, C, miles, km, pounds, kg)? ");
  scanf("%s", unit);

  if (unit[0] == 'C' || unit[0] == 'F')
  {
      convert_temperature(num, unit);
  }
  else if (strcmp(unit, responses[0]) == 0 || strcmp(unit, responses[1]) == 0)
  {
      convert_distance(num, unit);
  }
  else if (strcmp(unit, responses[2]) == 0 || strcmp(unit, responses[3]) == 0)
  {
      convert_weight(num, unit);
  }
  else
  {
      printf("Invalid. Bye.\n");
  }

  return 0;
}
