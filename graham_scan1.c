#include <time.h>
#include "stack.h"
#include "stack.c"
#include "sort.h"
#include "sort.c"

int orientation(Point p, Point current, Point next){
	float area = (current.x - p.x) * (next.y - p.y) - (current.y - p.y) * (next.x - p.x);
	
	if (area < 0)
		return -1; // clockwise
	else if (area > 0)
		return 1; // counter clockwise
	else
		return 0; // collinear
}

int grahamScan(Point points[], Stack *S, int size){
	int status = 1;
	clock_t start;
	clock_t end;
	Point anchor;
	Point p;
	Point next;
	int i;
	int offset;
	
	start = clock();
	
	anchor = find_anchor_point(points, size);
	bubble_sort(points, size, anchor);
	
    Push(S, points[0], &status);
    Push(S, points[1], &status);
	if(!status)
		return 0;
	
    //get rid of intermediate collinear points
    //check if 0 1 2 are collinear
    //if collinear, pop 1 then push 2
    //check if 0 2 3 are collinear
    //if collinear, pop 2 then push 3
    //repeat
	i = 2;
	while(i < size)
	{
		p = Top(S, &status);
    	next = points[i];
		if (S->top > 0 && orientation(NextToTop(S, &status), p, next) == 0) 
		{
        	Pop(S, &status);
        	Push(S, next, &status);
        	i++;
    	}
    	else
    	{
    		offset = i;
			i = size;
		}	
	}

    for (i = offset; i < size; i++) 
	{
        next = points[i];
        p = Pop(S, &status);
		while (S->top > 0 && orientation(NextToTop(S, &status), p, next) <= 0) 
		{
            p = Pop(S, &status);
        }
        Push(S, p, &status);
        Push(S, points[i], &status);
    }
    p = Pop(S, &status);
    if(orientation(NextToTop(S, &status), p, points[0]) > 0)
    {
    	Push(S, p, &status);
	}
	end = clock();
    
    printf("%6d %15lf\n", size, (double)(end - start));  
    
    return 1;
}
