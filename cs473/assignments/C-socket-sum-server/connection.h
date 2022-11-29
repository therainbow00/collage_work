
#ifndef CONNECTION_H
#define CONNECTION_H

#include <stdio.h>

struct connection {
  char *key;
  int fd;
  struct connection *next;
  struct connection *prev;
};

struct connection *conn_create(const char *key, int fd);
struct connection *conn_get(struct connection *list, const char *fd);
struct connection *conn_insert(struct connection **list, struct connection *newConnection);
struct connection *conn_remove(struct connection **list, struct connection *toRemove);
void conn_fprint(FILE* file, struct connection *list);

#endif
