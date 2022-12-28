# PROGRAM PENYEWAAN APARTEMEN

Program ini dirancang dan didesain oleh I Kadek Indra Agusta Pratama atau yang kerap dipanggil dengan nama Dudek dan Ni Komang Vaniya Apriandani. Program ini berisi sintaks-sintaks yang memungkinkan pengguna untuk memeriksa apartemen, menyewa apartemen, memeriksa tanggal jatuh tempo, hingga pembatalan apartemen.

## LATAR BELAKANG

Hal yang melatarbelakangi pembuatan program ini adalah adanya tugas besar semester ganjil yang diberikan oleh dosen pengampu mata kuliah Algoritma dan Pemrograman Teknologi Informasi, Universitas Udayana, Bapak I Kadek Suar Wibawa. Selain itu, pembuatan program ini didasari oleh rasa ingin tahu kami, sebagai Mahasiswa, terhadap algoritma dan pemrograman. Program ini juga dapat menjadi parameter kami dalam mengembangkan kemampuan-kemampuan yang kami miliki dan membuka kemampuan-kemampuan baru selama mengikuti perkuliahan di Program Studi Teknologi Informasi, Universitas Udayana.

## PERMINTAAN

Setelah program ini dibuat dan didemonstrasikan di kelas, kami diminta untuk membuat sebuah program menghitung perbedaan hari antara penyewa ketika memesan dan melakukan pembatalan. Sintaks-sintaks yang diekspektasikan mungkin akan menggunakan sintaks *difftime* yang berasal dari salah satu *library* bahasa pemrograman C, yaitu *time.h*.

Berikut adalah penggunaan *difftime* secara sederhana:

```C
#include <stdio.h>
#include <time.h>

int main(void)
{
    // Create two time_t variables to hold the current time and a future time
    time_t now, future;
    time(&now); // Get the current time and store it in 'now'
    future = now + 60; // Set 'future' to be 60 seconds in the future

    // Calculate the difference between 'now' and 'future'
    double diff = difftime(future, now);
    printf("The difference between 'now' and 'future' is %.f seconds.\n", diff);

    return 0;
}
```

Tapi, kami justru tidak menggunakan sintaks tersebut. Kami justru mengakalinya dengan menggunakan perhitungan waktu, seperti salah satu sintaks potongan berikut:

```C
time_t tiktok = time(NULL);
int a_day = tiktok / 86400;
```

Ketika variabel "*tiktok*" di-*casting* sebagai sebuah variabel dengan tipe data *time_t*, lalu kita melakukan *printf* dengan *data specifier* *%d* maka yang muncul adalah banyak "detik" dari tanggal 1 January 1970 tepat pukul 00:00 hingga saat ini. Jadi, kami mengakalinya dengan membagi variabel tersebut dengan menggunakan angka 86400 karena itu merupakan banyak detik dalam satu hari. Lalu, kami masukkan hasil kalkulasi itu ke dalam variabel *int hari* yang terdapat di dalam *struct Apartemen* (nama variabel kami ubah). Berikut adalah *struct* yang dimaksud:

```C
struct Apartemen
{
    char nik[20], masuk[20], keluar[20];
    int nomor, total, hari;
};
```

Untuk keterangan lebih lanjut dapat dilihat di komen yang terdapat di dalam *header* *apartment.h*. Sekian terima kasih.

## AKHIR KATA

Usaha dosen pengampu dalam membimbing kami sangat luar biasa, kami mengucapkan banyak terima kasih karena dapat belajar berbagai hal dan hasrat untuk ingin tahu dan mencari kami selalu terpancing.
