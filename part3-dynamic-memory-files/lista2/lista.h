/*
EXERCISE: Generic list
 */

#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>
#include <stdio.h>

typedef struct Solmu {
  void *data;
  struct Solmu *seur;
} Solmu;

typedef struct Lista {
  Solmu *paa;
  size_t dataKoko;
  void (*tulostaArvo)(FILE *virta, const void *arvo);
} Lista;

Solmu *s_luo(const void *data, size_t dataKoko, Solmu *seur);

Lista *ll_luo(size_t dataKoko,
              void (*tulostaArvo)(FILE *virta, const void *arvo));

void ll_tuhoa(Lista *lista);

Solmu *ll_lisaaEteen(Lista *lista, const void *data);
Solmu *ll_lisaaTaakse(Lista *lista, const void *data);

void ll_poistaEdesta(Lista *lista);
void ll_poista(Lista *lista, size_t i);

void ll_tulosta(const Lista *lista, FILE *virta);

#endif
