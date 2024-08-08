#include <stdlib.h>
#include <string.h>

void *mycalloc(size_t nmemb, size_t n) {
    // If any argument is 0 or the total size is overflow, return NULL.
    if (!nmemb || !n || (nmemb * n) / nmemb != nmemb) {
        return NULL;
    }

    void *mem = malloc(nmemb * n);
    if (mem == NULL) {
        return NULL;
    }

    memset(mem, 0, nmemb * n);

    return mem;
}
