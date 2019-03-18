#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE* f = fopen("../sandbox/readfile.in", "r");
    if (f == NULL) {
        printf("Cannot open file!\n");
        return ENOENT;
    }
    size_t buf_size = 256;
    char* buf = (char*) malloc(buf_size * sizeof(char));
    int32_t read;
    while ((read = getline(&buf, &buf_size, f)) != -1) {
        printf("%s", buf);
    }
    printf("\n");

clean_up:
    if (f != NULL) {
        fclose(f);
        f = NULL;
    }
    free(buf);
}