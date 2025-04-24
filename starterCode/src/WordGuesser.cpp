// Write your WordGuesser member function implementations here.
#include "WordGuesser.h"


WordGuesser::WordGuesser(std::vector<std::string> d, int l, int g){
    if(l < 1 || g < 0){
        throw "length of word cannot be less than one and guesses must be greater than -1";
    }
    dictionary = d;
    length = l;
    guesses = g;
    for(int i = 0; i < length; i++){
        pattern += "-";
    }
}
set<std::string>* WordGuesser::getWords(){
    set<string>* a;
    return a;
}
int WordGuesser::getGuessesLeft(){
    return guesses;
}
set<char> WordGuesser::getGuesses(){
    set<char> b;
    return b;
}
std::string WordGuesser::getPattern(){
    return pattern;
}
int WordGuesser::record(char guess){
    return 0;
}