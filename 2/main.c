#include "queue.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Queue fila_normal;
    Queue fila_prioritaria;
    init(&fila_normal);
    init(&fila_prioritaria);
    int opcao;
    int contador_normal = 1;
    int contador_prioritaria = 1;
    int caixa;
    do
    {
        printf("-------CAIXA-------\n");
        printf("1. Pegar ficha normal\n");
        printf("2. Pegar ficha prioritaria\n");
        printf("3. Chamar proximo\n");
        printf("4. Sair\n");
        printf("Digite uma opção : "); 
        scanf("%d",&opcao);

        switch (opcao)
        {
        // verifica se a fila normal esta cheia,caso esteja vai retornar avisando,se não,insere a pessoa na fila com a senha 1
        // a senha incrementa a cada pessoa
        case 1:
            if(!is_full(fila_normal)){
                enqueue(fila_normal, contador_normal);
                contador_normal++;
            }else{
                printf("A fila esta cheia.\n");
            }
            break;
        // verifica se a fila normal esta cheia,caso esteja vai retornar avisando,se não,insere a pessoa na fila com a senha 1
        // a senha incrementa a cada pessoa
        case 2:
            if (!is_full(fila_prioritaria)){
                enqueue(fila_prioritaria, contador_prioritaria);
                contador_prioritaria++;
            }else{
                printf("A fila esta cheia.\n");
            }
            break;
        // recebe o numero do caixa,se entre 1 e 3,verifica se não esta vazia a fila e chama a senha
        case 3:
            printf("Informe um caixa de 1 a 10 para ser antendido: ");
            scanf("%d",&caixa);
            if (caixa >= 4 && caixa <= 10 && !is_empty(fila_normal))
            {
                int senha_normal = dequeue(fila_normal);
                printf("Caixa(%d) Senha Normal(%d)\n",caixa,senha_normal);
            }
            if (caixa > 0 && caixa <= 3 && !is_empty(fila_prioritaria))
            {
                int senha_prioritaria = dequeue(fila_prioritaria);
                printf("Caixa(%d) Senha Prioritaria(%d)\n",1 + (rand () % 3),senha_prioritaria);
            }
            else if( caixa < 0 || caixa > 10){
                printf("Caixa inválido.\n");
            }      
            else{
                printf("Fila esta vazia.\n");
            }
            break;
        case 4:
            return 0;
        
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao);
    return 0;
}
