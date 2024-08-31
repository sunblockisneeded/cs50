#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string texts = get_string("Text: ");
    count_letters(texts);

    float index =
        0.0588 * count_letters(texts) / count_words(texts) * 100 - 0.296 * count_sentences(texts) / count_words(texts) * 100 - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}

int count_letters(string text)
{
    int len = strlen(text);
    char a[len];
    for (int i = 0; i < len; i++)
    {
        a[i] = (char) text[i];
    }
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(a[i]) != 0)
        {
            counter++;
        }
    }
    return counter;
}

int count_words(string text)
{
    int len = strlen(text);
    char a[len];
    for (int i = 0; i < len; i++)
    {
        a[i] = (char) text[i];
    }
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (isblank(a[i]) != 0)
        {
            counter++;
        }
    }
    return counter + 1;
}

int count_sentences(string text)
{
    int len = strlen(text);
    char a[len];
    for (int i = 0; i < len; i++)
    {
        a[i] = (char) text[i];
    }
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '?' || a[i] == '!' || a[i] == '.')
        {
            counter++;
        }
    }
    return counter;
}
