#include "node.h"

Node::Node(int key, Node* nxt) : key(key),
				 nxt(nxt)  {
}

Node::Node(int key) : Node(key,nullptr) { };
