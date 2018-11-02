#include "word.h"

#include <string>
#include <iostream>
using namespace std;

word::word(unsigned int initial_capacity){
    capacity = initial_capacity;
    used = 0;
    wordfile = new string[initial_capacity];
    bagfile = new bag[initial_capacity];
}

void word::add_word(string filesname, string word){
    if (wordfile[used]>wordfile[capacity])
    {
        cout << "exit";
    }
    unsigned int i = 0;
    for (i=0; i<used; i++)
    {
        if(wordfile[i] == word){
            bagfile[i].add(filesname);
        }
        else if(i>used)
        {
            bagfile->add(word);
            used++;
        }
}
}

int word::get_information(string word) const{
    for (int i=0; i<used; i++)
    {
        if (wordfile[i] == word) {
            cout << "Word: " << word << bagfile[i].size();
        }
        if (bagfile->size() == 1)
        {
            cout << "there is 1 file that contains" << word;
            bagfile[i].print();
        }
        else {
            cout << "there are" << bagfile->size() << "that contain" << word;
            bagfile[i].print();
            return 0;
        }
    }
    cout << "there is no file that contains " << word;
    return 0;
}
