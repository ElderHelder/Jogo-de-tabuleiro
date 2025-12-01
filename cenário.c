#include <stdio.h>

/*Primeiro crio uma arvore com galho esquerdo, direito e conteudo proprio */
typedef struct tree {
  	int casa;
    char* nome;
    char tipo; //recurso é r, normal é n, batalha é b
  	struct tree *esq;
 	struct tree *dir;
} arvore;

void Define(arvore** folha){
static int casa = 1;
folha->casa = casa;
node->char* nome;

casa++;
}

/* Função que insere elemento na árvore, retorna o tipo arvore*/
arvore *insere(arvore *raiz, int valor, char *nome) {

    // Árvore vazia, o novo nó será a raiz
/*Alocando espaço e um endereço para a raiz, indicando que os galhos estão vazios, quando a arvore recursivamente chegar em um galho vazio, vai criar ele e seus galhos, dando valor e endereço*/
    if (raiz == NULL) {
        arvore *folha = (arvore*) malloc(sizeof(arvore));
        folha->casa = valor;
        folha->nome = nome;
        folha->dir = NULL;
        folha->esq = NULL;

        return folha;
    }

    if (valor > raiz->info)
        raiz->dir = insere(raiz->dir, valor);
    else
        raiz->esq = insere(raiz->esq, valor);

    return raiz;
}

// Função imprime elementos in-order
void imprimeInorder(arvore *raiz) {
    if (raiz == NULL)
        return;
/*imprime o último esquerdo e vai voltando, quando imprimir todas as esquerdas, vai para a direita e imprime toda a esquerda dele, imprimindo em ordem*/
    imprimeInorder(raiz->esq);
    raiz->
    imprimeInorder(raiz->dir);
}


