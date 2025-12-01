#include <time.h>
#include <stdlib.h>

typedef struct {
    int arma;
    int escudo;
    int energia;
} Recursos;

typedef enum {
    RECURSO_ARMA,
    RECURSO_ESCUDO,
    RECURSO_ENERGIA
} TipoRecurso;

typedef struct {
    TipoRecurso tipo;
    int nivel;   // nível incrementado ao coletar
} Recurso;

typedef struct {
    int id;          // 1 ou 2
    Recursos rec;    // recursos do jogador
    Tree* posicao;     // ponteiro para o nó atual na árvore
} Player;

void inicializarPlayers(Player* p1, Player* p2, Tree* extremoEsq, Tree* extremoDir) {
    p1->id = 1;
    p1->rec.arma = 5;
    p1->rec.escudo = 5;
    p1->rec.energia = 8;
    p1->posicao = extremoEsq;

    p2->id = 2;
    p2->rec.arma = 5;
    p2->rec.escudo = 5;
    p2->rec.energia = 8;
    p2->posicao = extremoDir;
}