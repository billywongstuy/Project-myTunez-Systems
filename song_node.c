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

  new->next = n;
  strcpy(new->name,nam);
  strcpy(new->artist,artis);

  return new;
}

song_node * insert_inOrder(struct song_node *n, char nam[], char artis[]) {
  struct song_node *new = n;
  while (strcmp(n->artist,artis) > 0) {
    n = n->next;
  }
  while (strcmp(n->name,nam) > 0) {
    n = n->next;
  }
  insert_front(n,nam,artis);
  return new;
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

song_node * removeSong(struct song_node *n, char nam[]) {
  struct song_node *songLocation = find_by_songName(n,nam);
  songLocation->name = songLocation->next->name;
  songLocation->artist = songLocation->next->artist;
  songLocation->next = songLocation->next->next;
  return n;
}

song_node * emptyList(struct song_node *n) {
  struct node *temp = n;
  while (n) {
    n = n->next;
    //printf("Freeing node with %s", temp->name);
    free(temp);
    temp = n;
  }
}

int main() {
  return 0;
}
