#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int StrLen(char*);
void CountSize(char*, int&, int&);
void ReadLines(char*, char**, int);
char* StrCat(char*, char*);
bool isLetter(char);
bool isEnd(char);
int CountWords(char*);
void maxLenSentence(char**, int, char*);
int StrStr(char**, int, char*);
char* SubStr(char*, int, int);
int StrCmp(char*, char*);
char* StrMult(char*, int);

int main(int argc, char** argv)
{
	int w = 0;
	int h = 0;
	char filename[255] = "in.txt";
	CountSize(filename, h, w);
	char** lines = (char**)malloc(sizeof(char*) * h);
	for (int i = 0; i < h; ++i)
	{
		lines[i] = (char*)malloc(sizeof(char) * w);
	}
	ReadLines(filename, lines, w);

//Count of words in "in.txt"
    int sum = 0;
    for (int i = 0; i < h; ++i)
    {
        sum += CountWords(lines[i]);
    }

//Find max len sentence
    char maxLenS[500];
    maxLenSentence(lines, h, maxLenS);

//strlen()
    char a[255];
    char b[255];
    FILE* f = fopen("in.txt", "r");
    fscanf(f, "%s", &a);
    fscanf(f, "%s", &b);
    char* cat = StrCat(a, b);
    fclose(f);

//Write in out.txt
	f = fopen("out.txt", "w");
	fprintf(f, "Слов в тексте: %d\n", sum);
	fprintf(f, "Самое длинное предложение: %s\n\n", maxLenS);
	fprintf(f, "strcat(first two entries): %s\n", cat);
    char kin[] = "world";
    fprintf(f, "strstr(\"world\"): %d\n", StrStr(lines, h, kin));
    char* Substr = (lines[0] + 3);
    fprintf(f, "substr(1-ая строка, 4, 6): %s\n", SubStr(Substr, 4, 6));
    fprintf(f, "\nstrcmp(\"can\", \"can\"): %d\nstrcmp(\"b\", \"a\"): %d\nstrcmp(\"a\", \"b\"): %d\n\n", StrCmp("can", "can"), StrCmp("b", "a"), StrCmp("a", "b"));
    char mult[] = "pe";
    fprintf(f, "strmult(pe, 2): %s", StrMult(mult, 2));
    fclose(f);

// free data
	for (int i = 0; i < h; ++i)
	{
		free(lines[i]);
	}
	free(lines);
	return 0;
}

int StrLen(char* str)
{
	int res = 0;
	while (str[res++] != '\0');
	return res;
}

void CountSize(char* filename, int & lines, int & maxLine)
{
	FILE* file = fopen(filename, "r");

	int currentLen = 0;
	while (!feof(file))
	{
		char c = 0;
		fscanf(file, "%c", &c);
		if (c == '\n')
		{
			lines++;
			currentLen = 0;
		}
		else
		{
			currentLen++;
		}
		maxLine = (maxLine > currentLen ? maxLine : currentLen);
	}
	lines++;
	fclose(file);
}

void ReadLines(char* filename, char** lines, int maxlen)
{
	FILE* file = fopen(filename, "r");

	int ind = 0;
	while (!feof(file))
	{
		fgets(lines[ind], maxlen, file);
		ind++;
	}

	fclose(file);
}

char* StrCat(char* a, char* b)
{
    int n = StrLen(a) - 1;
    for (int i = 0; i < StrLen(b); ++i)
    {
        a[n + i] = b[i];
    }
    return a;
}

bool isLetter(char c)
{
	return (c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-';
}

bool isEnd(char c)
{
    return (c == '.' || c == '?' || c == '!');
}

int CountWords(char* a)
{
    int i = 0;
    int countWords = 0;
    while (a[i] != '\0')
    {
        if (!isLetter(a[i]))
        {
            i++;
        }
        else
        {
            i++;
            if (!isLetter(a[i]))
            {
                countWords++;
            }
        }
    }
    return countWords;
}

void maxLenSentence(char** lines, int h, char* b)
{
    char a[500];
    int j = 0;
    int k = 0;
    int cnt = 0;
    for (int i = 0; i < h; ++i)
    {
        while(j < StrLen(lines[i]) - 2)
        {
            while (!isEnd(lines[i][j]))
            {
                a[k++] = lines[i][j++];
            }
            a[k] = lines[i][j];
            if (cnt < k)
            {
                cnt = k;
                for (int l = 0; l < StrLen(a); ++l)
                {
                    b[l] = a[l];
                }
            }
            k = 0;
            j += 2;
        }
        j = 0;
    }
}

int StrStr(char** lines, int h, char* a)
{
    for (int i = 0; i < h; ++i)
    {
        int j = 0;
        while (j < StrLen(lines[i]) - 1)
        {
            if (lines[i][j] != *a)
            {
                j++;
            }
            else
            {
                int k = 0;
                int first = 0;
                first = j;
                int j2 = 0;
                j2 = j;
                while (lines[i][j2] == a[k])
                {
                    if (a[++k] == '\0')
                    {
                        if (i == 0)
                        {
                            return first - 3;
                        }
                        first -= 3;
                        while (i != 0)
                        {
                            first += StrLen(lines[--i]) - 2;
                        }
                        return first;
                    }
                    j2++;
                }
                j++;
            }
        }
    }
    return -1;
}

char* SubStr(char* str, int from, int to)
{
    if (to > StrLen(str) - 1 || from > to)
    {
        return "Error";
    }
    char* a = str;
    for (int i = from; i > 0; --i)
    {
        a++;
    }
    for (int i = to + 1 - from; i <= StrLen(a) - 1; ++i)
    {
        a[i] = '\0';
    }
    return a;
}

int StrCmp(char* a, char* b)
{
    int i = 0;
    while(a[i] != '\0' || b[i] != '\0')
    {
        if (a[i] == b[i])
        {
            ++i;
        }
        else
        {
            return a[i] - b[i];
        }
    }
    return 0;
}

char* StrMult(char* a, int n)
{
    if (n == 0)
    {
        return "";
    }
    if (n == 1)
    {
        return a;
    }
    if (n < 0)
    {
        return "Error";
    }
    int len = 0;
    len = StrLen(a) - 1;
    int j = 0;
    for (int i = 0; i < len * n; ++i)
    {
        if (j == len)
        {
            j = 0;
        }
        a[i] = a[j++];
    }
    a[len * n] = '\0';
    return a;
}
