#include "move.h"
#include "recursos.h"

int passadas_vulcao = 0;
int passadas_floresta = 0;

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

arvore* acao(int x, arvore* raiz, int casa, arvore* atual){
arvore* pai = vasculha(raiz, casa);
if(pai == NULL)
{
    puts("movimento invalido");
    return NULL;
}
if(x==1) return pai;
if(x==2 && atual->esq != NULL) return atual->esq;
if(x==3 && atual->dir != NULL) return atual->dir;
else
{
    puts("movimento invalido");
    return NULL;
}
}

void checar_estagio(Player* p) {
    int casa = p->posicao->casa;

    switch(casa) {

        case 7: // Núcleo-X
            printf("%s chegou no núcleo-x e venceu!\n",
                   p->id == 1 ? "herói" : "vilão");
            exit(0);

        case 4: // deserto
            printf("O heroi entrou no deserto e morreu de insolação.\n");
            printf("O vilao venceu!\n");
            exit(0);

        case 10: // bosque
            printf("O vilao levou uma emboscada no bosque e morreu.\n");
            printf("O heroi venceu!\n");
            exit(0);

        case 11: // vulcão
            if (passadas_vulcao >= 2) {
                printf("O vilao entrou no vulcao e morreu queimado!\n");
                printf("O heroi venceu!\n");
                exit(0);
            } else {
                puts("Cuidado! Nao volte ao vulcao muitas vezes!");
                passadas_vulcao++;
            }
            break;

        case 3: // floresta
            if (passadas_floresta >= 2) {
                printf("O heroi entrou na floresta e foi atacado por uma onça!\n");
                printf("O vilao venceu!\n");
                exit(0);
            } else {
                puts("A floresta e perigosa… cuidado ao retornar!");
                passadas_floresta++;
            }
            break;
    }
}

void jogo(arvore* raiz, Player* hero, Player* villain)
{
    printf("heroi está no(a) %s\n", (hero->posicao)->nome);
printf("vilao está no(a) %s\n", (villain->posicao)->nome);

checar_estagio(hero);
checar_estagio(villain);

puts("O que o heroi irá fazer? 1 pra cima, 2 pra esquerda-baixo, 3 pra direita-baixo");
hero->posicao = acao(getint(), raiz, (hero->posicao)->casa, hero->posicao);
puts("O que o vilao irá fazer? 1 pra cima, 2 pra esquerda-baixo, 3 pra direita-baixo");
villain->posicao = acao(getint(), raiz, (villain->posicao)->casa, villain->posicao);
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
