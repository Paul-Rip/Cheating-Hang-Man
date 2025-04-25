// Write your WordGuesser class headers here.

// The code already in this file is a print operator implementation
// to help you test your code. You do not have to use it.



// print operator for a set of any type
// outputs all items in the set separated by spaces
#ifndef _WORD_GUESSER_H
#define _WORD_GUESSER_H

#include <set>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;


class WordGuesser {
    private:
    vector<string> dictionary;
    int length;
    int guesses;
    set<char> characters;
    set<string>* words;
    string pattern;
    void createMap(map<string, string>& m, int& count, char guess, int& x);
    void newSet(map<string, string> m, int& count, int& x, int& total, char guess);
    void changePattern(char guess);
    bool checkCharacters(char guess);
    public:

    WordGuesser(vector<string> d, int l, int g);
    set<string>* getWords();
    int getGuessesLeft();
    set<char> getGuesses();
    string getPattern();
    int record(char guess);
    
};
template <typename T>
ostream& operator<< (ostream& out, const set<T>& words) {
    for(const T& word : words) {
        out << (T)word << " "; 
    }
    return out;
}

#endif