/*
**************************************************************************
Question 2 - This is related to counting the number of primes.
Did you know that as you get larger and larger integers, the chance that
a randomly chosen integer is prime gets close to 1/ln(n)?  This was
one of the crowning achievements of 19th century math - to prove different
versions of this fact.  Let's test it out quickly in the following table...
n     #ints<=n that are prime   %that are prime   100/ln(n)
-------------------------------------------------------------
10    4                         40%               43.429448%
100   25                        25%               21.714724%
Note that you can verify those calculations yourself on paper and calculator
if you like.  Let's check a few higher values, and also put in the
relative error (which is: 100*(estimate-correct)/correct) -
n     #ints<=n that are prime   %that are prime   100/ln(n)     relative error
-------------------------------------------------------------------------------
10    4                         40%               43.429448%    8.573620%
100   25                        25%               21.714724%    -13.141104%
1000  168                       16.8%             14.476483%    -13.830460%
The question for us, how does this relative error change as n gets larger?
The prime number theorem claims that this relative error gets closer to 0
as n gets larger.
-
Question 2 - Your mission is to verify that for a particular value of
n, in particular for n=1000000, what is the relative error?  You should
printf the relative error using %lf and do your calculations using double
variables.  The correct answer is written with 6 digits after the decimal
point, a - if the relative error is negative, and with a %
(like the relative error figures above).
-
Hints:
+ if you #include <math.h> and use the -lm flag when you compile (gcc -lm program.c),
  you can use log(n) for the natural logarithm.
+ you can use builtin programs that are on the server, in particular
  the primes program.  Try out the following in a C program:
    FILE * p = popen("primes 1 100", "r");
    int x; while (scanf("%d", &x) == 1) { printf("%d\n", x); }
    pclose(p);
  You can also try out the following:
    FILE * p = popen("primes 1 100 | wc", "r");
    int x; while (scanf("%d", &x) == 1) { printf("%d\n", x); }
    pclose(p);
+ or you can do the prime calculations yourself in C, but if your own code is
  not fast enough then you can use the hint.
+ careful if you use abs - it seems to always give back integers (so I didn't use it).
**************************************************************************
*/

/*
n     #ints<=n that are prime   %that are prime   100/ln(n)
-------------------------------------------------------------
10    4                         40%               43.429448%
*/
// relative error = 100 * (43.429448 - 40) / 40
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_prime(int num)
{
    int i, flag = 0, primes = 0;
    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (num == 1)
    {
        //printf("not prime\n");
    }
    else if (flag == 0)
    {
        //printf("prime\n");
        primes++;
    }
    else
    {
        //printf("not prime\n");
    }
    return primes;
}

int main()
{
    int x, i, j, flag = 0, primes = 0;
    double re, percent, ln_n, d_prime;

    printf("Interger: ");
    scanf("%d", &x);
    if (x < 1 )
    {
        printf("enter positive numbers only.\n");
        exit(0);
    }

    for (int i = 1; i <= x; i++)
    {
        primes += check_prime(i);
    }

    d_prime = (double) primes;
    percent = (d_prime / x) * 100;

    ln_n = 100 / log(x);

    re = 100 * (ln_n - percent) / percent;

    printf("relative error: %lf%\n", re);

    return 0;
}
