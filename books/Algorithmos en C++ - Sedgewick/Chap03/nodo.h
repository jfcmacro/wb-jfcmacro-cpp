#pragma once

struct Node {
  int key;
  Node* nxt;
  Node(int key, Node* nxt);
  Node(int key);
};
