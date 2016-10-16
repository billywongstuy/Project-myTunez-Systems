#include <stdio.h>
#include <stdlib.h>

#include "myTunez.h"

int nIndex(char c) {
  if (c >= 65 && c <= 90) {
    return c-65;
  }
  else if (c >= 97 && c <= 122) {
    return c-97;
  }
  return 25;
}

song_node * addSong(song_node *table[26], char *name, char *artist) {
  int i = nIndex(artist[0]);
  struct song_node *list = insert_inOrder(table[i],name,artist);
  return list;
}

song_node * searchSong(song_node *table[26], char *name) {
  return;
}

song_node * searchArtist(song_node *table[26], char *artist) {
  int i = nIndex(artist[0]);
  return find_by_artistName(table[i],artist);
}

void printByLetter(song_node *table[26], char c) {
  print_list(table[nIndex(c)]);
}

void printLibrary(song_node *table[26]) {
  int i = 0;
  while (i < 26) {
    print_list(table[i]);
    i++;
  }
}

void shufflePrint(song_node *table[26]) {

}

void deleteSong(song_node *table[26], char *name) {

}

void deleteAll(song_node *table[26]) {

}
