#include <stdio.h> 
void printMatrix(int matrix[5][5]); 
int abs(int number); 
int main() 
{ 
    int matrix[5][5]; 
    int counter = 0; 
    for (int i = 0; i < 5; i++) 
    { 
        for (int j = i; j >= 0; j--) 
        { 
            counter++; 
            matrix[j][abs(j - i)] = counter; 
        }; 
        printf("\n"); 
    }; 
    for (int i = 0; i < 5; i++) 
    { 
        for (int j = 4; j > i; j--) 
        { 
            counter++; 
            matrix[j][abs(4 - j + i + 1)] = counter; 
        }; 
        printf("\n"); 
    }; 
    printMatrix(matrix); 
    return 0; 
} 
int abs(int number) 
{ 
    if (number < 0) 
    { 
        return -number; 
    } 
    return number; 
} 
void printMatrix(int matrix[5][5]) 
{ 
    for (char i = 0; i < 5; i++) 
    { 
        for (char j = 0; j < 5; j++) 
        { 
            printf("%d ", matrix[i][j]); 
        }; 
        printf("\n"); 
    }; 
};

#include <stdio.h> 
void printMatrix(int matrix[5][5]); 
int abs(int number); 
int main() 
{ 
    int matrix[5][5] = {{1, 3, 6, 10, 15}, {2, 5, 9, 14, 19}, {4, 8, 13, 18, 22}, {7, 12, 17, 21, 24}, {11, 16, 20, 23, 25}}; 
    int i, j; 
    int counter = 0; 
    for (i = 0; i < 5; i++) 
    { 
        int x; 
        for (j = 0, x = 4; j < 5; j++, x--) 
        { 
            counter++; 
            int row = i % 2 == 0 ? j : x; 
            matrix[row][i] = counter; 
        }; 
    }; 
    printMatrix(matrix); 
    return 0; 
} 
int abs(int number) 
{ 
    if (number < 0) 
    { 
        return -number; 
    } 
    return number; 
} 
void printMatrix(int matrix[5][5]) 
{ 
    int i, j; 
    for (i = 0; i < 5; i++) 
    { 
        for (j = 0; j < 5; j++) 
        { 
            printf("%d ", matrix[i][j]); 
        }; 
        printf("\n"); 
    }; 
};
