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
    int val, i = 0, diff = 0, temp = 0, average, count = 0, day = 21, largest_average = 0, temp_average = 0, val_temp = 0, max_7_day_average = 0, val_day = 0, max_count = 0, num_of_max_7_day_average = 0;
    double percent;
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
                day++;
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
                        /*
                        printf("======================\n");
                        printf("count: %d\n", count);
                        printf("======================\n");
                        */
                        average = count / 7;
                        //printf("val: %d, val_temp: %d\n", val, val_temp);
                        printf("\n7 day average: %d\n\n", average);
                        max_count += count;
                        i = 0;
                        count = 0;
                        /*
                        if (temp_average == average)
                        {
                            printf("Both averages are the same, average: %d\n", average);
                            printf("\n");
                        }
                        else if (temp_average < average)
                        {
                            printf("temp_average: %d < average: %d\n", temp_average, average);
                            temp_average = average;
                            printf("average is larger, average: %d\n", average);
                            printf("\n");
                        }
                        else
                        {
                            printf("average: %d < temp_average: %d\n", average, temp_average);
                            printf("temp_average is larger, temp_average = %d\n", temp_average);
                            printf("\n");
                        }
                        */
                        if (val_temp > max_7_day_average)
                        {
                            max_7_day_average = val_temp;
                        }
                        printf("maximun 7 day average = %d, day: %d\n\n", max_7_day_average, val_day);
                        num_of_max_7_day_average++;
                        printf("%d\n", num_of_max_7_day_average);
                        //temp_average = largest_average;
                    }
                    //printf("count: %d\n", count);
                    //printf("\nbefore count adds val\n");
                    count += val;
                    //printf("after count adds val\n\n");
                    //printf("count: %d\n", count);
                    //printf("count: %d, val: %d\n", count, val);
                    //printf("i: %d | count: %d\n", i, count);
                    printf("# of new cases per day: %d\n", diff);
                    printf("val = %d, day: %d\n", val, day);
                    if (val > val_temp)
                    {
                        //printf("day: %d, val_temp: %d\n", day, val_temp);
                        //printf("val: %d, val_temp: %d\n", val, val_temp);
                        val_day = day;
                        val_temp = val;
                    }
                    i++;
                }
            }
            /*
            printf("\n");
            printf("-------------\n");
            printf("max_count: %d\n", max_count);
            printf("-------------\n");
            printf("\n- - - - - - - -\n");
            printf("num_of_max_7_day_average: %d\n", num_of_max_7_day_average);
            printf("- - - - - - - -\n");
            printf("\n################\n");
            percent = (double) max_count / (double) num_of_max_7_day_average;
            printf("%.1lf percent\n", percent);
            printf("################\n");
            */
        }
    }
    return 0;
}
