
#include "connection.h"

int main() {
  struct connection *list = NULL;
  
  struct connection *c1 = conn_create("one", 1);
  struct connection *c2 = conn_create("two", 2);
  struct connection *c3 = conn_create("three", 3);
  struct connection *c4 = conn_create("four", 4);

  list = conn_insert(&list, c1);
  list = conn_insert(&list, c2);
  list = conn_insert(&list, c3);
  list = conn_insert(&list, c4);

  conn_fprint(stdout, list);

  struct connection *g = conn_get(list, "two");
  printf("received: %s,%d\n", g->key, g->fd);

  struct connection *g2 = conn_get(list, "threeve");
  printf("should be null: %p\n", g2);

  conn_fprint(stdout, list);

  printf("remove four\n");
  g = conn_get(list, "four");
  printf("received: %s,%d\n", g->key, g->fd);
  list = conn_remove(&list, g);
  conn_fprint(stdout, list);


  printf("remove two\n");
  g = conn_get(list, "two");
  printf("received: %s,%d\n", g->key, g->fd);
  list = conn_remove(&list, g);
  conn_fprint(stdout, list);

  printf("remove three\n");
  g = conn_get(list, "three");
  printf("received: %s,%d\n", g->key, g->fd);
  list = conn_remove(&list, g);
  conn_fprint(stdout, list);

  printf("remove one\n");
  g = conn_get(list, "one");
  list = conn_remove(&list, g);

  conn_fprint(stdout, list);
}
