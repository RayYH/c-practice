#include<stdio.h>

void snippet() {
    // Here.. you can do something...
    int doses[] = {1, 3, 2, 1000};
    // doses[3] == *(doses + 3) == *(3 + doses) == 3[doses]
    printf("%i\n", 3[doses]);
}

int main(int argc, char *argv[]) {
    snippet();
    // remove snippet file
    remove(argv[0]);
    return 0;
}