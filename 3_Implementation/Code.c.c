/**
 * @file main.c
 * @author Mohammad Karamathulla 40020717
 * @brief Main program of the project
 * @copyright Copyright (c) 2021
 * 
 */
#include "student.h"


void main()
{
    error_t err;
    int i,j,choice;
    printf("*************************Student Managemnt System********************************\n\n\n");
    printf("**********************************Menu**********************************\n\n");
    printf("1. Add new Student\n");
    printf("2. Search Student\n");
    printf("3. Modify Student Record\n");
    printf("4. Delete Student Record\n");
    printf("5. Exit\n\n");
    printf("Enter your selection: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                err = Add();
                break;
            case 2:
                Search();
                break;
            case 3:
                Modify();
                break;
            case 4:
                Delete();
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
        }
}
