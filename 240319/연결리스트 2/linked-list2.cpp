#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* prev;
    Node* next;

    Node(int id) : id(id), prev(nullptr), next(nullptr) {}
};

Node* nodes[100001] = {};

void insertPrev(Node* u, Node* node) {
    node->prev = u->prev;
    node->next = u;

    if (nullptr != node->prev)
        node->prev->next = node;
    if (nullptr != node->next)
        node->next->prev = node;
}

void insertNext(Node* u, Node* node) {
    node->prev = u;
    node->next = u->next;

    if (nullptr != node->prev)
        node->prev->next = node;
    if (nullptr != node->next)
        node->next->prev = node;
}

void pop(Node* u) {
    if (u->prev != nullptr)
        u->prev->next = u->next;

    if (u->next != nullptr)
        u->next->prev = u->prev;

    u->prev = u->next = nullptr;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    for (int t = 0; t < q; t++) {
        int type, i;
        cin >> type >> i;

        if (1 == type) {
            pop(nodes[i]);
        }
        else if (2 == type) {
            int j;
            cin >> j;
            insertPrev(nodes[i], nodes[j]);
        }
        else if (3 == type) {
            int j;
            cin >> j;
            insertNext(nodes[i], nodes[j]);
        }
        else if (4 == type) {
            cout << ((nodes[i]->prev == nullptr) ? 0 : nodes[i]->prev->id) << ' '
                << ((nodes[i]->next == nullptr) ? 0 : nodes[i]->next->id) << '\n';
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ((nodes[i]->next == nullptr) ? 0 : nodes[i]->next->id) << ' ';
}