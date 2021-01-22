#include "core.h"

struct Person {
  char name[50];
  int age;
};

// typedef keyword and nested struct
typedef struct Book {
  struct Person author;
  char title[50];
  float price;
} Book;

typedef struct Complex {
  float real;
  float imag;
} Complex;

struct Employee {
  int emp_id;
  int length;
  // In gcc, when we create an array of zero length, it is considered as array
  // of incomplete type that’s why gcc reports its size as “0” bytes.
  // When we create array of zero length inside structure, it must be (and only)
  // last member of structure.
  char name[0];
};

// structures will be padded to 4-byte alignment
typedef struct {
  char Data1; // 1
  // 3-Bytes Added here.
  int Data2; // 4
  unsigned short Data3; // 2
  char Data4; // 1
  //1-byte Added here.

} sSampleStruct;

void add_numbers(Complex c1, Complex c2, Complex *result);

/**
 * Simple struct usage.
 */
void struct_usage() {
  struct Person person1, person2;

  strcpy(person1.name, "Ray");
  person1.age = 24;
  strcpy(person2.name, "Tom");
  person2.age = 25;

  assert(strcmp(person1.name, "Ray") == 0);
  assert(strcmp(person2.name, "Tom") == 0);
  assert(person1.age == 24);
  assert(person2.age == 25);

  Book book1;
  strcpy(book1.title, "Book Title!");
  book1.author = person1;
  book1.price = 12.7f;
  assert(strcmp(book1.author.name, "Ray") == 0);
  assert(book1.price == 12.7f);

  struct Person *person_ptr, person3;
  person_ptr = &person3;
  // person_ptr->name is equivalent to (*person_ptr).name
  strcpy(person_ptr->name, "Ray");
  assert(strcmp(person_ptr->name, "Ray") == 0);
  person_ptr->age = 24;
  assert(person_ptr->age == 24);
}

/**
 * We can define a struct array.
 */
void array_of_structure() {
  struct Complex arr[2] =
      {
          {.real = 1.0, .imag = 2.0},
          {.real = 2.0, .imag = 4.0}
      };
  assert(arr[0].real == 1.0);
  assert(arr[0].imag == 2.0);
  Complex result;
  add_numbers(arr[0], arr[1], &result);
  assert(result.real == 3.0);
  assert(result.imag == 6.0);
}

/**
 * We can use a pointer to reference to a struct.
 */
void struct_with_pointer() {
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

/**
 *
 */
void struct_hack() {
  struct Employee e;
  e.emp_id = 0;
  assert(e.emp_id == 0);
  assert(sizeof(e) == 8);
  // valid, now name is of length 128
  struct Employee *employee = malloc(sizeof(*employee) + sizeof(char) * 128);
  employee->emp_id = 1;
  employee->length = 128;
  strcpy(employee->name, "Rayyh");
  assert(employee->emp_id == 1);
  assert(employee->length == 128);
  assert(strcmp(employee->name, "Rayyh") == 0);
}

void add_numbers(Complex c1, Complex c2, Complex *result) {
  result->real = c1.real + c2.real;
  result->imag = c1.imag + c2.imag;
}

void passing_struct_by_ref() {
  Complex c1 = {
      1.0, 2.0
  };
  Complex c2 = {
      2.0, 4.0
  };
  Complex result;
  add_numbers(c1, c2, &result);
  assert(result.real == 3.0);
  assert(result.imag == 6.0);
  Complex c3 = {
      .real= 1.0,
      .imag = 2.0
  };
  Complex c4 = {
      .real = 2.0,
      .imag = 4.0
  };
  add_numbers(c3, c4, &result);
  assert(result.real == 3.0);
  assert(result.imag == 6.0);
}

int main(void) {
  struct_usage();
  struct_with_pointer();
  passing_struct_by_ref();
  array_of_structure();
  struct_hack();

  return 0;
}
