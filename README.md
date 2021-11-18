# Mobilita

Ini adalah repository Tugas Besar Alstrukdat Kelompok 7 Kelas K03

## Setup Environment

### Install gcc dan make

1. Install `gcc` dan `make` di komputer anda. Jika menggunakan windows, kita bisa pake mingw, mingw-w64, msys2, atau yang lainnya. Jika menggunakan linux berdistro ubuntu, gunakan perintah berikut:

```bash
sudo apt install build-essential
```

2. Setup PATH environment untuk `gcc` dan `make`

### Install libcheck

1. Jika menggunakan debian atau turunannya, gunakan perintah berikut

```shell
sudo apt install check
```

2. Jika menggunakan windows, lihat intruksi [disini](https://libcheck.github.io/check/web/install.html#mingwsource).

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

### Menjalankan Main Point dari ADT

Untuk menjalankan ADT, gunakan perintah sebagai berikut:

```
./run_adt.sh <Nama ADT>
```

Berikut ini adalah contoh menjalankan main point ADT `point`:

```bash
./run_adt.sh point
```

Pastikan anda telah mengubah file permission agar bisa dieksekusi:

```bash
chmod +x run_adt.sh
```

#### Dapat Kendala saat menjalankan Script?

Jika pake WSL, coba install `dos2unix`. Gunakan perintah

```shell
sudo apt install dos2unix -y
```

Lalu, jalankan perintah berikut untuk membuat run_adt versi wsl:

```shell
dos2unix -n -- run_adt.sh run_adt.wsl.sh
```

Lalu, jalankan perintah:

```shell
chmod +x run_adt.wsl.sh
./run_adt.wsl.sh
```

**NOTE :** Bila terjadi error _"Failed to change permission of temporary output file"_, jalankan perintah berikut:

```shell
echo -e "[automount]\noption = \"metadata\"" | sudo tee -a /etc/wsl.conf
```

Setelah menjalankan perintah tersebut, lakukan restart PC kalian.

Source : [Superuser - Unable to change file permissions on Ubuntu Bash for Windows 10](https://superuser.com/questions/1323645/unable-to-change-file-permissions-on-ubuntu-bash-for-windows-10)

#### Menggunakan Powershell

Selain menggunakan WSL, kita juga bisa gunakan powershell:

```powershell
./run_adt.ps1 <Nama ADT>
```

Contoh:

```powershell
./run_adt.ps1 pcolor
```

**Note :** Pastikan sudah setting PATH environment untuk `gcc` dan `make`. Selain itu, pastikan sudah mengatur Policy di Powershell. Untuk mengaturnya, jalankan perintah berikut:

```powershell
Set-ExecutionPolicy Unrestricted
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
   - Folder `components`, berisi prosedur yang dapat reusable untuk menampilkan ke layar.
   - Folder `lib`, berisi implementasi dari ADT beserta header filenya. Selain itu, bisa berisi fungsi/prosedur yang dapat membantu kita dalam menyusun file.
   - Folder `views` berisi prosedur yang digunakan untuk mencetak sebuah halaman pada layar. Contohnya seperti Menu Utama.
   - File `main.c` adalah start point program kita
4. Folder `test` berisi semua Unit Test.

## Fitur Permainan

1. Main Menu (new game, load, save, dan exit)
2. Mekanisme Waktu (menampilkan waktu permainan)
3. Daftar Pesanan (waktu pesanan masuk, pick up & drop off point, jenis item, dan time expired)
4. To Do List (pick up & drop off point, jenis item, dan waktu expired)
5. In Progress List (list berisi item yang telah dipick up tetapi belom didrop off)
6. Tas (Menyimpan item yang bisa diambil di lokasi)
7. Jenis Item (normal item, heavy item, Perishable item, VIP item)
8. Ability (speed boost, increase capacity, return to sender)
9. Gadget (kain pembungkus waktu, senter pembesar, pintu kemana saja, mesin waktu)
10. Inventory gadget (tempat penyimpanan gadget)
11. Peta (peta permainan)
12. Lokasi dan Command (MOVE, PICK_UP, DROP_OFF, MAP, TO_DO, IN_PROGRESS, BUY, INVENTORY, HELP, SAVE_GAME, RETURN)
13. Game Flow (start game, end game jika semua pesanan di antar dan perishable item hangus/diantar)
14. Save/Load Game

## Aturan Kontribusi

Bisa dilihat di [CONTRIBUTE.md](CONTRIBUTE.md)
