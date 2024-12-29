#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct library {
    char name[100];
    char author[100];
    char publisher[100];
    char year [10];
} Database;

int bookAdd() {
    Database newBook;
    FILE* fptr = fopen("Database.txt", "a");
    if (fptr == NULL) {
        printf("Error: Could not open the file.\n");
        return -1;
    }

    printf("Enter book name: ");
    scanf(" %[^\n]s", newBook.name);
    printf("Enter book author: ");
    scanf(" %[^\n]s", newBook.author);
    printf("Enter publisher name: ");
    scanf(" %[^\n]s", newBook.publisher);
    printf("Enter year of publication: ");
    scanf(" %[^\n]s", newBook.year);

    fprintf(fptr, "%s|%s|%s|%s\n", newBook.name, newBook.author, newBook.publisher, newBook.year);
    fclose(fptr);

    return 0;
}
int bookNameSearch(char* ptSearch) {
    int i=0;
    Database curretData;
    FILE* fptr;
    fptr = fopen("C:\\Users\\tubab\\CLionProjects\\Library_Project\\Database.txt", "r");
    if(fptr == NULL) {
        printf("error no1 \n");
        return -1;
    }
    while(!feof(fptr)) {
        fscanf((fptr), "%s", curretData.name);
        if(strcmp(curretData.name, ptSearch) == 0) {
            printf("Book name found \n");
            i++;
        }

        fclose(fptr);
        return i;
    }
}
int bookAuthorSearch(char* ptSearch) {
    int i=0;
    Database curretData;
    FILE* fptr;
    fptr = fopen("C:\\Users\\tubab\\CLionProjects\\Library_Project\\Database.txt", "r");
    if(fptr == NULL) {
        printf("error no2 \n");
        return -1;
    }
    while(!feof(fptr)) {
        fscanf((fptr), "%s", curretData.author);
        if(strcmp(curretData.author, ptSearch) == 0) {
            i++;
        }
        fclose(fptr);
        return i;
    }
}



int main(void)
{
    struct library;
    int prefer;
    int  bookSearchResult=0;
    int authorSearchResult=0;
    char searchBookName[50];
    char searchAuthorName[50];

    do {
        printf("\n\nHELLO! WELCOME TO LIBRARY MANAGEMENT SYSTEM...\n");
        printf("Please select the operation you want to do: \n");
        printf("Press 0 to exit.\n");
        printf("Press 1 to Book name research. \n");
        printf("Press 2 to Book author research.\n");
        printf("Press 3 to require new book.\n");
        scanf("%d", &prefer);
        switch (prefer) {
            case 0: printf("SEE YOU!"); break;
            case 1: printf("Enter book name : ");
            scanf("%s", &searchBookName);
            bookSearchResult=bookNameSearch(searchBookName);
            if (bookSearchResult== 0) {
                printf("\nBook name not found, please add new book.\n");
            }
            else {
                printf("\nToplam %d kayıt bulundu", bookSearchResult);
            }

            break;
            case 2: printf("Enter author name : ");
            scanf("%s", &searchAuthorName);
            authorSearchResult=bookAuthorSearch(searchAuthorName);
            if (authorSearchResult== 0) {
                printf("\nAuthor name not found\n");
            }
            else {
                printf("\nToplam %d kayıt bulundu", authorSearchResult);
            }
            break;
            case 3: if (bookAdd() != 0 ) {
                printf("Book not added sucsessfully.\n");
            }
            else {
                printf("Book added sucsessfully.\n");
            }
            break;
            default: printf("Please select an option.\n");
        }

    }
    while (prefer != 0);


    return 0;
}