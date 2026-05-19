#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

DblSolmu *ds_luo(double data, DblSolmu *seur) {
  DblSolmu *uusi;

  uusi = malloc(sizeof(DblSolmu));
  if (uusi == NULL) {
    return NULL;
  }

  uusi->data = data;
  uusi->seur = seur;

  return uusi;
}

DblLista *dl_luo(void) {
  DblLista *lista;

  lista = malloc(sizeof(DblLista));
  if (lista == NULL) {
    return NULL;
  }

  lista->paa = NULL;
  lista->n = 0;

  return lista;
}

void dl_tuhoa(DblLista *lista) {
  DblSolmu *s;
  DblSolmu *seuraava;

  if (lista == NULL) {
    return;
  }

  s = lista->paa;

  while (s != NULL) {
    seuraava = s->seur;
    free(s);
    s = seuraava;
  }

  free(lista);
}

DblSolmu *dl_lisaaEteen(DblLista *lista, double arvo) {
  DblSolmu *uusi;

  if (lista == NULL) {
    return NULL;
  }

  uusi = ds_luo(arvo, lista->paa);
  if (uusi == NULL) {
    return NULL;
  }

  lista->paa = uusi;
  lista->n++;

  return uusi;
}

double dl_poistaEdesta(DblLista *lista) {
  DblSolmu *poistettava;
  double arvo;

  if (lista == NULL || lista->paa == NULL) {
    return 0;
  }

  poistettava = lista->paa;
  arvo = poistettava->data;

  lista->paa = poistettava->seur;
  free(poistettava);

  lista->n--;

  return arvo;
}

void dl_tulosta(const DblLista *lista) {
  DblSolmu *s;

  if (lista == NULL) {
    return;
  }

  s = lista->paa;

  printf("Lista:");
  while (s != NULL) {
    printf(" %.1f", s->data);
    s = s->seur;
  }

  printf("\n");
}

double dl_alkio(const DblLista *lista, size_t i) {
  DblSolmu *s;
  size_t k;

  if (lista == NULL || i >= lista->n) {
    return 0;
  }

  s = lista->paa;
  k = 0;

  while (k < i) {
    s = s->seur;
    k++;
  }

  return s->data;
}

DblSolmu *dl_lisaa(DblLista *lista, size_t i, double arvo) {
  DblSolmu *uusi;
  DblSolmu *s;
  DblSolmu *e;
  size_t k;

  if (lista == NULL) {
    return NULL;
  }

  e = NULL;
  s = lista->paa;
  k = 0;

  while (s != NULL && k < i) {
    e = s;
    s = s->seur;
    k++;
  }

  uusi = ds_luo(arvo, s);
  if (uusi == NULL) {
    return NULL;
  }

  if (e == NULL) {
    lista->paa = uusi;
  } else {
    e->seur = uusi;
  }

  lista->n++;

  return uusi;
}

double dl_poista(DblLista *lista, size_t i) {
  DblSolmu *s;
  DblSolmu *e;
  double arvo;
  size_t k;

  if (lista == NULL || i >= lista->n) {
    return 0;
  }

  e = NULL;
  s = lista->paa;
  k = 0;

  while (k < i) {
    e = s;
    s = s->seur;
    k++;
  }

  arvo = s->data;

  if (e == NULL) {
    lista->paa = s->seur;
  } else {
    e->seur = s->seur;
  }

  free(s);
  lista->n--;

  return arvo;
}
