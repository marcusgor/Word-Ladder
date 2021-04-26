//
//Created by: Marcus Gerard Riccio 5/05/19
//Project 5a, 4-word word ladder
//wordladder.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include "WordLadder.hpp"

using namespace std;


WordLadder::WordLadder()
{
    vector<string> wordall;
    vector<string> words;
    queue<string> wordpartial;
}
/**
@post reads lexicon words from the input file and stores them for
 later use
 **/

void WordLadder::readLexicon(string input_file)
{
    ifstream word_file;
    string word;
    word_file.open(input_file);

        while (getline(word_file, word))
            {
        wordall.push_back(word);
            }

    word_file.close();
    
}

/**
@param start_word is the first word in the ladder
@param end_word is the last word in the ladder
@return a vector containing words s.t. the first word is start_word,
 the last word is end_word, and all words in between differ by
 only one character from the preceding and following words, in
 the shortest such transformation found in the current lexicon.
 If no transformation is found between start_word and end_word,
 returns an empty vector.
 **/

vector<string> WordLadder::findShortestLadder(string start_word, string end_word)
{

    if (start_word.length() != end_word.length() || start_word.length() == 0)
        {
        return {};
        }


    if (!(binary_search(wordall.begin(), wordall.end(), start_word)))
        {
        return words;       //empty case, start
        }
    if (!(binary_search(wordall.begin(), wordall.end(), end_word)))
        {
        return words;      //empty case, end
        }

    wordpartial.push(start_word);       //add first word to queue
    words.push_back(start_word);        //adds 1st into the ladder
    while (!wordpartial.empty()) //as queue is filled
        {
        wordpartial.pop();                  //dequeues 1st word

            if (words.back() == end_word)    //if word is equal to end word
                {
            return words;   //return word
                }
    

        for (int i = 0; i < wordall.size(); i++)                //loops through all words stored in wordall
            {
            for (int j = 0; j < 4; j++)                          //loops through up to four-char word length 
                {
                int difference = 0;     //set difference var

                if (wordall[i][j] != words.back()[j])            //checks if individual characters are different from word
                    {
                    difference++;                               //iteration if difference is found
                    }

                if (difference == 1) 
                    {

                    if(!(binary_search(words.begin(), words.end(), wordall[i])))   //if the word is not in the ladder
                        {
                        words.push_back(wordall[i]);        //adds word into wordall
                        wordpartial.push(wordall[i]);          //adds word queue
                        }
                    }
                }
            }
        }

} //end WordLadder.cpp