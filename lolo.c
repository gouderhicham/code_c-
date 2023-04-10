#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
int N;
int cube[MAX_N][MAX_N];
void display_matrix(int N, int cube[][MAX_N]);
void readInput(int num_count[], int cube[MAX_N][MAX_N]);
int main()
{
    int num_count[MAX_N * MAX_N + 1] = {0}; // keep track of the number count
    int x, y, i;

    // read input N
    printf("Enter matrix size N: ");
    scanf("%d", &N);

    // read matrix elements
    readInput(num_count, cube);
    int sum = 0;
    for (i = 0; i < N; i++)
    {
        sum += cube[i][i];
    };
    int rightDiag = 0, leftDiag = 0;
    for (i = 0; i < N; i++)
    {
        int j;
        int row = 0;
        int collumn = 0;
        for (j = 0; j < N; j++)
        {
            row += cube[i][j];
            collumn += cube[j][i];
        };
        rightDiag += cube[i][i];
        leftDiag += cube[N - i - 1][N - i - 1];
        if (row != sum || collumn != sum)
        {

            printf("no magic sqaure");
            exit(1);
        }
    };
    if (leftDiag != sum || rightDiag != sum)
    {
        printf("no magic sqaure");
        exit(1);
    };
    printf("magic sqaure exists !");
    return 0;
};
void display_matrix(int N, int cube[][MAX_N])
{
    int x, y;
    printf("\n");
    for (x = 0; x < N; x++)
    {
        int i, j;
        printf("| ");
        for (y = 0; y < N; y++)
        {
            printf("%d | ", cube[x][y]);
        }
        printf("\n");
        if (x < N - 1) // don't print horizontal line after last row
        {
            for (i = 0; i < N * 4 + 1; i++)
            {
                printf("-");
            }
            printf("\n");
        }
    }
}
void readInput(int num_count[], int cube[MAX_N][MAX_N])
{
    int y, x;
    for (x = 0; x < N; x++)
    {
        for (y = 0; y < N; y++)
        {
            int num;
            do
            {
                // read a number
                printf("Enter number for row %d, column %d: ", x + 1, y + 1);
                scanf("%d", &num);

                // check if the number is in the range [1 ... N^2]
                if (num < 1 || num > N * N)
                {
                    printf("Invalid number! Please enter a number from 1 to %d.\n", N * N);
                }
                else if (*(num_count + num) > 0)
                {
                    printf("Number %d has already been entered! Please enter another number.\n", num);
                }
                else
                {
                    // add the number to the matrix and increase the count
                    cube[x][y] = num;
                    num_count[num]++;
                    display_matrix(N, &cube[0]); // pass the matrix as a pointer to its first element
                    break;
                }
            } while (1); // repeat until a valid number is entered
        }
    }
}
