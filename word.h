//Kelly Yeh

#ifndef WORD_H
#define WORD_H
#include "bag.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class word
{
public:
    word(unsigned int initial_capacity=0); //constructor
    void add_word(string filesname, string word);
    int get_information(string word) const;
private:
    unsigned int capacity;
    unsigned int used;
    string *wordfile;
    bag *bagfile;
};
#endif /* word_h */
