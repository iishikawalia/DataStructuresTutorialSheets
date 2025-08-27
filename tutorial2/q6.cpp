#include <iostream>
using namespace std;

#define MAX 100

//printing a triplet matrix
void printTriplet(int T[MAX][3], int count) {
    for (int i = 0; i <= count; i++) {
        cout << T[i][0] << " " << T[i][1] << " " << T[i][2] << endl;
    }
}

//converting normal matrix to triplet
int createTriplet(int mat[MAX][MAX], int rows, int cols, int T[MAX][3]) {
    int k = 1, count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                T[k][0] = i;
                T[k][1] = j;
                T[k][2] = mat[i][j];
                k++;
                count++;
            }
        }
    }
    T[0][0] = rows;
    T[0][1] = cols;
    T[0][2] = count;
    return count;
}

// (a) taking Transpose of triplet
void transposeTriplet(int T[MAX][3], int res[MAX][3]) {
    int rows = T[0][0], cols = T[0][1], count = T[0][2];
    res[0][0] = cols;
    res[0][1] = rows;
    res[0][2] = count;

    int k = 1;
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= count; i++) {
            if (T[i][1] == c) {
                res[k][0] = T[i][1];
                res[k][1] = T[i][0];
                res[k][2] = T[i][2];
                k++;
            }
        }
    }
}

// (b) Addition of two triplet matrices
void addTriplets(int A[MAX][3], int B[MAX][3], int res[MAX][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible (different dimensions)\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            res[k][0] = A[i][0];
            res[k][1] = A[i][1];
            res[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        } else if (A[i][0] < B[j][0] || 
                  (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            res[k][0] = A[i][0];
            res[k][1] = A[i][1];
            res[k][2] = A[i][2];
            i++; k++;
        } else {
            res[k][0] = B[j][0];
            res[k][1] = B[j][1];
            res[k][2] = B[j][2];
            j++; k++;
        }
    }
    while (i <= A[0][2]) {
        res[k][0] = A[i][0];
        res[k][1] = A[i][1];
        res[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        res[k][0] = B[j][0];
        res[k][1] = B[j][1];
        res[k][2] = B[j][2];
        j++; k++;
    }

    res[0][0] = A[0][0];
    res[0][1] = A[0][1];
    res[0][2] = k - 1;
}

// (c) Multiplication of two triplet matrices
void multiplyTriplets(int A[MAX][3], int B[MAX][3], int res[MAX][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Multiplication not possible (dimension mismatch)\n";
        return;
    }

    int temp[MAX][MAX] = {0}; // temporary normal matrix

    // Multiply using triplet definition
    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B[0][2]; j++) {
            if (A[i][1] == B[j][0]) {
                temp[A[i][0]][B[j][1]] += A[i][2] * B[j][2];
            }
        }
    }

    // Convert back to triplet
    int count = 0, k = 1;
    for (int i = 0; i < A[0][0]; i++) {
        for (int j = 0; j < B[0][1]; j++) {
            if (temp[i][j] != 0) {
                res[k][0] = i;
                res[k][1] = j;
                res[k][2] = temp[i][j];
                k++; count++;
            }
        }
    }
    res[0][0] = A[0][0];
    res[0][1] = B[0][1];
    res[0][2] = count;
}

// ---------------- MAIN ----------------
int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int T1[MAX][3], T2[MAX][3];
    int trans[MAX][3], add[MAX][3], mul[MAX][3];

    cout << "Enter rows and cols of Matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            cin >> A[i][j];

    cout << "Enter rows and cols of Matrix B: ";
    cin >> rowsB >> colsB;
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            cin >> B[i][j];

    int countA = createTriplet(A, rowsA, colsA, T1);
    int countB = createTriplet(B, rowsB, colsB, T2);

    cout << "\nTriplet of A:\n"; printTriplet(T1, countA);
    cout << "\nTriplet of B:\n"; printTriplet(T2, countB);

    // (a) Transpose of A
    transposeTriplet(T1, trans);
    cout << "\nTranspose of A:\n"; printTriplet(trans, countA);

    // (b) Addition A + B
    addTriplets(T1, T2, add);
    cout << "\nAddition (A + B):\n"; printTriplet(add, add[0][2]);

    // (c) Multiplication A * B
    multiplyTriplets(T1, T2, mul);
    cout << "\nMultiplication (A * B):\n"; printTriplet(mul, mul[0][2]);

    return 0;
}
