#include <iostream>
using namespace std;

class List {

    struct Node {
        int    elem;
        Node* next;

        Node(int elem, Node* next = 0)
            : elem(elem), next(next)
        { }
    };

    Node* head;

public:
    List()
        : head(0)
    { }

    List& operator+(int elem) {
        Node* w = new Node(elem);
        if (head) {
            Node *h = head;
            while (h->next) h = h->next;
            h->next = w;
        } else {
            head = w;
        }
        return *this;
    }

    List& operator-(int elem) {
        head = new Node(elem,head);
        return *this;
    }

    int operator!() const {
        int cnt = 0;
        for (Node* h = head; h ; h = h->next, ++cnt);
        return cnt;
    }

    ~List() {
        Node *prev, *curr = head;
        while (curr) {
            prev = curr;
            curr = curr->next;
            cerr << "deleting " << prev->elem << endl;
            delete prev;
        }
    }

    friend ostream& operator<<(ostream&, const List&);
};

ostream& operator<<(ostream& s, const List& L) {
        for(List::Node* h = L.head ; h ; h = h->next)
            s << h->elem << " ";
        return s;
}

int main() {
    List list;

    list + 1;
    list + 2 - 0 - (-1);
    cout <<  list+3  << endl;
    cout << "List has " << !list << " elements" << endl;
}
