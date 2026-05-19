#include "lista.h"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/* Helper function to create a new node with the given data and next pointer. */
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

/* Helper function to free the memory allocated for a node. */
void s_tuhoa(Solmu *s) {
  if (s != NULL) {
    free(s->data);
    free(s);
  }
}

/* Helper function to free the memory allocated for a chain of nodes. */
static void s_tuhoaKetju(Solmu *s) {
  Solmu *seur;

  while (s != NULL) {
    seur = s->seur;
    s_tuhoa(s);
    s = seur;
  }
}

/* Function to create a new list with the given data size and print function. */
Lista *ll_luo(size_t dataKoko, void (*tulosta)(FILE *virta, const void *arvo)) {
  Lista *lista;

  lista = malloc(sizeof(Lista));
  if (lista == NULL) {
    return NULL;
  }

  lista->paa = NULL;
  lista->dataKoko = dataKoko;
  lista->n = 0;
  lista->tulostaArvo = tulosta;

  return lista;
}

/* Function to free the memory allocated for a list and its nodes. */
void ll_tuhoa(Lista *lista) {
  if (lista != NULL) {
    s_tuhoaKetju(lista->paa);
    free(lista);
  }
}

/* Function to insert a new node with the given value at the specified index in
 * the list. */
Solmu *ll_lisaa(Lista *lista, size_t i, const void *arvo) {
  return ll_moniLisaa(lista, i, arvo, NULL);
}

/* Function to insert a new node with the given value at the front of the list.
 */
Solmu *ll_lisaaEteen(Lista *lista, const void *arvo) {
  return ll_lisaa(lista, 0, arvo);
}

/* Function to insert a new node with the given value at the end of the list. */
Solmu *ll_moniLisaa(Lista *lista, size_t i, const void *arvo, ...) {
  va_list ap;
  Solmu *edellinen;
  Solmu *seuraava;
  Solmu *uusi;
  Solmu *eka;
  Solmu *vika;
  const void *nykyinen;
  size_t j;
  size_t lisatty;

  if (lista == NULL || arvo == NULL || i > lista->n) {
    return NULL;
  }

  edellinen = NULL;
  seuraava = lista->paa;

  for (j = 0; j < i; ++j) {
    edellinen = seuraava;
    seuraava = seuraava->seur;
  }

  eka = NULL;
  vika = NULL;
  lisatty = 0;

  nykyinen = arvo;

  va_start(ap, arvo);

  while (nykyinen != NULL) {
    uusi = s_luo(nykyinen, lista->dataKoko, NULL);

    if (uusi == NULL) {
      va_end(ap);
      s_tuhoaKetju(eka);
      return NULL;
    }

    if (eka == NULL) {
      eka = uusi;
    } else {
      vika->seur = uusi;
    }

    vika = uusi;
    ++lisatty;

    nykyinen = va_arg(ap, const void *);
  }

  va_end(ap);

  vika->seur = seuraava;

  if (edellinen == NULL) {
    lista->paa = eka;
  } else {
    edellinen->seur = eka;
  }

  lista->n += lisatty;

  return eka;
}

/* Function to remove the node at the specified index from the list. */
void ll_poista(Lista *lista, size_t i) {
  Solmu *poistettava;
  Solmu *edellinen;
  size_t j;

  if (lista == NULL || i >= lista->n) {
    return;
  }

  if (i == 0) {
    poistettava = lista->paa;
    lista->paa = poistettava->seur;
  } else {
    edellinen = lista->paa;

    for (j = 0; j < i - 1; ++j) {
      edellinen = edellinen->seur;
    }

    poistettava = edellinen->seur;
    edellinen->seur = poistettava->seur;
  }

  s_tuhoa(poistettava);
  --lista->n;
}

/* Function to print the elements of the list using the provided print function.
 */
void ll_tulosta(const Lista *lista, FILE *virta) {
  Solmu *s;

  fprintf(virta, "Lista:");

  if (lista != NULL) {
    s = lista->paa;

    while (s != NULL) {
      fprintf(virta, " ");
      lista->tulostaArvo(virta, s->data);
      s = s->seur;
    }
  }

  fprintf(virta, "\n");
}

/* Function to insert a new node with the given value at the end of the list. */
Solmu *ll_lisaaTaakse(Lista *lista, const void *arvo) {
  if (lista == NULL) {
    return NULL;
  }

  return ll_lisaa(lista, lista->n, arvo);
}
