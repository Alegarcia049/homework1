#include <iostream>
#include <chrono>
using namespace std;


int main(){
    auto startTime = chrono::high_resolution_clock::now(); 
    bool equal = compare_words(word1, word2); 
    auto endTime = chrono::high_resolution_clock::now(); 
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    cout << "Result of comparison is... " << (equal?"word are equal":"words are different") << endl;
    cout  <<  "compare_words()  tomó: "   <<  elapsedTime.count()  <<  " nanosegundos cuando se proceso en el compilador" << endl;
}