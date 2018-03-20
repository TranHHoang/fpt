#include <stdio.h>
#define MAXSIZE 100

int length;
float a[MAXSIZE];

int printMenu() {
	int choice;
	printf("  Select options:\n"
		   "  1. Enter the list of float numbers\n"
		   "  2. Sort the list in increasing order\n"
		   "  3. Search value x in the list\n"
		   "  4. Display the list\n"
		   "  0. Exit\n"
		   "  Your selection (0 -> 4): "
		);
	fflush(stdin);
	scanf("%d", &choice);
	return choice;
}

void enterList() {
	printf("\n Input size of array n = ");
	scanf("%d", &length);
	printf(" Enter %d float numbers: ", length);
	for (int i = 0; i < length; i++) {
		scanf("%f", &a[i]);
	}
}

void sort() {
	for (int i = length - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				float t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

void search() {
	float x;
	printf("Enter the value x to be searched: ");
	scanf("%f", &x);
	for (int i = 0; i < length; i++) {
		if (a[i] == x) {
			printf("Found %.1f at position %d\n", x, i);
			return;
		}
	}
	printf("Not found %.1f\n", x);
}

void display(const char *mes) {
	printf("%s", mes);
	for (int i = 0; i < length; i++) {
		printf("%.1f ", a[i]);
	}
	printf("\n");
}

int main() {
	do {
		switch (printMenu()) {
		case 1:
			enterList();
			break;
		case 2:
			display("Before sorting: ");
			sort();
			display("After sorting: ");
			break;
		case 3:
			search();
			break;
		case 4:
			display("");
			break;
		case 0:
			return 0;
		}
	} while (1);
}