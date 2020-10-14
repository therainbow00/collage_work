#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct person {
    char first[100];
    char last[100];
    int year_born;
};

void get_person(struct person *p)
{
    scanf("%s", (*p).first);
    scanf("%S", (*p).last);
    (*p). year_born = 1900;

}
void print_person(struct person *p)
{

}

void import_person(struct person *p, char *line);
void import_people(struct person *p, char *)

int main()
{
    struct person professor, student1, student2;

    professor.year_born = 1900;

    scanf("%s", student1.first);
    scanf("%s", student1.last);
    student1.year_born = 2000

    get_person(&professor);
    get_person(&person)


    return 0;
}
