#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//The purpose of this file is to make a quiz that records your score based on the questions you answered.

int math_quiz(){
    //This is the function for the math_quiz. If the user selects math quiz, then it goes to this function

    int rn1, rn2;
    int k;
    int mult, add, sub, div;
    int ans1, ans2, ans3;
    float ans4;
    int grade = 0;
    float final_grade;

    srand (time(NULL));


    for(k = 0; k < 4; k+=1) {
        rn1 = rand() % 51;
        rn2 = rand() % 51;
        printf("Your question is:\n");
        mult = rn1 * rn2;
        add = rn1 + rn2;
        sub = rn1- rn2;
        div = rn1/rn2;
        printf("What is %d * %d?\n", rn1, rn2);
        scanf("%d", &ans1);
        printf("What is %d + %d?\n", rn1, rn2);
        scanf("%d", &ans2);
        printf("What is %d - %d?\n", rn1, rn2);
        scanf("%d", &ans3);
        printf("What is %d / %d?\n", rn1, rn2);
        scanf("%d", &ans4);

        if(mult == ans1){
            grade+=1;
        }
        if(add == ans2){
            grade+=1;
        }
        if(sub == ans3){
            grade+=1;
        }
        if(div == ans4){
            grade+=1;
        }

    }
    final_grade = (grade/16.)*100 ;
    printf("%.2f\n", final_grade);
    FILE *fp;
    fp = fopen("Output.txt", "w");
    fprintf(fp, "\nYour score on the math_quiz is %.2f\n", final_grade);
    fclose(fp);
}



int computer_science_quiz(){
    //This is the function for the computer_science_quiz, if the user selects computer_science_quiz then it takes them here.
    int j;
    char ans1[100], ans2[100], ans3[100], ans4[100], ans5[100];
    int score = 0;

    printf("What is the result of T and F?\n");
    fgets(ans1,99,stdin);
    if(strcmp(ans1, "F") == 0){
        score+=1;
    }

    printf("What is the result of T or F?\n");
    fgets(ans2, 99, stdin);
    if(strcmp(ans2, "T") == 0){
        score+=1;
    }

    printf("What does SSD stand for?\n");
    fgets(ans3,99,stdin);
    if(strcmp(ans3, "Solid State Drive\n") == 0){
        score+=1;
    }

    printf("What does HDD stand for?\n");
    fgets(ans4,99,stdin);
    if(strcmp(ans4, "Hard Disk Drive\n") == 0){
        score+=1;
    }

    printf("Convert the number 15 to binary.\n");
    fgets(ans5,99,stdin);
    if(strcmp(ans5, "01111b\n") == 0){
        score+=1;
    }
    printf("You score is %d/5\n", score);
    FILE *fp;
    fp = fopen("Output.txt", "w");
    fprintf(fp, "Your score on the computer_science_quiz is %d\n", score);
    fclose(fp);

}

