#ifndef H_ITEM
#define H_ITEM

#include "../../../boolean.h"
#include "../time/time.h"

typedef struct item {
  int itemID;
  int expired;
  char type;
} Item;

/* Memberikan nilai true bila item pertama dan kedua sama */
boolean i_is_equal(Item i1, Item i2);

/* Membuat Item baru.
   Bila type merupakan perishable (Karakter 'P'), perlu menambahkan expired.
   Bila tidak, isikan nilai -1.

   Expired adalah waktu saat item telah tidak berlaku.
*/
void i_create_item(Item* i, char type, int expired);

/* Mengembalikan true bila item sudah expired */
boolean i_is_expired(Item i, Time currentTime);

/* Mengembalikan true bila i merupakan perishable item */
boolean i_is_perishable(Item i);

/* Mengembalikan nama jenis item */
char* i_item_type_name(Item i);

#endif