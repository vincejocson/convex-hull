#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <math.h>
#include "stack.h"


// Function to find the anchor point with lowest y (or lowest x if tied)
Point find_anchor_point(Point points[], int n);

// Function to calculate the polar angle from the anchor point
double calculate_polar_angle(Point anchor, Point p);

// Bubble Sort based on polar angle
void bubble_sort(Point points[], int n, Point anchor);

// Heap Sort based on polar angle
void heap_sort(Point points[], int n, Point anchor);

#endif // SORT_H
