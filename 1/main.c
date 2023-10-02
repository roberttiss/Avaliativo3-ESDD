#include <stdio.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
    Queue fila_original;
    Queue auxiliar;
    int number;

    
    init(&fila_original);
    printf("Ordem dos inseridos na fila\n\n");
    for (int i = 0; i != 20; i++)
    {
        scanf("%d", &number);
        printf("%d. %d\n", i + 1, number);
        enqueue(fila_original, number); 
    }
    
    
    init(&auxiliar);
    while (!is_empty(fila_original)) // verifica se a fila original não esta vazia
    {
        number = dequeue(fila_original); // remove o numero da fila original
        if (number == 0 || (number % 2) == 1)
        {
            enqueue(auxiliar, number); // insere o numero na fila auxiliar se for zero ou impar
        } 
    }
    
    printf("\nFila com os números restantes\n\n");
    while (!is_empty(auxiliar)) // verifica se a fila auxiliar não esta vazia
    {
        number = enqueue(fila_original, dequeue(auxiliar)); //remove da fila auxiliar os numeros e insere na original
    }

    while (!is_empty(fila_original)) // verifica se a fila original não esta vazia
    {
        number = dequeue(fila_original); // remove o numero da fila original
        printf("%d\n", number); // imprime o numero
    }
    
    return 0;
}
