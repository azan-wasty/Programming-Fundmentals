//#include <iostream>
//#include <cstring>
//using namespace std;
//void removeNonAlphabets(char sentence[]) {
//    int index = 0;
//    int length = strlen(sentence);
//
//    for (int i = 0; i < length; i++) {
//        // Check if the character is an alphabet (A-Z or a-z), space, or full stop.
//        if ((sentence[i] >= 'A' && sentence[i] <= 'Z') ||
//            (sentence[i] >= 'a' && sentence[i] <= 'z') ||
//            sentence[i] == ' ' || sentence[i] == '.') {
//            // Move valid characters to the current index position.
//            sentence[index++] = sentence[i];
//        }
//    }
//
//    // Null-terminate the modified string.
//    sentence[index] = '\0';
//}
//
//int main() {
//    char sentence[100];
//
//    cout << "Enter a sentence: ";
//    cin.getline(sentence, 100);
//
//    removeNonAlphabets(sentence);
//
//    cout << "Processed sentence: " << sentence << std::endl;
//
//    return 0;
//}
