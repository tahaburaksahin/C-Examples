#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node *next;
};

template <typename T>
void addFront(Node<T>*& head, T data) {
    head = new Node<T>{data, head};
}

template <typename T>
void addBack(Node<T>*& head, T data) {
    if (head == nullptr) addFront(head, data);
    else {
        Node<T>* tmp = head;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = new Node<T>{data, nullptr};
    }
}

template<typename T>
void printList(const Node<T>* h) {
    std::cout << "[ ";
    while (h != nullptr) {
        std::cout << h->data << " ";
        h = h->next;
    }
    std::cout << "]\n";
}

template <typename T>
void deleteList(Node<T>*& h) {
    while (h != nullptr) {
        Node<T>* t = h->next;
        delete h;
        h = t;
    }
}

int main() {
      // "somestring"s will be a literal of type std::string
    using namespace std::literals;

    Node<int>* headI{nullptr};
    addBack(headI,  3);
    addBack(headI,  4);
    addFront(headI, 2);
    addFront(headI, 1);
    printList(headI);
    deleteList(headI);

    Node<std::string>* headS{nullptr};
    addBack(headS,  "hearts"s);
    addBack(headS,  "spades"s);
    addFront(headS, "diamonds"s);
    addFront(headS, "clubs"s);
    printList(headS);
    deleteList(headS);
}
