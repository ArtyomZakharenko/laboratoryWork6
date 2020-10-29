#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char ** CreateArray (int *);
void FillArray (char **, int);

int main()
{
    

    return 0;
}

char ** CreateArray (int * size){
    char ** arr = NULL;
    int i;
    printf("Enter amount of strings: ");
    scanf("%d", size);
    printf("\n");
    
    arr = (char **)calloc(*size, sizeof(char *));
        for(i = 0; i < 21; i++){
            arr[i] = (char*)calloc(21, sizeof(char));
        }
    
    return arr;
}

void FillArray (char ** arr, int size){
    int i;
    
    for(i = 0; i < size; i++){
        printf("Enter string %d (max 20 chars): ", i+1);
        scanf("%20ms", &arr[i]);
    }
    printf("\n");
}
