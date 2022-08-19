/*
Zero Matrix

    algorithm:
        iterate through matrix and save the columns and rows with 0

        after the rows and columns are saved, 0 them out
*/

#include <iostream>

#define ROWS 3
#define COLS 3


void zeroOut(int (&matrix)[ROWS][COLS], bool flag, int index)
{
    int size = 0;

    (flag) ? size = ROWS : size = COLS; 

    for(int i = 0; i < size; i++)
    {
        (!flag) ? matrix[index][i] = 0 : matrix[i][index] = 0; 
    }
}

void zeroMatrix(int (&matrix)[ROWS][COLS])
{
    bool zeroRow[ROWS] = { 0 };
    bool zeroCol[COLS] = { 0 };

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(matrix[i][j] == 0)
            {
                zeroRow[i] = true;
                zeroCol[j] = true;
            }
        }
    }

    for(int i = 0; i < ROWS; i++)
    {
        if(zeroRow[i]) zeroOut(matrix, false, i);
    }

    for(int i = 0; i < COLS; i++)
    {
        if(zeroCol[i]) zeroOut(matrix, true, i);
    }
}


int main()
{
    int matrix[ROWS][COLS] = {{1,2,1},
                              {0,1,1},
                              {1,1,1}};

    zeroMatrix(matrix);

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}