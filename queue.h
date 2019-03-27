//
// Created by Administrator on 2019/3/14.
//

#ifndef BTREE_QUEUE_H
#define BTREE_QUEUE_H


struct list {
    void *value;
    struct list *l;
};

struct list_tail {
    int len;
    struct list *next;
};

int list_len(struct list_tail *l);
void list_insert(struct list_tail *lt, void *value);
void destroy(struct list_tail *lt);
void tail(struct list_tail *lt, int (*print)(void *));

#endif //BTREE_QUEUE_H
