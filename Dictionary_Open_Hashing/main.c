#include <stdio.h>
#include "Open_Hash.h"

int main(void) {
    printf("Hello, World!\n");

    Dict D;
    initializeDict(D);

    info d1 = {"Yevgeny", "Grazio", "Albano", "cebu", "tipolo"};
    info d2 = {"Kurt", "Mike", "Pino", "cebu", "cabancalan"};
    info d3 = {"Maria", "Angelica", "Zaragoza", "cebu", "casuntingan"};

    hashValue("tipolo");

    insert_to_Dict(&D, d1);
    insert_to_Dict(&D, d2);
    insert_to_Dict(&D, d3);

    displayDict(D);

    return 0;
}
