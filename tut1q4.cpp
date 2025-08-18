#include <iostream>
using namespace std;
int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int size = sizeof(array) / sizeof(array[0]);
int matrix1[5][4]= {{2, 3, 4, 5}, {2, 3, 5, 4}, {1, 2, 1, 1},{8, 9, 0, 0},{0,0,0,0}};
int matrix2[4][6]= {{2, 1, 1, 5,1,8}, {2, 1, 1, 4,1,6}, {1, 2, 1, 1,1,0},{1, 1, 1, 1,1,9}};
int mulmatrix[5][6];
int mmr=5;
int mmc=6;
int row1=5, column2=6;
int c=4,column1=4,row2 = 4;
void DisplayMatrix1()
{
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            cout << matrix1[i][j]<<" ";
        }
        cout << endl;
    }
}
void DisplayMatrix2()
{
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            cout << matrix2[i][j]<<" ";
        }
        cout << endl;
    }
}
void DisplayArray()
{
    cout<<"[";
    for (int i = 0; i < size; i++)
    {
        cout << array[i]<<" ";
    }
    cout<<"]"<<endl;
}

// reversing of array
int RevArr[8];
void ReverseArray()
{
    for (int i = 0; i < size; i++)
    {
        RevArr[i] = array[size - 1 - i];
    }
}
void DisplayRevArray()
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << RevArr[i] << " ";
    }
    cout << "]"<<endl;
}

// multiplication
void MatrixMultiplication()
{
    for (int i=0; i < mmr; i++)
    {
        for (int j = 0; j < mmc; j++)
        {
            for(int k=0; k<c; k++){
                mulmatrix[i][j]+=matrix1[i][c]*matrix2[c][j];
            }
        }
    }
};
void DisplayMultiplicationResult()
{
    for (int i = 0; i < mmr; i++)
    {
        for (int j = 0; j < mmc; j++)
        {
            cout << mulmatrix[i][j]<<" ";
        }
        cout << endl;
    }
}

// transpose
int tmatrix[6][5];
void MatrixTranspose()
{
    for (int i = 0; i < mmc; i++)
    {
        for (int j = 0; j < mmr; j++)
        {
            tmatrix[i][j] = mulmatrix[j][i];
        }
    }
}
void DisplayT()
{
    for (int i = 0; i < mmc; i++)
    {
        for (int j = 0; j < mmr; j++)
        {
            cout << tmatrix[i][j] << " ";
        }
        cout << endl;
    }
}
// main function
int main()
{
    cout<<"Original Array:"<<endl;
    DisplayArray();
    cout << "Reversed Array:" << endl;
    ReverseArray();
    DisplayRevArray();
    cout << "matrix 1:" << endl;
    DisplayMatrix1();
    cout << "matrix 2:" << endl;
    DisplayMatrix2();
    cout << "Result of Matrix Multiplication:" << endl;
    MatrixMultiplication();
    DisplayMultiplicationResult();
    cout << "Transpose of resultant matrix: " << endl;
    MatrixTranspose();
    DisplayT();
}
