#include <stdio.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define maximo_itens 10
#define maximo_nome 50

typedef struct{
    char TipoDoItem[maximo_nome];
    char nomeDoItem[maximo_nome];
    int quantidadeDeItens;
} item;

int totalDeItens = 0;
item mochila[maximo_itens];

int funcaofreefire() {
    int opcao;
    
    do{
    printf("----- FREE FIRE -----\n");
    printf("1 - adicionar itens\n");
    printf("2 - remover item\n");
    printf("3 - listar itens\n");
    printf("4 - sair\n");
    printf("---------------\n");
    printf("escolha uma opção: ");
    scanf("%d", &opcao);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    switch(opcao) {
       
        case 1:
        printf("nome do item: ");
        fgets(mochila[totalDeItens].nomeDoItem, maximo_nome, stdin); // fgets é usado para ler e armazenas em um array uma linha de texto
        printf("tipo do item: ");
        fgets(mochila[totalDeItens].TipoDoItem, maximo_nome, stdin); 

        mochila[totalDeItens].nomeDoItem[strcspn(mochila[totalDeItens].nomeDoItem, "\n")] = '\0';
        mochila[totalDeItens].TipoDoItem[strcspn(mochila[totalDeItens].TipoDoItem, "\n")] = '\0';        
        printf("número de itens: \n");
        scanf("%d", &mochila[totalDeItens].quantidadeDeItens);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        totalDeItens++;

        break;

        case 2:
    if (totalDeItens == 0) {
        printf("Nenhum item cadastrado para remover!\n");
        break;
    }

    int indice_remover;
    printf("Digite o número do item a remover: ");
    scanf("%d", &indice_remover);

    while ((c = getchar()) != '\n' && c != EOF);

    if (indice_remover < 1 || indice_remover > totalDeItens) {
        printf("Opção de item inválida! Por favor, tente novamente.\n");
    } else {        int indice_array = indice_remover - 1;

        printf("Removendo item: %s...\n", mochila[indice_array].nomeDoItem);

        
        for (int i = indice_array; i < totalDeItens - 1; i++) {
            mochila[i] = mochila[i + 1];
        }

        totalDeItens--;

        printf("Item removido com sucesso! Total de itens: %d\n", totalDeItens);
    }
    break;
        break;

        case 3: 
        for(int i = 0; i < totalDeItens; i++) {
            printf("----------\n");
            printf("item: %d\n", i + 1);
            printf("nome: %s\n", mochila[i].nomeDoItem);
            printf("tipo: %s\n", mochila[i].TipoDoItem);
            printf("quantidade: %d\n", mochila[i].quantidadeDeItens);
        }

        if(totalDeItens == 0) {
            printf("nenhum item foi cadastrado !\n");
        }
        break;

        case 4:
        printf("saindo...");
        break;

        default: 
        printf("opção inválida !\n");
        }
        
    } while(opcao != 4);

} 

int main() { 
    funcaofreefire();
    return 0;
}
