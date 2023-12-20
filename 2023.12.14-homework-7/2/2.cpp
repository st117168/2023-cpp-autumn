#include <string>
#include <fstream>

bool isLetter(char);
int countOfWords(std::string);
std::string findWord(std::string, int);
char lowerCase(char);
std::string lowerWord(std::string);
std::string AllWordsString();
int amtWord(std::string, std::string);
std::string mostCommonWord(std::string);
int StrLen(std::string);
bool isPalindrome(std::string);

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

//Write in "out.txt"
    FILE* f = fopen("out.txt", "w");
    fprintf(f, "Cамое часто встречающееся слово: %s\n\n", mostCommonWord(AllWordsString()).c_str());
    fprintf(f, "isPalindrome(\"Level\"): %d\nisPalindrome(\"banana\"): %d\n", isPalindrome("Level"), isPalindrome("banana"));
    fclose(f);

    return 0;
}

bool isLetter(char c)
{
	return (c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-';
}

int countOfWords(std::string str)
{
    int i = 0;
    int sum = 0;
    while(str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            sum++;
        }
        i++;
    }
    return sum;
}

std::string findWord(std::string str, int i)
{
    if (i < 1)
    {
        return "";
    }
    std::string word = "";
    int j = 0;
    while (i--)
    {
        word = "";
        while (str[j] != ' ')
        {
            word += str[j++];
        }
        j++;
    }
    return word;
}

char lowerCase(char c)
{
    if ((c >= 'А' && c <= 'Я') || (c >= 'A' && c <= 'Z'))
    {
        return c + 32;
    }
    return c;
}

std::string lowerWord(std::string word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        word[i] = lowerCase(word[i]);
        i++;
    }
    return word;
}

std::string AllWordsString()
{
    std::ifstream fin("in.txt");
    std::string s = "";
    while (!fin.eof())
    {
        char a = fin.get();
        if (isLetter(a))
        {
            s += lowerCase(a);
        }
        if (a == '\n' || a == ' ')
        {
            s += ' ';
        }
    }
    fin.close();
    return s;
}

int amtWord(std::string text, std::string word)
{
    int sum = 0;
    for (int i = 1; i <= countOfWords(text); ++i)
    {
        sum += lowerWord(word) == findWord(text, i);
    }
    return sum;
}

std::string mostCommonWord(std::string text)
{
    std::string mcWord = "";
    int sum = 0;
    for (int i = 1; i <= countOfWords(text); ++i)
    {
        std::string word = findWord(text, i);
        int amtW = amtWord(text, word);
        if (amtW > sum)
        {
            mcWord = word;
            sum = amtW;
        }
    }
    return mcWord;
}

int StrLen(std::string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

bool isPalindrome(std::string str)
{
    int len = StrLen(str);
    for (int i = 0; i <= len / 2; ++i)
    {
        if (lowerCase(str[i]) != lowerCase(str[len - i - 1]))
        {
            return 0;
        }
    }
    return 1;
}
