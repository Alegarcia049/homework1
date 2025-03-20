#include <iostream>
#include <chrono>

using namespace std;


int main(){
    const char * word_1 = (char *) word1;
    const char * word_2 = (char *) word2;
    auto startTime = std::chrono::high_resolution_clock::now(); 
    auto equal = compare_words(word_1, word_2);
    auto endTime = chrono::high_resolution_clock::now(); 
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "Result of comparison is... " << (equal?"word are equal":"words are different") << endl;
    cout  <<  "compare_words()  tomó: "   <<  elapsedTime.count()  <<  " nanosegundos cuando se proceso en runtime" << endl;
}