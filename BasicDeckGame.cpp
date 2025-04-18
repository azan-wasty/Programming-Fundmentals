//#include <iostream>
//using namespace std;
//int main() {
//	int deck[52] = { 0,1,2,3,4,5,6,0,8,9,10,10,10,0,1,2,3,4,5,6,0,8,9,10,10,10,1,2,3,4,5,6,0,8,9,10,10,10,0,1,2,3,4,5,6,0,8,9,10,10,10 };
//	int index = 0;
//	int p1[5], p2[5], p3[5], p4[5];
//	for (int i = 0; index <= 20; i++) {
//		p1[i] = deck[index];
//		index++;
//		p2[i] = deck[index];
//		index++;
//		p3[i] = deck[index];
//		index++;
//		p4[i] = deck[index];
//		index++;
//	}
//	int open = deck[index]; index++;
//	int pl = 1;
//	while (index < 52) {
//
//		if (pl == 1) {
//			int max = p1[0], max_index = 0;
//			for (int j = 1; j <= 4; j++) {
//				if (max > p1[j]) {
//					max = p1[j];
//					max_index = j;
//				}
//			}
//			if (open < max) {
//				swap(open, p1[max_index]);
//			}
//			else {
//				open = deck[index]; index++;
//				if (open < max) {
//					swap(open, p1[max_index]);
//				}
//			}
//			pl = 2;
//		}
//		else if (pl == 2) {
//			int max = p2[0], max_index = 0;
//			for (int j = 1; j <= 4; j++) {
//				if (max > p2[j]) {
//					max = p2[j];
//					max_index = j;
//				}
//			}
//			if (open < max) {
//				swap(open, p2[max_index]);
//			}
//			else {
//				open = deck[index]; index++;
//				if (open < max) {
//					swap(open, p2[max_index]);
//				}
//			}
//			pl = 3;
//		}
//		else if (pl == 3) {
//			int max = p3[0], max_index = 0;
//			for (int j = 1; j <= 4; j++) {
//				if (max > p3[j]) {
//					max = p3[j];
//					max_index = j;
//				}
//			}
//			if (open < max) {
//				swap(open, p3[max_index]);
//			}
//			else {
//				open = deck[index]; index++;
//				if (open < max) {
//					swap(open, p3[max_index]);
//				}
//			}
//			pl = 4;
//		}
//		else {
//			int max = p4[0], max_index = 0;
//			for (int j = 1; j <= 4; j++) {
//				if (max > p4[j]) {
//					max = p4[j];
//					max_index = j;
//				}
//			}
//			if (open < max) {
//				swap(open, p4[max_index]);
//			}
//			else {
//				open = deck[index]; index++;
//				if (open < max) {
//					swap(open, p4[max_index]);
//				}
//			}
//			pl = 1;
//		}
//	}
//	for (int k = 0; k <= 4; k++) {
//		cout << p1[k] << " ";
//	}
//	cout << endl;
//	for (int k = 0; k <= 4; k++) {
//		cout << p2[k] << " ";
//	}
//	cout << endl;
//	for (int k = 0; k <= 4; k++) {
//		cout << p3[k] << " ";
//	}
//	cout << endl;
//	for (int k = 0; k <= 4; k++) {
//		cout << p4[k] << " ";
//	}
//	cout << endl;
//	return 0;
//}