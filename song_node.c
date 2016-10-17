#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "song_node.h"


void print_list(struct song_node *n) {
  while (n) {
    printf("%s by %s\n", n->name, n->artist);
    n = n->next;
  }
}

song_node * insert_front(struct song_node *n, char *nam, char *artis) {
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  
  new->next = n;
  strcpy(new->name,nam);
  strcpy(new->artist,artis);

  return new;
}


song_node * insert_inOrder(struct song_node *n, char *nam, char *artis) {
  //printf("PRELIST:\n"); print_list(n); printf("\n\n");
  
  struct song_node * temp = n;
  //printf("\ninserting SONG NAME:%s by %s\n",nam,artis);
  if (n == NULL) {
    n = insert_front(n,nam,artis);
    printf("added %s\n",nam);
    return n;
  }
  
  if (strcmp(n->artist,artis) > 0 || (strcmp(n->artist,artis) == 0 && strcmp(n->name,nam) > 0)) {
    //printf("current locationee: %s\n",temp->name);
    n = insert_front(n,nam,artis);
    //printf("&\n"); print_list(n); printf("&\n\n");
    //printf("added %s\n",nam);
    return n;
  }

  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node*));
  strcpy(new->artist,artis);
  strcpy(new->name,nam);
  
  while (temp->next && strcmp(n->artist,artis) < 0 && strcmp(temp->next->artist,artis) < 0) {
    //printf("move type 1: %s and %s\n",temp->artist,temp->next->artist);
    temp = temp->next;
  }
  if (strcmp(n->artist,artis) <= 0) {
    while (temp->next && strcmp(temp->name,nam) < 0  && strcmp(temp->next->name,nam) < 0 && strcmp(temp->next->artist,artis) <= 0) {
      //printf("move type 2: %s and %s\n",temp->name,temp->next->name);
      temp = temp->next;
    }
  }
    
  if (temp != NULL) {
    //printf("not null");
    new->next = temp->next;
    temp->next = new;
  }
  else {
    temp->next = new;
  }
  //printf("added %s\n",nam);
  return n;
}

song_node * find_by_songName(struct song_node *n, char *nam) {
  struct song_node *l = n;
  while (l && !(strcmp(l->name,nam) == 0)) {
    l = l->next;
  }
  if (l == NULL) {
    return NULL;
  }
  return l;
}

song_node * find_by_artistName(struct song_node *n, char *artis) {

  struct song_node *l = n;
  while (l && !(strcmp(l->artist,artis) == 0)) {
    l = l->next;
  }
  if (l == NULL) {
    return NULL;
  }
  return l;
}

song_node * random_Song(struct song_node *n) {
  if (n == NULL) {
    return;
  }
  srand(time(NULL));
  int s = rand();
  
  struct song_node *r = n;
  struct song_node *place = n->next;
  int a = 2;
  while (place) {
    if (s % a == 0) {
      r = place;
    }
    place = place->next;
    a += 2;
  }
  return r;
}


song_node * removeSong(struct song_node *n, char *nam, char *artis) {

  song_node *l = n;

  if (strcmp(l->name,nam) == 0 && strcmp(l->artist,artis) == 0) {
    struct song_node *r = l;
    l = l->next;
    return r;
  }
  
  while (l->next && (strcmp(l->next->artist,artis) != 0 || strcmp(l->next->name,nam) != 0)) {
    l = l->next;
  }

  struct song_node *removed = l->next;
  
  if (l->next == NULL) {
    return NULL;
  }

  l->next = l->next->next;
  return removed;
}


song_node * free_list( struct song_node *n ) {
  
  struct song_node *f = n;
  
  while (f) {
    n = n->next;
    printf("freeing song_node: %s by %s\n",f->name,f->artist);
    free(f);
    f = n;
  }
  return n; 
}
