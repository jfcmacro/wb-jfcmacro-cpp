#include <iostream>
#include <cstdlib>
#include "node.h"

int
main(int argc, char* argv[]) {
  int N, M;
  Node *head = nullptr, *aux = nullptr;

  std::cin >> N >> M;

  head = new Node { 1 };
  aux = head;

  for (int i = 0; i <= N; i++) {
    head->nxt = new Node { i };
    head = head->nxt;
  }

  head->nxt = aux;

  while (head != head->nxt) {
    for (int i = 1; i < M; i++) head = head->nxt;

    std::cout << head->nxt << " ";
    head->nxt = aux->nxt;
    delete aux;
    aux = head->nxt;
  }

  std::cout << head->key << std::endl;
}
