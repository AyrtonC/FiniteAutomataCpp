//
//  Automata.h
//  Automata_Simulator_V0.1
//
//  Created by Ayrton Cavalieri on 9/6/14.
//  Copyright (c) 2014 AyrtonC. All rights reserved.
//

#ifndef Automata_Simulator_V0_1_Automata_h
#define Automata_Simulator_V0_1_Automata_h

#include <stdlib.h>

typedef struct lista** Automata;

Automata inicializaAutomata(unsigned int tam);
Automata destroiAutomata(Automata automata, unsigned int tam);
bool automataInicializado(Automata aut);

bool testaCadeia(Automata ests, const char *str, unsigned int tam);

Automata insereTransicao(Automata ests, unsigned int estado, char caracter, unsigned int destino, bool final, bool inicial);

#endif
