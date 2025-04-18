//#include <iostream>
//#include <cmath>
//using namespace std;
//int main() {
//	const int n = 20;
//	int max = 0, max_index = 0;
//	float r[n] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//	float x[n] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//	float y[n] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//	for (int i =0; i < n; i++) {
//		int counter = 0;
//		for (int j = 0; j < n; j++) {
//			float dist = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
//			int cum_r = r[i] + r[j];
//			if (dist < cum_r) {
//				counter = counter + 1;
//			}
//			}
//		if (counter > max) {
//			max = counter;
//			max_index = i + 1;
//		}
//		}
//	cout << "The circle overlapping with the most is " << max_index+1 << " with " << max - 1 << " overlaps";
//	return 0;
//	}