#include "./testCases.h"
#include <assert.h>



ListTemplate * createBasicList() {
    ListTemplate * out = _createList();
    for (int i = 0; i < 10; i++) {
        int * value = malloc(sizeof(int));
        *value = i;
        _append(out, value);
    }
    return out;
}


void testListCreation() {
    ListTemplate * test = _createList();
    assert(test->head == NULL);
    assert(test->size == 0);
    assert(test->tail == NULL);
    free(test);

    printf("\tList creation passed\n");
}

void testLinkCreation() {
    int * value = malloc(sizeof(int));
    ListLink * test = _createLink(value);
    assert(test->value == value);
    assert(test->prev == NULL);
    assert(test->next == NULL);
    free(test);
    free(value);

    printf("\tLink creation passed\n");

}

void testChaining() {
    ListLink * a = _createLink(NULL);
    ListLink * b = _createLink(NULL);
    _chainTogether(a, b);

    assert(a->next == b);
    assert(b->prev == a);

    free(a);
    free(b);

    printf("\tLink chaining passed\n");
}

void testGetLen() {
    ListTemplate * test = _createList();
    for (int i = 0; i < 10; i++) {
        test->size = i;
        assert(i == _getLen(test));
    }

    printf("\tSize getter passed\n");
}

void testGetLink() {
    ListTemplate * test = _createList();
    ListLink * links[20];
    for (int i = 0; i < 20; i++) {
        _append(test, NULL);
        links[i] = test->tail;
    }


    for (int i = 0; i < 20; i++) {
        assert(_getLink(test, i) == links[i]);
    }

    _deleteList(test);

    printf("\tLink getter passed\n");
}




void testGetVal() {
    ListTemplate * test = _createList();

    for (int i = 0; i < 20; i++) {
        int * val = malloc(sizeof(int));
        *val = i;
        _append(test, val);
    }

    for (int i = 0; i < 20; i++) {
        int * val = _getVal(test, i);
        assert(*val == i);
    }

    _deleteList(test);

    printf("\tValue getter passed\n");
}



void testPopper() {
    ListTemplate * test = createBasicList();
    for (int i = 0; i < 5; i++) {
        int * val = _pop(test);
        assert(*val == i);
        assert(_getLen(test) == 10 - i - 1);
        free(val);
    }

    _deleteList(test);

    printf("\tPop function passed\n");
}






void completeAllTests() {
    testListCreation();
    testLinkCreation();
    testChaining();
    testGetLen();
    testGetLink();
    testGetVal();
    testPopper();

    printf("\nALL TESTS PASSED\n");
}