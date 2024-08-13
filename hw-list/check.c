#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

struct Node {
    struct Node* next;
    int data;
};

int main() {
    struct Node n;
    n.next = (struct Node *)malloc(sizeof(struct Node));
    n.data = 1;

    printf("%d %d\n", &n, &(n.next));

    int new_addr = (uint8_t*)&(n.next) - offsetof(struct Node, next);

    printf("%d\n", new_addr);

    return 0;
}