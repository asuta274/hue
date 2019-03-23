#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE* f = fopen("../sandbox/coursera/algo41/large.txt", "r");
    if (f == NULL) {
        printf("Cannot open file!\n");
        return ENOENT;
    }

    int32_t nb_vertecies, nb_edges;
    fscanf(f, "%d %d", &nb_vertecies, &nb_edges);
    int32_t (*distances)[nb_vertecies][nb_vertecies] = malloc(sizeof(int32_t[2][nb_vertecies][nb_vertecies]));

    size_t buf_size = 256;
    char* buf = (char*) malloc(buf_size * sizeof(char));
    int32_t read, u, v, d;
    for(u = 0; u < nb_vertecies; u++) {
        for (v = 0; v < nb_vertecies; v++) {
            distances[0][u][v] = INT32_MAX;
            distances[1][u][v] = INT32_MAX;
        }
    }

    while ((read = fscanf(f, "%d %d %d", &u, &v, &d)) != EOF) {
        distances[0][u - 1][v - 1] = d;
    }

    int32_t cur = 0, prev = 1;

    for (int32_t k = 0; k < nb_vertecies; k++) {
        prev = k % 2;
        cur = (k + 1) % 2;
        for(u = 0; u < nb_vertecies; u++) {
            for (v = 0; v < nb_vertecies; v++) {
                int32_t min = distances[prev][u][v];
                if (distances[prev][u][k] != INT32_MAX && distances[prev][k][v] != INT32_MAX) {
                    int32_t min_k = distances[prev][u][k] + distances[prev][k][v];
                    min = (min < min_k) ? min : min_k;
                }
                distances[cur][u][v] = min;
            }
            printf("%d tasks done\n", k);
        }
    }

    int32_t min = 0;
    for(u = 0; u < nb_vertecies; u++) {
        for (v = 0; v < nb_vertecies; v++) {
            min = (min < distances[cur][u][v]) ? min : distances[cur][u][v];
        }
    }

    printf("%d\n", min);

clean_up:
    if (f != NULL) {
        fclose(f);
        f = NULL;
    }
    free(buf);
    free(distances);
}