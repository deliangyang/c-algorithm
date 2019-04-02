//
// Created by Administrator on 2019/3/29.
//

#include <malloc.h>
#include <stdio.h>

#define STR(x) #x

typedef struct tree node;

struct tree {
    node *parent;
    int val;
    node *lchild;
    node *rchild;
};

void insert_to_emtpy_node(node *tr, node *p) {
    if (tr->val >= p->val) {
        if (tr->lchild == NULL) {
            tr->lchild = p;
            p->parent = tr;
            return;
        } else {
            insert_to_emtpy_node(tr->lchild, p);
        }
    } else if (tr->val < p->val) {
        if (tr->rchild == NULL) {
            tr->rchild = p;
            p->parent = tr;
            return;
        } else {
            insert_to_emtpy_node(tr->rchild, p);
        }
    }
}

node *insert_val(node *t, int val) {
    node *n = (node *) malloc(sizeof(node));
    n->parent = t;
    n->val = val;
    n->lchild = NULL;
    n->rchild = NULL;
    if (t == NULL) t = n;
    else {
        insert_to_emtpy_node(t, n);
    }
    return t;
}

void print_sort_tree(node *t) {
    if (t == NULL) return;
    print_sort_tree(t->lchild);
    printf("val: %d\n", t->val);
    print_sort_tree(t->rchild);
}

void destory_tree(node *t) {
    if (t == NULL) return;
    destory_tree(t->lchild);
    printf("remove: %d\n", t->val);
    free(t);
    destory_tree(t->rchild);
}

int main(int argc, char* argv[]) {
    node *tree = NULL;
    tree = insert_val(tree, 2);
    insert_val(tree, 21);
    insert_val(tree, 2);
    insert_val(tree, 23);
    insert_val(tree, 2312123);
    insert_val(tree, 212233);
    insert_val(tree, 21233);
    insert_val(tree, 233);
    insert_val(tree, 12);
    insert_val(tree, 12);
    insert_val(tree, 12);
    insert_val(tree, 12);
    insert_val(tree, 12);
    print_sort_tree(tree);
    destory_tree(tree);
    printf("str: %s", STR(asdfadf));
}