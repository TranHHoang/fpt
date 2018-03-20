#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define char* string

struct Word {
    char chars[256];
};

void split(struct Word wordList[], int &wordCount, char s[]) {
    static int i; // 10
    string tmpS = strtok(s, " ");
    while (tmpS != NULL) {
        strcpy(wordList[wordCount++].chars, tmpS);
        tmpS = strtok(NULL, " "); 
    }
}

void sort(struct Word wordList[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcmp(wordList[j].chars, wordList[j + 1].chars) > 0) {
                struct Word t = wordList[j];
                wordList[j] = wordList[j + 1];
                wordList[j + 1] = t;
            }
        }
    }
}

void fun(int tc, char s[]) {
    int listSize = 0;
    struct Word wordList[100];
    split(wordList, listSize, s);

    if (tc == 1) {
        sort(wordList, listSize);
        for (int i = 0; i < listSize; i++) {
            printf("%s ", wordList[i].chars);
        }
    }
    else {
        for (int i = 1; i < listSize - 1; i++) {
            printf("%s ", wordList[i].chars);
        }
    }
}

int main() {
    char s[256];
    gets(s);
    fun(2, s);

    system("pause");
}