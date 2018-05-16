#ifndef TEXTWORD_H
#define TEXTWORD_H

#include <string>

class TextWord
{
public:
    unsigned int count;
    std::string word;

    TextWord(std::string word, int count);
    TextWord(std::string word);

    static int Comparator(const TextWord * textWord1, const TextWord * textWord2);
};

#endif
