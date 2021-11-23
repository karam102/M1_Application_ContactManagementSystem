#ifndef __STUDENT_H__
#define __STUDENT_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{SUCCESS=1,FAILURE}error_t;

FILE *fl,*tmp;
    struct data{
    char Id[20];
    char Name[20];
    char Add[20];
    char ParName[20];
    char Batch[20];
    char Phone_no[20];
}stud1;

struct student{

    struct data stud;
    struct student *next;
}*head,*temp,*curr;

error_t Add(void);

void Search(void);

void Delete(void);

void Modify(void);

#endif
