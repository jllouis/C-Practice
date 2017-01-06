// by: lael :)
//removes duplicate nodes from linked list

#include <stdlib.h>
#include <stdio.h>

struct listNode{
    int value;
    struct listNode* next;
};

struct listNode* remove_duplicates(struct listNode* head){
    int encountered[256] = {0};

    struct listNode * tempNode;
    struct listNode * previousNode;
    struct listNode * toDelete;
    encountered[head->value] = 1;
    tempNode = head->next;
    previousNode = head;

    while(tempNode)
    {
        if (encountered[tempNode->value])
        {
            previousNode->next = tempNode->next;
            toDelete = tempNode;
            tempNode = tempNode->next;
            free(toDelete);
        }
        else
        {
            encountered[tempNode->value] = 1;
            previousNode = tempNode;
            tempNode = tempNode->next;
        }

    }

    return head;
}

int main(void) {

    struct listNode* a = malloc(sizeof(struct listNode));
    struct listNode* b = malloc(sizeof(struct listNode));
    struct listNode* c = malloc(sizeof(struct listNode));
    struct listNode* d = malloc(sizeof(struct listNode));
    struct listNode* e = malloc(sizeof(struct listNode));
    struct listNode* f = malloc(sizeof(struct listNode));
    struct listNode* g = malloc(sizeof(struct listNode));
    struct listNode* h = malloc(sizeof(struct listNode));

    a->value = 1; a->next = b;
    b->value = 2; b->next = c;
    c->value = 2; c->next = d;
    d->value = 4; d->next = e;
    e->value = 5; e->next = f;
    f->value = 5; f->next = g;
    g->value = 3; g->next = h;
    h->value = 1; h->next = NULL;

    remove_duplicates(a);

    return 0;
}