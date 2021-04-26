//
//Created by: Marcus Gerard Riccio 5/05/19
//4-word word ladder
//wordladder.hpp

#ifndef WORDLADDER_
#define WORDLADDER_


#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class WordLadder
{
    public:
        WordLadder();
        void readLexicon(string input_file);
        vector<string> findShortestLadder(string start_word, string end_word);
    
    private:
        vector<string> wordall;      //vector containing ALL words in file
        vector<string> words;        //intializes a vector that has all words in a word ladder
        queue<string> wordpartial;      //queue that contains bit of the current word
};

//#include "WordLadder.cpp"
#endif