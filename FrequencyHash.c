#include<stdio.h>
#include<stdlib.h>
typedef struct element{
    char caracter;
    int frequency;
    struct element * next;
}Element;

typedef struct hashtable{
    Element * tablefrequency[37];
}HashTable;

HashTable * CreateHash()
{
    int i;
    HashTable * hashtable=(HashTable*)malloc(sizeof(HashTable));
    for(i=0;i<37;i++)
    {
        hashtable->tablefrequency[i]=NULL;
    }
    return hashtable;
}
int HashFunction(char caracter)
{
    return caracter%37;
}
void put(HashTable * hashtable, char caracter)
{
    int key;
    key=HashFunction(caracter);
    if(hashtable->tablefrequency[key] == NULL)
    {
        Element * element=(Element*)malloc(sizeof(Element));
        element->caracter=caracter;
        element->frequency=1;
        element->next=NULL;
        hashtable->tablefrequency[key]=element;
    }
    else
    {
        Element * current;
        Element * previous=NULL;
        for( current=hashtable->tablefrequency[key] ; current != NULL ; current=current->next )
        {
            if(current->caracter == caracter)
                break;
            previous=current;
        }
        if(current != NULL)
        {
            current->frequency++;
        }
        else
        {
            Element * element=(Element*)malloc(sizeof(Element));
            element->caracter=caracter;
            element->frequency=1;
            element->next=NULL;
            previous->next=element;
        }

    }
}
void PrintHashTable(HashTable * hashtable)
{
    int i;
    Element * aux;
    for(i=0 ; i < 37 ; i++ )
    {
        for(aux=hashtable->tablefrequency[i]; aux !=
        NULL ; aux = aux->next)
        {
            printf("caracter: %c    frequencia: %d\n",aux->caracter,aux->frequency);
        }
    }
}
