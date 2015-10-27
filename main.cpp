//
//  main.cpp
//  Automata_Simulator_V0.1
//
//  Created by Ayrton Cavalieri on 9/6/14.
//  Copyright (c) 2014 AyrtonC. All rights reserved.
//

#include <iostream>
#include "Automata.h"

using namespace std;

Automata escreveEstados(Automata aut, unsigned int tam){
    unsigned int dest;
    char carac, info;
    bool inicial, final, iniciou = false;
    for(unsigned int i = 0; i < tam; i++){
        final = false;
        inicial = false;
        cout << "Informações do estado " << i+1 << ":" << endl;
        if(iniciou == false){
            cout << "É inicial? (S - Sim)" << endl;
            cin >> info;
            if(info == 's' || info == 'S'){
                inicial = true;
                iniciou = true;
            }else{
                inicial = false;
            }
        }
        cout << "É final? (S - Sim)" << endl;
        cin >> info;
        if(info == 's' || info == 'S'){
            final = true;
        }
        cout << "Deseja inserir transições?" << endl;
        cin >> info;
        if(info == 's' || info == 'S'){
            do{
                cout << "Digite o caracter de transição:" << endl;
                cin >> carac;
                cout << "Digite o estado de destino:" << endl;
                cin >> dest;
                dest--;
                aut = insereTransicao(aut, i, carac, dest, final, inicial);
                cout << "Deseja continuar inserindo transições?" << endl;
                cin >> info;
            }while(info != 'n' && info != 'N');
        }else{
            aut = insereTransicao(aut, i, -1, 0, final, inicial);
        }
    }
    return aut;
}

int main(int argc, const char * argv[]){
    Automata aut;
    unsigned int tam;
    string cadeia;
    cout << "Digite a quantidade de estados:" << endl;
    cin >> tam;
    aut = inicializaAutomata(tam);
    if(automataInicializado(aut) == false){
        cout << "Erro ao inicializar automata!\n";
        return -1;
    }
    aut = escreveEstados(aut, tam);
    do{
        cout << "Digite a cadeia para teste:" << endl;
        cin >> cadeia;
        if(cadeia == "clear")
            system("clear");
        if(cadeia != "exit" && cadeia != "clear"){
            testaCadeia(aut, cadeia.c_str(), tam) == true ? cout << "Cadeia reconhecida!\n" : cout << "Cadeia inválida!\n";
        }
    }while(cadeia != "exit");
    aut = destroiAutomata(aut, tam);
    return 0;
}
