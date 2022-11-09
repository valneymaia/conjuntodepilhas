#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "pilha.h"
#include "cdp.h"


typedef struct conjunto_de_pilhas CDP;


CDP * criar_lista()
{
    CDP *novo = malloc(sizeof(CDP));
    novo->proxima_pilha = NULL;
    novo->pilha = criar();
    return novo;
}


void inserir_lista(CDP *cdp, struct aluno dados, int n)
{
    if(cdp == NULL) {
        printf("Lista nao alocada.");
        return;
    }

    CDP *aux = cdp;


    while(tamanho(aux->pilha) >= n && aux->proxima_pilha != NULL) {
        aux = aux->proxima_pilha;
    }

    // Se chegou na ultima pilha da lista e ele esta cheia, cria uma nova e insere nela
    if(aux->proxima_pilha == NULL && tamanho(aux->pilha) >= n) {
        CDP *nova = criar_lista();
        aux->proxima_pilha = nova;
        aux = nova;
    }

    inserir(aux->pilha, dados);
    return;
}


void imprimir_lista(CDP *cdp)
{
    if(cdp == NULL || cdp->pilha == NULL || tamanho(cdp->pilha) == 0) {
        printf("Lista vazia.\n");
        return;
    }

    CDP *aux = cdp;
    int i = 1;
    while(aux != NULL) {
        printf("%da pilha: ", i);
        printf("\n---------\n");
        imprimePilha(aux->pilha);
        printf("\n\n");
        aux = aux->proxima_pilha;
        i++;
    }
}


void destruir_lista(CDP *cdp)
{
    // Na destruicao, dos enderecos de memoria serao perdidos, sendo necessario recria-los caso necessario.
    if(cdp == NULL || cdp->pilha == NULL || cdp->pilha == 0)
        return;

    CDP *temp = cdp;
    while(temp != NULL && tamanho(temp->pilha) > 0) {
        destruir(temp->pilha);
        temp = temp->proxima_pilha;
    }
}
