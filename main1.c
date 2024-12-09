#include <stdio.h>
#include <math.h>
#include "graham_scan1.c"

typedef char String30[31];

int Import(Point points[], String30 filename, int *size)
{
	FILE *fp_importfile;
	int i;
	
	if((fp_importfile = fopen(filename, "r")) == NULL)
	{
		printf("File \'%s' does not exist.\n\n", filename);
		fclose(fp_importfile);
		return 0;
	}
	else
	{
		fscanf(fp_importfile, "%d", size);
		for(i = 0; i < *size; i++)
		{
        	fscanf(fp_importfile, "%lf %lf", &points[i].x, &points[i].y);
   		}
   		fclose(fp_importfile);
   		return 1;
	}
}

void Export(Stack S, String30 filename, int size)
{
	FILE *fp_exportfile;
	int i;
	
	fp_exportfile = fopen(filename, "w");
	fprintf(fp_exportfile, "%d\n", (S.top)+1);
	for(i = 0; i <= S.top; i++)
	{
		fprintf(fp_exportfile, "%lf	%lf\n", S.array[i].x, S.array[i].y);
	}
	fclose(fp_exportfile);
	printf("Output saved in %s successfully.\n", filename);
}

int main()
{
	Point points[LIMIT];
	int size;
	String30 input_filename, output_filename;
	Stack S;
	
	printf("Enter Input Filename (including extension): ");
	scanf("%s", input_filename);
	printf("Enter Output Filename (including extension): ");
	scanf("%s", output_filename);
	
	if(Import(points, input_filename, &size) == 1)
	{
		Create(&S);
		if (grahamScan(points, &S, size) == 1)
		{
			printstack(S, size);
			Export(S, output_filename, size);
		}
		else
			printf("Scan Unsuccessful\n");	
	}
	return 0;
}