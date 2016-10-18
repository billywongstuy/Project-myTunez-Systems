#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myTunez.h"

song_node *table[26];


int nIndex(char c) {
  if (c >= 65 && c <= 90) {
    return c-65;
  }
  else if (c >= 97 && c <= 122) {
    return c-97;
  }
  return 25;
}

void addSong(char *name, char *artist) {
  int i = nIndex(artist[0]);
  table[i] = insert_inOrder(table[i],name,artist); 
}

song_node * searchSong(char *name) {
  int i = 0;
  struct song_node * l;
  while (l == NULL) {
    l = find_by_songName(table[i],name);
    i++;
  }
  return l;
}

song_node * searchArtist(char *artist) {
  int i = nIndex(artist[0]);
  return find_by_artistName(table[i],artist);
}

void printByLetter(char c) {
  print_list(table[nIndex(c)]);
}


void print_Artist(char *artist) {
  //This needs a fix
  struct song_node * start = searchArtist(artist);
  //print_Node(start);
  //printf("oooooo\n");
  while (strcmp(start->artist,artist) == 0) {
    //printf("dhuidboooooo\n");
    print_Node(start);
    start = start->next;
  }
}

void printLibrary() {
  int i = 0;
  while (i < 26) {
    print_list(table[i]);
    i++;
  }
}

void shufflePrint() {
  //call random_Song by in what way?
}

void deleteSong(char *name, char *artist) {
  //removeSong(table[what])
  int i = nIndex(artist[0]);
  removeSong(table[i],name,artist);
}

void deleteAll() {
  int i = 0;
  while (i < 26) {
    free_list(table[i]);
  }
}


/*

song_node * addSong(song_node *table[26], char *name, char *artist) {
  int i = nIndex(artist[0]);
  table[i] = insert_inOrder(table[i],name,artist);
  return table;
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
*/
