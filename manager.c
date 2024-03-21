#include <stdio.h>
#include <stdlib.h>


struct Book {
    char name[64];
    char author[64];
    int library_num;
};

//extern 
void add(struct Book books[], struct Book *pBook, int num);
void printAll(struct Book books[],int num);
void search(struct Book books[], int num);
void printBook(struct Book *pBook);

int main() {
    int count = 0;

    //making array of boks
    struct Book books[100];

    //making a pointer
    struct Book *pBook = books;

    add(books, pBook, count++);

    printAll(books, count);

}


void add(struct Book books[], struct Book *pBook, int num) {
    system("cls");
    printf("\n\t\t########### Add new book! ###########\t\t\n");
    printf("\nBook title -->\t");
    gets(pBook->name);
    printf("\nBook Author -->\t");
    gets(pBook->author);
    printf("\nLibrary Number = %d", num);
    pBook->library_num = num + 1;

    printBook(pBook);
    pBook += 1;
   
}


void printAll(struct Book books[], int num) {
    system("cls");
    printf("\n\t\t################## Library details ##################\t\t\n");
    printf("\t\t------------------------------------------------------\t\t\n");
    printf("\n\t\tBook Title\t\tBook Author\t\tLibrary number\t\t\n");

    for(int i = 0; i < num; i++) {
        printf("\n\t\t%s",books[i].name);
        printf("\t\t\t%s",books[i].author);
        printf("\t\t\t%d",books[i].library_num);
    }
}

void search(struct Book books[], int num) {
    char title[32];
    printf("what is the title book are you loking for?\n");
    gets(title);

    for(int i = 0; i < num; i++) {
        if (strcmp(books[i].name, title) == 0) {
            printBook(&books[i]);
        }
    }

}

void printBook(struct Book *pBook) {
    //system("cls");
    printf("\n\t\t################## Book details ##################\t\t\n");
    printf("\t\t------------------------------------------------------\t\t\n");
    printf("\n\t\tBook Title\t\tBook Author\t\tLibrary number\t\t\n");

    printf("\n\t\t%s", *pBook->name);
    printf("\t\t\t%s", *pBook->author);
    printf("\t\t\t%d", pBook->library_num);
    
}