//#include <iostream>
//using namespace std;
//
//
//        int countMostlyWhite(int data[][1000], int m, int n, int k) {
//        int count = 0;
//        int threshold = (k * k) / 2; // At least k^2 / 2 white pixels needed
//
//        // Iterate through all possible top-left corners of k x k sub-matrices
//            for (int i = 0; i <= m - k; ++i) {
//                for (int j = 0; j <= n - k; ++j) {
//                    // Count the number of white pixels (1s) in the k x k block
//                    int whitePixels = 0;
//                    for (int p = i; p < i + k; ++p) {
//                        for (int q = j; q < j + k; ++q) {
//                            whitePixels += data[p][q];
//                        }
//                    }
//
//                    // If the white pixel count meets the threshold, it's a mostly white block
//                    if (whitePixels >= threshold) {
//                        ++count;
//                    }
//                }
//            }
//        return count;
//    }
//
//    // Example usage
//    int main() {
//        int m = 5, n = 4,k;
//        cout << "Enter block size";
//        do {
//            cin >> k;
//            if (k > 4) {
//                cout << "Enter value one smaller than matriz coulumn and row";
//            }
//        } while (k > 4);
//        int data[5][1000] = {
//            {0, 0, 1, 0},
//            {0, 1, 0, 1},
//            {0, 0, 0, 1},
//            {1, 0, 1, 0},
//            {0, 1, 1, 1}
//        };
//
//        cout << "Number of mostly white blocks: " << countMostlyWhite(data, m, n, k) << endl;
//
//        return 0;
//    }
