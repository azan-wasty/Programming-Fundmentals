//#include <iostream>
//using namespace std;
//void shiftrows(int matrix[][5], int rows) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < 5; j++) {
//			matrix[i][j] = (i + 1) * matrix[i][j];
//		}
//	}
//}
//void printmatrix(char matrix[][5], int rows) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < 5; j++) {
//			cout << matrix[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//int main() {
//	const int rows = 3;
//	int matrix[rows][5] = {{3, 7, 2, 9, 5},{8, 4, 6, 1, 0},{5, 2, 8, 3, 7}};
//	cout << "original matrix:" << endl;
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < 5; j++) {
//			cout << matrix[i][j] << " ";
//		}
//		cout << endl;
//	}
//		shiftrows(matrix, rows);
//		cout << "updated matrix:" << endl;
//		for (int i = 0; i < rows; i++) {
//			for (int j = 0; j < 5; j++) {
//				cout << matrix[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return 0;
//	}