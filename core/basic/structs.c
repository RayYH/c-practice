#include "structs.h"

struct person {
    char name[50];
    int age;
};

// typedef keyword and nested struct
typedef struct book {
    struct person author;
    char title[50];
    float price;
} book;

typedef struct complex {
    float real;
    float imag;
} complex;

void struct_usage() {
    char name[20];

    struct person person1, person2;
    strcpy(person1.name, "Ray");
    person1.age = 24;
    strcpy(person2.name, "Tom");
    person2.age = 25;

    printf("%s's age is %d.\n", person1.name, person1.age);
    printf("%s's age is %d.\n", person2.name, person2.age);

    book book1;
    strcpy(book1.title, "Book Title!");
    book1.author = person1;
    book1.price = 12.7f;

    printf("The price of %s's book '%s' is %.2f.\n", book1.author.name, book1.title, book1.price);

    struct person *person_ptr, person3;
    person_ptr = &person3;
    printf("Enter name: ");
    scanf("%s", name);
    strcpy(person_ptr->name, name);

    printf("Enter age: ");
    scanf("%d", &person_ptr->age);

    printf("Displaying:\n");

    // person_ptr->name is equivalent to (*person_ptr).name
    printf("Name: %s\n", person_ptr->name);
    printf("Age: %d\n", person_ptr->age);
}

void memory_allocation() {
    struct person *ptr;
    int i, n;

    printf("Enter the number of persons: ");
    scanf("%d", &n);
    // allocating memory for n numbers of struct person
    ptr = (struct person *) malloc(n * sizeof(struct person));
    for (i = 0; i < n; ++i) {
        printf("Enter first name and age respectively: ");
        // To access members of 1st struct person,
        // ptr->name and ptr->age is used

        // To access members of 2nd struct person,
        // (ptr+1)->name and (ptr+1)->age is used
        scanf("%s %d", (ptr + i)->name, &(ptr + i)->age);
    }

    printf("Displaying Information:\n");
    for (i = 0; i < n; ++i) {
        printf("Name: %s\tAge: %d\n", (ptr + i)->name, (ptr + i)->age);
    }
}

void add_numbers(complex c1, complex c2, complex *result) {
    result->real = c1.real + c2.real;
    result->imag = c1.imag + c2.imag;
}

void passing_struct_by_ref() {
    complex c1, c2, result;

    printf("For first number,\n");
    printf("Enter real part: ");
    scanf("%f", &c1.real);
    printf("Enter imaginary part: ");
    scanf("%f", &c1.imag);

    printf("For second number, \n");
    printf("Enter real part: ");
    scanf("%f", &c2.real);
    printf("Enter imaginary part: ");
    scanf("%f", &c2.imag);

    add_numbers(c1, c2, &result);
    printf("\nresult.real = %.1f\n", result.real);
    printf("result.imag = %.1f", result.imag);
}