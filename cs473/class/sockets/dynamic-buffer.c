
#include "dynamic-buffer.h"

void append(struct dynamicBuffer *buffer, const char *newData, int newDataLength) {
    buffer->data = realloc(buffer->data, sizeof(char) * buffer->length + newDataLength);

    strncpy(buffer->data + buffer->length, newData, newDataLength);

    buffer->length += newDataLength;
}

void removeCharsLeft(struct dynamicBuffer *buffer, int numberChars) {
    if( numberChars >= buffer->length) {
        buffer->length = 0;
        buffer->data = NULL;
        return;
    }

    int newLength = buffer->length - numberChars;

    memmove(buffer->data, buffer->data + numberChars, newLength);

    buffer = realloc(buffer->data, newLength);
    buffer->length = newLength;
}
