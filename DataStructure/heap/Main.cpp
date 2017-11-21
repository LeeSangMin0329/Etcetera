#include <iostream>
#include "Heap.h"

using namespace std;

enum Menu{
	Blank,
	Create,
	Destroy,
	Insert,
	Delete,
	MultInsert,
	MultDelete,
	PrintParent,
	PrintChild,
	PrintHeap,
};

int main(void) {

	Heap* heap = NULL;
	int input, count;

	while (true) {
		cout << endl << "1 CREATE" << endl
			<< "2 DESTROY" << endl
			<< "3 INSERT" << endl
			<< "4 DELETE" << endl
			<< "5 MULTIPLE INSERT" << endl
			<< "6 MULTIPLE DELETE" << endl
			<< "7 PRINT PARENT" << endl
			<< "8 PRINT CHILD" << endl
			<< "9 PRINT HEAP" << endl
			<< "node index start to 0" << endl << endl;

		cout << "Input command : ";
		cin >> input;
		getchar();

		if (input != Create && heap == NULL) {
			cout << "you should create heap first" << endl;
			continue;
		}
		if (input == Destroy && heap == NULL) {
			cout << "you should create heap first" << endl;
			continue;
		}

		switch (input)
		{
		case Create:
			cout << "Input max heap size : ";
			cin >> input;
			getchar();
			heap = new Heap(input);
			break;
		case Destroy:
			delete(heap);
			heap = NULL;
			break;
		case Insert:
			cout << "Input data : ";
			cin >> input;
			getchar();
			heap->Add(input);
			break;
		case Delete:
			heap->Remove();
			break;
		case MultInsert:
			cout << "Input how much to insert : ";
			cin >> count;
			getchar();
			for (int i = 0; i < count; i++) {
				cout << "Input data : ";
				cin >> input;
				getchar();
				heap->Add(input);
			}
			break;
		case MultDelete:
			cout << "Input how much to delete : ";
			cin >> count;
			getchar();
			for (int i = 0; i < count; i++) {
				heap->Remove();
			}
			break;
		case PrintParent:
			cout << "Input index : ";
			cin >> input;
			getchar();
			heap->PrintParent(input);
			break;
		case PrintChild:
			cout << "Input index : ";
			cin >> input;
			getchar();
			heap->PrintChild(input);
			break;
		case PrintHeap:
			heap->PrintHeap();
			break;
		default:
			getchar();
			break;
		}
		cout << endl;










	}




	return 0;
}