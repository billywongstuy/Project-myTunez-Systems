#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song_node.h"


char[] convertToLowerCase(char *original) {
  int len = strlen(original);
  char newString[len];
  while (len) {
    if (*original >= 65 && *original <= 90) {
      newString[len(newString)-len] = *original+32;
    }
    else {
      newString[len(newString)-len] = *original;
    }
    len--;
    original++;
  }
  return newString;
}

void print_list(struct song_node *n) {
  while (n) {
    printf("%s by %s\n", n->name, n->artist);
    n = n->next;
  }
}

struct song_node * insert_front(struct song_node *n, char *nam, char *artis) {
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));

  new->next = n;
  new->name = nam;
  new->artist = artis;

  return new;
}

struct song_node * insert_inOrder(struct song_node *n, char *nam, char *artis) {
  
}

struct song_node * find_by_songName(struct song_node *n, char *nam) {
  while (!(n->name.equals(*nam))) {
    n = n->next;
  }
  return n;
}

struct song_node * find_by_artistName(struct song_node *n, char *artis) {
  while (!(n->artist.equals(*artis))) {
    n = n->next;
  }
  return n;
}

struct song_node * random_Song(struct song_node *n) {
  
}

struct song_node * removeSong(struct song_node *n, char *nam) {
  struct song_node *songLocation = find_by_songName(n,nam);
  songLocation->name = songLocation->next->name;
  songLocation->artist = songLocation->next->artist;
  songLocation->next = songLocation->next->next;
  return n;
}

struct song_node * emptyList(struct song_node *n) {
  struct node *temp = n;
  while (n) {
    n = n->next;
    //printf("Freeing node with %s", temp->name);
    free(temp);
    temp = n;
  }
}
