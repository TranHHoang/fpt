#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

struct Book {
	char code[256];
	char title[256];
	int quantity;
	float price;
} books[MAXSIZE];

int length;

int printSelect() {
	int choice;
	printf("  Select options:\n"
		   "  1. Enter the list of books\n"
		   "  2. Display the list of books\n"
		   "  3. Sort the list of books by code\n"
		   "  0. Exit\n"
		   "  Your selection (0 -> 3): "
		);
	scanf("%d", &choice);
	return choice;
}

int isCodeExist(char code[], int len) {
	//printf("Hello");
	for (int i = 0; i < len; i++) {
		if (strcmp(books[i].code, code) == 0) {
			return 1;
		}
	}
	
	return 0;
}

void enterBook() {
	printf("Enter number of books: ");
	scanf("%d", &length);

	for (int i = 0; i < length; i++) {
		printf(" Book %d:\n", i + 1);
		do {
			printf(" Enter code: ");
			fflush(stdin);
			gets(books[i].code);
			if (isCodeExist(books[i].code, i) == 1)
				printf("The code %s already exists, please reenter!\n", books[i].code);
			else break;
		} while (1);
		printf(" Enter title: ");
		fflush(stdin);
		gets(books[i].title);
		printf(" Enter quantity: ");
		scanf("%d", &books[i].quantity);
		printf(" Enter price: ");
		scanf("%f", &books[i].price);
	}
}

void display() {
	printf("\n%2s%10s%10s%8s%9s\n", "Code", "Title", "Quantity", "Price", "Value");
	
	float sum = 0;

	for (int i = 0; i < length; i++) {
		sum += books[i].price * books[i].quantity;
		printf("%2s%11s%10d%8.1f%9.1f\n", books[i].code, books[i].title, books[i].quantity, books[i].price, books[i].price * books[i].quantity);
	}
	printf("\n%s %5.1f\n\n", "Total value:", sum);
}

void sort() {
	for (int i = length - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(books[j].code, books[j + 1].code) > 0) {
				struct Book t = books[j];
				books[j] = books[j + 1];
				books[j + 1] = t;
			}
		}
	}
}

int main() {
	do {
		switch (printSelect()) {
		case 0:
			return 0;
		case 1:
			enterBook();
			break;
		case 2:
			display();			
			break;
		case 3:
			sort();
			break;
		}
	} while (1);
}