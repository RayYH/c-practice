#include "core.h"

struct Person {
  char name[50];
  int age;
};

typedef struct Book {
  struct Person author;
  char title[50];
  float price;
} Book;

void basic_usage() {
  struct Person person1, person2, person3, *person_ptr;

  strcpy(person1.name, "Ray");
  person1.age = 24;
  strcpy(person2.name, "Tom");
  person2.age = 25;

  assert(strcmp(person1.name, "Ray") == 0);
  assert(strcmp(person2.name, "Tom") == 0);
  assert(person1.age == 24);
  assert(person2.age == 25);

  person_ptr = &person3;
  strcpy(person_ptr->name, "Ray");
  person_ptr->age = 24;
  assert(strcmp(person_ptr->name, "Ray") == 0);
  assert(person_ptr->age == 24);
  assert((*person_ptr).age == 24);

  Book book1;
  strcpy(book1.title, "Book Title!");
  book1.author = person1;
  book1.price = 12.7f;
  assert(strcmp(book1.author.name, "Ray") == 0);
  assert(book1.price == 12.7f);
}

/**
 * We can use a pointer to reference to a struct.
 */
void structs_with_pointers() {
  START

  struct Person *ptr;
  int i, n = 3;
  char name[20];
  char ch[1] = {'1'};

  // allocating memory for n numbers of struct Person
  ptr = (struct Person *) malloc(n * sizeof(struct Person));

  for (i = 0; i < n; ++i) {
    strcpy(name, "person");
    strcat(name, ch);
    ch[0]++;
    strcpy((ptr + i)->name, name);
    (ptr + i)->age = 20 + i;
  }

  printf("Displaying Information:\n");
  for (i = 0; i < n; ++i) {
    printf("Name: %s\tAge: %d\n", (ptr + i)->name, (ptr + i)->age);
  }

  END
}

int main(void) {
  basic_usage();
  structs_with_pointers();

  return 0;
}
