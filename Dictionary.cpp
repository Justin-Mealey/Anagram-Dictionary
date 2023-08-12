#include "Dictionary.h"
#include <algorithm> // for sort
#include <cctype>
using namespace std;

void removeNonLetters(string& s);

Dictionary::Dictionary() { 
    m_buckets = 50000; hashArray = new vector<string>[50000]; 
}
Dictionary::~Dictionary() {
    delete[] hashArray;
}
void Dictionary::insert(string word) {
    removeNonLetters(word);
    string temp = word;
    sort(temp.begin(), temp.end());
    hashArray[hashfunction(temp)].push_back(word);
}
void Dictionary::lookup(string letters, void callback(string)) const {
    if (callback == nullptr)
        return;

    removeNonLetters(letters);
    sort(letters.begin(), letters.end());
    vector<string> bucket = hashArray[hashfunction(letters)];
    for (int i = 0; i < bucket.size(); i++) {
        string temp = bucket[i];
        sort(temp.begin(), temp.end());
        if (temp == letters)
            callback(bucket[i]);
    }
}
size_t Dictionary::hashfunction(string sortedWord) const {
    hash<string> myS;
    return myS(sortedWord) % m_buckets;
}
void removeNonLetters(string& s) // H e !@ ll O  ->  hello
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop everything off from "to" to end.
}