//
// Created by isaq25 on 22/05/2025.
//

#ifndef STRUCT_H
#define STRUCT_H

// tipos 1 = normal,2 = Eletrico,3 = Planta,4 = Venenoso,5 - Fogo, 6 - Metal
// 2 tipos 34 = Planta e venenoso
typedef struct {
    char item[30];
    int recuperar;
    int qtd;
}Potion;
typedef struct {
    Potion curar;

}Bag;


typedef struct {
    char nome[30];
    int tipo;
    int dano;

}Ataque;
typedef struct {
    char nome[30];
    int hp;
    Ataque ataque1;
    Ataque ataque2;
    Ataque ataque3;
    Ataque ataque4;
    int defesa;
    int nivel;
    char tipo[30];
    int tipo_num;
    int hp_max;
    int velo;
}Pokemon;

#endif //STRUCT_H
