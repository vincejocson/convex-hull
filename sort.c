#include "sort.h"

// Helper function to find the anchor point
Point find_anchor_point(Point points[], int n) {
    Point anchor, temp;
    int anchor_index;
    anchor = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].y < anchor.y || (points[i].y == anchor.y && points[i].x < anchor.x)) {
            anchor = points[i];
            anchor_index = i;
        }
    }
    temp = points[0];
    points[0] = anchor;
    points[anchor_index] = temp;
    return anchor;
}

// Helper function to calculate the polar angle between two points
double calculate_polar_angle(Point anchor, Point p) {
    return atan2(p.y - anchor.y, p.x - anchor.x);
}

double calculate_distance(Point a, Point b) {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

// Bubble Sort implementation
void bubble_sort(Point points[], int n, Point anchor) {
	Point temp;
	double p1, p2;
	int i, j;
	for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - i - 1; j++) 
		{
			p1 = calculate_polar_angle(anchor, points[j]);
			p2 = calculate_polar_angle(anchor, points[j + 1]);
			if (p1 > p2 || (p1 == p2 && calculate_distance(anchor, points[j]) > calculate_distance(anchor, points[j + 1]))) 
			{
				temp = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp;
            }
        }
    }
}

// Helper functions for Heap Sort
void heapify(Point points[], int n, int i, Point anchor) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    double p1, p2;
	p1 = calculate_polar_angle(anchor, points[left]);
	p2 = calculate_polar_angle(anchor, points[largest]);
    if (left < n && (p1 > p2 || (p1 == p2 && calculate_distance(anchor, points[left]) > calculate_distance(anchor, points[largest])))) {
        largest = left;
    }
    p1 = calculate_polar_angle(anchor, points[right]);
	p2 = calculate_polar_angle(anchor, points[largest]);
    if (right < n && (p1 > p2 || (p1 == p2 && calculate_distance(anchor, points[right]) > calculate_distance(anchor, points[largest])))) {
        largest = right;
    }

    if (largest != i) {
        Point temp = points[i];
        points[i] = points[largest];
        points[largest] = temp;
        heapify(points, n, largest, anchor);
    }
}

// Heap Sort implementation
void heap_sort(Point points[], int n, Point anchor) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(points, n, i, anchor);
    }
    for (int i = n - 1; i > 0; i--) {
        Point temp = points[0];
        points[0] = points[i];
        points[i] = temp;
        heapify(points, i, 0, anchor);
    }
}
