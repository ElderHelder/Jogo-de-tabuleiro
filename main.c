#include "move.h"


arvore* inicializa(){
return NULL;
}

arvore* ExtEsq(arvore *raiz) /*para indicar onde o jogador comeca, o mesmo para ExtDir*/
{
    while(raiz->esq != NULL) raiz = raiz->esq;
    return raiz;
}

arvore* ExtDir(arvore *raiz)
{
    while(raiz->dir != NULL) raiz = raiz->dir;
    return raiz;
}

arvore* acao(int x, arvore* raiz, int casa, arvore* atual, Player *p){ /*sobe e desce o jogador, verificado comandos errados ou falhas na memoria e verifica se os recursos sao validos para chegar no nucleo*/
arvore* pai = vasculha(raiz, casa);
if(pai == NULL)
{
    puts("movimento invalido");
    return NULL;
}
if(x==1)
{ 
if(pai->casa == 7)
{
	if (p->rec.arma > 10 && p->rec.escudo > 10 && p->rec.energia > 10){          
return pai;
}
     else
     puts("recursos insuficientes");
     return atual;
	}
else if(pai->casa != 7)
return pai;
}
if(x==2 && atual->esq != NULL) return atual->esq;
if(x==3 && atual->dir != NULL) return atual->dir;
else
{
    puts("movimento invalido");
    return NULL;
}
}

void jogo(arvore* raiz, Player* hero, Player* villain)
{/*o jogo em si esta aqui, essa funcao se chama ate o fim do jogo(ela por si so nao para, mas as funcoes que ela chama tem poder de fechar o programa) ela diz que o local e ensina os movimentos, deixando para as outras funcoes que ela chama para dizer recursos, situacao e mover*/
    printf("heroi está no(a) %s\n", (hero->posicao)->nome);
printf("vilao está no(a) %s\n", (villain->posicao)->nome);

checar_estagio(hero);
checar_estagio(villain);
checar_tipo(hero);
checar_tipo(villain);

puts("O que o heroi irá fazer? 1 pra cima, 2 pra esquerda-baixo, 3 pra direita-baixo");
hero->posicao = acao(getint(), raiz, (hero->posicao)->casa, hero->posicao, hero);
puts("O que o vilao irá fazer? 1 pra cima, 2 pra esquerda-baixo, 3 pra direita-baixo");
villain->posicao = acao(getint(), raiz, (villain->posicao)->casa, villain->posicao, villain);
printf("\x1b[2J\x1b[H"); //limpa tela
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
