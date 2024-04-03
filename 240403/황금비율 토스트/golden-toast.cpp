#include <iostream>
using namespace std;

class Node {
public:
	char value;
	Node* prev;
	Node* next;

	Node() {    // 기본 생성자
		this->value = ' ';
		prev = next = nullptr;
	}

	Node(char value) {    // 매개변수 생성자
		this->value = value;
		prev = next = nullptr;
	}

	friend class List;
};

class List {
private:
	Node* header;    // 가장 앞 벽
	Node* trailer;   // 가장 뒤 벽
	int s;           // 리스트의 크기

public:
	List() {
		header = new Node();
		trailer = new Node();
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = nullptr;
		s = 0;
	}

	bool empty() {
		return (s == 0);
	}

	int size() {
		return s;
	}

	Node* begin() {
		return header->next;
	}

	Node* end() {
		return trailer;
	}

	void insert(Node* pos, char value) {
		Node* new_node = new Node(value);

		new_node->prev = pos->prev;
		new_node->next = pos;

		pos->prev->next = new_node;
		pos->prev = new_node;

		s++;
	}

	void erase(Node* pos) {
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;

		delete pos;
		s--;
	}
};

int main() {
	List L;
	Node* p = L.end();

	int n, m; cin >> n >> m;

	string bread; cin >> bread;

	for (int i = 0; i < n; i++) {
		L.insert(p, bread[i]);
	}

	L.end();

	for (int i = 0; i < m; i++) {
		char cmd; cin >> cmd;

		if (cmd == 'L') {
			if (p == L.begin()) {
				continue;
			}

			p = p->prev;
		}

		else if (cmd == 'R') {
			if (p == L.end()) {
				continue;
			}

			p = p->next;
		}

		else if (cmd == 'D') {
			if (p == L.end()) {
				continue;
			}

			Node* p_ = p->next;
			L.erase(p);
			p = p_;
		}

		else if (cmd == 'P') {
			char c; cin >> c;
			L.insert(p, c);
		}
	}

	p = L.begin();

	while (p != L.end()) {
		cout << p->value;
		p = p->next;
	}
}