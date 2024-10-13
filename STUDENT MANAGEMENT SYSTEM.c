#include <stdio.h>
#include <string.h>
#include <stdlib.h> // FOR USING SYSTEM CLEAR FUNCTION;
#include <windows.h>
struct student 
{
	char name[100];
	char department[100];
	char enrollment[100];
	int age;
};
void edit(int j, struct student S[100])
{
	int find;
	re3:
	printf("\nEDIT FUNCTION\n");
	printf("THE TOTAL NUMBER OF STUDENT/'S:- %d\n",j);
	printf("Which Student:- ");
	scanf("%d",&find);
	fflush(stdin);
	if((find > 0) && (find  <=j))
	{
		find--;
		printf("\nEditing %d's information\n",find+1);
		printf("\nEnter Name :- ");
		gets(S[find].name);
		printf("Enter Department:- ");
		gets(S[find].department);
		printf("Enter Enrollment Number:- ");
		gets(S[find].enrollment);
		printf("Enter Age:- ");
		scanf("%d",&S[find].age);
		printf("Edited !!....\n");	
	}	
	else
	{
		goto re3;
	}
}
int main()
{
	struct student S[100];
	int i,j=0;
	int choice;
	res:
	printf("|--------------------------------------------|\n");
	printf("|------SIMPLE STUDENT MANAGEMENT SYSTEM------|\n");
	printf("|------BY HEET KUMBHARANA(1CE58)-------------|\n");
	printf("|--------------------------------------------|\n"); 
	printf("\nENTER NUMBER OF STUDENT/S\n");
	scanf("%d",&choice);
	if(choice <= 0) 
	{
		printf("PROGRAM CLOSING.........\n");
		Sleep(4);
		exit(1);
	}
	fflush(stdin);
	for(i=0;i<choice;i++)
	{
		printf("\n---STUDENT %d---\n",i+1);
		printf("Enter Name :- ");
		gets(S[i].name);
		printf("Enter Department:- ");
		gets(S[i].department);
		printf("Enter Enrollment Number:- ");
		gets(S[i].enrollment);
		printf("Enter Age:- ");
		scanf("%d",&S[i].age);
		fflush(stdin);
		j++;
	}
	printf("\nSTORED!!\n");
	printf("Total Number of Student/'s = %d\n",j);
	int choice2;
	re:
	printf("\n<----PROGRAM FUNCTIONS---->");
	printf("\n1. Add Student\n2. View Information\n3. Reset The Program\n4. Exit The Program\n5. Edit Information\n");
	printf("Enter Choice:- ");
	scanf("%d",&choice2);
	fflush(stdin);
	if((choice2 == 0) || (choice2 >5))
	{
		printf("\n---ERROR IN INPUT!!---\n");
		goto re;
	}
	if(choice2 == 1)
	{
		printf("\n---STUDENT %d---\n",j+1);
		printf("Enter Name:- ");
		gets(S[i].name);
		printf("Enter Department:- ");
		gets(S[i].department);
		printf("Enter Enrollment Number:- ");
		gets(S[i].enrollment);
		printf("Enter Age:- ");
		scanf("%d",&S[i].age);
		fflush(stdin);
		j++;
		printf("\nUPDATED!!\n");
		printf("\nTOTAL NUMBER OF STUDENT/'S = %d\n",j);
		goto re;
	}
	if(choice2 == 2)
	{
		int viewinfo;
		re2:
		printf("WHICH STUDENT:- ");
		scanf("%d",&viewinfo);
		getchar(); 
		if((viewinfo > 0)&&(viewinfo <= j))//THIS LINE CHECKS, WHETHER VIEWINFO ENTERED BY USER IS IN THE LIMIT;
		{
			viewinfo--;//THIS LINE DECREMENTS, VIEWINFO'S VALUE, SO IT CAN CORRECTLY CHECK ARRAY WITH 0 INDEX;
			printf("\n---STUDENT %d's details---\n",viewinfo+1);
			printf("\n-----------\n");
			printf("|NAME:- %s\n",S[viewinfo].name);
			printf("|DEPARTMENT:- %s\n",S[viewinfo].department);
			printf("|ENROLLMENT NUMBER:- %s\n",S[viewinfo].enrollment);
			printf("|AGE:- %d\n",S[viewinfo].age);
			printf("------------\n");
			goto re;
		}
		else
		{
			printf("\n!!STUDENT NOT FOUND!!\n");
			goto re2;
		}
	}
    if(choice2 == 3)
	{
		int clr;
		printf("DO YOU REALLY WANT TO CLEAR THE DATA(1 = YES)(0 = NO):- ");
		scanf("%d",&clr);
		if(clr == 1)
		{
			printf("PROGRAM IS RESETTING!!.....\n");
			Sleep(4);
			system("cls");
			goto res;
		}
		if(clr == 0)
		{
			printf("\nRedirecting to options\n");
			goto re;
		}
	}
	if(choice2 == 4)
	{
		exit(2);
	}
	if(choice2 == 5)
	{
		edit(j,S);
		goto re;
	}
	return 0;
}