// Write your WordGuesser member function implementations here.
#include "WordGuesser.h"


WordGuesser::WordGuesser(vector<string> d, int l, int g){
    if(l < 1 || g < 0){
        throw "length of word cannot be less than one and guesses must be greater than -1";
    }
    dictionary = d;
    length = l;
    guesses = g;
    words = new set<string>();
    for(int i = 0; i < length; i++){
        pattern += "-";
    }
    for(int i = 0; i < d.size(); i++){
        words->insert(d[i]);
    }
}
set<std::string>* WordGuesser::getWords(){
    return words;
}
int WordGuesser::getGuessesLeft(){
    return guesses;
}
set<char> WordGuesser::getGuesses(){
    return characters;
}
std::string WordGuesser::getPattern(){
    return pattern;
}
void WordGuesser::createMap(map<string, string>& m, int& count, char guess, int& x){
    cout << "working 2" << endl;
    for(string s : *words){
        for(char c : s){
            count++;
            if(c == guess){
                x = count;
            }
        }
        string key = guess + to_string(x);
        auto it = m.find(key);
        if(it == m.end()){
            m[key] = " " + s;
        }else {
            m[key] += " " + s;
        }
        x = 0;
        count = 0;
    }
}
void WordGuesser::newSet(map<string, string> m, int& count, int& x, int& total, char guess){
    cout << "working 3" << endl;
    for(auto element : m){
        for(char c : element.second){
            if(c == ' '){
                count++;
            }
        }
        if(count > total){
            total = count;
            delete words;
            words = new set<string>();
            istringstream ss(element.second);
            string word;
            while(ss >> word){
                x = 0;
                for(char c : word){
                    if(c == guess){
                        x++;
                    }
                }
                words->insert(word);
            }
        }
        count = 0;
    }
}
void WordGuesser::changePattern(char guess){
    
    int index;
    vector<int> v;
    for(string s : *words){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == guess){
                cout << i << endl;
                v.push_back(i);
            }
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << "i " << i << endl;
        cout << v[i] << endl;
        pattern[v[i]] = guess;
    }
    
    
}
bool WordGuesser::checkCharacters(char guess){
    auto it = characters.find(guess);
    if(it == characters.end()){
        characters.insert(guess);
        return true;
    } else {
        return false;
    }
}
int WordGuesser::record(char guess){
    int x = 0;
    int count = 0;
    int total = 0;
    string originalPattern = pattern;
    map<string, string> m;
    if(checkCharacters(guess)){
        cout << "working 1" << endl;
        createMap(m, count, guess, x);
        newSet(m, count, x, total, guess);
        changePattern(guess);
        if(pattern == originalPattern){
            guesses--;
        }
    } else{
        throw "Character already guessed please try again";
    }
    return x;
}