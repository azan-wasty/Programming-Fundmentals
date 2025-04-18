//#include <iostream>
//#include<fstream>
//#include <string>
//
//using namespace std;
//int main() {
//	string data = { "this is a messaege" };
//	string arr = { 0 };
//		
//	ofstream fout("input.txt");
//	fout << data;
//	fout.close();
//	int r;
//	cout << "do you wwant to encrypt or decrypt?(0 and 1 respectively)";
//	cin >> r;
//	if (r == 1) {
//		
//		string data1 ;
//		ifstream fin("input.txt");
//		getline(fin, data1);
//		fin.close();
//		for (int i = 0; data[i] != 0; i++){
//			data1[i] = data1[i] + 1;
//		}
//		ofstream fout("encrypted.txt");
//		fout << data1;
//		fout.close();
//	}
//	if (r == 0) {
//
//		string data2;
//		ifstream fin("encrypted.txt");
//		getline(fin, data2);
//		fin.close();
//		for (int i = 0; data[i] != 0; i++) {
//			data2[i] = data2[i] - 1;
//		}
//		ofstream fout("decrypted.txt");
//		fout << data2;
//		fout.close();
//	}
//	return 0;
//}