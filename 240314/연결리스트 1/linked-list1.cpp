#include <iostream>
using namespace std;

struct Node {
	string value;
	Node* prev;
	Node* next;

	Node(string s) : value{ s }, prev{ nullptr }, next{ nullptr } {}
};

void insert_prev(Node* node, string s) {
	Node* new_node = new Node(s);

	new_node->prev = node->prev;
	new_node->next = node;

	if (new_node->prev != nullptr) {
		new_node->prev->next = new_node;
	}

	if (new_node->next != nullptr) {
		new_node->next->prev = new_node;
	}
}

void insert_next(Node* node, string s) {
	Node* new_node = new Node(s);

	new_node->prev = node;
	new_node->next = node->next;

	if (new_node->prev != nullptr) {
		new_node->prev->next = new_node;
	}

	if (new_node->next != nullptr) {
		new_node->next->prev = new_node;
	}
}

void print(Node* node) {
	if (node->prev == nullptr) {
		cout << "(Null) ";
	}

	else {
		cout << node->prev->value << ' ';
	}

	if (node == nullptr) {
		cout << "(Null) ";
	}

	else {
		cout << node->value << ' ';
	}

	if (node->next == nullptr) {
		cout << "(Null) ";
	}

	else {
		cout << node->next->value << ' ';
	}

	cout << '\n';
}

int main() {
	string s_init; cin >> s_init;
	Node* cur = new Node(s_init);
	int n; cin >> n;

	while (n--) {
		int num; cin >> num;

		if (num == 1) {
			string s_value; cin >> s_value;
			insert_prev(cur, s_value);
			print(cur);
		}

		else if (num == 2) {
			string s_value; cin >> s_value;
			insert_next(cur, s_value);
			print(cur);
		}

		else if (num == 3) {
			if (cur->prev != nullptr) {
				cur = cur->prev;
			}
			print(cur);
		}

		else if (num == 4) {
			if (cur->next != nullptr) {
				cur = cur->next;
			}
			print(cur);
		}
	}
}