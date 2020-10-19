/*
**************************************************************************
Question 4 - covid-19 positive cases in Vigo county.
You will compute the maximum 7day running average of the # of new cases in
Vigo County, up until Oct 3.
-
The data that you will use is in the file
  /u1/junk/kinne/covid-19/time_series_covid19_confirmed_US.csv
+ You can transfer the file to your computer and look at it in Excel.
+ You can scan through the file one line at a time as you have in other
programs.
+ You can use strstr to determine if a given line is the one
for Vigo County [if (strstr(line, "Vigo") != NULL) ...]
+ Once you have the line for Vigo County, you will scan through this line
to compute the # of new cases each day.  I used the following
  char * begin = strstr(line, "US\",");
  char *t = strtok(begin, ",");
  t = strtok(NULL, ",");
  while (t != NULL) { int val = atoi(t); ... ; t = strtok(NULL, ","); }
How that works - begin will be the spot "US" in the line, and t
is the next "token" after that.  strtok will pick out the next
number from the line (though as a string, so atoi).
+ To compute the # of new cases each day, you subtract a number from the
previous one.  You should print these out and check that they are correct.
You can compute them in Excel as well to check.
+ Once you have the # of new cases per day, keep a 7 day running average -
(7 days including current and 6 before it) and print that as well.
For each, print which day of the year it is (the first one is day 22, the
last one in the file is day 277).
-
Question 4 - which day of the year had the maximum 7 day running average,
and what was this value (to 3 significant figures)?  If the max was
on the last day in the file and was 23.4567 then you would type your answer
in as
277 23.5
-
Note - if you want to convert between dates and the day of the year, you
can use http://www.easysurf.cc/wdate5.htm
**************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *f = fopen("/u1/junk/kinne/covid-19/time_series_covid19_confirmed_US.csv", "r");
    int val, i = 0, diff, temp = 0, count1 = 0, average, average1, count = 0;
    char * line = NULL;
    char * t;
    char * begin;
    size_t len = 0;
    ssize_t line_length;
    while ((line_length = getline(&line, &len, f)) > 0)
    {
        if (strstr(line, "Vigo") != NULL)
        {
            begin = strstr(line, "US\",");
            t = strtok(begin, ",");
            t = strtok(NULL, ",");
            while (t != NULL)
            {
                printf("t = %s\n", t);
                val = atoi(t);
                diff = val - temp;
                if (diff < 0)
                {
                    diff = 0;
                }
                temp = val;
                t = strtok(NULL, ",");
                if (i < i + 1)
                {
                    if (i == 7)
                    {
                        average = count / 7;
                        printf("\n7 day average: %d\n", average);
                        printf("\n");
                        i = 0;
                        count = 0;
                    }
                    count += val;
                    printf("\ni: %d | count: %d\n", i, count);
                    i++;
                }
                /*
                if (i >= 7)
                {
                    if (i < (7 * 2))
                    {
                        count1 += val;
                        printf("i: %d | (7 * 2): %d\n", i, (7 * 2));
                        i++;
                    }
                }
                */
                printf("# of new cases per day: %d\n", diff);
            }
            //average1 = count1 / 7;
            //printf("next 7 days: %d\n", average1);
        }
    }
    return 0;
}
