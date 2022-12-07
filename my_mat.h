#ifndef MY_MAT_H
#define MY_MAT_H


#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include<unistd.h>

void take_values(int[][10]);

bool Route_exist(int[][10], int, int);

int Cal_minDistance(bool[], int[], int, int);

void cleaning_matrix(int[], bool[], int);

void apply_dijkstra(int[], bool[], int[][10]);

void calculate_shortest_path(int[][10], int, int);

void print(int[][10]);

void Exit();

void clean_stdin();

#endif
