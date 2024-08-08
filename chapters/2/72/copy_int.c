#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes >= sizeof(val)) {
        memcpy(buf, (void *) &val, sizeof(val));
    }
}

int main() {
    int i = 0xabcdef12;

    void* buf = malloc(4);
    memset(buf, 0, 4);
    copy_int(i, buf, 2);
    printf("%x\n", *(int*)buf);

    copy_int(i, buf, 4);
    printf("%x\n", *(int*)buf);

    return 0;
}

