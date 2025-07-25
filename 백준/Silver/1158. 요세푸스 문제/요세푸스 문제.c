#include <stdio.h>
#include <stdlib.h>

void func(int N, int K) {
    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    int index = 0;
    int size = N;

    printf("<");
    while (size > 0) {
        int cnt = 0;
        while (cnt < K) {
            if (arr[index] != 0) {
                cnt++;
            }
            if (cnt == K) break;
            index = (index + 1) % N;
        }

        printf("%d", arr[index]);
        arr[index] = 0;
        size--;

        if (size != 0)
            printf(", ");
        index = (index + 1) % N;
    }
    printf(">\n");

    free(arr);
}

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    func(N, K);
    return 0;
}
