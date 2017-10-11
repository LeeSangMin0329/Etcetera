#include <stdio.h>
#include "ListP.h"

#define TRUE 1

int main(void) {
	ListType list;

	Init(&list);

	while (TRUE) {
		printf("\n--------------------------------------------------\n");
		printf("NOTICE : Enter the command.\n\n");
		printf("    Insert\t\t:\tI\n");
		printf("    Delete\t\t:\tD\n");
		printf("    Reverse\t\t:\tr\n");
		printf("    Retreve\t\t:\tR\n");
		printf("    RandomAppend\t:\tA\n");
		printf("    EmptyCheck\t\t:\tE\n");
		printf("    Length\t\t:\tL\n");
		printf("    PrintList\t\t:\tP\n");

		printf("\n>>");

		char inputChar;
		int position = 0, item = 0;
		scanf_s("%c", &inputChar, sizeof(char));
		getchar();

		switch (inputChar)
		{
		case 'I':
			printf("\nNOTICE : Enter insert position and item. (start position is zero.)\n>>");
			scanf_s("%d %d", &position, &item);
			getchar();
			Insert(&list, position, item);
			break;
		case 'D':
			printf("\nNOTICE : Enter delete position. (start position is zero.)\n>>");
			scanf_s("%d", &position);
			getchar();
			Delete(&list, position);
			break;
		case 'r':
			Reverse(&list);
			printf("\nNOTICE : List reverse was successful.\n");
			break;
		case 'R':
			printf("\nNOTICE : Enter item to you want search\n>>");
			scanf_s("%d", &item);
			getchar();
			Retrieve(&list, item);
			break;
		case 'A':
			printf("\nNOTICE : Enter the number of random values to generate.\n>>");
			scanf_s("%d", &position);
			getchar();
			RandomAppend(&list, position);
			break;
		case 'E':
			if (Length(&list)) {
				printf("\nNOTICE : List is not empty.\n");
			}
			else {
				printf("\nNOTICE : List is empty.\n");
			}
			break;
		case 'L':
			printf("\nNOTICE : %d elements is exist.\n", Length(&list));
			break;
		case 'P':
			PrintList(&list);
			break;
		default:
			printf("\nERROR : Invalid command.");
			break;
		}
	}

	// if program exit, all memory is free automatically. so this function is useless.
	Destroy(&list);

	return 0;
}