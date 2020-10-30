#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char ** CreateArray (int *);
void FillArray (char **, int);
void DeleteNewlineChars (char **, int);
void ShowArray (char **, int);
void SearchStringWithBiggestWord(char **, int);

void DefineStringWithBiggestWord(int *, int);


int main()
{
    int amountOfString;
    char ** array = CreateArray(&amountOfString);
    FillArray(array, amountOfString);
    DeleteNewlineChars(array, amountOfString);
    ShowArray(array, amountOfString);
    SearchStringWithBiggestWord(array, amountOfString);
    
    _getch();

    return 0;
}

char ** CreateArray (int * size){
    char ** arr = NULL;
    int i;
    printf("Enter amount of strings: ");
    scanf("%d", size);
    printf("\n");
    
    arr = (char **)calloc(*size, sizeof(char *));
        for(i = 0; i < *size; i++){
            arr[i] = (char*)calloc(22, sizeof(char));
        }
    
    return arr;
}

void FillArray (char ** arr, int size){
    int i;
    
    getchar();
    for(i = 0; i < size; i++){
        printf("Enter string %d (max 20 chars): ", i+1);
        fgets(arr[i], 22, stdin);
    }
    printf("\n");
}

void DeleteNewlineChars(char ** arr, int size){
    int i, j;
    
    for(i = 0; i < size; i++){
        for(j = 0; j < 22; j++){
            if (arr[i][j] == '\n'){
                arr[i][j] = '\0';
            }
        }
    }
}

void ShowArray (char ** arr, int size){
    int i;
    printf("Your array:\n");
    for (i = 0; i < size; i++){
        puts(arr[i]);
    }
    printf("\n");
}

void SearchStringWithBiggestWord(char ** arr, int size){
    int i, j;
    void (*define)(int *, int);
    
    int * resultArr = (int *)calloc(size, sizeof(int));
    int counter = 0;
    int maxElement = 0;
    for (i = 0; i < size; i++){
        counter = 0;
        for (j = 0; j < 22; j++){
          if(arr[i][j] != '\0'){
              if (arr[i][j] == ' '){
                  counter = 0;
                  continue;
              }
                counter++;
              }
              if(counter > resultArr[i]){
                  resultArr[i] = counter;
              }
              if (arr[i][j] == '\0'){
                  break;
              }
        }
    }
    
    
    define = DefineStringWithBiggestWord;
    define(resultArr, size);
}

void DefineStringWithBiggestWord (int * arr, int size){
    int i;
    int maxElement = *arr;
    for(i = 1; i < size; i++){
        if (maxElement < arr[i]){
            maxElement = arr[i];
        }
    }
    
    for (i = 0; i < size; i++){
        if (arr[i] == maxElement){
            printf("Number of string with the biggest word is %d\n", i+1);
        }
    }
}
