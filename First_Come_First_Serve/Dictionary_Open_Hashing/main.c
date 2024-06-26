#include <stdio.h>
#include "Open_Hash.h"

int main(void) {
    printf("Hello, World!\n");

    Dict D;
    initializeDict(D);

    info d1 = {"Yevgeny", "Grazio", "Albano", "cebu", "tipolo"};
    info d2 = {"Kurt", "Mike", "Pino", "cebu", "cabancalan"};
    info d3 = {"Maria", "Angelica", "Zaragoza", "cebu", "casuntingan"};
    info d4 = {"Mario", "Angelo", "Zaragoza", "cebu", "casuntingan"};
    info d5 = {"Manuel", "Anthony", "Zaragoza", "cebu", "casuntingan"};
    info d6 = {"Nathan", "Buddy", "Pernites", "cebu", "nasipit"};

//    insert_to_Dict(&D, d1);
//    insert_to_Dict(&D, d2);
//    insert_to_Dict(&D, d3);
//    insert_to_Dict(&D, d4);
//    insert_to_Dict(&D, d5);

    insert_sorted_to_Dict(&D, d1);
    insert_sorted_to_Dict(&D, d2);
    insert_sorted_to_Dict(&D, d3);
    insert_sorted_to_Dict(&D, d4);
    insert_sorted_to_Dict(&D, d5);
    insert_sorted_to_Dict(&D, d6);

    displayDict(D);

    isMember(&D, d6);
//
//    delete_from_Dict(&D, d5);
//
//    displayDict(D);

    return 0;
}
