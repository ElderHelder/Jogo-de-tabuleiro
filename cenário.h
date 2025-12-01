#include <stdio.h>

//nota: para inicializar o tabuleiro crie a arvore e defina as 15 casas na função principal usando a função insere, tambem use srand no main, a raiz deve ser a casa 1

char* nomes_cenarios[15] = {"Núcleo-x", "cemiterio", "jardim", "floresta", "deserto", "cidade", "vila", "castelo", "igreja", "lago", "bosque", "vulcão", "nevada", "ruinas", "esconderijo"}; //nome da casa
char tipos[3] = {'r', 'n', 'b'};
/*Primeiro crio uma arvore com galho esquerdo, direito e conteudo proprio */
typedef struct tree {
  	int casa;
    char* nome;
    char tipo; //recurso é r, normal é n, batalha é b
  	struct tree *esq;
 	struct tree *dir;
} arvore;

void Define(arvore** folha){
static int indice_tipo = 0;
(*folha)->nome = nomes_cenarios[(*folha)->casa];
(*folha)->tipo = tipos[rand() % 3];
indice_tipo++;
}

/* Função que insere elemento na árvore, retorna o tipo arvore*/
arvore *insere(arvore *raiz, int valor, char *nome) {

    // Árvore vazia, o novo nó será a raiz
/*Alocando espaço e um endereço para a raiz, indicando que os galhos estão vazios, quando a arvore recursivamente chegar em um galho vazio, vai criar ele e seus galhos, dando valor e endereço*/
    if (raiz == NULL) {
        arvore *folha = (arvore*) malloc(sizeof(arvore));
        folha->casa = valor;
        folha->dir = NULL;
        folha->esq = NULL;

        return folha;
    }

    if (casa > raiz->casa)
        raiz->dir = insere(raiz->dir, valor);
    else
        raiz->esq = insere(raiz->esq, valor);

    return raiz;
}

// Função que vai visitar todas as casas e defini-las
void ponteiro_visitante(arvore *raiz) {
    if (raiz == NULL)
        return;
/*define a último esquerda e vai voltando, quando definir todas as esquerdas, vai para a direita e define toda a esquerda dele, definindo todas as casas*/
    ponteiro_visitante(raiz->esq);
    Define(&raiz);
    ponteiro_visitante(raiz->dir);
}
