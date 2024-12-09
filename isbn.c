#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char title[100];
    char author[50];
    char isbn[13];  
} Book;


void sortBooksByISBN(Book books[], int n);
int binarySearchByISBN(Book books[], int n, char targetISBN[]);
void printBookDetails(Book book);

int main() {
    Book library[] = {
        {"O Senhor dos Anéis", "J.R.R. Tolkien", "9780345339706"},
        {"1984", "George Orwell", "9780451524935"},
        {"O Código Da Vinci", "Dan Brown", "9780307474278"},
        {"Dom Quixote", "Miguel de Cervantes", "9780060934347"},
        {"Orgulho e Preconceito", "Jane Austen", "9780141439518"}
    };
    int n = sizeof(library) / sizeof(library[0]);
    char targetISBN[13];
    int result;

    printf("Digite o ISBN do livro que deseja buscar: ");
    scanf("%s", targetISBN);

    sortBooksByISBN(library, n);
    result = binarySearchByISBN(library, n, targetISBN);

    if (result != -1) {
        printf("\nLivro encontrado:\n");
        printBookDetails(library[result]);
    } else {
        printf("\nLivro com ISBN %s não encontrado.\n", targetISBN);
    }

    return 0;
}

void sortBooksByISBN(Book books[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(books[j].isbn, books[j + 1].isbn) > 0) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int binarySearchByISBN(Book books[], int n, char targetISBN[]) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int comparison = strcmp(books[mid].isbn, targetISBN);
        if (comparison == 0)
            return mid;
        if (comparison < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void printBookDetails(Book book) {
    printf("Título: %s\n", book.title);
    printf("Autor: %s\n", book.author);
    printf("ISBN: %s\n", book.isbn);
}
