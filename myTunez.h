#include "song_node.h"

song_node * addSong(song_node table[], char *name, char *artist);

song_node * searchSong(song_node table[], char *name);

song_node * searchArtist(song_node table[], char *artist);

void printByLetter(song_node table[], char c);

void printLibrary(song_node table[]);

void shufflePrint(song_node table[]);

void deleteSong(song_node table[], char *name);

void deleteAll(song_node table[]);

