#include "cenario.h"
#include "recursos.h"

//verificando frequencia
int passadas_vulcao = 0; 
int passadas_floresta = 0;

int getint(){ //facilitando pegar inteiros
int a;
scanf("%d", &a);
return a;
}

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

void checar_estagio(Player* p) { /*cenarios especiais e cenario final*/
    int casa = p->posicao->casa;
if(casa%2 == 0)//para os nos folhas
puts("nao va para baixo");
    switch(casa) {

        case 7: // Núcleo-X
            printf("%s chegou no núcleo-x com recursos suficientes e venceu!\n",
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
                puts("Para chegar no nucleo tenha mais de 10 em todos os recursos");
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
                puts("Para chegar para o nucleo, tenha mais de 10 em todos os recursos");
                passadas_floresta++;
            }
            break;
    }
}

void checar_tipo(Player* p) { /*dinamizando os cenarios de acordo com os tipos que tem*/
    char tipo_atual = p->posicao->tipo;
    int escolha, acaso;

    if (tipo_atual == 'r') {
        printf("%s chegou em um estágio *de recurso* e ganhou 1 arma, 1 escudo e 1 energia!\n",
               p->id == 1 ? "Herói" : "Vilão");

        p->rec.arma++;
        p->rec.escudo++;
        p->rec.energia++;
    }

    else if (tipo_atual == 'n') {
        printf("%s chegou em um estágio *normal*. Nada acontece.\n",
               p->id == 1 ? "Herói" : "Vilão");
    }

    else if (tipo_atual == 'b') {
        printf("%s chegou em um estágio *de batalha*!\n", 
               p->id == 1 ? "Herói" : "Vilão");

        printf("Deseja lutar (1) ou evitar a batalha (2)? ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            // 50% chance de vitória
            acaso = rand() % 2;

            if (acaso == 1) {
                printf("Vitória na batalha! %s ganhou 2 recursos aleatórios.\n",
                       p->id == 1 ? "Herói" : "Vilão");

                // ganho de recursos
                int r1 = rand() % 3;
                int r2 = rand() % 3;

                if (r1 == 0) p->rec.arma++;
                else if (r1 == 1) p->rec.escudo++;
                else p->rec.energia++;

                if (r2 == 0) p->rec.arma++;
                else if (r2 == 1) p->rec.escudo++;
                else p->rec.energia++;
            }
            else {
                printf("Derrota na batalha! %s perdeu 1 recurso em cada categoria.\n",
                       p->id == 1 ? "Herói" : "Vilão");

                // perdas
                if (p->rec.arma > 0) p->rec.arma--;
                if (p->rec.escudo > 0) p->rec.escudo--;
                if (p->rec.energia > 0) p->rec.energia--;
            }
        } 
        else {
            printf("%s evitou a batalha e nada aconteceu.\n",
                   p->id == 1 ? "Herói" : "Vilão");
        }
    }

    // Exibe recursos atuais
    printf("\n== Recursos de %s ==\n", p->id == 1 ? "Herói" : "Vilão");
    printf("Arma: %d | Escudo: %d | Energia: %d\n\n",
           p->rec.arma,
           p->rec.escudo,
           p->rec.energia);
}
