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

song_node * insert_front(struct song_node *n, char nam[], char artis[]) {
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  /*
  int i;
  for(i = 0; nam[i]; i++){
    nam[i] = tolower(nam[i]);
  }
  for(i = 0; artis[i]; i++){
    artis[i] = tolower(artis[i]);
    }*/
  
  new->next = n;
  strcpy(new->name,nam);
  strcpy(new->artist,artis);

  return new;
}

song_node * insert_inOrder(struct song_node *n, char nam[], char artis[]) {
  /*
  int i;
  for(i = 0; nam[i]; i++){
    nam[i] = tolower(nam[i]);
  }
  for(i = 0; artis[i]; i++){
    artis[i] = tolower(artis[i]);
  }*/
  
  if (n == NULL) {
    n = insert_front(n,nam,artis);
    return n;
  }

  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node*));
  
  strcpy(new->name,nam);
  strcpy(new->artist,artis);  
  
  if (strcmp(n->artist,artis) > 0 || (strcmp(n->artist,artis) == 0 && strcmp(n->name,nam) > 0)) {
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

  new->next = temp->next;
  temp->next = new;
  
  return n;
}

song_node * find_by_songName(struct song_node *n, char nam[]) {
  /*
  int i;
  for(i = 0; nam[i]; i++){
    nam[i] = tolower(nam[i]);
  }*/
  
  while (!(strcmp(n->name,nam) == 0)) {
    n = n->next;
  }
  return n;
}

song_node * find_by_artistName(struct song_node *n, char artis[]) {
  /*
  int i;
  for(i = 0; artis[i]; i++){
    artis[i] = tolower(artis[i]);
  }*/
  
  while (!(strcmp(n->artist,artis) == 0)) {
    n = n->next;
  }
  return n;
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

/*
song_node * removeSong(struct song_node *n, char nam[]) {

  int i;
  for(i = 0; nam[i]; i++){
    nam[i] = tolower(nam[i]);
  }

  struct song_node *songLocation = find_by_songName(n,nam);
  songLocation->name = (char*)(songLocation->next->name);
  songLocation->artist = songLocation->next->artist;
  songLocation->next = songLocation->next->next;
  return n;
}
*/

struct song_node * free_list( struct song_node *n ) {

  struct song_node *f = n;
  while ( n ) {
    n = n->next;
    printf("freeing song_node: %d\n", f->name);
    free(f);
    f = n;    
  }
  return n;
}

int main() {
  song_node * songs = 0;
  print_list(songs);

  /*
  songs = insert_front(songs,"Song1","Artist1");
  songs = insert_front(songs,"Song2","Artist2");
  songs = insert_front(songs,"Song3","Artist3");
  */

  songs = insert_inOrder(songs,"Song1","Artist1");
  songs = insert_inOrder(songs,"Tong1","Arsis");

  print_list(songs);
  printf("\n---------------\n");
  
  songs = insert_inOrder(songs,"Song2","Artist2");


  print_list(songs);
  printf("\n--------------\n");
  
  songs = insert_inOrder(songs,"Song3","Artist3");

  print_list(songs);
  printf("\n--------------\n");

  songs = insert_inOrder(songs,"Yello","Artist2");
  songs = insert_inOrder(songs,"Wello","Artist2");

  print_list(songs);
  printf("\n--------------\n");
  
  songs = insert_inOrder(songs,"Allo","Artist2");

  print_list(songs);
  printf("\n--------------\n");
  
  songs = insert_inOrder(songs,"Xello","Artist2");

  print_list(songs);
  printf("\n--------------\n");
  
  songs = insert_inOrder(songs,"Twine","Artist2");

  print_list(songs);
  printf("\n--------------\n");
  
  songs = insert_inOrder(songs,"Zimmy","Artist3");

  print_list(songs);
  printf("\n--------------\n");

  printf("Random: %s",(random_Song(songs))->name);
  
  return 0;
}
