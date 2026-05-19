/*
EXERCISE: Multi-insert into a list
Implement a linked list in C.
The linked list should support the following operations:
- Create a new list.
- Add an element to the front of the list.
- Add an element to the end of the list.
- Remove an element from the front of the list.
- Remove an element from a specific position in the list.
- Print the elements of the list.
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
  size_t n;
  void (*tulostaArvo)(FILE *virta, const void *arvo);
} Lista;

Solmu *s_luo(const void *data, size_t dataKoko, Solmu *seur);
void s_tuhoa(Solmu *s);

Lista *ll_luo(size_t dataKoko, void (*tulosta)(FILE *virta, const void *arvo));
void ll_tuhoa(Lista *lista);

Solmu *ll_lisaa(Lista *lista, size_t i, const void *arvo);
Solmu *ll_lisaaEteen(Lista *lista, const void *arvo);
Solmu *ll_moniLisaa(Lista *lista, size_t i, const void *arvo, ...);

void ll_poista(Lista *lista, size_t i);
void ll_tulosta(const Lista *lista, FILE *virta);
Solmu *ll_lisaaTaakse(Lista *lista, const void *arvo);

#endif
