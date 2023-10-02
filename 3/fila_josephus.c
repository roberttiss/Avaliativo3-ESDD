#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
    Queue fila;
    Queue fila_vivos;
    Queue fila_mortos;
    char *pessoa;
    
    init(&fila);
    for(int i = 0; i != 40; i++) {
        pessoa = malloc(sizeof(char) * 20);
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoa, 20, stdin);
        enqueue(fila, pessoa);
    }

    init(&fila_vivos);
    init(&fila_mortos);
    int sobreviventes = 40;
    int i = 1;

     while(sobreviventes > 1)
    {
        //
        //Captura a primeira pessoa da fila
        //Em seguida, preenche a fila de vivos contando q o indice seja diferente de 3 (posição onde a pessoa morre)
        //Caso o indice é 3,preenche a fila dos mortos
        pessoa = dequeue(fila);
        if (i == 3)
        {
            enqueue(fila_mortos, pessoa);
            sobreviventes--;
        }else{
            enqueue(fila_vivos, pessoa);
        }

        //Retorna as pessoas da fila de vivos para a fila principal
        
        while (!is_empty(fila_vivos))
        {
            enqueue(fila, dequeue(fila_vivos));

        }
        //

        //
        //Reseta o index quando ele ultrapassar 3

        i++;
        if (i > 3)
        {
            i=1;
        }
        //
    }

    pessoa = dequeue(fila);
    printf("\nSobrevivente: %s", pessoa);

    return 0;
}
