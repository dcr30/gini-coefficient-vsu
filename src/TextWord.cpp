#include "TextWord.h"

TextWord::TextWord(std::string word, int count)
{
    this->word = word;
    this->count = count;
}

TextWord::TextWord(std::string word)
{
    this->word = word;
    this->count = 1;
}

int TextWord::Comparator(const TextWord* textWord1, const TextWord* textWord2)
{
    return textWord1->count < textWord2->count;
}
