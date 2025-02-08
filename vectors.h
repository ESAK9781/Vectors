#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct Link_Struct {
    struct Link_Struct * next;
    struct Link_Struct * prev;
    void * value;
} ListLink;

typedef struct List_Struct {
    ListLink * head;
    ListLink * tail;
    int size;
} ListTemplate;

ListLink * _createLink(void * value);
ListTemplate * _createList();
void _chainTogether(ListLink * a, ListLink * b);

void _deleteLink(ListLink * link);
void _deleteList(ListTemplate * list);

int _getLen(ListTemplate * list);
ListLink * _getLink(ListTemplate * list, int index);
void * _getVal(ListTemplate * list, int index);
void * _pop(ListTemplate * list);

void _insert(ListTemplate * list, void * value, int index);
void _append(ListTemplate * list, void * value);
void _push(ListTemplate * list, void * value);

void * _popAt(ListTemplate * list, int index);
void _deleteAt(ListTemplate * list, int index);
