#include <iostream>
using namespace std;

class node {
public:
   char v;
   node* prev;
   node* next;
   node() {
      this->v = NULL;
      prev = next = nullptr;
   }
   node(char v) {
      this->v = v;
      prev = next = nullptr;
   }
};

class List {
private:
   int s;
   node* header;
   node* trailer;
public:
   List() {
      this->s = 0;
      header = trailer = new node();
      header->prev = trailer->next = nullptr;
      header->next = trailer;
      trailer->prev = header;
   }

   node* begin() {
      return header->next;
   }

   node* end() {
      return trailer;
   }

   void insert(node* pos, char v) {
      node* newnode = new node(v);
      newnode->prev = pos->prev;
      newnode->next = pos;
      pos->prev->next = newnode;
      pos->prev = newnode;
      s++;
   }

   void erase(node* pos) {
      pos->prev->next = pos->next;
      pos->next->prev = pos->prev;
      delete pos;
      s--;
   }

   void print() {
      node* cur_node = begin();
      while (cur_node != end()) {
         cout << cur_node->v;
         cur_node = cur_node->next;
      }
      cout << '\n';
   }
};

int main() {
   int n, m;
   cin >> n >> m;
   List l;
   node* p = l.end();

   for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      l.insert(p, c);
   }

   p = l.end();


   while (m--) {
      string cmd; cin >> cmd;

      if (cmd == "L") {
         if (p == l.begin()) {
            continue;
         }
         p = p->prev;
      }

      else if (cmd == "R") {
         if (p == l.end()) {
            continue;
         }
         p = p->next;
      }

      else if (cmd == "D") {
         if (p == l.end()) {
            continue;
         }
         l.erase(p);
      }
      else if (cmd == "P") {
         char new_char; cin >> new_char;
         l.insert(p, new_char);
      }
   }
   l.print();
}