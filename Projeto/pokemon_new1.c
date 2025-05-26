#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "struct.h"
#include "fuction.c"

int main() {
    setlocale(LC_ALL, ".UTF-8");

    int i=1;
    int atual1 = 0;
    int atual2 = 0;
    Pokemon time1[2];
    Pokemon time2[2];
    Pokemon squirtle;
    // tipos 1 = normal,2 = Eletrico,3 = Planta,4 = Venenoso,5 - Fogo, 6 - Metal,7-Agua
    // 2 tipos 34 = Planta e venenoso
    strcpy(squirtle.nome, "Squirtle");
    squirtle.hp = 120;
    squirtle.hp_max = 120;
    squirtle.defesa = 8;
    squirtle.nivel = 10;
    strcpy(squirtle.tipo, "Agua");
    squirtle.tipo_num = 7;
    squirtle.velo = 8;

    strcpy(squirtle.ataque1.nome, "Tackle");
    squirtle.ataque1.tipo = 2;
    squirtle.ataque1.dano = 10;

    strcpy(squirtle.ataque2.nome, "Tail-whip");
    squirtle.ataque2.tipo = 1;
    squirtle.ataque2.dano = 5;

    strcpy(squirtle.ataque3.nome, "Water-gun");
    squirtle.ataque3.tipo = 7;
    squirtle.ataque3.dano = 15;

    strcpy(squirtle.ataque4.nome, "Bubble");
    squirtle.ataque4.tipo = 7;
    squirtle.ataque4.dano = 25;

    Pokemon bulbasaur;
    strcpy(bulbasaur.nome, "Bulbasaur");
    bulbasaur.hp = 100;
    bulbasaur.hp_max = 100;
    bulbasaur.defesa = 7;
    bulbasaur.nivel = 10;
    strcpy(bulbasaur.tipo, "Planta e Venenoso");
    bulbasaur.tipo_num = 34;
    bulbasaur.velo = 7;

    strcpy(bulbasaur.ataque1.nome, "Tackle");
    bulbasaur.ataque1.tipo = 1;
    bulbasaur.ataque1.dano = 10;

    strcpy(bulbasaur.ataque2.nome, "Growl");
    bulbasaur.ataque2.tipo = 1;
    bulbasaur.ataque2.dano = 5;

    strcpy(bulbasaur.ataque3.nome, "Vine-whip");
    bulbasaur.ataque3.tipo = 3;
    bulbasaur.ataque3.dano = 14;

    strcpy(bulbasaur.ataque4.nome, "Razor-leaf");
    bulbasaur.ataque4.tipo = 3;
    bulbasaur.ataque4.dano = 18;

    Pokemon charmander;
    strcpy(charmander.nome, "Chamander");
    charmander.hp = 130;
    charmander.hp_max = 130;
    charmander.defesa = 5;
    charmander.nivel = 10;
    strcpy(charmander.tipo, "Fogo");
    charmander.tipo_num = 5;
    charmander.velo = 9;

    strcpy(charmander.ataque1.nome, "Scratch");
    charmander.ataque1.tipo = 1;
    charmander.ataque1.dano = 10;

    strcpy(charmander.ataque2.nome, "Growl");
    charmander.ataque2.tipo = 1;
    charmander.ataque2.dano = 5;

    strcpy(charmander.ataque3.nome, "Ember");
    charmander.ataque3.tipo = 5;
    charmander.ataque3.dano = 18;

    strcpy(charmander.ataque4.nome, "Metal Claw");
    charmander.ataque4.tipo = 6;
    charmander.ataque4.dano = 14;

    int pk1,pk2;
    char jogador1[30],jogador2[30];


    Bag mochila = {"Potion",20,3};


    printf("\n");
    printf("Nome do jogador 1:");
    scanf("%s",jogador1);

    printf("Nome do jogador 2:");
    scanf("%s",jogador2);
    printf("%s qual pokemon deseja escolher?\n",jogador1);

    printf("1 -");
    mostrarstatus(bulbasaur);
    printf("\n");
    printf("2 -");
    mostrarstatus(charmander);
    printf("\n");
    printf("3 -");
    mostrarstatus(squirtle);
    printf("\n");
    pk2 = ler_inteiro_seguro();

    if (pk2!=1 && pk2!=2 && pk2!=3) {
        while (pk2!=1 && pk2!=2 && pk2!=3) {
            printf("Opcao invalida.Tente novamente\n");
            pk2 = ler_inteiro_seguro();

            fflush(stdin);
        }
    }
    switch(pk2) {
        case 1:
            time1[0] = bulbasaur;
            break;
        case 2:
            time1[0] = charmander;
            break;
        case 3:
            time1[0] = squirtle;
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
    int escolha;
    printf("%s qual pokemon deseja escolher?\n",jogador2);
    printf("1 -");
    mostrarstatus(bulbasaur);
    printf("\n");
    printf("2 -");
    mostrarstatus(charmander);
    printf("\n");
    printf("3 -");
    mostrarstatus(squirtle);
    printf("\n");
    scanf("%d",&pk1);
    pk1 = ler_inteiro_seguro();

    if (pk1 != 1 && pk1 != 2 && pk1 != 3) {
        do {
            printf("Opcao invalida. Tente novamente\n");
            pk1 = ler_inteiro_seguro();
        } while (pk1 != 1 && pk1 != 2 && pk1 != 3);
    }

    switch(pk1) {
        case 1:
            time2[0] = bulbasaur;
            break;
        case 2:
            time2[0] = charmander;
            break;
        case 3:
            time2[0] = squirtle;
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }




    mostrarstatus(time1[atual1]);
    printf("\n");
    mostrarstatus(time2[atual2]);
    printf("\n");
    printf("====== BATALHA COMECOU ======");



    while (time1[atual1].hp > 0 && time2[atual2].hp > 0 ) {

        printf("\n========= RODADA %d =======\n",i);
        if (time1[atual1].velo > time2[atual2].velo) {
                printf(" %s, ",jogador1);
                printf("O que vai fazer?\n");
                printf("1 = Atacar\n");
                printf("2 = Mochila\n");
                printf("3 = Trocar de pokemon\n");
                printf("4 = Fugir\n");
                scanf("%d",&pk2);
                if (pk2!=1 && pk2!=2 && pk2!=3) {
                    while (pk2!=1 && pk2!=2 && pk2!=3) {
                        printf("Opcao invalida.Tente novamente\n");
                        scanf("%d",&pk2);
                        fflush(stdin);
                    }
                }
                switch (pk2) {

                    case 1:
                        atacar(&time1[atual1],&time2[atual2]);
                        printf("\n");
                        if (time2[atual2].hp <= 0){
                            time2[atual2].hp = 0;
                            printf("%s Venceu!",jogador1);
                            exit(0);
                }

                        break;
                    case 2:
                        Mochila(&time1[atual1],&mochila);
                        printf("\n");
                        break;

                    case 3:
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                          }

            int escolha2;
            printf("%s,",jogador2);
            printf(" O que vai fazer?\n");
            printf("1 = Atacar\n");
            printf("2 = Mochila\n");
            printf("3 = Trocar de pokemon\n");
            printf("4 = Fugir\n");
            scanf("%d",&escolha2);
            switch(escolha2) {

                    case 1:
                        atacar(&time2[atual2],&time1[atual1]);
                        printf("\n");
                        if (time1[atual1].hp <= 0){
                            time1[atual1].hp = 0;
                            printf("%s Venceu!",jogador2);
                            exit(0);
                        }
                        break;
                    case 2:
                        Mochila(&time2[atual2],&mochila);
                        printf("\n");
                        break;
                    default:
                        printf("opcao invalida\n");
                        break;


                }
                printf("\n");
                i++;
            }
        else if (time2[atual2].velo > time1[atual1].velo) {
                printf(" %s, ",jogador2);
                printf("O que vai fazer?\n");
                printf("1 = Atacar\n");
                printf("2 = Mochila\n");
                printf("3 = Trocar de pokemon\n");
                printf("4 = Fugir\n");
                scanf("%d",&pk2);
                if (pk2!=1 && pk2!=2 && pk2!=3) {
                    while (pk2!=1 && pk2!=2 && pk2!=3) {
                        printf("Opcao invalida.Tente novamente\n");
                        scanf("%d",&pk2);
                        fflush(stdin);
                    }
                }
                switch (pk2) {

                    case 1:
                        atacar(&time2[atual2],&time1[atual1]);
                        printf("\n");
                        if (time1[atual1].hp <= 0){
                            time1[atual1].hp = 0;
                            printf("%s Venceu!",jogador2);
                            exit(0);
                }
                        break;
                    case 2:
                        Mochila(&time2[atual2],&mochila);
                        printf("\n");
                        break;

                    case 3:
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                        return 0;  }
                if (time1[atual1].hp == 0 ) {
                    printf("%s Venceu!",jogador2);
                    exit (0);
                }
                int escolha2;
                printf("%s,",jogador1);
                printf(" O que vai fazer?\n");
                printf("1 = Atacar\n");
                printf("2 = Mochila\n");
                printf("3 = Trocar de pokemon\n");
                printf("4 = Fugir\n");
                scanf("%d",&escolha2);
                switch(escolha2) {

                    case 1:
                        atacar(&time1[atual1],&time2[atual2]);
                        printf("\n");
                        if (time2[atual2].hp <= 0){
                            time2[atual2].hp = 0;
                            printf("%s Venceu!",jogador1);
                            exit(0);

                        }
                        break;
                    case 2:
                        Mochila(&time1[atual1],&mochila);
                        printf("\n");
                        break;
                    default:
                        printf("opcao invalida\n");
                        break;


                }
                printf("\n");
                i++;
            }


        }



    return 0;
}