#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: mycopy <src> <dest>\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (!src) { perror("open src"); return 1; }

    FILE *dst = fopen(argv[2], "wb");
    if (!dst) { perror("open dest"); fclose(src); return 1; }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0)
        fwrite(buffer, 1, bytes, dst);

    fclose(src);
    fclose(dst);
    return 0;
}
