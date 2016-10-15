#include <stdio.h>
#include <stdlib.h>

#include "song_node.h"


int main() {
  song_node * songs = 0;

  printf("Testing linkedlist functions:\n");
  
  print_list(songs);

  /*  
  songs = insert_front(songs,"Song1","Artist1");
  songs = insert_front(songs,"Song2","Artist2");
  songs = insert_front(songs,"Song3","Artist3");
  */

  songs = insert_inOrder(songs,"Song1","Artist1");
  songs = insert_inOrder(songs,"Tong1","Arsis");  
  songs = insert_inOrder(songs,"Song2","Artist2");
  songs = insert_inOrder(songs,"Song3","Artist3");

  print_list(songs);
  printf("\n--------------\n");

  songs = insert_inOrder(songs,"Yello","Artist2");
  songs = insert_inOrder(songs,"Wello","Artist2");
  songs = insert_inOrder(songs,"Allo","Artist2");

  print_list(songs);
  printf("\n--------------\n");
  
  songs = insert_inOrder(songs,"Xello","Artist2");  
  songs = insert_inOrder(songs,"Twine","Artist2");
  songs = insert_inOrder(songs,"Zimmy","Artist3");

  print_list(songs);
  printf("\n--------------\n");

  printf("Random: %s",(random_Song(songs))->name);

  printf("\n\nFind Wello: \n");
  printf("Name of found song: %s by %s",(find_by_songName(songs,"Wello"))->name,(find_by_songName(songs,"Wello"))->artist);

  printf("\n\nFind Cello: \n");
  if (find_by_songName(songs,"Cello") != NULL) {
  printf("Name of found song: %s by %s",(find_by_songName(songs,"Cello"))->name,(find_by_songName(songs,"Cello"))->artist);
  }
  else {
    printf("Not found!");
  }

  printf("\n\nFind Artist3: \n");
  printf("Name of found artist song: %s by %s",(find_by_artistName(songs,"Artist3"))->name,(find_by_artistName(songs,"Artist3"))->artist);

  removeSong(songs,"Xello");

  printf("\n\nRemoved Xello\n\n");

  print_list(songs);

  printf("\n");
  songs = free_list(songs);

  printf("\nFreed songs\n\n");

  print_list(songs);
  
  return 0;
}
