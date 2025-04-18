//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//const int max_name_length = 50;      // maximum length for names
//const int max_assignments = 10;      // maximum number of assignments
//
//int main() {
//	// create and write to input1.txt
//	ofstream outputfile("input1.txt");
//	outputfile << "3 ali ahmad khan 3 2.4 3.3 7.1 l12-2000 "
//		"kiran ali panday 2 7.0 6 l12-3000 "
//		"imran javed khan 1 2.2 l12-3001";
//	outputfile.close();  // close the output file after writing
//
//	// read from input1.txt
//	ifstream inputfile("input1.txt");
//
//	if (!inputfile) {
//		cerr << "error opening file: input1.txt" << endl;
//		return 1;
//	}
//
//	int numberofstudents;
//	inputfile >> numberofstudents;  // read the number of students
//
//	// arrays to hold student data
//	char firstname[max_name_length];
//	char middlename[max_name_length];
//	char lastname[max_name_length];
//	char rollnumber[max_name_length];
//	float marks[max_assignments];
//
//	for (int i = 0; i < numberofstudents; ++i) {
//		// read names
//		inputfile >> firstname >> middlename >> lastname;
//
//		// read number of assignments
//		int numassignments;
//		inputfile >> numassignments;
//
//		// ensure we do not exceed the maximum assignments
//		if (numassignments > max_assignments) {
//			cerr << "error: number of assignments exceeds maximum allowed." << endl;
//			return 1;
//		}
//
//		// read marks and calculate total marks
//		float totalmarks = 0.0f;
//		for (int j = 0; j < numassignments; ++j) {
//			inputfile >> marks[j];
//			totalmarks += marks[j];  // calculate total marks
//		}
//
//		// read roll number
//		inputfile >> rollnumber;
//
//		
//		cout << rollnumber << " " << lastname << " " << (int)(totalmarks * 10 + 0.5) / 10.0 << endl;
//	}
//
//	inputfile.close();
//	system("pause");
//	return 0;
//}