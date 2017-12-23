#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int chained(int n);
void printf_order(int i, int j);
int p[7][7];
FILE* fp;
int pos[MAX];

void main()
{
	int A, m, i;
	int buf[8];
	char name[30];


	FILE *fd;
	printf("input file name? ");
	scanf_s("%s", name, sizeof(name));

	fopen_s(&fd, name, "r");
	fscanf_s(fd, "%d", &m);

	for (i = 0; i <= m - 1; i++)
	{
		fscanf_s(fd, "%d", &pos[i]);
	}


	fopen_s(&fp, "output.txt", "w");
	A = chained(m - 1);
	printf_order(1, m - 1);

	fclose(fp);
}

int chained(int n)
{
	int M[MAX][MAX];
	int i, j, k;
	int diagonal;
	int a;

	for (i = 1; i <= n; i++)
		M[i][i] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++)
		{
			j = i + diagonal;
			M[i][j] = 99999;

			for (k = i; k <= j - 1; k++)
			{
				a = M[i][k] + M[k + 1][j] + (pos[i - 1] * pos[k] * pos[j]);

				if (a < M[i][j])
				{
					M[i][j] = a;
					p[i][j] = k;
				}
			}
		}
	return M[1][n];

}

void printf_order(int i, int j)
{
	int k;
	if (i == j)
		fprintf(fp, " %d ", i);
	else
	{
		k = p[i][j];
		fprintf(fp, "(");
		printf_order(i, k);
		printf_order(k + 1, j);
		fprintf(fp, ")");
	}
}
