#ifndef mySTACKS_H
#define mySTACKS_H

#include "mySTACK.h"

namespace mySTACKS {

    class ListStack: public STACK {
        struct Node {
            int   data;
            Node* next;
            Node(int data, Node* next);
        };
        Node* head;
        ListStack();
    public:
        friend STACK* STACK::getInstance(int);
        int pop();
        void push(int data);
        bool empty();
        ~ListStack();
    };

    class ArrayStack : public STACK {
        int  top;
        int* arr;
        ArrayStack();
    public:
        friend STACK* STACK::getInstance(int);
        void push(int data);
        int pop();
        bool empty();
        ~ArrayStack();
    };
}
#endif
