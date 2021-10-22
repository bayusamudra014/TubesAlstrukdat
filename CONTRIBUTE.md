# Traktat Kontribusi

Traktat ini ditulis supaya kita sama-sama nyaman yah. Klo ada yang tidak setuju, bilang aja :D. Selain itu, dibuatnya ini biar mencegah adanya konflik nama fungsi/prosedur di program.

## Setup Environment

1. Install `gcc` dan `make` di komputer anda. Jika menggunakan windows, kita bisa pake mingw, mingw-w64, msys2, atau yang lainnya. Jika menggunakan linux berdistro ubuntu, gunakan perintah berikut:
```bash
sudo apt install build-essential
```
2. Setup PATH environment untuk `gcc` dan `make`

## Kompilasi dan Run Program

### Melakukan Kompilasi

Untuk melakukan kompilasi, kita hanya perlu menjalankan perintah berikut
```shell
make build
```

### Menjalankan Program

Untuk melakukan kompilasi dan menjalankan program, kita dapat menggunakan perintaah berikut
```shell
make run
```

### Testing Unit Test

Untuk melakukan unit testing, kita dapat menjalankan perintah berikut
```shell
make test
```
Dalam project ini, kita menggunakan libcheck sebagai library untuk melakukan asersi, pastikan sudah menginstall libcheck. Jika belum, lihat Olympia carannya.

## Stuktur Project
Dalam project ini ada beberapa folder diantaranya sebagai berikut:
1. Folder `bin` merupakan isi program kita.
2. Folder `build` berisi object file dari setiap file pada src dan test.
3. Folder `src` merupakan source code kita. Dalam folder ini terdapat beberapa folder lagi, yaitu
   * Folder `components`, berisi prosedur yang dapat reusable untuk menampilkan ke layar.
   * Folder `lib`, berisi implementasi dari ADT beserta header filenya. Selain itu, bisa berisi fungsi/prosedur yang dapat membantu kita dalam menyusun file.
   * Folder `views` berisi prosedur yang digunakan untuk mencetak sebuah halaman pada layar. Contohnya seperti Menu Utama.
   * File `main.c` adalah start point program kita
 4. Folder `test` berisi semua Unit Test.

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

### Pembuatan Prosedur atau Fungsi Implementasi
1. Jika membuat prosedur, pastikan tulis deskripsinya. Mulai dari Initial State dan Final State.
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
