/*
**************************************************************************
Question 3 - here we look at the % of the human genome that is
each of the four nucleotides.  The four different letters of DNA (G, C, A, T)
show up in different abuncances in different species, so it is interesting
to see what the % of each is.  In particular, it is common to look at the
percentage of the base pairs that are either G or C.
-
For this question, scan through the file
  /u1/junk/kinne/genomes/GRCh38.p12.genome.fa
and calculate the percentage of the nucleotides that are G or C.
-
+ You should read the file line by line using either fgets or getline
and ignore any line that starts with >.  Those lines are the names
of chromosomes, so are not something we should count for nucleotides.
+ One way to scan through the file would be this -
  FILE *f = fopen("filename...", "r");
  char * line = NULL;
  size_t len = 0;
  while (getline(&line, &len, f) > 0) {
    // line is a line, with \n at the end, scan through it to
    // update counts of each of the nucleotides
  }
  free(line)
  fclose(f);
+ The file you are reading is around 3.3GB.  It will take a minute or so for
your program to read through it.  You should test on a smaller file, one
you can use is GRCh38.p12.genome.fa.100k in the same directory (it is the
first 100k lines of the whole file.  The correct answer for this smaller
file is 52.3.
+ You will have a count of the letters that are GC and a count of the
total number of GCAT letters.  Do not count \n or anything else other than
GCAT in your total count.
+ Keep the counts as long int's, do the division using a double, and print using
%lf the % of GC.  Note that you need long int because the total count is larger
than 2 billion.
-
Question 3 - the % of the genome file GCAT letters that are GC.  Use 3 significant
figures and no %.  So if the value were 52.67234% you would type 52.7
-
**************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double calculating_percentage(double a, double b)
{
    double percent = (a / b) * 100;
    return percent;
}

int main()
{
    int count_G = 0, i, count_C = 0, character_len = 0, count_A = 0, count_T = 0, line_count = 0;
    double percent_G, percent_C, percent_A, percent_T, addition_G_C, addition_G_C_A_T, percent;
    FILE *f = fopen("/u1/junk/kinne/genomes/GRCh38.p12.genome.fa", "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t line_length;
    while ((line_length = getline(&line, &len, f)) > 0)
    {
        line_count++;
        character_len += line_length;
        for (i = 0; i < line_length; i++)
        {
            if (line[i] == 'G')
            {
                count_G++;
            }
            else if (line[i] == 'C')
            {
                count_C++;
            }
            else if (line[i] == 'A')
            {
                count_A++;
            }
            else if (line[i] == 'T')
            {
                count_T++;
            }
        }

        // line is a line, with \n at the end, scan through it to
        // update counts of each of the nucleotides
    }

    percent_G = calculating_percentage((double) count_G, (double) character_len);
    percent_C = calculating_percentage((double) count_C, (double) character_len);
    percent_A = calculating_percentage((double) count_A, (double) character_len);
    percent_T = calculating_percentage((double) count_T, (double) character_len);

    addition_G_C = percent_G + percent_C;
    addition_G_C_A_T = percent_G + percent_C + percent_A + percent_T;
    percent = (percent_G + percent_C) / (percent_G + percent_C + percent_A + percent_T) * 100;

    printf("percent of 'G' and 'C' / 'G', 'C', 'A' and 'T' in the file: %.1lf\n", percent);

    free(line);
    line = NULL;
    fclose(f);
    return 0;
}
