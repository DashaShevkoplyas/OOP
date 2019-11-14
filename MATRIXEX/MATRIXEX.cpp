#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cstdio>


using namespace std;
class ArrayHandler {
public:
	ArrayHandler(int** matr, int elem, int width) {
		MATRIX = matr;
		ELEM = elem;
		WIDTH = width;
	}

	virtual int getMatrix() {
		cout << "New matrix created! " << endl;
		return 0;
	}
	virtual int printMatrix() {
		cout << "Printed!" << endl;
		return 0;
	}
	virtual int findELEM() {
		cout << "ELEM FOUNDED!" << endl;
		return 0;
	}
	virtual int multiply() {
		cout << "MULTIPLY!" << endl;
		return 0;
	}
protected:
	int** MATRIX;
	int ELEM;
	int WIDTH;

};



class Matrix : public ArrayHandler {
public:
	Matrix(int** matr = 0, int elem = 0, int width = 0) :ArrayHandler(matr, elem, width) {}
	int getMatrix() {
		int i, j;
		srand(time(NULL));

		for (i = 0; i < ELEM; i++) {
			MATRIX[i] = new int[WIDTH];
			for (j = 0; j < WIDTH; j++) {
				MATRIX[i][j] = rand() % 1000;
			}
		}
		return **MATRIX;
	}
	int printMatrix() {
		int i, j;
		for (i = 0; i < ELEM; i++) {
			for (j = 0; j < WIDTH; j++) {
				cout << MATRIX[i][j] << "\t";
			}cout << endl;
		}
		cout << "MATRIX " << endl;
		return **MATRIX;
	}


	int findELEM() {
		int i, j, b1, k;
		for (j = 1; j < ELEM; j++) {
			for (i = 1; i < ELEM; i++) {
				if (i != j) {
					b1 = MATRIX[i][j] / MATRIX[j][j];
					for (k = 1; k < ELEM < +1; k++) {
						MATRIX[i][k] = MATRIX[i][k] - b1 * MATRIX[j][k];
					}
				}
			}
		}
		int* x = new int[ELEM];
		cout << "\nThe solution is:\n";
		for (i = 1; i <= ELEM; i++) {
			x[i] = MATRIX[i][ELEM + 1] / MATRIX[i][i];
			cout << "x" << i << "=" << x[i] << " ";
		}
		return *x;
	}
	int multiply() {
		int i, j, k;
		int **mat3 = new int*[ELEM];

		for (i = 0; i < ELEM; i++) {
			mat3[i] = new int[WIDTH];
			for (j = 0; j < WIDTH; j++) {
				mat3[i][j] = 0;
				for (k = 0; k < ELEM; k++) {
					mat3[i][j] += MATRIX[i][k] * MATRIX[k][i];
					cout << mat3[i][j] << "\t";
				}cout << endl;
			}
		}
		return **mat3;
	}

};




int main()
{
	const unsigned arrSize = 100;
	const unsigned matrixSize = 3, matrixSize2 = 4;
	static int **matr_1 = new int*[matrixSize], **matr_2 = new int*[matrixSize2], **matr_3 = new int*[matrixSize];

	ArrayHandler* handleARR;

	Matrix m1(matr_1, matrixSize, matrixSize2);
	Matrix m2(matr_2, matrixSize2, matrixSize);
	Matrix m3(matr_3, matrixSize, matrixSize);




	handleARR = &m1;
	handleARR->getMatrix();
	handleARR->printMatrix();
	handleARR->getMatrix();
	handleARR->printMatrix();
	handleARR->multiply();

	handleARR = &m3;
	handleARR->getMatrix();
	handleARR->printMatrix();
	handleARR->findELEM();



















	return 0;
}
