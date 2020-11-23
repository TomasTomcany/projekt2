/******************************************************************
FIIT STU
Proceduralne programovanie
2020/21
Tomas Tomcany

Program: Projekt2
******************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct entry
{
	char name[51];
	char species[31];
	int height;
	double weight;
	int birth_date;
	int feeding_date;
	char caretaker[51];
	struct entry* next;
}ENTRY;

void foo_n(ENTRY** p_start)
{
	FILE* f;
	f = fopen("zvierata.txt", "r");

	int line = 1, count = 0, test;
	char string1[51], string2[51];
	ENTRY* new_entry = (ENTRY*)malloc(sizeof(ENTRY));

	rewind(f);
	while (!feof(f)) {
		switch (line){
			case 0: {
				ENTRY* new_entry = (ENTRY*)malloc(sizeof(ENTRY));
				break;
			}
			case 1:
				fscanf(f, "%s", &string1);									 // get through "$$$"
				fscanf(f, "%s", &new_entry->name);
				break;
			case 2: {
				fscanf(f, "%s", &string1);
				fscanf(f, "%s", &string2);
				strcpy(new_entry->species, strcat(strcat(string1, " "), string2));
				break;
			}
			case 3:
				fscanf(f, "%d", &new_entry->height);
				break;
			case 4:
				fscanf(f, "%lf", &new_entry->weight);
				break;
			case 5:
				fscanf(f, "%d", &new_entry->birth_date);
				break;
			case 6:
				fscanf(f, "%d", &new_entry->feeding_date);
				break;
			case 7:
				fscanf(f, "%s", &string1);
				fscanf(f, "%s", &string2);
				strcpy(new_entry->caretaker, strcat(strcat(string1, " "), string2));
				break;
		}

		line++;
		if (line > 7) {
			line = 0;
			new_entry->next = (*p_start);
			(*p_start) = new_entry;
		}
	}


	fclose(f);
}

int main(void) 
{
	ENTRY* p_start = NULL;
	char input = '\0';

	while (input != 'k') {
		scanf("%c", &input);
		switch (input) {
			case 'n':
				foo_n(&p_start);
				break;
		}
	}


	return 0;
}