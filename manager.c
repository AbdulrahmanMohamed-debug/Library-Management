/******************************************************************************

RAM/Memory
------------ 
Index/address   -> value

0XFF01A     -> book
0XFF01A + 1 -> book
0XFF01A + 2 -> ...
0XFF01A + 3 -> 0
0XFF01A + 4 -> ...
0XFF01A + 5 -> 0XFF01A (this memoery is pointing to a Book struct or Int)


pBook = 0XFF01A + 5 - is the pointer to Book

When running a binary any OS will reserve 4 segments for your application in memory

1- Code segment /text 
2- Stack
3- Heap
4- Data/constants

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

// one book is using 64+64+4 = 36 bytes
struct Book {
    char name[64]; // name is a pointer (array variable is a pointer`)
    char author[64]; // author is a pointer
    int library_num; // library is not a pointer it's a variable on the stack with type int (takes 4 bytes)
};

//extern 
void add(struct Book* books, int* num);
void printAll(struct Book* books, int num);
void search(struct Book* books, int num);
void printBook(struct Book *pBook);
void switching(struct Book* books, int* count);

int main() {
    int count = 0;

    struct Book *books = (struct Book *) malloc(100 * sizeof(struct Book));
    //add(books, &count);
    //printAll(books, count);

    while(1==1) {
        switching(books, &count);
    }

    free(books);
}



void add(struct Book* books, int* num) {
    struct Book * pointer_to_current_book = books + *num; 

    printf("\n\t\t########### Add new book! ###########\t\t\n");
    printf("\nBook title -->\t");

    //while ((getchar()) == "\n");
    fgets(pointer_to_current_book->name, 64, stdin);

    printf("\nBook Author -->\t");
    fgets(pointer_to_current_book->author, 64, stdin);
    pointer_to_current_book->library_num = *num + 1;
    *num = *num +1;

    printBook(pointer_to_current_book);

}


void printAll(struct Book* books, int num) {
    printf("\n\t\t################## Library details ##################\t\t\n");
    printf("\t\t------------------------------------------------------\t\t\n");
    printf("\n\t\tBook Title\t\tBook Author\t\tLibrary number\t\t\n");

    for(int i = 0; i < num; i++) {
        printf("\n\t\t%s", (books + i)->name);
        printf("\t\t\t%s", (books + i)->author);// books+i->author returns address (%s requires address)
        printf("\t\t\t%d", (books + i)->library_num);// books + i)->library_num returns int
    }
}

void search(struct Book* books, int num) {
    char title[32];
    printf("what is the title book are you loking for?\n");
    gets(title);

    for(int i = 0; i < num; i++) {
        
        if (strcmp((books + i)->name, title) == 0) {
            printBook(books + i);
        }
    }

}


void printBook(struct Book *pBook) {
    //system("cls");
    printf("\n\t\t################## Book details ##################\t\t\n");
    printf("\t\t------------------------------------------------------\t\t\n");
    printf("\n\t\tBook Title\t\tBook Author\t\tLibrary number\t\t\n");

    printf("\n\t\t%s", pBook->name);
    printf("\t\t\t%s", pBook->author);
    printf("\t\t\t%d", pBook->library_num);
    
}

void switching(struct Book* books, int* count) {

    //system("cls");
    printf("\n\nwhat would you like to do?\n");
    printf("(1) Add a book\n");
    printf("(2) Show all books in the library\n");
    printf("(3) Search book details\n");
    printf("(4) exit");


    printf("\nEnter a number -->");
    int choice;
    scanf("%d", &choice);
    getchar();
    switch (choice) {
        case 1:
            add(books, count);
            break;
        case 2:
            printAll(books, *count);
            break;
        case 3:
            search(books,*count);
            break;
        case 4:
            exit(0);
        default:
            printf("Please enter a valid number in the next attempt");
            break;
    }
}
