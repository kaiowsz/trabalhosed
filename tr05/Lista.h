#ifndef LISTA_H
#define LISTA_H

typedef float TipoDado; 

typedef struct Cell { 
    TipoDado dado; 
    struct Cell * seguinte;
} TipoCelula; 

TipoCelula* InsFimL(TipoCelula* L, TipoDado dado);
TipoCelula* CriacaolistaInvertida(void);
void ImprimeL(TipoCelula* L);
void ImpDado(TipoDado dado);
TipoDado LeituraDado(void);

TipoCelula* RemocaoDadoL(TipoCelula* L, TipoDado dado);

#endif