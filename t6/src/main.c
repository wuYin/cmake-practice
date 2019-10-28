#include <stdio.h>

int debug = 1;

#ifndef ENABLE_DEBUG
debug = 0;
#endif

int main() {
    printf("is debuging: %d\n", debug);
}
