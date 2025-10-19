//Studen Name:Edasu Yadik
//Studen ID  :231AEB028
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynArray;

void da_init(DynArray *a) {
    a->size = 0;
    a->capacity = 4;
    a->data = (int*)malloc(a->capacity * sizeof(int));
    assert(a->data != NULL);
}

void da_free(DynArray *a) {
    free(a->data);
    a->data = NULL;
    a->size = a->capacity = 0;
}

void da_reserve(DynArray *a, size_t newcap) {
    if (newcap <= a->capacity) return;
    int *nd = (int*)realloc(a->data, newcap * sizeof(int));
    assert(nd != NULL);
    a->data = nd;
    a->capacity = newcap;
}

void da_grow_if_full(DynArray *a) {
    if (a->size >= a->capacity)
        da_reserve(a, a->capacity * 2);
}

void da_push_back(DynArray *a, int value) {
    da_grow_if_full(a);
    a->data[a->size++] = value;
}

void da_insert(DynArray *a, size_t idx, int value) {
    assert(idx <= a->size);
    da_grow_if_full(a);
    memmove(&a->data[idx + 1], &a->data[idx], (a->size - idx) * sizeof(int));
    a->data[idx] = value;
    a->size++;
}

void da_remove_at(DynArray *a, size_t idx) {
    assert(idx < a->size);
    memmove(&a->data[idx], &a->data[idx + 1], (a->size - idx - 1) * sizeof(int));
    a->size--;
}

void da_print(const DynArray *a, const char *label) {
    printf("%s [size=%zu cap=%zu]:", label, a->size, a->capacity);
    for (size_t i = 0; i < a->size; ++i)
        printf(" %d", a->data[i]);
    printf("\n");
}

int main(void) {
    DynArray a;
    da_init(&a);

    da_push_back(&a, 1);
    da_push_back(&a, 2);
    da_push_back(&a, 3);
    da_print(&a, "Edasu's array after push");

    da_insert(&a, 1, 99);
    da_print(&a, "Edasu's array after insert");

    da_remove_at(&a, 2);
    da_print(&a, "Edasu's array after remove");

    da_free(&a);
    return 0;
}

