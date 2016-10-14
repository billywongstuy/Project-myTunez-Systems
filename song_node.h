typedef struct song_node {
  char name[256];
  char artist[256];
  struct song_node * next;
};


char[] convertToLowerCase(char *original);

void print_list(struct song_node *n);

struct song_node * insert_front(struct song_node *n, char *nam, char *artis);

struct song_node * insert_inOrder(struct song_node *n, char *nam, char *artis);

struct song_node * find_by_songName(struct song_node *n, char *nam);

struct song_node * find_by_artistName(struct song_node *n, char *artis);

struct song_node * random_Song(struct song_node *n);

struct song_node * removeSong(struct song_node *n, char *nam);

struct song_node * emptyList(struct song_node *n);


