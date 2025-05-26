#include <stdio.h>
#include <stdlib.h>
#include "struct.h"



float Efetivididade(int tipoAtaque, int tipoDefensor) {
    // tipos 1 = normal,2 = Eletrico,3 = Planta,4 = Venenoso,5 - Fogo, 6 - Metal,7-Agua
    // 2 tipos 34 = Planta e venenoso
    float valor_dano;
    if (tipoAtaque == 2 && tipoDefensor == 7) {
        valor_dano=2;
    }
    else if (tipoAtaque == 5 && tipoDefensor == 34) {
        valor_dano=2;
    }
    else if (tipoAtaque == 3 && tipoDefensor == 7) {
        valor_dano=2;
    }
    else if (tipoAtaque == 5 && tipoDefensor == 3) {
        valor_dano=2;
    }
    else if (tipoAtaque == 7 && tipoDefensor == 5) {
        valor_dano=2;
    }
    else if (tipoAtaque == 3 && tipoDefensor == 5) {
        valor_dano=0.5;
    }
    else if (tipoAtaque == 5 && tipoDefensor == 7) {
        valor_dano=0.5;
    }
    else if (tipoAtaque == 7 && tipoDefensor == 3) {
        valor_dano=0.5;
    }
    else {
        valor_dano = 1;
    }

    return valor_dano;
}


void Mochila(Pokemon *atacante,Bag *mochila) {
    int use;
    if (mochila->curar.qtd <= 0) {
        printf("Voce nao tem potion");
        return;

    }
    printf("O que deseseja usar?\n");
    printf("1 = Potion\n");
    scanf("%d",&use);
    switch(use) {
        case 1:
            if (atacante->hp == atacante->hp_max) {
                printf("%s ja esta com o HP cheio",atacante->nome);
            }
            else {
                int recupera = mochila->curar.recuperar;
                if (atacante->hp + recupera > atacante->hp_max) {
                    recupera = atacante->hp_max - atacante->hp;
                }
                atacante->hp += recupera;
                mochila->curar.qtd --;
                printf("%s recuperou %d de HP com a potion e ficou com %d de HP",atacante->nome,recupera,atacante->hp);
            }
            break;
        default:
            printf("Invalido\n");
            break;

    }


}



void atacar(Pokemon *atacante,Pokemon *defensor) {
    int op;
    float valor_dano;
    printf("%s\n",atacante->nome);
    printf("Escolha seu ataque:\n");
    printf("1 = %s\n",atacante->ataque1.nome);
    printf("2 = %s\n",atacante->ataque2.nome);
    printf("3 = %s\n",atacante->ataque3.nome);
    printf("4 = %s\n",atacante->ataque4.nome);
    scanf("%d",&op);
    switch (op) {
        case 1:
            valor_dano=Efetivididade(atacante->ataque1.tipo,defensor->tipo_num);
            float dano_aplicado = atacante->ataque1.dano*valor_dano;
            if (valor_dano > 1.9 && valor_dano < 2.1) {
                valor_dano = 2;
                printf("%s atacou %s com %s e foi super efetivo e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque1.nome,dano_aplicado);
            }
            else if (valor_dano > 0.4 && valor_dano < 0.6) {
                valor_dano = 0.5;
                printf("%s atacou %s com %s e nao foi muito efetivo e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque1.nome,dano_aplicado);
            }
            else {
                printf("%s atacou %s com %s e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque1.nome,dano_aplicado);
            }
            defensor->hp -= dano_aplicado;
            if (defensor->hp < 0) {
                defensor->hp = 0;
            }

            printf("%s ficou com %d de HP.\n",defensor->nome,defensor->hp);
            dano_aplicado/=valor_dano;
            break;

        case 2:
            valor_dano=Efetivididade(atacante->ataque2.tipo,defensor->tipo_num);
            dano_aplicado = atacante->ataque2.dano*valor_dano;
            if (valor_dano > 1.9 && valor_dano < 2.1) {
                valor_dano = 2;
                printf("%s atacou %s com %s e foi super efetivo e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque2.nome,dano_aplicado);
            }
            else if (valor_dano > 0.4 && valor_dano < 0.6) {
                valor_dano = 0.5;
                printf("%s atacou %s com %s e nao foi muito efetivo e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque2.nome,dano_aplicado);
            }
            else {
                printf("%s atacou %s com %s e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque2.nome,dano_aplicado);
            }
            defensor->hp -= dano_aplicado;
            if (defensor->hp < 0) {
                defensor->hp = 0;
            }

            printf("%s ficou com %d de HP.\n",defensor->nome,defensor->hp);
            dano_aplicado/=valor_dano;
            break;

        case 3:
            valor_dano=Efetivididade(atacante->ataque3.tipo,defensor->tipo_num);
            dano_aplicado = atacante->ataque3.dano*valor_dano;
            atacante->ataque3.dano -= defensor->defesa;
            if (valor_dano > 1.9 && valor_dano < 2.1) {
                valor_dano = 2;
                printf("%s atacou %s com %s e foi super efetivo e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque3.nome,dano_aplicado);
            }
            else if (valor_dano > 0.4 && valor_dano < 0.6) {
                valor_dano = 0.5;
                printf("%s atacou %s com %s e nao foi muito efetivo e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque3.nome,dano_aplicado);
            }
            else {
                printf("%s atacou %s com %s e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque3.nome,dano_aplicado);
            }
            defensor->hp -= dano_aplicado;
            if (defensor->hp < 0) {
                defensor->hp = 0;
            }

            printf("%s ficou com %d de HP.\n",defensor->nome,defensor->hp);
            dano_aplicado/=valor_dano;
            break;
        case 4:
            valor_dano=Efetivididade(atacante->ataque4.tipo,defensor->tipo_num);
            dano_aplicado = atacante->ataque4.dano*valor_dano;
            if (valor_dano > 1.9 && valor_dano < 2.1) {
                valor_dano = 2;
                printf("%s atacou %s com %s e foi super efetivo e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque4.nome,dano_aplicado);

            }
            else if (valor_dano > 0.4 && valor_dano < 0.6) {
                valor_dano = 0.5;
                printf("%s atacou %s com %s e nao foi muito efetivo e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque4.nome,dano_aplicado);

            }
            else {
                printf("%s atacou %s com %s e causou %.1f de dano.\n",atacante->nome,defensor->nome,atacante->ataque4.nome,dano_aplicado);

            }
            defensor->hp -= dano_aplicado;
            if (defensor->hp < 0) {
                defensor->hp = 0;
            }

            printf("%s ficou com %d de HP.\n",defensor->nome,defensor->hp);
            dano_aplicado/=valor_dano;
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }

}
void mostrarstatus(Pokemon p) {
    printf("Nome: %s || Nivel:%d || HP:%d || Tipo:%s || Velocidade %d",p.nome,p.nivel,p.hp,p.tipo,p.velo);
    printf("\n");
}
#include <ctype.h> // Para isdigit
// Verifica se a string contém apenas dígitos

#include <string.h>
int somente_digitos(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit((unsigned char)str[i])) return 0;
    }
    return 1;
}

int ler_inteiro_seguro() {
    char buffer[100];
    int numero;

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0; // Remove '\n'

            if (somente_digitos(buffer)) {
                numero = atoi(buffer);

                if (numero == 1 || numero == 2 || numero == 3) {
                    return numero;
                }
            } else {
                printf("Entrada invalida. Digite apenas numeros inteiros (1, 2 ou 3).\n");
            }
        }
    }
}

