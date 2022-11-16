#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "pilha.h"
#include "cdp.h"

typedef struct conjunto_de_pilhas CDP;

void imprimeMenu(){
    printf("_________________________________\n");
    printf("1- Inserir aluno\n");
    printf("2- Remover aluno\n");
    printf("3- Acessa aluno no topo da pilha\n");
    printf("4- Imprime as pilhas\n");
    printf("5- remover por nome\n");
    printf("6- Destruir pilhas\n");
    printf("7- Sair do Programa\n");
    printf("-------------\nSua opcao: ");
}


void preencheAluno(struct aluno *dados){
    printf("Digite o nome: ");
    gets(dados->nome);
    printf("Digite a matricula: ");
    scanf("%d", &dados->matricula);
    printf("\n");
}


int main()
{
    CDP *cdp = criar_lista();
    int opcao = -1;
    struct aluno dados;
    int lim;
    char nome[50];

    printf("digite um inteiro para o tamanho limite da pilha: \n");
    scanf("%d", &lim);
    while(getchar() != '\n');

    while(opcao != 7){
        imprimeMenu();
        scanf("%d", &opcao);
        while(getchar() != '\n');
        printf("\n");

        if(opcao == 1){
            preencheAluno(&dados);
            inserir_lista(cdp, dados, lim);
        }
        else if(opcao == 2){
            remover(cdp->pilha);
        }
        else if(opcao == 3){
            acessar(cdp->pilha, &dados);
            printf("Nome: %s, Matricula: %d\n", dados.nome, dados.matricula);
        }
        else if(opcao == 4){
            imprimir_lista(cdp);
        }
        else if(opcao == 5) {
            printf("Digite o nome: ");
            gets(nome);
            remover_por_nome(cdp, nome);
        }
        else if(opcao == 6){
            destruir_lista(cdp);
            cdp = criar_lista();
        }
        else if(opcao == 7)
            printf("Encerrando o programa\n");

        else
            printf("Opcao invalida, tente novamente\n");

    }
    return 0;
}

