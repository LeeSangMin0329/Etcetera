#include <iostream>
#include "ListPinCpp.h"

using namespace std;

int main(void) {
	ListP* list = new ListP();
	
	while (true) {
		cout << "\n--------------------------------------------------\n";
		cout << "NOTICE : Enter the command.\n\n";
		cout << "    Insert\t\t:\tI\n";
		cout << "    Delete\t\t:\tD\n";
		cout << "    Reverse\t\t:\tr\n";
		cout << "    Retrieve\t\t:\tR\n";
		cout << "    RandomAppend\t:\tA\n";
		cout << "    EmptyCheck\t\t:\tE\n";
		cout << "    Length\t\t:\tL\n";
		cout << "    PrintList\t\t:\tP\n";
		cout << "    DeDuplicate\t\t:\td\n";

		cout << "\n>>";

		char inputChar;
		int position = 0, item = 0;
		cin >> inputChar;
		getchar();

		switch (inputChar)
		{
		case 'I':
			cout << "\nNOTICE : Enter insert position and item. (start position is zero.)\n>>";
			cin >> position >> item;
			getchar();
			list->Insert(position, item);
			break;
		case 'D':
			cout << "\nNOTICE : Enter delete position. (start position is zero.)\n>>";
			cin >> position;
			getchar();
			list->Delete(position);
			break;
		case 'r':
			list->Reverse();
			cout << "\nNOTICE : List reverse successful.\n";
			break;
		case 'R':
			cout << "\nNOTICE : Enter item to you want search.\n>>";
			cin >> item;
			getchar();
			list->Retrieve(item);
			break;
		case 'A':
			cout << "\nNOTICE : Enter the number of random values to generate.\n>>";
			cin >> position;
			getchar();
			list->RandomAppend(position);
			break;
		case 'E':
			if (list->Length()) {
				cout << "\nNOTICE : List is not empty.\n";
			}
			else {
				cout << "\nNOTICE : List is empty.\n";
			}
			break;
		case 'L':
			cout << "\nNOTICE : " << list->Length() << " elements is exist.\n";
			break;
		case 'P':
			list->PrintList();
			break;
		case 'd':
			list->DeDuplicate();
			cout << "\nNOTICE : List deduplication successful.\n";
			break;
		default:
			cout << "\nERROR : Invalid command.";
			break;
		}
	}

	return 0;
}