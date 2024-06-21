//
// Created by Kurt Mike Pino on 6/21/24.
//

#ifndef ADT_SET_UNION_INTERSECTION_UNION_INTERSECTION_H
#define ADT_SET_UNION_INTERSECTION_UNION_INTERSECTION_H
#define SET_MAX 8

typedef int SET[SET_MAX];

/*
 * Create a program to Find the UNION & INTERSECTION of 2 Sets
 *
 * Functions that accept 2 sets and returns the resulting Union & Intersection
 *
 * Functions to add or delete values in the Set
 *
 * Keep the integrity of the 2 initial sets when finding Union & Intersection
 *
 * Display Union & Intersection
 */

void insert_To_SET(SET S, int x);
void delete_From_SET(SET S, int x);

SET *Union(SET A, SET B);
SET *Intersection(SET A, SET B);
SET *Difference(SET A, SET B);
void displaySET(SET S);

#endif //ADT_SET_UNION_INTERSECTION_UNION_INTERSECTION_H
