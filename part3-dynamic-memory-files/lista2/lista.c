#include "lista.h"

#include <stdlib.h>

Solmu *s_luo(const void *data, size_t dataKoko, Solmu *seur) {
  Solmu *s;

  if (data == NULL) {
    return NULL;
  }

  s = malloc(sizeof(Solmu));
  if (s == NULL) {
    return NULL;
  }

  s->data = malloc(dataKoko);
  if (s->data == NULL) {
    free(s);
    return NULL;
  }

  memcpy(s->data, data, dataKoko);
  s->seur = seur;

  return s;
}

Lista *ll_luo(size_t dataKoko,
              void (*tulostaArvo)(FILE *virta, const void *arvo)) {
  Lista *lista;

  lista = malloc(sizeof(Lista));
  if (lista == NULL) {
    return NULL;
  }

  lista->paa = NULL;
  lista->dataKoko = dataKoko;
  lista->tulostaArvo = tulostaArvo;

  return lista;
}

void ll_tuhoa(Lista *lista) {
  if (lista == NULL) {
    return;
  }

  while (lista->paa != NULL) {
    ll_poistaEdesta(lista);
  }

  free(lista);
}

Solmu *ll_lisaaEteen(Lista *lista, const void *data) {
  Solmu *uusi;

  if (lista == NULL || data == NULL) {
    return NULL;
  }

  uusi = s_luo(data, lista->dataKoko, lista->paa);
  if (uusi == NULL) {
    return NULL;
  }

  lista->paa = uusi;

  return uusi;
}

Solmu *ll_lisaaTaakse(Lista *lista, const void *data) {
  Solmu *uusi;
  Solmu *s;

  if (lista == NULL || data == NULL) {
    return NULL;
  }

  uusi = s_luo(data, lista->dataKoko, NULL);
  if (uusi == NULL) {
    return NULL;
  }

  if (lista->paa == NULL) {
    lista->paa = uusi;
    return uusi;
  }

  s = lista->paa;
  while (s->seur != NULL) {
    s = s->seur;
  }

  s->seur = uusi;

  return uusi;
}

void ll_poistaEdesta(Lista *lista) {
  Solmu *s;

  if (lista == NULL || lista->paa == NULL) {
    return;
  }

  s = lista->paa;
  lista->paa = s->seur;

  free(s->data);
  free(s);
}

void ll_poista(Lista *lista, size_t i) {
  Solmu *edellinen;
  Solmu *s;
  size_t kohta;

  if (lista == NULL || lista->paa == NULL) {
    return;
  }

  if (i == 0) {
    ll_poistaEdesta(lista);
    return;
  }

  edellinen = lista->paa;
  s = lista->paa->seur;
  kohta = 1;

  while (s != NULL && kohta < i) {
    edellinen = s;
    s = s->seur;
    kohta++;
  }

  if (s == NULL) {
    return;
  }

  edellinen->seur = s->seur;

  free(s->data);
  free(s);
}

void ll_tulosta(const Lista *lista, FILE *virta) {
  const Solmu *s;

  if (lista == NULL || virta == NULL || lista->tulostaArvo == NULL) {
    return;
  }

  fprintf(virta, "Lista:");
  s = lista->paa;
  while (s != NULL) {
    fprintf(virta, " ");
    lista->tulostaArvo(virta, s->data);
    s = s->seur;
  }
  fprintf(virta, "\n");
}
