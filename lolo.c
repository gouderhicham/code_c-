#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>
#include "types.h"
#define MAX_N 100

int main()
{
    int N;
    int cube[MAX_N][MAX_N];
    int num_count[MAX_N * MAX_N + 1] = {0}; 
    int x, y;

   
    printf("Enter matrix size N: ");
    scanf("%d", &N);

  
    for (x = 0; x < N; x++)
    {
        for (y = 0; y < N; y++)
        {
            int num;
            do
            {
                
                printf("Enter number for row %d, column %d: ", x + 1, y + 1);
                scanf("%d", &num);

               
                if (num < 1 || num > N * N)
                {
                    printf("Invalid number! Please enter a number from 1 to %d.\n", N * N);
                }
                
                else if (num_count[num] > 0)
                {
                    printf("Number %d has already been entered! Please enter another number.\n", num);
                }
                else
                {
                    
                    cube[x][y] = num;
                    num_count[num]++;
                    break;
                }
            } while (1); 
        }
    }
    bool status = true;
    int sum = 0;
    for (char i = 0; i < N; i++)
    {
        sum += cube[i][i];
    };
    int rightDiag = 0, leftDiag = 0;
    for (char i = 0; i < N; i++)
    {

        int row = 0;
        int collumn = 0;
        for (char j = 0; j < N; j++)
        {
            row += cube[i][j];
            collumn += cube[j][i];
        };
        rightDiag += cube[i][i];
        leftDiag += cube[N - i - 1][N - i - 1];
        if (row != sum || collumn != sum)
        {
            status = false;
            printf("no magic sqaure");
            exit(1);
        }
    };
    if (leftDiag != sum || rightDiag != sum)
    {
        status = false;
        printf("no magic sqaure");
        exit(1);
    };
    printf("magic sqaure exists !");
    return 0;
};

// NOTE: Evaluate a postfix expression using a stack.
// Convert an infix expression to a postfix expression using a stack.
// Implement a stack with push, pop, and find - min operations, all with O(1) time complexity.
// Implement a stack that can perform push, pop, and get the minimum element in O(1) time complexity.
// Given a stack of integers, sort the stack using an auxiliary stack.
// Given a stack, reverse the elements of the stack using only stack operations.
// Implement a queue using two stacks.
