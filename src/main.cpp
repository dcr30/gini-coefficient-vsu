#include "main.h"

int main()
{
    // Файл с текстом
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cout << "Unable to open file";
        std::cin.get();
        return EXIT_FAILURE;
    }
    // Слова и их количество в тексте
    std::vector<TextWord*> textWords;
    // Чтение текста из файла
    std::string currentLine;
    while (std::getline(inputFile, currentLine))
    {
        // Разбиение строки на слова
        std::istringstream iss(currentLine);
        do
        {
            std::string word;
            iss >> word;

            if (word.length() > 0)
            {
                bool isInserted = false;
                for (auto const& textWord : textWords) {
                    if (textWord->word == word)
                    {
                        textWord->count++;
                        isInserted = true;
                    }
                }
                if (!isInserted)
                {
                    textWords.push_back(new TextWord(word));
                }
            }
        } while (iss);
    }
    inputFile.close();
    // Сортировка слов по их количеству в тексте
    std::sort(textWords.begin(), textWords.end(), TextWord::Comparator);

    // Вывод отсортированных слов
    std::cout << "Words sorted by count:" << std::endl;
    for (auto const& textWord : textWords)
    {
        std::cout << textWord->word << " " << textWord->count << std::endl;
    }
    std::cout << std::endl;

    // Алгоритм нахождения коэффициента Джини
    double sbt = 0.5 * textWords.size() * textWords.back()->count;
    double st = 0;
    for (std::size_t i = 0; i < textWords.size(); i++)
    {
        unsigned int cp = 0;
        if (i > 0)
        {
            cp = textWords[i - 1]->count;
        }
        st += 0.5 * (cp + textWords[i]->count);
    }

    double ratioJ = (sbt - st) / sbt;

    std::cout << "J = " << ratioJ << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}
