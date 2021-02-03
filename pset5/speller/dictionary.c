// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1]; // max is LENGTH = 45 so max size of array is 46 to incl null char.
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table    array of node pointers
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    //test if file exsists
    if(file == NULL)
    {
        printf("Could not open %s.\n", file);
        return false;
    }
    
    // storage space for word
    char word[LENGTH + 1];
    
    while(fscanf(file, "%s", word) != EOF)
    {
        //alloc memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
            {
                return false;
            }
        //copy word into node    
        strcpy(n->word, word);
        // hash func defined in dictionary.c takes a string and returns an index
        hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;

    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
