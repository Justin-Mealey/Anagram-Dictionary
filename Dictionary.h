#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

class Dictionary
{
public:
    Dictionary();
    ~Dictionary();
    void insert(std::string word);
    void lookup(std::string letters, void callback(std::string)) const;
private:
    int m_buckets;
    std::vector<std::string>* hashArray;

    size_t hashfunction(std::string sortedWord) const;
};

#endif