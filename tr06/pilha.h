#ifndef PILHA_H
#define PILHA_H

typedef float TipoDado; 

typedef struct Cell 
{ 
    TipoDado dado; 
    struct Cell *seguinte; 
} TipoCelula; 

typedef TipoCelula* Pilha; 

Pilha Inicializar();
int PilhaVazia(Pilha P);
int PilhaCheia(Pilha P);
int TopoPilha(Pilha P, TipoDado *pelem);
void Empilhar(Pilha* pP, TipoDado elem);
int Desempilhar(Pilha *pP, TipoDado *pelem);
void Destruir(Pilha *pP);
void Esvaziar(Pilha *pP);
void ImprimirPilha(Pilha P);

#endif
