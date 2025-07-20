#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct visit {
    int dep;
    int t;
} visit;

int queue[100001];
int front = 0, rear = 0;
int order = 1;

void addq(int data) {
    queue[rear++] = data;
}

int popq(void) {
    return queue[front++];
}

void add(node** list, int from, int to) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = to;
    temp->next = list[from];
    list[from] = temp;
}

// C용 비교 함수
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void sort_adj_list(node** list, int N) {
    for (int i = 1; i <= N; i++) {
        int size = 0;
        node* cur = list[i];
        while (cur) {
            size++;
            cur = cur->next;
        }

        int* temp_arr = (int*)malloc(sizeof(int) * size);
        cur = list[i];
        for (int j = 0; j < size; j++) {
            temp_arr[j] = cur->data;
            node* tmp = cur;
            cur = cur->next;
            free(tmp);
        }

        qsort(temp_arr, size, sizeof(int), compare);

        list[i] = NULL;
        for (int j = size - 1; j >= 0; j--) {
            node* newnode = (node*)malloc(sizeof(node));
            newnode->data = temp_arr[j];
            newnode->next = list[i];
            list[i] = newnode;
        }

        free(temp_arr);
    }
}

void bfs(node** list, int start, visit* visited) {
    visited[start].dep = 0;
    visited[start].t = order++;
    addq(start);

    while (front != rear) {
        int temp = popq();
        node* cur = list[temp];
        while (cur) {
            int next = cur->data;
            if (visited[next].dep == -1) {
                visited[next].dep = visited[temp].dep + 1;
                visited[next].t = order++;
                addq(next);
            }
            cur = cur->next;
        }
    }
}

int main(void) {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);

    node** list = (node**)malloc(sizeof(node*) * (N + 1));
    visit* visited = (visit*)malloc(sizeof(visit) * (N + 1));

    for (int i = 1; i <= N; i++) {
        list[i] = NULL;
        visited[i].dep = -1;
        visited[i].t = 0;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add(list, u, v);
        add(list, v, u);
    }

    sort_adj_list(list, N);
    bfs(list, R, visited);

    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += (long long)visited[i].dep * visited[i].t;
    }
    printf("%lld\n", sum);

    for (int i = 1; i <= N; i++) {
        node* cur = list[i];
        while (cur) {
            node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(list);
    free(visited);

    return 0;
}
