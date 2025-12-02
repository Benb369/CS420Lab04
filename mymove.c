#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <oldfilename> <newfilename>\n", argv[0]);
        exit(1);
    }

    char *oldname = argv[1];
    char *newname = argv[2];

    
    if (rename(oldname, newname) == -1) {
        perror("mymove: rename failed");
        exit(1);
    }

    return 0;
}
