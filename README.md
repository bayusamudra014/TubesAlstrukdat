# Mobilita
Ini adalah repository Kelompok 7 Kelas K03

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

## Aturan Kontribusi
Bisa dilihat di [CONTRIBUTE.md](CONTRIBUTE.md)
