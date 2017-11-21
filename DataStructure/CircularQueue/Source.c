#define MAXBUFFERSIZE 3

#include <stdio.h>
int Is_empty();
int Is_full();
void Enqueue(int clip);
int Dequeue(void);


static int ringBuffer[MAXBUFFERSIZE];
static int frontIndex = 0;
static int rearIndex = 0;

int main(void) {
	
	
	int i, j;
	Enqueue(3);
	Dequeue();
	while (1) {
		scanf_s("%d %d", &i, &j);

		if (i) {
			Enqueue(j);
		}
		else {
			Dequeue();
		}
		for (int i = 0; i < MAXBUFFERSIZE;i++)
			printf("%d ", ringBuffer[i]);
	}
	
	return 0;
}

int Is_empty() {
	return (frontIndex == rearIndex);
}

int Is_full() {
	return (((rearIndex + 1) % MAXBUFFERSIZE) == frontIndex);
}

void Enqueue(int clip) {
	if (Is_full()) {
		printf("queue is full\n");
		return;
	}

	rearIndex = ((rearIndex + 1) % MAXBUFFERSIZE);
	ringBuffer[rearIndex] = clip;
}

int Dequeue(void) {
	if (Is_empty()) {
		printf("queue is empty\n");
		return;
	}
	frontIndex = (frontIndex + 1) % MAXBUFFERSIZE;
	printf("dequ %d\n", ringBuffer[frontIndex]);
	return ringBuffer[frontIndex];
}