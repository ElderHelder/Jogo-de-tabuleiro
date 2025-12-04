#include "cenario.h"

arvore* vasculha(arvore *raiz, int casa) { //Função baseada na busca inorder para achar um determinado nó da arvore
    if (raiz == NULL)
        return NULL;

    arvore* tmp = vasculha(raiz->esq, casa);
    if(tmp != NULL)
    {
        return tmp;
    }
    if((raiz->esq != NULL && (raiz->esq)->casa == casa) || (raiz->dir != NULL && (raiz->dir)->casa == casa)){
        return raiz;
    }
    return vasculha(raiz->dir, casa);
}
