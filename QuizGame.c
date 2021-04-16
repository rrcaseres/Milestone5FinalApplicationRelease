#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include "Quiz.c"

char message[200];

int main(void) {

    // structures of each type of category
    struct category Music = { .questions = NULL };
    struct category Animal = { .questions = NULL };
    struct category CyberSecurity = { .questions = NULL };


    // These are the variables that store answers, categories and completion of the quiz.
    char answer;
    int category, i, j; 
    int correct = 0;
    int isDone = 1;

    char music[5][120] = // Stores questions and multiple choice selection for the category of music
    {
        "Who is the artist of the song '4 your eyez'?\na)J Cole \nb)Lil Wayne \nc)Drake \nd)Nas \n", //1st question and answers for category 1 music
        "Who sings the song 'Dangerously in Love'?\na)SZA \nb)Beyonce \nc)TLC \nd)Aaliyah \n", //2nd question and answers for category 1 music
        "Who was on 'Degrassi'?\na)J Cole \nb)Lil Wayne \nc)Drake \nd)Nas \n", //3rd question and answers for category 1 music
        "Who is the artist of the album 'To Pimp a Buuterfly'?\na)J Cole \nb)Lil Wayne \nc)Kendrick Lamar \nd)SchoolBoy Q \n", //4th question and answers for category 1 music
        "Who is a member of 'Outcast'?\na)Young Jeezy \nb)Akon \nc)Andre 3000 \nd)Nas \n" //5th question and answers for category 1 music
    };
    char animals[5][120] = // Stores questions and multiple choice selection for the category of animals
    {
        "What animal is the king of the jungle?\na)Lion \nb)Mouse \nc)Horse \nd)Pony \n", //1st question and answers for category 2 Animals
        "What animal is a house pet?\na)Lion \nb)Rhino \nc)Dragon \nd)Dog \n", //2nd question and answers for category 2 Animals
        "What animal was Timon from Lion King?\na)Elephant \nb)Snake \nc)Aligator \nd)MeerKat \n", //3rd question and answers for category 2 Animals
        "What animal is a 'Black Mamba'?\na)Cat \nb)Snake \nc)Aligator \nd)Mouse \n", //4th question and answers for category 2 Animals
        "What do you call a baby cow?\na)yoot \nb)youngin \nc)calf \nd)baby cow \n" //5th question and answers for category 2 Animals
    };
    char cybersecurity[5][120] = // Stores questions and multiple choice selection for the category of cybersecrurity 
    {
        "What does DNS stand for?\na)Domain Name Server \nb)Domain Name System \nc)Domain Name scan \nd)Domain Name size \n", //1st question and answers for category 3 Cybersecurity
        "What does IP stand for?\na)Interweb Permission \nb)Internet Protocol \nc)Internet Pass \nd)Internet Push \n", //2nd question and answers for category 3 Cybersecurity
        "Port number 53 is assocaited with what protocol?\na)DNS \nb)SSH \nc)Telnet \nd)HTTPS \n", //3rd question and answers for category 3 Cybersecurity
        "What does SSH stand for?\na)Secure Session Home \nb)Secure Socket Layer \nc)Secure Shell \nd)HTTPS \n", //4th question and answers for category 3 Cybersecurity
        "What test administered by Comptia for the security+ cert?\na)A+ \nb)Network+ \nc)Sy0-501 \nd)Linux + \n" //5th question and answers for category 3 Cybersecurity
    };

    //correct answer
    char answers[3][5] = // stores the correct answers for the multiple choice questions for each category 
    {
        {'a','b','c','c','c'}, //These are the answers that are stored for the first category Music in order from number 1-5
        {'a','d','d','b','c'}, //These are the answers that are stored for the Second category Animals in order from number 1-5
        {'a','b','a','c','c'} //These are the answers that are stored for the third category Cybersecurity in order from number 1-5
    };
    for (i = 0; i < 5; i++) {

        //These lines Copy the questions and answers from the arrays into the structures types
        strcpy_s(&Music.questions.Q[i].index.Q, 120, music[i]);
        *Music.questions.Q[i].index.A = answers[0][i];
        strcpy_s(&Animal.questions.Q[i].index.Q, 120, animals[i]);
        *Animal.questions.Q[i].index.A = answers[1][i];
        strcpy_s(&CyberSecurity.questions.Q[i].index.Q, 120, cybersecurity[i]);
        *CyberSecurity.questions.Q[i].index.A = answers[2][i];
    }

    FILE *file; // File I/O variable creation
    file = fopen("scores.txt", "a+");   // Initializing the file I/O variable to the file with ability to read and write (append)
    int cat; // variable to category to be written in scores.txt at the end of the quiz
    char username[20]; // variable to store username as a string (character list) to be written in scores.txt at the end of the quiz
    memset(username, '\0', sizeof(username));   // setting username array indexes to '\0' meaning empty
    while (isDone == 1) { // this loop starts the quiz by asking category 
        printf("Enter your username: \n");
        scanf("%s", username); // getting the input of username from user
        printf("\nEnter category number 1 - Music, 2 - Animals, 3 - Cybersecurity\n"); //print statement 
        scanf_s("%d", &category); // scan the user input 
        if (category == 1) { // if the category is selected then it starts the questions from this category 
            for (j = 0; j < 5; j++) { // this is the for loop that goes over each question
                printf("%s", Music.questions.Q[j].index.Q); // prints the category if chosen
                scanf_s("%c", &answer);// The program execution wasnt stopping at the first scanf so i used 2 
                scanf_s("%c", &answer); //  user input
                if (*Music.questions.Q[j].index.A != answer) { //checks each answer from the answer array 
                    printf("Wrong Answer!"); // print statement if the answer is incorrect
                    // formatting a message before writing into the file
                    sprintf(message, "%s - ", username);
                    strcat(message, "Music");
                    strcat(message, " - Not Complete\n");
                    fputs(message, file); //writes the message specified above to the file using file I/O operation fputs
                    break;
                }
                if (j == 4) { // if the 4th question is correct it sets isDone to 0 to exit the while loop
                    isDone = 0;
                }
            }
        }
        else if (category == 2) { // // if the category is selected then it starts the questions from this category
            for (j = 0; j < 5; j++) { // this is the for loop that goes over each question
                printf("%s", Animal.questions.Q[j].index.Q); // prints the category if chosen
                scanf_s("%c", &answer);// The program execution wasnt stopping at the first scanf so i used 2 
                scanf_s("%c", &answer); //  user input
                if (*Animal.questions.Q[j].index.A != answer) { //checks each answer from the answer array 
                    printf("Wrong Answer!"); // print statement if the answer is incorrect
                    // formatting a message before writing into the file
                    sprintf(message, "%s - ", username);
                    strcat(message, "Animal");
                    strcat(message, " - Not Complete\n");
                    fputs(message, file);   //writes the message specified above to the file using file I/O operation fputs
                    break;
                }
                if (j == 4) { // if the 4th question is correct it sets isDone to 0 to exit the while loop
                    isDone = 0;
                }
            }
        }
        else if (category == 3) { // if the category is selected then it starts the questions from this category
            for (j = 0; j < 5; j++) { // this is the for loop that goes over each question
                printf("%s\n", CyberSecurity.questions.Q[j].index.Q); // prints the category if chosen
                scanf_s("%c", &answer);// The program execution wasnt stopping at the first scanf so i used 2 
                scanf_s("%c", &answer); //  user input
                if (*CyberSecurity.questions.Q[j].index.A != answer) { //checks each answer from the answer array 
                    printf("Wrong Answer!\n"); // print statement if the answer is incorrect
                    // formatting a message before writing into the file
                    sprintf(message, "%s - ", username);
                    strcat(message, "CyberSecurity");
                    strcat(message, " - Not Complete\n");
                    fputs(message, file);   //writes the message specified above to the file using file I/O operation fputs
                    break; // exits the for loop
                }
                if (j == 4) { // if the 4th question is correct it sets isDone to 0 to exit the while loop
                    isDone = 0;
                }
            }
        }
        else {
            printf("Pick a listed category!"); // print statement
        }
        //This is the loop that goes untill the quiz is complete 
    }
    // formatting a message before writing into the file
    // using if-else operations, specifies the category type that user selected in the beginning of the quiz in order to write into the file 
    sprintf(message, "%s - ", username);
    if (category == 1) {
        strcat(message, "Music");
    }
    else if (category == 2) {
        strcat(message, "Animal");
    }
    else {
        strcat(message, "CyberSecurity");
    }
    strcat(message, " - Complete\n");

    fputs(message, file);   //writes the message specified above to the file using file I/O operation fputs
    printf("Congrats! You have completed the quiz!"); // print statement 
    return 0;
}