int history_quiz()
{
    //This function for the history_quiz, if the user selects history_quiz it takes them here.
    int count = 0;
    char answer1[100], answer2[100], answer3[100], answer4[100], answer5[100], answer6[100], answer7[100], answer8[100], answer9[100], answer10[100];

    printf("What year did the Civil War start?\n");
    fgets(answer1, 99, stdin);
    if (strcmp(answer1, "1861\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What year did the Great Depression Start?\n");
    fgets(answer2, 99, stdin);
    if (strcmp(answer2, "1929\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("Who did the United States fight in the War of 1812?\n");
    fgets(answer3, 99, stdin);
    if (strcmp(answer3, "Great Britain\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("From whom did the U.S. buy territory during the Louisiana Purchase?\n");
    fgets(answer4, 99, stdin);
    if (strcmp(answer4, "France\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("On which ship did the Pilgrims sail to North America?\n");
    fgets(answer5, 99, stdin);
    if (strcmp(answer5, "The Mayflower\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What city was the first capital of the United States?\n");
    fgets(answer6, 99, stdin);
    if (strcmp(answer6, "New York City\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("People who supported The British in the Revolutionary War were called?\n");
    fgets(answer7, 99, stdin);
    if (strcmp(answer7, "Loyalists\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("Who first discovered America?\n");
    fgets(answer8, 99, stdin);
    if (strcmp(answer8, "Leif Erikson\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("Who was the first US President?\n");
    fgets(answer9, 99, stdin);
    if (strcmp(answer9, "George Washington\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("When was the Declaration of Independence signed?\n");
    fgets(answer10, 99, stdin);
    if (strcmp(answer10, "August 2nd, 1776\n") == 0)
    {
        printf("correct\n");
        count++;
    }
    printf("Your score is %d/10", count);
    FILE *fp;
    fp = fopen("Output.txt", "w");
    fprintf(fp, "Your score on the history_quiz is %d\n", count);
    fclose(fp);
}

int geography_quiz() {
    //This is the function for geography_quiz, if the user selects geography_quiz then it takes them here.

    int count = 0;
    char answer1[100], answer2[100], answer3[100], answer4[100], answer5[100], answer6[100], answer7[100], answer8[100], answer9[100], answer10[100];

    printf("What is the capital of Indiana?\n");
    fgets(answer1, 99, stdin);
    if (strcmp(answer1, "Indianapolis\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What is the capital of France?\n");
    fgets(answer2, 99, stdin);
    if (strcmp(answer2, "Paris\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What is the capital of Germany?\n");
    fgets(answer3, 99, stdin);
    if (strcmp(answer3, "Berlin\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What state is Mount Rushmore in?\n");
    fgets(answer4, 99, stdin);
    if (strcmp(answer4, "South Dakota\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What is the capital of Florida?\n");
    fgets(answer5, 99, stdin);
    if (strcmp(answer5, "Tallahassee\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("Where are the Everglades located?\n");
    fgets(answer6, 99, stdin);
    if (strcmp(answer6, "Florida\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What is the capital of California?\n");
    fgets(answer7, 99, stdin);
    if (strcmp(answer7, "Sacramento\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What is the capital of Luxembourg?\n");
    fgets(answer8, 99, stdin);
    if (strcmp(answer8, "Luxembourg\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What is the capital of Greece?\n");
    fgets(answer9, 99, stdin);
    if (strcmp(answer9, "Athens\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What is the capital of Ecuador?\n");
    fgets(answer10, 99, stdin);
    if (strcmp(answer10, "Quito\n") == 0)
    {
        printf("correct\n");
        count++;
    }
    printf("You got a %d/10\n", count);
    FILE *fp;
    fp = fopen("Output.txt", "w");
    fprintf(fp, "Your score on the geography_quiz %d\n", count);
    fclose(fp);

}

void physics_enviornmental_science_quiz()
{
    //This is the function for physics_enviornmental_science_quiz, if they physics_enviornmental_science_quiz then it takes them here.
    int count = 0;
    char answer1[100], answer2[100], answer3[100], answer4[100], answer5[100], answer6[100], answer7[100], answer8[100], answer9[100], answer10[100];

    printf("Which of the following process unit is used for air pollution control in chemical plants? \n");
    scanf("%s", answer1);
    if (strcmp(answer1, "Thermal Oxidizer\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("Full form of CTBT is.. \n");
    scanf("%s", answer2);
    if (strcmp(answer2, "Comprehensive Nuclear-Test-Ban Treaty\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("What is the full form of BOD? \n");
    scanf("%s", answer3);
    if (strcmp(answer3, "Bactorial Oxygen Demand\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("How much percentage of nitrogen consist in Earth's Atmosphere? (use % sign not 'percentage') \n");
    scanf("%s", answer4);
    if (strcmp(answer4, "78%\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("Full form of COD is... \n");
    scanf("%s", answer5);
    if (strcmp(answer5, "Chemical Oxygen Demand\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("How many seconds in a minute? \n");
    scanf("%s", answer6);
    if (strcmp(answer6, "60\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("How many minutes in one hour? \n");
    scanf("%s", answer7);
    if (strcmp(answer7, "60\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("How many meters in a kilometer? \n");
    scanf("%s", answer8);
    if (strcmp(answer8, "1,000\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("How many centimeters in a meter? \n");
    scanf("%s", answer9);
    if (strcmp(answer9, "100\n") == 0)
    {
        printf("correct\n");
        count++;
    }

    printf("How many grams in a kilogram? \n");
    scanf("%s", answer10);
    if (strcmp(answer10, "1000\n") == 0)
    {
        printf("correct\n");
        count++;
    }
    printf("Your score is %d/10\n");
    FILE *fp;
    fp = fopen("Output.txt", "w");
    fprintf(fp, "Your score on the physics_enviornmental_science_quiz is %d\n", count);
    fclose(fp);
}


int main() {
    //This is our main function, from here the user selects what test they take.

    char name[100];
    int value;

    printf("Welcome to our Quiz that is based off of five subjects.\n");
    printf("Please enter your name\n");
    fgets(name, 99, stdin);
    printf("Your name is %s", name);

    FILE *fp;
    fp = fopen("Output.txt", "w");
    fprintf(fp, "Name: %s\n", name);
    fclose(fp);

    printf("Please enter a number 1-5 for which subject you would like to take a quiz over.\n");
    printf("Enter 1 for a Math Quiz\n");
    printf("Enter 2 for a History Quiz\n");
    printf("Enter 3 for a Computer Science Quiz\n");
    printf("Enter 4 for a Physics/Enviornmental Science Quiz\n");
    printf("Enter 5 for a Geography Quiz\n");

    scanf("%d", &value);

    if(value == 1){
        math_quiz();
    }
    if(value == 2){
        history_quiz();
    }
    if(value == 3){
        computer_science_quiz();
    }
    if(value == 4){
        physics_enviornmental_science_quiz();
    }
    if(value == 5){
        geography_quiz();
    }
}
