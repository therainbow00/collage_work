
#ifndef SOCKETS_DYNAMIC_BUFFER_H
#define SOCKETS_DYNAMIC_BUFFER_H

#include <stdlib.h>
#include <string.h>

struct dynamicBuffer {
    char *data;
    int length;
};

void append(struct dynamicBuffer *buffer, const char *newData, int newDataLength);
void removeCharsLeft(struct dynamicBuffer *buffer, int numberChars);

#endif //SOCKETS_DYNAMIC_BUFFER_H
