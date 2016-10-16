#include "song_node.h"

song_node * addSong(song_node *table[26], char *name, char *artist);

song_node * searchSong(song_node *table[26], char *name);

song_node * searchArtist(song_node *table[26], char *artist);

void printByLetter(song_node *table[26], char c);

void printLibrary(song_node *table[26]);

void shufflePrint(song_node *table[26]);

void deleteSong(song_node *table[26], char *name);

void deleteAll(song_node *table[26]);

