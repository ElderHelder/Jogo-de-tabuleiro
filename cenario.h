#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//nota: para inicializar o tabuleiro crie a arvore e defina as 15 casas na função principal usando a função insere, tambem use srand no main, a raiz deve ser a casa 7

char* nomes_cenarios[15] = {"castelo", "cemiterio", "jardim", "floresta", "deserto", "cidade", "vila", "Núcleo-x", "igreja", "lago", "bosque", "vulcão", "nevada", "ruinas", "esconderijo"}; //nome da casa
char tipos[3] = {'r', 'n', 'b'};
/*Primeiro crio uma arvore com galho esquerdo, direito e conteudo proprio */
typedef struct tree {
  	int casa;
    char* nome;
    char tipo; //recurso é r, normal é n, batalha é b
  	struct tree *esq;
 	struct tree *dir;
} arvore;

void Define(arvore* folha){
    folha->nome = nomes_cenarios[folha->casa];
    folha->tipo = tipos[rand() % 3];
}

arvore *insere(arvore *raiz, int valor) {
    if (raiz == NULL) {
        arvore *folha = malloc(sizeof(arvore));
        folha->casa = valor;
        folha->nome = NULL;
        folha->tipo = 0;
        folha->esq = NULL;
        folha->dir = NULL;
        return folha;
    }

    if (valor > raiz->casa)
        raiz->dir = insere(raiz->dir, valor);
    else
        raiz->esq = insere(raiz->esq, valor);

    return raiz;
}

// Função que vai visitar todas as casas e defini-las
void ponteiro_visitante(arvore *raiz) {
    if (raiz == NULL)
        return;

    ponteiro_visitante(raiz->esq);
    Define(raiz);
    ponteiro_visitante(raiz->dir);
}

void tabuleirizador(arvore** raiz){
*raiz = insere(*raiz, 7);
int a = 0;
a = 1; /*ordem especial de inserções para uma arvore balanceada*/
while(a < 7){
    *raiz = insere(*raiz, 1 + 2*a);
    a += 4;
}
a = 1;
while(a < 14){
    *raiz = insere(*raiz, a);
    a += 4;
}
a = 0;
while(a < 15){
    *raiz = insere(*raiz, a);
    a += 2;
}
ponteiro_visitante(*raiz);
}
