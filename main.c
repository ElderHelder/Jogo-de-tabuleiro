#include "move.h"
#include "recursos.h"

int getint(){
int a;
scanf("%d", &a);
return a;
}

arvore* inicializa(){
return NULL;
}

arvore* ExtEsq(arvore *raiz)
{
    while(raiz->esq != NULL) raiz = raiz->esq;
    return raiz;
}

arvore* ExtDir(arvore *raiz)
{
    while(raiz->dir != NULL) raiz = raiz->dir;
    return raiz;
}

arvore* acao(int x, arvore* raiz, int casa){
arvore* pai = vasculha(raiz, casa);
if(pai == NULL)
{
    puts("movimento invalido");
    return NULL;
}
if(x==1) return pai;
if(x==2 && pai->esq != NULL) return pai->esq;
if(x==3 && pai->dir != NULL) return pai->dir;
else
{
    puts("movimento invalido");
    return NULL;
}
}

void jogo(arvore* raiz, Player* hero, Player* villain)
{
    printf("heroi está no(a) %s\n", (hero->posicao)->nome);
printf("vilao está no(a) %s\n", (villain->posicao)->nome);

puts("O que o heroi irá fazer? 1 pra cima, 2 pra esquerda-baixo, 3 pra direita-baixo");
hero->posicao = acao(getint(), raiz, (hero->posicao)->casa);
puts("O que o vilao irá fazer? 1 pra cima, 2 pra esquerda-baixo, 3 pra direita-baixo");
villain->posicao = acao(getint(), raiz, (villain->posicao)->casa);

jogo(raiz, hero, villain);
}

int main(){
srand(time(NULL));
arvore *tabuleiro = inicializa();
tabuleirizador(&tabuleiro);

arvore* extremoEsq = ExtEsq(tabuleiro);
arvore* extremoDir = ExtDir(tabuleiro);

Player *heroi = malloc(sizeof(Player));
Player *vilao = malloc(sizeof(Player));
inicializarPlayers(heroi, vilao, extremoEsq, extremoDir);
jogo(tabuleiro, heroi, vilao);

return 0;
}
