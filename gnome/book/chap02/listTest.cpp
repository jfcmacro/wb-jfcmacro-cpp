#include <glib.h>
#include <iostream>

using namespace std;

gint compareInt(gconstpointer a, gconstpointer b);

int
main(int argc, char * const argv[]) {

  gint32 value;
  GSList* list = NULL;

  while (cin >> value) {
    gint32* p = (gint32*) g_malloc(sizeof(gint32));
    *p = value;
    list = g_slist_insert_sorted(list, p, compareInt);
  }

  GSList* curr = list;

  while (curr) {
    gint32* p = (gint32*) (curr->data);
    cout << *p << endl;
    g_free(p);
    curr = curr->next;
  }

  return 0;
}

gint
compareInt(gconstpointer a, gconstpointer b) {
  return *((gint32*) a) - *((gint32*) b);
}
