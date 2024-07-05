#include <stdio.h>
#include "Closed_Hash.h"

int main(void) {
    //printf("Hello, World!\n");

    ClosedDic D;
    initializeDictClosed(&D);

    Studtype A = {"101010", {"Mike", 'G', "Pino"}, "Cabancalan", 123};
    Studtype B = {"121212", {"Yevgeny", 'A', "Albano"}, "Tipolo", 456};

    insert_Dict(&D, &A);
    insert_Dict(&D, &B);

    display_Dict(D);
    return 0;
}
