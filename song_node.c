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


/*
song_node * insert_inOrderLoop(struct song_node *front, struct song_node *n, char *nam, char *artis) {
  if (n && strcmp(n->artist,artis) < 0 && strcmp(n->name,nam) < 0) {
    printf("Looping %s\n", nam);
    return insert_inOrderLoop(front,n->next,nam,artis);
  }
  printf("Name of song after: %s\n",n->name);
  n = insert_front(n,nam,artis);
  printf("&\n"); print_list(n); printf("&\n\n");
  printf("&\n"); print_list(front); printf("&\n\n");
  
  return front;
}
*/

song_node * insert_inOrder(struct song_node *n, char *nam, char *artis) {
  //printf("PRELIST:\n"); print_list(n); printf("\n\n");
  
  struct song_node * temp = n;
  //printf("\ninserting SONG NAME:%s by %s\n",nam,artis);
  if (n == NULL) {
    n = insert_front(n,nam,artis);
    return n;
  }
  
  if (strcmp(n->artist,artis) > 0 || (strcmp(n->artist,artis) == 0 && strcmp(n->name,nam) > 0)) {
    printf("current locationee: %s\n",temp->name);
    n = insert_front(n,nam,artis);
    printf("&\n"); print_list(n); printf("&\n\n");
    return n;
  }
  
  while (temp->next && strcmp(n->artist,artis) < 0) {
    temp = temp->next;
  }
  if (strcmp(n->artist,artis) <= 0) {
    while (temp->next && strcmp(n->name,nam) < 0) {
      temp = temp->next;
    }
  }
  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node*));
  strcpy(new->artist,artis);
  strcpy(new->name,nam);
  //printf("current location: %s\n",temp->name);
    
  if (temp->next) {
    new->next = temp->next->next;
    temp->next->next = new;
  }
  else {
    new->next = temp->next;
    temp->next = new;
  }
  
  //printf("&\n"); print_list(n); printf("&\n\n");
  return n;
}

/*
temp = n;
loop through temp
new->next = temp->next
temp->next = new

This stores the info

 */


/*song_node * insert_inOrder(struct song_node *n, char *nam, char *artis) {

  printf("\n%s\n",nam);
  
  if (n == NULL) {
    n = insert_front(n,nam,artis);
    return n;
  }

  
  
  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node*));

  printf("\n%s %s %s %s\n",n->artist,artis,n->name,nam);
  
  strcpy(new->name,nam);  //after this statement n->artist changed
  strcpy(new->artist,artis);  

  printf("\n%s %s %s %s\n",n->artist,artis,n->name,nam);
  
  if (strcmp(n->artist,artis) > 0 || (strcmp(n->artist,artis) == 0 && strcmp(n->name,nam) > 0)) {
    printf("\nOOOOO: %s\n",nam);
    new->next = n;
    return new;
  }  
  
  struct song_node *temp = n;

  //While the new artist is after the current artist and the next artist isn't equal to new artist
  while (temp->next && strcmp(temp->artist,artis) < 0 && strcmp(temp->next->artist,artis) != 0) {
    //printf("%s >> ",temp->name);
    temp = temp->next;
  }

  //If the next artist is equal to the new artist
  //while the new name is after the next name
  while (temp->next && strcmp(temp->next->name,nam) < 0 && strcmp(temp->next->artist,artis) == 0) {
    //printf("%s >>> ",temp->name);
    temp = temp->next;
  }

  printf("\n%s\n",nam);
  printf("\n%s and current temp: %lu\n",nam,temp);

  new->next = temp->next;
  temp->next = new;

  //printf("\n***********************\n");
  //print_list(n);
  //printf("\n***********************\n");
  
  return n;
}*/

song_node * find_by_songName(struct song_node *n, char *nam) {
  /*
  int i;
  for(i = 0; nam[i]; i++){
    nam[i] = tolower(nam[i]);
  }*/
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
  
  while (l->next && !(strcmp(l->next->artist,artis) == 0) && !(strcmp(l->next->name,nam) == 0)) {
    l = l->next;
  }

  song_node *removed = l->next;
  
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
