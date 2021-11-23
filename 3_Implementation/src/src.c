/**
 * @file student_management_system.c
 * @author Mohammad Karamathulla 40020717
 * @brief A program for managing student records
 * @copyright Copyright (c) 2021
 * 
 */
#include "student.h"

/**
 * @brief A function to enter student records
 * 
 * @return error_t 
 */
error_t Add(void)
{
    int i;
    struct student *n_node;
    n_node=(struct student*)malloc(sizeof(struct student));
    printf("Enrollement No.: ");
    for(i=0;i<=19;i++)
    {
        n_node->stud.Id[i]='\0';
        n_node->stud.Name[i]='\0';
        n_node->stud.Add[i]='\0';
        n_node->stud.Batch[i]='\0';
        n_node->stud.Phone_no[i]='\0';
    }
    scanf("%s",n_node->stud.Id);
        //here you can confirms the ID
    printf("Name: ");scanf("%s",n_node->stud.Name);
    printf("Address: ");scanf("%s",n_node->stud.Add);
    printf("Parent's name: ");scanf("%s",n_node->stud.ParName);
    printf("Batch: ");scanf("%s",n_node->stud.Batch);
    printf("Phone Number: ");scanf("%s",n_node->stud.Phone_no);
    printf("The record is added sucessfully");
    n_node->next=NULL;
    if(head==NULL)
    {
        head=n_node;
        curr=n_node;
    }
    else
    {
        curr->next=n_node;
        curr=n_node;
    }
    fl=fopen("data.txt","ab+");
	if (fl == NULL)
		return FAILURE;
	else
		return SUCCESS;
	
    fwrite(&curr->stud, sizeof(curr->stud), 1, fl);
    
    fclose(fl);
}
/**
 * @brief A function to search a particular entry of student from a file
 * 
 */
void Search(void){
    int i;
    char s_Id[20];
    for(i=0;i<=19;i++)
    {
        s_Id[i]='\0';
        stud1.Id[i]='\0';
    }
    int isFound = 0;
    printf("Enter ID to Search: ");
    scanf("%s",s_Id);
    fl = fopen("data.txt","rb");
    i=0;
    while(fread(&stud1, sizeof(stud1), 1, fl) == 1){

       // i++;
        if(strcmp(s_Id,stud1.Id) == 0){
            isFound = 1;
            break;

        }

    }
   //  printf("%d",i);
    if(isFound == 1){
        printf("The record is Found");
        printf("ID: %s",stud1.Id);
        printf("Name: %s",stud1.Name);
        printf("Address: %s",stud1.Add);
        printf("Parent's Name: %s",stud1.ParName);
        printf("Batch: %s",stud1.Batch);
        printf("Phone No: %s",stud1.Phone_no);
    }else{
        printf("Sorry, No record found in the database");
    }
    fclose(fl);
    printf("%d",i);
    return;
}
/**
 * @brief A function to delete records from a file
 * 
 */
void Delete(void)
{
    int i;
    char s_Id[20];
    for(i=0;i<=19;i++)
    {
        s_Id[i]='\0';
        stud1.Id[i]='\0';
    }
    int isFound = 0;
    printf("Enter enrollment number to delete: ");
    scanf("%s",s_Id);
    fl = fopen("data.txt","rb");
    tmp = fopen("temp.txt", "wb");
    i=0;
    while(fread(&stud1, sizeof(stud1), 1, fl) == 1){

        i++;
        if(strcmp(s_Id,stud1.Id) != 0){
            fwrite(&stud1, sizeof(stud1), 1, tmp);


        }

    }
    fclose(fl);
    fclose(tmp);
    remove("data.txt");
    rename("temp.txt","data.txt");
    printf("record deleted\n");
    return;
}

/**
 * @brief A function to modify an existing student record
 * 
 */
void Modify(void){
    char s_Id[19];
    int isFound = 0;
    printf("Enter enrollment number to Modify: ");
    scanf("%s",s_Id);
    fl = fopen("data.txt","rb+");
    while(fread(&stud1, sizeof(stud1),1,fl) == 1){
        if(strcmp(s_Id, stud1.Id) == 0){

            printf("ID: ");scanf("%s",stud1.Id);
            printf("Name: ");scanf("%s",stud1.Name);
            printf("Address: ");scanf("%s",stud1.Add);
            printf("Parent's name: ");scanf("%s",stud1.ParName);
            printf("Batch: ");scanf("%s",stud1.Batch);
            printf("Phone Number: ");scanf("%s",stud1.Phone_no);
            fseek(fl,sizeof(stud1), SEEK_CUR);
            fwrite(&stud1,sizeof(stud1), 1, fl);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        printf("No Record Found");
    }
    else
        printf("Record modified\n");
    fclose(fl);
    return;
}
