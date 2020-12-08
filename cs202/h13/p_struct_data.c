/*
  Programming concept: structures

  Program should:      define a structure to store the year, month, day, and high temperature.  write a function get_data that has a parameter that is a pointer to a struct and reads from the user into the struct pointed to by the parameter.  write a function print_data that takes the struct pointer as a parameter and prints the data.  in main, declare a struct, call the get_data function, call the print_data function.

 */

#include <stdio.h>
#include <stdlib.h>

struct info
{
    int year;
    int day;
    char month[51];
    float high_tem;
};

void get_data(struct info *data)
{
    struct info * d = (struct info *) malloc(sizeof(struct info));

    printf("Year: ");
    scanf("%d", &d->year);

    printf("Month: ");
    scanf("%50s", d->month);

    printf("Day: ");
    scanf("%d", &d->day);

    printf("Temperature (a floating point #): ");
    scanf("%f", &d->high_tem);
}
void print_data(struct info *data)
{
    if (data == NULL)
    {
        printf("Perameter has nothing\n");
    }
    else
    {
        printf("%lf degrees on %s/%d/%d\n", data->high_tem, data->month, data->day, data->year);
    }
}

int main(int argc, char *argv[]) {
  struct info * data = NULL;
  if (data == NULL)
  {
      get_data(data);
      print_data(data);
  }

  return 0;
}
