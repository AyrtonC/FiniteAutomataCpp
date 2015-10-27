//
//  Automata.cpp
//  Automata_Simulator_V0.1
//
//  Created by Ayrton Cavalieri on 9/6/14.
//  Copyright (c) 2014 AyrtonC. All rights reserved.
//

#include "Automata.h"

struct lista{
    char caracter;
    unsigned int destino;
    bool final;
    bool inicial;
    struct lista *prox;
};

struct lista** inicializaAutomata(unsigned int tam){
    struct lista **automata;
    unsigned int i;
    automata = (struct lista**)malloc(tam * sizeof(struct lista*));
    for(i = 0; i < tam; i++)
        automata[i] = NULL;
    return automata;
}

struct lista** destroiAutomata(struct lista **automata, unsigned int tam){
    unsigned int i;
    struct lista *p, *t;
    for(i = 0; i < tam; i++){
        if(automata[i] != NULL){
            p = automata[i];
            while(p != NULL){
                t = p->prox;
                free(p);
                p = t;
            }
            automata[i] = NULL;
        }
    }
    free(automata);
    return NULL;
}

bool automataInicializado(struct lista **aut){
    if(aut == NULL)
        return false;
    else
        return true;
}

void testa(struct lista **ests, const char *str, unsigned int pos, bool &exito){
    struct lista *p;
    if(str[0] == '\0'){
        for(p = ests[pos]; p != NULL; p = p->prox)
            if(p->caracter == '?')
                testa(ests, str, p->destino, exito);
        if(ests[pos]->final == true)
            exito = true;
    }else{
        for(p = ests[pos]; p != NULL && exito != true; p = p->prox){
            if(p->caracter == '?') //Vale o mesmo que épsilon.
                testa(ests, str, p->destino, exito);
            else if(str[0] == p->caracter)
                testa(ests, &str[1], p->destino, exito);
        }
    }
}

bool testaCadeia(struct lista **ests, const char *str, unsigned int tam){
    bool exito = false;
    unsigned int i;
    for(i = 0; i < tam; i++){
        if(ests[i]->inicial == true){
            testa(ests, str, i, exito);
            break;
        }
    }
    return exito;
}

struct lista* insereLista(struct lista *l, char caracter, unsigned int destino, bool final, bool inicial){
    if(l == NULL){
        l = (struct lista*)malloc(sizeof(struct lista));
        l->prox = NULL;
        l->caracter = caracter;
        l->destino = destino;
        l->final = final;
        l->inicial = inicial;
    }else{
        struct lista *novo = (struct lista*)malloc(sizeof(struct lista));
        novo->caracter = caracter;
        novo->destino = destino;
        novo->final = final;
        novo->inicial = inicial;
        novo->prox = l;
        l = novo;
    }
    return l;
}

struct lista** insereTransicao(struct lista **ests, unsigned int estado, char caracter, unsigned int destino, bool final, bool inicial){
    ests[estado] = insereLista(ests[estado], caracter, destino, final, inicial);
    return ests;
}
