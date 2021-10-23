# Traktat Kontribusi

Traktat ini ditulis supaya kita sama-sama nyaman yah. Klo ada yang tidak setuju, bilang aja :D. Selain itu, dibuatnya ini biar mencegah adanya konflik nama fungsi/prosedur di program.

## Penulisan Program

Untuk menyamakan semua source code, ada beberapa standard penting yang kita dapat pakai:

### Penamaan
1. Setiap fungsi atau prosedur, gunakan nama dalam snake case. Contoh sebagai berikut
```c
void print_color(){
  // Kode disini
}
```
2. Setiap nama ADT, gunakan semua huruf nonkapital dan tidak ada karakter khusus seperti -, \_, atau yang lainnya.
3. Jika kalian ingin membuat fungsi atau prosedur yang ga ingin diakses di luar file tersebut, gunakan prefix `__`. contoh `__fungsi_gamau_diakses`.
4. Setiap konstanta harus menggunakan CAPITAL CASE. contoh `TEXT_RED`.
5. Setiap fungsi atau prosedur dalam ADT kecuali konstruktor menggunakan prefix huruf-huruf awal setiap kata dari nama ADT (bukan nama folder yaa) dilanjutkan dnegan underscore. Contoh, misal aku ingin membuat prosedur append di ADT static list, maka nama prosedurnya `sl_append`. 
6. Fungsi atau prosedur yang berada pada folder `console`, tidak perlu mengikuti aturan nomor 5.
7. Nama setiap folder yang berisi ADT harus bernama ADT tersebut dengan menghilangkan semua spasi dan menggunakan lowercase. Contoh misal ADT yang ingin dibuat Dynamic List, maka nama foldernya `dynamiclist`.
8. Pastikan setiap kali membuat fungsi atau prosedur, menggunakan nama yang berbeda dengan fungsi atau prosedur lainnya.
9. Semua nama tipe data bentukan menggunakan PascalCase. Contoh kita membuat tipe data bentukan dari Dynamic List, gunakan nama seperti berikut:
```c
typedef struct{...} DynamicList;
```

### Struktur Project
1. Setiap ADT dibuat dalam satu folder terpisah, jangan disatukan dalam satu folder yang sama. Nama folder merupakan nama ADT.
2. Setiap folder harus memiliki satu file header yang bernama sama dengan nama foldernya. Contoh, misalkan nama ADT-nya adalah matrix, maka harus ada sebuah folder matrix yang didalamnya ada file bernama `matrix.h`
3. Pastikan setiap file header harus memiliki direktif `#ifndef` sebelum mendefinisikan semua fungsi atau prosedur yang  ada. Contoh
```c
// File header.h

#ifndef H_HEADER
#define H_HEADER

// Disini definisikan file header kalian

#endif
```
4. Tempatkan kode kalian di folder yang tepat yaa.
5. Semua folder yang berada di dalam folder `views` mengikuti aturan nomor 2. Selain itu, harus terdapat prosedur yang  diawal dengan `show_` dilanjutkan dengan nama halaman, ini merupakan prosedur khusus jadi agak beda penamaannya yaa. Contoh untuk Halaman Menu Utama:
```c
void show_main_menu(){
  // ...
}
```

### Pembuatan Prosedur atau Fungsi Implementasi
1. Jika membuat prosedur, pastikan tulis deskripsinya. Tuliskan Initial State dan Final State jika dibutuhkan.
2. Jika membuat fungsi, pastikan menuliskan batasan dan juga output dari fungsinya.
3. Sangat dianjurkan memberi contoh penggunaan fungsinya.
4. Tuliskan deskripsi sebelum menuliskan _signature_ fungsi/prosedur. Contoh:
```c
/* Prosedur ini akan print text dengan warna pada console. Setelah prosedur
   ini dijalankan, warna console otomatis tereset.

  Contoh pakai:
  print_color(TEXT_BLUE, "Halo, Dunia");
*/
void print_color(Color color, char* string);

```
5. Semua deskripsi tuliskan di header file, jangan di file implementasi.

## Penulisan Unit Test

Berikut aturan untuk membuat unit test:
1. Pastikan satu folder digunakan untuk satu ADT saja.
2. Setiap folder merupakan sebuah Suite. Pastikan kita membuat file `suite.c` dan file `test.h`.
   * Fungsi dari `suite.c` adalah untuk menjalankan semua test case yang ada pada folder tersebut.
   * FUngsi dari `test.h` adalah untuk mendeklarasikan semua fungsi yang ada di folder tersebut.
3. Jika kalian ingin medeklarasikan fungsi atau prosedur pembantu, implementasikan pada `helper.c`
4. Setiap fungsi suite gunakan nama dengan prefix `suite_`. Contoh `suite_matrix`
5. Setiap file test case harus ada sebuah fungsi dengan prefix `test_namaADT_`. Fungsi ini digunakan untuk menjalankan semua test case yang ada pada file tersebut. Contoh
```c
TCase* test_matrix_penjumlahan(){
  // Ini adalah driver semua tc yang berkatian dengan penjumlahan matriks
}
```
6. Setiap tc, dipastikan menggunakan prefix `tc_namaADT_`. Contohnya sebagai berikut
```c
START_TEST(tc_matrix_konstruktor_3) {
  // Algoritma TC-nya disini
}
END_TEST
```
