//
// Created by Administrator on 2019/3/14.
//

#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

int list_len(struct list_tail *lt) {
    return lt->len;
}

void list_insert(struct list_tail *lt, void *value) {
    struct list *l = (struct list *) malloc(sizeof(struct list));
    printf("*l:%p\n", l);
    struct list *tl;
    l->value = value;
    l->l = NULL;

    if (lt->next == NULL) {
        lt->next = l;
    } else {
        tl = lt->next;
        while (tl->l != NULL) {
            tl = tl->l;
        }
        tl->l = l;
    }
    printf("value: %d\n", *((int *)value));
    lt->len++;
}

void destroy(struct list_tail *lt) {
    struct list *l;
    while (lt->next != NULL) {
        l = lt->next;
        lt->next = l->l;
        free(l);
    }
    lt->len = 0;
}

void tail(struct list_tail *lt, int (*print)(void *)) {
    struct list *l;
    l = lt->next;
    while (l) {
        printf("l:%p\n", l);
        printf("l->l:%p\n", l->l);
        print(l->value);
        l = l->l;
    }
}


