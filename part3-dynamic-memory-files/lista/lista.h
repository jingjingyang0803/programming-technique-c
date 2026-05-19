/*
EXERCISE: Double list
*/

#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>

typedef struct dblsolmu {
  double data;
  struct dblsolmu *seur;
} DblSolmu;

typedef struct {
  DblSolmu *paa;
  size_t n;
} DblLista;

DblSolmu *ds_luo(double data, DblSolmu *seur);

DblLista *dl_luo(void);
void dl_tuhoa(DblLista *lista);

DblSolmu *dl_lisaaEteen(DblLista *lista, double arvo);
double dl_poistaEdesta(DblLista *lista);
void dl_tulosta(const DblLista *lista);

double dl_alkio(const DblLista *lista, size_t i);
DblSolmu *dl_lisaa(DblLista *lista, size_t i, double arvo);
double dl_poista(DblLista *lista, size_t i);

#endif
