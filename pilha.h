#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

struct aluno{
    int matricula;
    char nome[50];
};

typedef struct elemento* Pilha;

Pilha* criar();
int vazia(Pilha *);
int inserir(Pilha *, struct aluno);
int remover(Pilha *);
int acessar(Pilha*, struct aluno *);
void destruir(Pilha *);
int imprimePilha(Pilha* pd);



typedef struct Elem *Lista;

Lista* criarPilha();
int inserePilha(Lista*, Pilha*);



#endif // PILHA_H_INCLUDED
