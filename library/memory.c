#include <memory.h>

void memory_copy(char* dest, char* from, int bytes) {
    for (int i=0;i<bytes;i++) {
        dest[i]=from[i];
    }
}