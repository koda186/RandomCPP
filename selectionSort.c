#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFF_SIZE 40
#define STRUCT_SIZE 512

struct info{
	char name[BUFF_SIZE];
	char stAddress[BUFF_SIZE];
	char cityAndState[BUFF_SIZE];
	char zip[BUFF_SIZE];
};

void selectionSort(struct info *ptrStruct[], int countAddress);

int main(void)
{
	int count;
	int countAddress;					
	struct info *ptrStruct[STRUCT_SIZE];//Declare an array of pointers to structures.

	/*This loop inputs the information from the input.txt file into each struct.*/
	for (count = 0; count < STRUCT_SIZE; count++)
	{
		//allocate memory for each element in the array.
		ptrStruct[count] = (struct info*) malloc(sizeof(struct info));	
		//if (strlen(gets(ptrStruct[count]->name, BUFF_SIZE, stdin)) == 0)//does not work
		if (gets(ptrStruct[count]->name) == NULL)
		{
			free(ptrStruct[count]);
			break;
		}
		gets(ptrStruct[count]->stAddress);
		gets(ptrStruct[count]->cityAndState);
		gets(ptrStruct[count]->zip);
	}

	countAddress = count;
	selectionSort(ptrStruct, countAddress);

	printf("\nTotal addresses %d\n", countAddress);
	printf("LEAST TO GREATEST: \n");
	/*This loop echoes the input with the zip codes from least to greatest.*/
	for (count = 0; count < countAddress; count++)
	{
		printf("%s\n", ptrStruct[count]->name);
		printf("%s\n", ptrStruct[count]->stAddress);
		printf("%s\n", ptrStruct[count]->cityAndState);
		printf("%s\n", ptrStruct[count]->zip);
	}
}

void selectionSort(struct info *ptrStruct[], int countAddress)
{
	int count1, count2;
	int minIndex;
	struct info *ptrTemporary;	
	//struct info ptrTemporary;

	for (count2 = 0; count2 < countAddress - 1; count2++)
	{
		minIndex = count2;
		for (count1 = count2 + 1; count1 < countAddress; count1++)
		{

			if (strcmp(ptrStruct[count1]->zip, ptrStruct[minIndex]->zip) < 0)//FIX THIS PROBLEM
				minIndex = count1;
		}
		if (minIndex != count2){
			ptrTemporary = ptrStruct[count2];
			ptrStruct[count2] = ptrStruct[minIndex];
			ptrStruct[minIndex] = ptrTemporary;
		}
	}
}