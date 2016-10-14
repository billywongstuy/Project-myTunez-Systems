#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song_node.h"

/*
char convertToLowerCase(char original) {
  int len = strlen(original);
  char newString[len];
  int start = 0;
  while (len) {
    if (original[start] >= 65 && original[start] <= 90) {
      newString[strlen(*newString)-len] = original[start]+32;
    }
    else {
      newString[strlen(*newString)-len] = original[start];
    }
    len--;
    start++;
  }
  return newString;
}
*/


void print_list(struct song_node *n) {
  while (n) {
    printf("%s by %s\n", n->name, n->artist);
    n = n->next;
  }
}

song_node * insert_front(struct song_node *n, char nam[], char artis[]) {
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));

  //printf("inserting\n");
  new->next = n;
  strcpy(new->name,nam);
  strcpy(new->artist,artis);

  return new;
}

song_node * insert_inOrder(struct song_node *n, char nam[], char artis[]) {

  if (n == NULL) {
    n = insert_front(n,nam,artis);
    //printf("inserted at beginning and done\n");
    return n;
  }

  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node*));
  
  strcpy(new->name,nam);
  strcpy(new->artist,artis);
  new->next = NULL;

  if (strcmp(new->artist,artis) > 0 || (strcmp(new->artist,artis) == 0 && strcmp(new->name,nam) > 0)) {
    new->next = n;
    return new;
  }

  struct song_node *prev;
  struct song_node *temp = n;

  while (temp && strcmp(temp->artist,artis) < 0) {
    prev = temp;
    temp = temp->next;
  }

  if (temp && strcmp(temp->artist,artis) == 0) {
    while (temp && strcmp(temp->name,nam) < 0) {
      prev = temp;
      temp = temp->next;
    }
  }

  new->next = temp;
  prev->next = new;

  return prev;
  
}

song_node * find_by_songName(struct song_node *n, char nam[]) {
  while (!(strcmp(n->name,nam) == 0)) {
    n = n->next;
  }
  return n;
}

song_node * find_by_artistName(struct song_node *n, char artis[]) {
  while (!(strcmp(n->artist,artis) == 0)) {
    n = n->next;
  }
  return n;
}

song_node * random_Song(struct song_node *n) {
  
}

/*
song_node * removeSong(struct song_node *n, char nam[]) {
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

  songs = insert_inOrder(songs,"Aong1","Artist1");

  //print_list(songs);
  
  songs = insert_inOrder(songs,"Song2","Artist2");
  songs = insert_inOrder(songs,"Song3","Artist3");

  print_list(songs);

  
  
  return 0;
}
