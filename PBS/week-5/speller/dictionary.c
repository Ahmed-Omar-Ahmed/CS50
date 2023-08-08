#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

unsigned int hash(const char *word);

const unsigned int N = 187751;

node *table[N];

int word_count = 0;

bool check(const char *word)
{
    for (node *tmp = table[hash(word)]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}
unsigned int hash(const char *word)
{
    int hash = 0;
    for (int i = 0; i <= strlen(word); i++)
    {
        hash = (31 * hash + toupper(word[i])) % N;
    }
    return hash;
}
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    char *word = malloc(LENGTH + 1);
    if (word == NULL)
    {
        return false;
    }
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        int pos = hash(word);
        strcpy(n->word, word);
        if (table[pos] == NULL)
        {
            n->next = NULL;
        }
        else
        {
            n->next = table[pos];
        }
        table[pos] = n;
        word_count++;
    }
    fclose(dict);
    free(word);
    return true;
}

unsigned int size(void)
{
    return word_count;
}

bool unload(void)
{
    // TODO
    for (int i = 0; i <= N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}