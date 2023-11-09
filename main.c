#include <stdio.h>
#include <stdlib.h>

void printBytes(unsigned char *address, int size) {
    int count;
    for (count = 0; count < size; count++) {
        printf("%.2x ", address[count]);
    }
}

int getIndex(void) {
    int index = 0;
    int goodAnswer = 0;
    do {
        printf("\nChange d[index] to 5\nWhich index 0, 1, 2 or 3 (-1 to quit): ");
        scanf("%d", &index);
        if (index == -1) break;
        switch (index) {
            case 0:
            case 1:
            case 2:
            case 3:
            case -1: goodAnswer = 1;
        }
    } while (!goodAnswer);
    return index;
}

int main(int argc, char **argv) {
    int a = 5000;
    int b = 23;
    int c[1] = {1};
    int d[1] = {2};
    int index = 0;

    while (1) {
        printf("\nVariable    Memory        Bytes         Value\n");
        printf("-----------------------------------------------\n");
        printf("int a       %p   ", &a);
        printBytes((unsigned char *) &a, sizeof(int));
        printf("\t(%d)\n", a);
        printf("int b       %p   ", &b);
        printBytes((unsigned char *) &b, sizeof(int));
        printf("\t(%d)\n", b);
        printf("int[1] c    %p   ", c);
        printBytes((unsigned char *) c, sizeof(int[1]));
        printf("\t(%d)\n", c[0]);
        printf("int[1] d    %p   ", d);
        printBytes((unsigned char *) d, sizeof(int[1]));
        printf("\t(%d)\n", d[0]);

        index = getIndex();
        if (index <= -1) break;
        d[index] = 5;
    }

    return 0;
}
