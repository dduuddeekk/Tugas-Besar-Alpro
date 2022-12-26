#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#define KELUARGA_MALAM 500000
#define KELUARGA_BULAN 13500000
#define KELUARGA_TAHUN 156000000
#define PRIVATE_MALAM 350000
#define PRIVATE_BULAN 9000000
#define PRIVATE_TAHUN 98000000
#define SARAPAN 129999
void mainmenu();
int validasi_angka(int range1, int range2)
{
    char buff[1024], invalid;
    int valid;
    scanf("%[^\n]", buff);
    getchar();
    if (sscanf(buff, "%d%c", &valid, &invalid) == 1 && valid >= range1 && valid <= range2)
    {
        return valid;
    }
    else
    {
        printf("\n\t\t\t\t Inputan Salah!\n\t\t\t\t Masukkan kembali.!\n\t\t\t\t >> ");
        validasi_angka(range1, range2);
    }
}
int validasi_lantai(int range1, int range2, int range3, int range4)
{
    char buff[1024], invalid;
    int valid;
    scanf("%[^\n]", buff);
    getchar();
    if (sscanf(buff, "%d%c", &valid, &invalid) == 1 && valid >= range1 && valid <= range2 && valid >= range3 && valid <= range4)
    {
        return valid;
    }
    else
    {
        printf("\n\t\t\t\t Inputan Salah!\n\t\t\t\t Masukkan kembali.!\n\t\t\t\t >> ");
        validasi_lantai(range1, range2, range3, range4);
    }
}
int validasi_tahun(int range1)
{
    char buff[1024], invalid;
    int valid;
    scanf("%[^\n]", buff);
    getchar();
    if (sscanf(buff, "%d%c", &valid, &invalid) == 1 && valid >= range1)
    {
        return valid;
    }
    else
    {
        printf("\n\t\t\t\t Inputan Salah!\n\t\t\t\t Masukkan kembali.!\n\t\t\t\t >> ");
        validasi_tahun(range1);
    }
}
struct Kamar
{
    char nik[20];
    int nomor;
    int total;
    char masuk[20];
    char keluar[20];
};
int pilih;
void menu()
{
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ********   Pilihan Halaman  ******** ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||   [1]    |   Pengecekan Apartemen    ||\n");
    printf("\t\t\t\t||   [2]    |   Pengecekan Jatuh Tempo  ||\n");
    printf("\t\t\t\t||   [3]    |   Penyewaan Apartemen     ||\n");
    printf("\t\t\t\t||   [4]    |   Layanan Tambahan        ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t||                  [5]BATALKAN PESANAN ||\n");
    printf("\t\t\t\t||                  [0]KELUAR           ||\n");
    printf("\t\t\t\t||===================================== ||\n");
    printf("\t\t\t\t||Masukkan pilihan: ");
}
/* void lantai_pertama(){ //untuk memeriksa pribadi lantai 1
    struct Kamar tamu;
    FILE *baca = fopen("datatamu.txt","r");
    int i = 0;
    if(baca == NULL){
        printf("\t\t\t\t Belum ada kamar yang disewakan pada lantai ini.\n");
    }else{
        printf("\t\t\t\t Kamar yang sudah dipesan: \n");
        while(!feof(baca)){
            fscanf(baca, "%99[^\n],%d\n", tamu.nik, &tamu.nomor);
            if(tamu.nik >= 101 && tamu.nik <= 105){
                printf("%d. %d\n",i+1,tamu.nomor);
                i++;
            }else{
                printf("\t\t\t\t Belum ada kamar yang disewakan pada lantai ini.\n");
            }
        }
        fclose(baca);
    }
}
void lantai_kedua(){ //untuk memeriksa pribadi lantai 2
    struct Kamar tamu;
    FILE *baca = fopen("datatamu.txt","r");
    int i = 0;
    if(baca == NULL){
        printf("\t\t\t\t Belum ada kamar yang disewakan pada lantai ini.\n");
    }else{
        printf("\t\t\t\t Kamar yang sudah dipesan: \n");
        while(!feof(baca)){
            fscanf(baca, "%99[^\n],%d\n", tamu.nik, &tamu.nomor);
            if(tamu.nik >= 201 && tamu.nik <= 205){
                printf("%d. %d\n",i+1,tamu.nomor);
                i++;
            }else{
                printf("\t\t\t\t Belum ada kamar yang disewakan pada lantai ini.\n");
            }
        }
        fclose(baca);
    }
}
void lantai_ketiga(){ //untuk memeriksa keluarga
    struct Kamar tamu;
    FILE *baca = fopen("datatamu.txt","r");
    int i = 0;
    if(baca == NULL){
        printf("\t\t\t\t Belum ada kamar yang disewakan pada lantai ini.\n");
    }else{
        printf("\t\t\t\t Kamar yang sudah dipesan: \n");
        while(!feof(baca)){
            fscanf(baca, "%99[^\n],%d\n", tamu.nik, &tamu.nomor);
            if(tamu.nik >= 301 && tamu.nik <= 305){
                printf("%d. %d\n",i+1,tamu.nomor);
                i++;
            }else{
                printf("\t\t\t\t Belum ada kamar yang disewakan pada lantai ini.\n");
            }
        }
        fclose(baca);
    }
} */
// menampilkan kamar yang tersedia
void check_apartment()
{
    struct Kamar tamu[15]; // array of struct (gg boys)
    FILE *masuk;
    int kamar[15];
    masuk = fopen("datatamu.txt", "r");
    if (masuk == NULL)
    {
        printf("\t\t\t\t Berkas belum ada atau belum dibuat, terima kasih.\n");
    }
    else
    {
        while (!feof(masuk))
        {
            for (int i = 0; i < 15; i++)
            {
                fscanf(masuk, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", tamu[i].nik, &kamar[i], &tamu[i].total, tamu[i].masuk, tamu[i].keluar);
            }
        }
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15 - i - 1; j++)
            {
                if (kamar[j] < kamar[j + 1])
                {
                    int temp = kamar[j];
                    kamar[j] = kamar[j + 1];
                    kamar[j + 1] = temp;
                }
            }
        }
        // jadi, kamar diurutkan dari nomor yang terbesar.
        system("cls");
        printf("\t\t\t\t Kamar yang sudah dipesan: \n");
        for (int i = 0; i < 15; i++)
        {
            if (kamar[i] >= 101 && kamar[i] <= 105)
                printf("\t\t\t\t %d\n", kamar[i]);
            else if (kamar[i] >= 201 && kamar[i] <= 205)
                printf("\t\t\t\t %d\n", kamar[i]);
            else if (kamar[i] >= 301 && kamar[i] <= 305)
                printf("\t\t\t\t %d\n", kamar[i]);
            else
                printf("\0");
        }
        fclose(masuk);
    }
    /*
    //yang ini tidak jadi karena terjadi bug
    if(masuk == NULL){
        printf("\t\t\t\t Belum ada kamar yang disewakan.\n");
    }else{
        do{
            baca = fscanf(masuk, "%99[^,],%d\n", tamu[i].nomor, kamar[i]);
            i++;
            if(baca == 2){
                printf("\t\t\t\t %d. %d\n",i+1,kamar[i]);
            }else{
                printf("\t\t\t\t Belum ada kamar yang disewakan.");
            }
        }while(!feof(masuk));
    }
    */
    fclose(masuk);
}
/*void bubbleSort(int angka[], int size){
    int i,j,temp;

    for(i=0; i<size-1; i++){
        for(j=0; j<size-1-i; j++){
            if(angka[j] > angka[j+1]){
                temp = angka[j];
                angka[j] = angka[j+1];
                angka
                [j+1] = temp;
            }
        }
    }
*/
/*
    int pilih;
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ******   Pilihan Paket Kamar  ****** ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||   [1]    |     Keluarga              ||\n");
    printf("\t\t\t\t||   [2]    |     Pribadi               ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t||                            [0]KELUAR ||\n");
    printf("\t\t\t\t||===================================== ||\n");
    printf("\t\t\t\t||Masukkan pilihan: ");
    pilih = validasi_angka(0, 2);
    switch(pilih){
        case 1:
            lantai_ketiga();
            break;
        case 2:
            int piliih;
            printf("\t\t\t\t||Masukkan nomor lantai: ");
            piliih = validasi_angka(1, 2);
            switch(piliih){
                case 1:
                    lantai_pertama();
                    break;
                default:
                    lantai_kedua();
            }
            break;
        default:
            printf("\t\t\t\t Terima kasih karena telah menggunakan program ini.\n");
    }
} */
bool modulation_cheker3(struct Kamar tamu, FILE *cekdata)
{
    char temp_nik[20], temp_masuk[20], temp_keluar[20];
    int temp_nomor, temp_total;
    if (cekdata == NULL)
    {
        cekdata = fopen("datatamu.txt", "w");
        return true;
    }
    else
    {
        do
        {
            fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", temp_nik, &temp_nomor, &temp_total, temp_masuk, temp_keluar);
            if (strcmp(temp_nik, tamu.nik) != 0)
            {
                return true;
            }
            else if (temp_nomor != tamu.nomor)
            {
                return true;
            }
            else
            {
                return false;
            }
        } while (!feof(cekdata));
    }
    fclose(cekdata);
}
void tampilkan_tempo(int nomor)
{ // menampilkan jatuh tempo, tapi belum semua.
    FILE *buka;
    char buffer[255];
    system("cls");
    switch (nomor)
    {
    case 101:
        buka = fopen("struk101.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 102:
        buka = fopen("struk102.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 103:
        buka = fopen("struk103.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 104:
        buka = fopen("struk104.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 105:
        buka = fopen("struk105.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 201:
        buka = fopen("struk201.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 202:
        buka = fopen("struk202.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 203:
        buka = fopen("struk203.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 204:
        buka = fopen("struk204.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 205:
        buka = fopen("struk205.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 301:
        buka = fopen("struk301.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 302:
        buka = fopen("struk302.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 303:
        buka = fopen("struk303.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 304:
        buka = fopen("struk304.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    case 305:
        buka = fopen("struk305.txt", "r");
        while (fgets(buffer, 255, buka) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(buka);
        break;
    default:
        printf("\t\t\t\t Tidak ada.\n");
        fclose(buka);
    }
    fclose(buka);
}
void pengecekan_tempo()
{ // jatuh tempo
    FILE *cekdata = fopen("datatamu.txt", "r");
    struct Kamar tamu, tempo;
    bool checker;
    system("cls");
    printf("\t\t\t\t||_________________________________________________||\n");
    printf("\t\t\t\t||                                                 ||\n");
    printf("\t\t\t\t||======  Halo, pelanggan kami yang tercinta  =====||\n");
    printf("\t\t\t\t||                                                 ||\n");
    printf("\t\t\t\t||=================================================||\n");
    printf("\t\t\t\t||Silakan masukkan NIK Anda: ");
    scanf("%[^\n]", tempo.nik);
    getchar();
    if (strlen(tempo.nik) != 16)
    {
        printf("\t\t\t\t Inputan Anda Salah!\n");
        system("pause");
        pengecekan_tempo();
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tempo.nik[i]))
        {
            printf("\t\t\t\t Inputan Anda Salah!\n");
            system("pause");
            pengecekan_tempo();
        }
    }
    printf("\t\t\t\t||Silakan masukkan nomor kamar Anda: ");
    tempo.nomor = validasi_angka(101, 305);
    checker = modulation_cheker3(tempo, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Data tidak ada ....\n");
    }
    else
    {
        tampilkan_tempo(tempo.nomor);
    }
    /*
    if (cekdata == NULL)
    {
        printf("\t\t\t\t Maaf data tamu tidak ada!\n");
    }
    else
    {
        do
        {
            fscanf(cekdata, "%16[^,],%d,%d,%11[^,],%11[^,]\n", tamu.nik, &tamu.nomor, &tamu.total, tamu.masuk, tamu.keluar);
            if (strcmp(tamu.nik, nik) == 1 && tamu.nomor == nomor)
            {
                printf("\t\t\t\t Data Terverifikasi.\n"); // no kamar belom terverif
                tampilkan_tempo(nomor);
                break;
            }
            else
            {
                printf("\t\t\t\t Mohon maaf data tidak ada, mungkin Anda belum registrasi!.\n");
                break;
            }
        } while (!feof(cekdata));
    }
    */fclose(cekdata);
}
void struk_malam(time_t waktu, char nama_pengguna[1024], struct Kamar tamu, int n, int harga, FILE *tulis)
{
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    int a = tm.tm_mday + n;
    if (tm.tm_year % 4 == 0)
    {
        if (tm.tm_mon == 12)
        {
            if (a > 31)
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 31, (tm.tm_mon + 1) - 12, tm.tm_year + 1);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 31, (tm.tm_mon + 1) - 12, tm.tm_year + 1);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
            else
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
        }
        else if (tm.tm_mon == 2)
        {
            if (a > 29)
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 29, tm.tm_mon + 1, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 29, tm.tm_mon + 1, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
            else
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
        }
        else if (tm.tm_mon == 1 && 3 && 5 && 7 && 8 && 10)
        {
            if (a > 31)
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 31, tm.tm_mon + 1, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 31, tm.tm_mon + 1, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
            else
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
        }
        else
        {
            if (a > 30)
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 30, tm.tm_mon + 1, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 30, tm.tm_mon + 1, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
            else
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
        }
    }
    else
    {
        if (tm.tm_mon == 12)
        {
            if (a > 31)
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 31, (tm.tm_mon + 1) - 12, tm.tm_year + 1);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 31, (tm.tm_mon + 1) - 12, tm.tm_year + 1);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
            else
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
        }
        else if (tm.tm_mon == 2)
        {
            if (a > 28)
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 28, tm.tm_mon + 1, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 28, tm.tm_mon + 1, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
            else
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
        }
        else if (tm.tm_mon == 1 && 3 && 5 && 7 && 8 && 10)
        {
            if (a > 31)
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 31, tm.tm_mon + 1, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 31, tm.tm_mon + 1, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
            else
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
        }
        else
        {
            if (a > 30)
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 30, tm.tm_mon + 1, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", (tm.tm_mday + n) - 30, tm.tm_mon + 1, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
            else
            {
                printf("==================================================\n");
                printf("\n");
                printf("   Nama Pemilik    : %s\n", nama_pengguna);
                printf("   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        printf("%c", tamu.nik[i]);
                }
                printf("\n");
                printf("   Nomor Kamar     : %d\n", tamu.nomor);
                printf("   Total           : Rp. %d\n", harga);
                printf("\n");
                printf("==================================================\n");
                printf("\n");
                printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                printf("\n");
                printf("==================================================\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
                fprintf(tulis, "   NIK (ID tamu)   : ");
                for (int i = 0; i < 16; i++)
                {
                    if (i >= 16)
                        break;
                    else
                        fprintf(tulis, "%c", tamu.nik[i]);
                }
                fprintf(tulis, "\n");
                fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
                fprintf(tulis, "   Total           : Rp. %d\n", harga);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fprintf(tulis, "\n");
                fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                fprintf(tulis, "\n");
                fprintf(tulis, "==================================================\n");
                fclose(tulis);
            }
        }
    }
    fclose(tulis);
}
void struk_bulan(time_t waktu, char nama_pengguna[1024], struct Kamar tamu, int n, int harga, FILE *tulis)
{
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    int a = tm.tm_mon + n;
    if (tm.tm_mon == 12)
    {
        printf("==================================================\n");
        printf("\n");
        printf("   Nama Pemilik    : %s\n", nama_pengguna);
        printf("   NIK (ID tamu)   : ");
        for (int i = 0; i < 16; i++)
        {
            if (i >= 16)
                break;
            else
                printf("%c", tamu.nik[i]);
        }
        printf("\n");
        printf("   Nomor Kamar     : %d\n", tamu.nomor);
        printf("   Total           : Rp. %d\n", harga);
        printf("\n");
        printf("==================================================\n");
        printf("\n");
        printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
        printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday, (tm.tm_mon + n) - 12, tm.tm_year + 1);
        printf("\n");
        printf("==================================================\n");
        fprintf(tulis, "==================================================\n");
        fprintf(tulis, "\n");
        fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
        fprintf(tulis, "   NIK (ID tamu)   : ");
        for (int i = 0; i < 16; i++)
        {
            if (i >= 16)
                break;
            else
                fprintf(tulis, "%c", tamu.nik[i]);
        }
        fprintf(tulis, "\n");
        fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
        fprintf(tulis, "   Total           : Rp. %d\n", harga);
        fprintf(tulis, "\n");
        fprintf(tulis, "==================================================\n");
        fprintf(tulis, "\n");
        fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
        fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday, (tm.tm_mon + n) - 12, tm.tm_year + 1);
        fprintf(tulis, "\n");
        fprintf(tulis, "==================================================\n");
        fclose(tulis);
    }
    else
    {
        if (a > 12)
        {
            printf("==================================================\n");
            printf("\n");
            printf("   Nama Pemilik    : %s\n", nama_pengguna);
            printf("   NIK (ID tamu)   : ");
            for (int i = 0; i < 16; i++)
            {
                if (i >= 16)
                    break;
                else
                    printf("%c", tamu.nik[i]);
            }
            printf("\n");
            printf("   Nomor Kamar     : %d\n", tamu.nomor);
            printf("   Total           : Rp. %d\n", harga);
            printf("\n");
            printf("==================================================\n");
            printf("\n");
            printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
            printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday, (tm.tm_mon + n) - 12, tm.tm_year + 1);
            printf("\n");
            printf("==================================================\n");
            fprintf(tulis, "==================================================\n");
            fprintf(tulis, "\n");
            fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
            fprintf(tulis, "   NIK (ID tamu)   : ");
            for (int i = 0; i < 16; i++)
            {
                if (i >= 16)
                    break;
                else
                    fprintf(tulis, "%c", tamu.nik[i]);
            }
            fprintf(tulis, "\n");
            fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
            fprintf(tulis, "   Total           : Rp. %d\n", harga);
            fprintf(tulis, "\n");
            fprintf(tulis, "==================================================\n");
            fprintf(tulis, "\n");
            fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
            fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday, (tm.tm_mon + n) - 12, tm.tm_year + 1);
            fprintf(tulis, "\n");
            fprintf(tulis, "==================================================\n");
            fclose(tulis);
        }
        else
        {
            printf("==================================================\n");
            printf("\n");
            printf("   Nama Pemilik    : %s\n", nama_pengguna);
            printf("   NIK (ID tamu)   : ");
            for (int i = 0; i < 16; i++)
            {
                if (i >= 16)
                    break;
                else
                    printf("%c", tamu.nik[i]);
            }
            printf("\n");
            printf("   Nomor Kamar     : %d\n", tamu.nomor);
            printf("   Total           : Rp. %d\n", harga);
            printf("\n");
            printf("==================================================\n");
            printf("\n");
            printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
            printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + n, tm.tm_year);
            printf("\n");
            printf("==================================================\n");
            fprintf(tulis, "==================================================\n");
            fprintf(tulis, "\n");
            fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
            fprintf(tulis, "   NIK (ID tamu)   : ");
            for (int i = 0; i < 16; i++)
            {
                if (i >= 16)
                    break;
                else
                    fprintf(tulis, "%c", tamu.nik[i]);
            }
            fprintf(tulis, "\n");
            fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
            fprintf(tulis, "   Total           : Rp. %d\n", harga);
            fprintf(tulis, "\n");
            fprintf(tulis, "==================================================\n");
            fprintf(tulis, "\n");
            fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
            fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + n, tm.tm_year);
            fprintf(tulis, "\n");
            fprintf(tulis, "==================================================\n");
            fclose(tulis);
        }
    }
    fclose(tulis);
}
void struk_tahun(time_t waktu, char nama_pengguna[1024], struct Kamar tamu, int n, int harga, FILE *tulis)
{
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    printf("==================================================\n");
    printf("\n");
    printf("   Nama Pemilik    : %s\n", nama_pengguna);
    printf("   NIK (ID tamu)   : ");
    for (int i = 0; i < 16; i++)
    {
        if (i >= 16)
            break;
        else
            printf("%c", tamu.nik[i]);
    }
    printf("\n");
    printf("   Nomor Kamar     : %d\n", tamu.nomor);
    printf("   Total           : Rp. %d\n", harga);
    printf("\n");
    printf("==================================================\n");
    printf("\n");
    printf("   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
    printf("   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year + n);
    printf("\n");
    printf("==================================================\n");
    fprintf(tulis, "==================================================\n");
    fprintf(tulis, "\n");
    fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
    fprintf(tulis, "   NIK (ID tamu)   : ");
    for (int i = 0; i < 16; i++)
    {
        if (i >= 16)
            break;
        else
            fprintf(tulis, "%c", tamu.nik[i]);
    }
    fprintf(tulis, "\n");
    fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
    fprintf(tulis, "   Total           : Rp. %d\n", harga);
    fprintf(tulis, "\n");
    fprintf(tulis, "==================================================\n");
    fprintf(tulis, "\n");
    fprintf(tulis, "   Tanggal Memesan : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
    fprintf(tulis, "   Jatuh Tempo     : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year + n);
    fprintf(tulis, "\n");
    fprintf(tulis, "==================================================\n");
    fclose(tulis);
}
bool modulation_cheker(struct Kamar tamu, FILE *cekdata)
{
    char temp_nik[20], temp_masuk[20], temp_keluar[20];
    int temp_nomor, temp_total;
    do
    {
        fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", temp_nik, &temp_nomor, &temp_total, temp_masuk, temp_keluar);
        if (strcmp(temp_nik, tamu.nik) == 0)
        {
            return true;
        }
        else if (temp_nomor == tamu.nomor)
        {
            return true;
        }
        else
        {
            return false;
        }
    } while (!feof(cekdata));
    fclose(cekdata);
}
void sewa_keluarga_malam(struct Kamar tamu)
{
    // waktu menggunakan localtime.
    FILE *cekdata;
    FILE *tulis;
    FILE *datatamu;
    struct Kamar kamar[15], data, pengunjung;
    char temp_nik[16];
    char nama_pengguna[1024];
    // n adalah lama menyewa;
    int temp_nomor, n, temp_total, temp_masuk, temp_keluar;
    bool check;
    time_t waktu, tanggal;
    tanggal = time(NULL);
    struct tm tm = *localtime(&tanggal);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    int i = 0;
    system("cls");
    printf("\t\t\t\t||Masukkan nama lengkap Anda: ");
    scanf("%[^\n]", nama_pengguna);
    getchar();
    /* This is supposed to be validation
    for(int i = 0; i < 1024; i++){
        if(((int)nama_pengguna[i] >= 0 && (int)nama_pengguna[i] <= 64) || ((int)nama_pengguna[i] >= 91 && (int)nama_pengguna[i] <= 96) || (int)nama_pengguna[i] >= 123){
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Anda memasukkan karakter yang bukan huruf!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            family_machine_night(tamu);
        }
    }
    */
    printf("\t\t\t\t||Masukkan NIK Anda: ");
    // fflush(stdin);
    // fgets(tamu.nik, sizeof(tamu.nik), stdin);
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        sewa_keluarga_malam(tamu);
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tamu.nik[i]))
        {
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            sewa_keluarga_malam(tamu);
        }
    }
    // for(int i = 0; i < 16; i++){
    //   pengunjung.nik[i] = tamu.nik[i];
    //}
    /*
    while(!feof(cekdata)){
        fscanf(cekdata, "%16[^,],%d,%d,%11[^,],%11[^,]\n", kamar[i].nik, &kamar[i].nomor, &kamar[i].total, kamar[i].masuk, kamar[i].keluar);
        for(int j = 0; j < 16; j++){
            if((int)tamu.nik[j] == (int)kamar[i].nik[j]){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                sewa_keluarga_malam(tamu);
            }
        }
        i++;
    }fclose(cekdata);*/
    printf("\t\t\t\t||Masukkan nomor kamar yang diinginkan: ");
    tamu.nomor = validasi_angka(301, 305);
    printf("\t\t\t\t||Berapa malam Anda hendak menyewa: ");
    n = validasi_angka(1, 29);
    system("cls");
    int a = tm.tm_mday + n;
    cekdata = fopen("datatamu.txt", "r");
    check = modulation_cheker(tamu, cekdata);
    fclose(cekdata);
    if (check == true)
    {
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
        system("pause");
    }
    /*
    if(cekdata == NULL){
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t Silakan memesan kamar yang lain.\n");
    }else{
        do{
            fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", temp_nik, &temp_nomor, &temp_total, temp_masuk, temp_keluar);
            if(strcmp(temp_nik, tamu.nik) == 0){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }else if(temp_nomor == tamu.nomor){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }
            else{
                i = 0;
            }
        }while(!feof(cekdata));
        fclose(cekdata);
    }
    */
    else
    {
        /*(strcmp(data.nik, tamu.nik)!=0 && data.nomor != tamu.nomor)*/
        switch (tamu.nomor)
        {
        case 301:
            tulis = fopen("struk301.txt", "w");
            tamu.total = n * KELUARGA_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 302:
            tulis = fopen("struk302.txt", "w");
            tamu.total = n * KELUARGA_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 303:
            tulis = fopen("struk303.txt", "w");
            tamu.total = n * KELUARGA_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 304:
            tulis = fopen("struk304.txt", "w");
            tamu.total = n * KELUARGA_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 305:
            tulis = fopen("struk305.txt", "w");
            tamu.total = n * KELUARGA_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        default:
            printf("Dadaaaaa....");
        }
        datatamu = fopen("datatamu.txt", "a");
        /*
        for(int j = 0; j < 16; j++){
            if(j >= 16) break;
            else fprintf(datatamu, "%c", tamu.nik[j]);
        }*/
        fprintf(datatamu, "%s,%d,%d", tamu.nik, tamu.nomor, tamu.total);
        if (tm.tm_year % 4 == 0)
        {
            if (tm.tm_mon == 12)
            {
                if (a > 31)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 31, (tm.tm_mon + 1) - 12, tm.tm_year + 1);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else if (tm.tm_mon == 2)
            {
                if (a > 29)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 29, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else if (tm.tm_mon == 1 && 3 && 5 && 7 && 8 && 10)
            {
                if (a > 31)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 31, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else
            {
                if (a > 30)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 30, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
        }
        else
        {
            if (tm.tm_mon == 12)
            {
                if (a > 31)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 31, (tm.tm_mon + 1) - 12, tm.tm_year + 1);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else if (tm.tm_mon == 2)
            {
                if (a > 28)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 28, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else if (tm.tm_mon == 1 && 3 && 5 && 7 && 8 && 10)
            {
                if (a > 31)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 31, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else
            {
                if (a > 30)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 30, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
        }
        fclose(datatamu);
    }
    // fclose(cekdata);

    // fclose(cekdata);
}
void sewa_keluarga_bulan(struct Kamar tamu)
{
    // waktu menggunakan localtime.
    FILE *cekdata;
    FILE *tulis;
    FILE *datatamu;
    struct Kamar kamar[15], data, pengunjung;
    char temp_nik[16];
    char nama_pengguna[1024];
    // n adalah lama menyewa;
    int temp_nomor, n, temp_total, temp_masuk, temp_keluar;
    bool check;
    time_t waktu, tanggal;
    tanggal = time(NULL);
    struct tm tm = *localtime(&tanggal);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    int i = 0;
    system("cls");
    printf("\t\t\t\t||Masukkan nama lengkap Anda: ");
    scanf("%[^\n]", nama_pengguna);
    getchar();
    /* This is supposed to be validation
    for(int i = 0; i < 1024; i++){
        if(((int)nama_pengguna[i] >= 0 && (int)nama_pengguna[i] <= 64) || ((int)nama_pengguna[i] >= 91 && (int)nama_pengguna[i] <= 96) || (int)nama_pengguna[i] >= 123){
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Anda memasukkan karakter yang bukan huruf!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            family_machine_night(tamu);
        }
    }
    */
    printf("\t\t\t\t||Masukkan NIK Anda: ");
    // fflush(stdin);
    // fgets(tamu.nik, sizeof(tamu.nik), stdin);
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        sewa_keluarga_bulan(tamu);
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tamu.nik[i]))
        {
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            sewa_keluarga_bulan(tamu);
        }
    }
    // for(int i = 0; i < 16; i++){
    //   pengunjung.nik[i] = tamu.nik[i];
    //}
    /*
    while(!feof(cekdata)){
        fscanf(cekdata, "%16[^,],%d,%d,%11[^,],%11[^,]\n", kamar[i].nik, &kamar[i].nomor, &kamar[i].total, kamar[i].masuk, kamar[i].keluar);
        for(int j = 0; j < 16; j++){
            if((int)tamu.nik[j] == (int)kamar[i].nik[j]){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                sewa_keluarga_malam(tamu);
            }
        }
        i++;
    }fclose(cekdata);*/
    printf("\t\t\t\t||Masukkan nomor kamar yang diinginkan: ");
    tamu.nomor = validasi_angka(301, 305);
    printf("\t\t\t\t||Berapa bulan Anda hendak menyewa: ");
    n = validasi_angka(0, 12);
    int a = tm.tm_mon + n;
    system("cls");
    cekdata = fopen("datatamu.txt", "r");
    check = modulation_cheker(tamu, cekdata);
    fclose(cekdata);
    if (check == true)
    {
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
        system("pause");
    }
    /*
    if(cekdata == NULL){
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t Silakan memesan kamar yang lain.\n");
    }else{
        do{
            fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", temp_nik, &temp_nomor, &temp_total, temp_masuk, temp_keluar);
            if(strcmp(temp_nik, tamu.nik) == 0){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }else if(temp_nomor == tamu.nomor){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }
            else{
                i = 0;
            }
        }while(!feof(cekdata));
        fclose(cekdata);
    }
    */
    else
    {
        /*(strcmp(data.nik, tamu.nik)!=0 && data.nomor != tamu.nomor)*/
        switch (tamu.nomor)
        {
        case 301:
            tulis = fopen("struk301.txt", "w");
            tamu.total = n * KELUARGA_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 302:
            tulis = fopen("struk302.txt", "w");
            tamu.total = n * KELUARGA_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 303:
            tulis = fopen("struk303.txt", "w");
            tamu.total = n * KELUARGA_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 304:
            tulis = fopen("struk304.txt", "w");
            tamu.total = n * KELUARGA_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 305:
            tulis = fopen("struk305.txt", "w");
            tamu.total = n * KELUARGA_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        default:
            printf("Dadaaaaa....");
        }
        datatamu = fopen("datatamu.txt", "a");
        /*
        for(int j = 0; j < 16; j++){
            if(j >= 16) break;
            else fprintf(datatamu, "%c", tamu.nik[j]);
        }*/
        fprintf(datatamu, "%s,%d,%d", tamu.nik, tamu.nomor, tamu.total);
        if (tm.tm_mon == 12)
        {
            fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
            fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday, (tm.tm_mon + n) - 12, tm.tm_year + 1);
        }

        else
        {
            if (a > 12)
            {
                fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday, (tm.tm_mon + n) - 12, tm.tm_year + 1);
            }
            else
            {
                fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + n, tm.tm_year);
            }
        }
        fclose(datatamu);
    }
    // fclose(cekdata);

    // fclose(cekdata);
}
void sewa_keluarga_tahun(struct Kamar tamu)
{
    // waktu menggunakan localtime.
    FILE *cekdata;
    FILE *tulis;
    FILE *datatamu;
    struct Kamar kamar[15], data, pengunjung;
    char temp_nik[16];
    char nama_pengguna[1024];
    // n adalah lama menyewa;
    int temp_nomor, n, temp_total, temp_masuk, temp_keluar;
    bool check;
    time_t waktu, tanggal;
    tanggal = time(NULL);
    struct tm tm = *localtime(&tanggal);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    int i = 0;
    system("cls");
    printf("\t\t\t\t||Masukkan nama lengkap Anda: ");
    scanf("%[^\n]", nama_pengguna);
    getchar();
    /* This is supposed to be validation
    for(int i = 0; i < 1024; i++){
        if(((int)nama_pengguna[i] >= 0 && (int)nama_pengguna[i] <= 64) || ((int)nama_pengguna[i] >= 91 && (int)nama_pengguna[i] <= 96) || (int)nama_pengguna[i] >= 123){
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Anda memasukkan karakter yang bukan huruf!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            family_machine_night(tamu);
        }
    }
    */
    printf("\t\t\t\t||Masukkan NIK Anda: ");
    // fflush(stdin);
    // fgets(tamu.nik, sizeof(tamu.nik), stdin);
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        sewa_keluarga_tahun(tamu);
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tamu.nik[i]))
        {
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            sewa_keluarga_tahun(tamu);
        }
    }
    // for(int i = 0; i < 16; i++){
    //   pengunjung.nik[i] = tamu.nik[i];
    //}
    /*
    while(!feof(cekdata)){
        fscanf(cekdata, "%16[^,],%d,%d,%11[^,],%11[^,]\n", kamar[i].nik, &kamar[i].nomor, &kamar[i].total, kamar[i].masuk, kamar[i].keluar);
        for(int j = 0; j < 16; j++){
            if((int)tamu.nik[j] == (int)kamar[i].nik[j]){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                sewa_keluarga_malam(tamu);
            }
        }
        i++;
    }fclose(cekdata);*/
    printf("\t\t\t\t||Masukkan nomor kamar yang diinginkan: ");
    tamu.nomor = validasi_angka(301, 305);
    printf("\t\t\t\t||Berapa tahun Anda hendak menyewa: ");
    n = validasi_tahun(0);
    int a = tm.tm_mon + n;
    system("cls");
    cekdata = fopen("datatamu.txt", "r");
    check = modulation_cheker(tamu, cekdata);
    fclose(cekdata);
    if (check == true)
    {
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
        system("pause");
    }
    /*
    if(cekdata == NULL){
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t Silakan memesan kamar yang lain.\n");
    }else{
        do{
            fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", temp_nik, &temp_nomor, &temp_total, temp_masuk, temp_keluar);
            if(strcmp(temp_nik, tamu.nik) == 0){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }else if(temp_nomor == tamu.nomor){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }
            else{
                i = 0;
            }
        }while(!feof(cekdata));
        fclose(cekdata);
    }
    */
    else
    {
        /*(strcmp(data.nik, tamu.nik)!=0 && data.nomor != tamu.nomor)*/
        switch (tamu.nomor)
        {
        case 301:
            tulis = fopen("struk301.txt", "w");
            tamu.total = n * KELUARGA_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 302:
            tulis = fopen("struk302.txt", "w");
            tamu.total = n * KELUARGA_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 303:
            tulis = fopen("struk303.txt", "w");
            tamu.total = n * KELUARGA_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 304:
            tulis = fopen("struk304.txt", "w");
            tamu.total = n * KELUARGA_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 305:
            tulis = fopen("struk305.txt", "w");
            tamu.total = n * KELUARGA_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        default:
            printf("Dadaaaaa....");
        }
        datatamu = fopen("datatamu.txt", "a");
        fprintf(datatamu, "%s,%d,%d", tamu.nik, tamu.nomor, tamu.total);
        fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
        fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year + n);
        fclose(datatamu);
    }
    // fclose(cekdata);

    // fclose(cekdata);
}
void sewa_pribadi_malam(struct Kamar tamu)
{
    // waktu menggunakan localtime.
    FILE *cekdata;
    FILE *tulis;
    FILE *datatamu;
    struct Kamar kamar[15], data, pengunjung;
    char temp_nik[16];
    char nama_pengguna[1024];
    // n adalah lama menyewa;
    int temp_nomor, n, temp_total, temp_masuk, temp_keluar;
    bool check;
    time_t waktu, tanggal;
    tanggal = time(NULL);
    struct tm tm = *localtime(&tanggal);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    int i = 0;
    system("cls");
    printf("\t\t\t\t||Masukkan nama lengkap Anda: ");
    scanf("%[^\n]", nama_pengguna);
    getchar();
    /* This is supposed to be validation
    for(int i = 0; i < 1024; i++){
        if(((int)nama_pengguna[i] >= 0 && (int)nama_pengguna[i] <= 64) || ((int)nama_pengguna[i] >= 91 && (int)nama_pengguna[i] <= 96) || (int)nama_pengguna[i] >= 123){
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Anda memasukkan karakter yang bukan huruf!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            family_machine_night(tamu);
        }
    }
    */
    printf("\t\t\t\t||Masukkan NIK Anda: ");
    // fflush(stdin);
    // fgets(tamu.nik, sizeof(tamu.nik), stdin);
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        sewa_pribadi_malam(tamu);
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tamu.nik[i]))
        {
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            sewa_pribadi_malam(tamu);
        }
    }
    // for(int i = 0; i < 16; i++){
    //   pengunjung.nik[i] = tamu.nik[i];
    //}
    /*
    while(!feof(cekdata)){
        fscanf(cekdata, "%16[^,],%d,%d,%11[^,],%11[^,]\n", kamar[i].nik, &kamar[i].nomor, &kamar[i].total, kamar[i].masuk, kamar[i].keluar);
        for(int j = 0; j < 16; j++){
            if((int)tamu.nik[j] == (int)kamar[i].nik[j]){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                sewa_keluarga_malam(tamu);
            }
        }
        i++;
    }fclose(cekdata);*/
    printf("\t\t\t\t||Masukkan nomor kamar yang diinginkan: ");
    tamu.nomor = validasi_angka(101, 205);
    if (tamu.nomor != 101 && tamu.nomor != 102 && tamu.nomor != 103 && tamu.nomor != 104 && tamu.nomor != 105 && tamu.nomor != 201 && tamu.nomor != 202 && tamu.nomor != 203 && tamu.nomor != 204 && tamu.nomor != 205)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        sewa_pribadi_malam(tamu);
    }
    printf("\t\t\t\t||Berapa malam Anda hendak menyewa: ");
    n = validasi_angka(1, 29);
    system("cls");
    int a = tm.tm_mday + n;
    cekdata = fopen("datatamu.txt", "r");
    check = modulation_cheker(tamu, cekdata);
    fclose(cekdata);
    if (check == true)
    {
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
        system("pause");
    }
    /*
    if(cekdata == NULL){
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t Silakan memesan kamar yang lain.\n");
    }else{
        do{
            fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", temp_nik, &temp_nomor, &temp_total, temp_masuk, temp_keluar);
            if(strcmp(temp_nik, tamu.nik) == 0){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }else if(temp_nomor == tamu.nomor){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }
            else{
                i = 0;
            }
        }while(!feof(cekdata));
        fclose(cekdata);
    }
    */
    else
    {
        /*(strcmp(data.nik, tamu.nik)!=0 && data.nomor != tamu.nomor)*/
        switch (tamu.nomor)
        {
        case 101:
            tulis = fopen("struk101.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 102:
            tulis = fopen("struk102.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 103:
            tulis = fopen("struk103.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 104:
            tulis = fopen("struk104.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 105:
            tulis = fopen("struk105.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 201:
            tulis = fopen("struk201.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 202:
            tulis = fopen("struk202.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 203:
            tulis = fopen("struk203.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 204:
            tulis = fopen("struk204.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 205:
            tulis = fopen("struk205.txt", "w");
            tamu.total = n * PRIVATE_MALAM;
            struk_malam(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        default:
            printf("Dadaaaaa....");
        }
        datatamu = fopen("datatamu.txt", "a");
        /*
        for(int j = 0; j < 16; j++){
            if(j >= 16) break;
            else fprintf(datatamu, "%c", tamu.nik[j]);
        }*/
        fprintf(datatamu, "%s,%d,%d", tamu.nik, tamu.nomor, tamu.total);
        if (tm.tm_year % 4 == 0)
        {
            if (tm.tm_mon == 12)
            {
                if (a > 31)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 31, (tm.tm_mon + 1) - 12, tm.tm_year + 1);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else if (tm.tm_mon == 2)
            {
                if (a > 29)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 29, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else if (tm.tm_mon == 1 && 3 && 5 && 7 && 8 && 10)
            {
                if (a > 31)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 31, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else
            {
                if (a > 30)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 30, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
        }
        else
        {
            if (tm.tm_mon == 12)
            {
                if (a > 31)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 31, (tm.tm_mon + 1) - 12, tm.tm_year + 1);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else if (tm.tm_mon == 2)
            {
                if (a > 28)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 28, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else if (tm.tm_mon == 1 && 3 && 5 && 7 && 8 && 10)
            {
                if (a > 31)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 31, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
            else
            {
                if (a > 30)
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", (tm.tm_mday + n) - 30, tm.tm_mon + 1, tm.tm_year);
                }
                else
                {
                    fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                    fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday + n, tm.tm_mon, tm.tm_year);
                }
            }
        }
        fclose(datatamu);
    }
    // fclose(cekdata);

    // fclose(cekdata);
}
void sewa_pribadi_bulan(struct Kamar tamu)
{
    // waktu menggunakan localtime.
    FILE *cekdata;
    FILE *tulis;
    FILE *datatamu;
    struct Kamar kamar[15], data, pengunjung;
    char temp_nik[16];
    char nama_pengguna[1024];
    // n adalah lama menyewa;
    int temp_nomor, n, temp_total, temp_masuk, temp_keluar;
    bool check;
    time_t waktu, tanggal;
    tanggal = time(NULL);
    struct tm tm = *localtime(&tanggal);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    int i = 0;
    system("cls");
    printf("\t\t\t\t||Masukkan nama lengkap Anda: ");
    scanf("%[^\n]", nama_pengguna);
    getchar();
    /* This is supposed to be validation
    for(int i = 0; i < 1024; i++){
        if(((int)nama_pengguna[i] >= 0 && (int)nama_pengguna[i] <= 64) || ((int)nama_pengguna[i] >= 91 && (int)nama_pengguna[i] <= 96) || (int)nama_pengguna[i] >= 123){
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Anda memasukkan karakter yang bukan huruf!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            family_machine_night(tamu);
        }
    }
    */
    printf("\t\t\t\t||Masukkan NIK Anda: ");
    // fflush(stdin);
    // fgets(tamu.nik, sizeof(tamu.nik), stdin);
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        sewa_pribadi_bulan(tamu);
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tamu.nik[i]))
        {
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            sewa_pribadi_bulan(tamu);
        }
    }
    // for(int i = 0; i < 16; i++){
    //   pengunjung.nik[i] = tamu.nik[i];
    //}
    /*
    while(!feof(cekdata)){
        fscanf(cekdata, "%16[^,],%d,%d,%11[^,],%11[^,]\n", kamar[i].nik, &kamar[i].nomor, &kamar[i].total, kamar[i].masuk, kamar[i].keluar);
        for(int j = 0; j < 16; j++){
            if((int)tamu.nik[j] == (int)kamar[i].nik[j]){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                sewa_keluarga_malam(tamu);
            }
        }
        i++;
    }fclose(cekdata);*/
    printf("\t\t\t\t||Masukkan nomor kamar yang diinginkan: ");
    tamu.nomor = validasi_angka(101, 205);
    if (tamu.nomor != 101 && tamu.nomor != 102 && tamu.nomor != 103 && tamu.nomor != 104 && tamu.nomor != 105 && tamu.nomor != 201 && tamu.nomor != 202 && tamu.nomor != 203 && tamu.nomor != 204 && tamu.nomor != 205)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        sewa_pribadi_bulan(tamu);
    }
    printf("\t\t\t\t||Berapa bulan Anda hendak menyewa: ");
    n = validasi_angka(0, 12);
    int a = tm.tm_mon + n;
    system("cls");
    cekdata = fopen("datatamu.txt", "r");
    check = modulation_cheker(tamu, cekdata);
    fclose(cekdata);
    if (check == true)
    {
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
        system("pause");
    }
    /*
    if(cekdata == NULL){
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t Silakan memesan kamar yang lain.\n");
    }else{
        do{
            fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", temp_nik, &temp_nomor, &temp_total, temp_masuk, temp_keluar);
            if(strcmp(temp_nik, tamu.nik) == 0){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }else if(temp_nomor == tamu.nomor){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }
            else{
                i = 0;
            }
        }while(!feof(cekdata));
        fclose(cekdata);
    }
    */
    else
    {
        /*(strcmp(data.nik, tamu.nik)!=0 && data.nomor != tamu.nomor)*/
        switch (tamu.nomor)
        {
        case 101:
            tulis = fopen("struk101.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 102:
            tulis = fopen("struk102.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 103:
            tulis = fopen("struk103.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 104:
            tulis = fopen("struk104.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 105:
            tulis = fopen("struk105.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 201:
            tulis = fopen("struk201.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 202:
            tulis = fopen("struk202.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 203:
            tulis = fopen("struk203.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 204:
            tulis = fopen("struk204.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 205:
            tulis = fopen("struk205.txt", "w");
            tamu.total = n * PRIVATE_BULAN;
            struk_bulan(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        default:
            printf("Dadaaaaa....");
        }
        datatamu = fopen("datatamu.txt", "a");
        /*
        for(int j = 0; j < 16; j++){
            if(j >= 16) break;
            else fprintf(datatamu, "%c", tamu.nik[j]);
        }*/
        fprintf(datatamu, "%s,%d,%d", tamu.nik, tamu.nomor, tamu.total);
        if (tm.tm_mon == 12)
        {
            fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
            fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday, (tm.tm_mon + n) - 12, tm.tm_year + 1);
        }

        else
        {
            if (a > 12)
            {
                fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday, (tm.tm_mon + n) - 12, tm.tm_year + 1);
            }
            else
            {
                fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
                fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + n, tm.tm_year);
            }
        }
        fclose(datatamu);
    }
    // fclose(cekdata);

    // fclose(cekdata);
}
void sewa_pribadi_tahun(struct Kamar tamu)
{
    // waktu menggunakan localtime.
    FILE *cekdata;
    FILE *tulis;
    FILE *datatamu;
    struct Kamar kamar[15], data, pengunjung;
    char temp_nik[16];
    char nama_pengguna[1024];
    // n adalah lama menyewa;
    int temp_nomor, n, temp_total, temp_masuk, temp_keluar;
    bool check;
    time_t waktu, tanggal;
    tanggal = time(NULL);
    struct tm tm = *localtime(&tanggal);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    int i = 0;
    system("cls");
    printf("\t\t\t\t||Masukkan nama lengkap Anda: ");
    scanf("%[^\n]", nama_pengguna);
    getchar();
    /* This is supposed to be validation
    for(int i = 0; i < 1024; i++){
        if(((int)nama_pengguna[i] >= 0 && (int)nama_pengguna[i] <= 64) || ((int)nama_pengguna[i] >= 91 && (int)nama_pengguna[i] <= 96) || (int)nama_pengguna[i] >= 123){
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Anda memasukkan karakter yang bukan huruf!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            family_machine_night(tamu);
        }
    }
    */
    printf("\t\t\t\t||Masukkan NIK Anda: ");
    // fflush(stdin);
    // fgets(tamu.nik, sizeof(tamu.nik), stdin);
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        sewa_keluarga_bulan(tamu);
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tamu.nik[i]))
        {
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            sewa_keluarga_bulan(tamu);
        }
    }
    // for(int i = 0; i < 16; i++){
    //   pengunjung.nik[i] = tamu.nik[i];
    //}
    /*
    while(!feof(cekdata)){
        fscanf(cekdata, "%16[^,],%d,%d,%11[^,],%11[^,]\n", kamar[i].nik, &kamar[i].nomor, &kamar[i].total, kamar[i].masuk, kamar[i].keluar);
        for(int j = 0; j < 16; j++){
            if((int)tamu.nik[j] == (int)kamar[i].nik[j]){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                sewa_keluarga_malam(tamu);
            }
        }
        i++;
    }fclose(cekdata);*/
    printf("\t\t\t\t||Masukkan nomor kamar yang diinginkan: ");
    tamu.nomor = validasi_angka(101, 205);
    if (tamu.nomor != 101 && tamu.nomor != 102 && tamu.nomor != 103 && tamu.nomor != 104 && tamu.nomor != 105 && tamu.nomor != 201 && tamu.nomor != 202 && tamu.nomor != 203 && tamu.nomor != 204 && tamu.nomor != 205)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        sewa_pribadi_tahun(tamu);
    }
    printf("\t\t\t\t||Berapa tahun Anda hendak menyewa: ");
    n = validasi_tahun(0);
    int a = tm.tm_mon + n;
    system("cls");
    cekdata = fopen("datatamu.txt", "r");
    check = modulation_cheker(tamu, cekdata);
    fclose(cekdata);
    if (check == true)
    {
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
        system("pause");
    }
    /*
    if(cekdata == NULL){
        printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t Silakan memesan kamar yang lain.\n");
    }else{
        do{
            fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", temp_nik, &temp_nomor, &temp_total, temp_masuk, temp_keluar);
            if(strcmp(temp_nik, tamu.nik) == 0){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }else if(temp_nomor == tamu.nomor){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t silakan memesan kamar yang lain.\n");
                system("pause");
                i = 1;
            }
            else{
                i = 0;
            }
        }while(!feof(cekdata));
        fclose(cekdata);
    }
    */
    else
    {
        /*(strcmp(data.nik, tamu.nik)!=0 && data.nomor != tamu.nomor)*/
        switch (tamu.nomor)
        {
        case 101:
            tulis = fopen("struk101.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 102:
            tulis = fopen("struk102.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 103:
            tulis = fopen("struk103.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 104:
            tulis = fopen("struk104.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 105:
            tulis = fopen("struk105.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 201:
            tulis = fopen("struk201.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 202:
            tulis = fopen("struk202.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 203:
            tulis = fopen("struk203.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 204:
            tulis = fopen("struk204.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        case 205:
            tulis = fopen("struk205.txt", "w");
            tamu.total = n * PRIVATE_TAHUN;
            struk_tahun(waktu, nama_pengguna, tamu, n, tamu.total, tulis);
            fclose(tulis);
            break;
        default:
            printf("Dadaaaaa....");
        }
        datatamu = fopen("datatamu.txt", "a");
        fprintf(datatamu, "%s,%d,%d", tamu.nik, tamu.nomor, tamu.total);
        fprintf(datatamu, ",%02d/%02d/%04d,", tm.tm_mday, tm.tm_mon, tm.tm_year);
        fprintf(datatamu, "%02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year + n);
        fclose(datatamu);
    }
    // fclose(cekdata);

    // fclose(cekdata);
}
// PROSEDUR UNTUK MENAMPILKAN FASILITAS KAMAR KELUARGA
void fasilitas_keluarga()
{
    struct Kamar tamu;
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||               Facility of Family's Room            ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||                       Facility                     ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||   [1]  | Two Bedroom                               ||\n");
    printf("\t\t\t\t||   [2]  | One Large Double Bed                      ||\n");
    printf("\t\t\t\t||   [3]  | One Single Bed                            ||\n");
    printf("\t\t\t\t||   [4]  | Free Wi-Fi                                ||\n");
    printf("\t\t\t\t||   [5]  | Private Bedroom                           ||\n");
    printf("\t\t\t\t||   [6]  | Private Kitchen                           ||\n");
    printf("\t\t\t\t||   [7]  | Daily Housekeeping                        ||\n");
    printf("\t\t\t\t||   [8]  | Digital television                        ||\n");
    printf("\t\t\t\t||   [9]  | Two Soffa                                 ||\n");
    printf("\t\t\t\t||  [10]  | Shower                                    ||\n");
    printf("\t\t\t\t||  [11]  | Cable Channels                            ||\n");
    printf("\t\t\t\t||  [12]  | Dinning Area                              ||\n");
    printf("\t\t\t\t||  [13]  | Air Conditioning                          ||\n");
    printf("\t\t\t\t||  [14]  | Family Room                               ||\n");
    printf("\t\t\t\t||  [15]  | Desk                                      ||\n");
    printf("\t\t\t\t||  [16]  | Towels                                    ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t|| ****************    List Harga    **************** ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||        Harga           |        Per                ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t|| Rp 500.000,00          | per malam                 ||\n");
    printf("\t\t\t\t|| Rp 13.500.000,00       | per bulan                 ||\n");
    printf("\t\t\t\t|| Rp 156.000.000,00      | per tahun                 ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    system("pause");
    system("cls");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t|| ****************    List Kamar    **************** ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||  Kamar layanan Keluarga terdapat di Lantai Ketiga  ||\n");
    printf("\t\t\t\t||   Dengan nomor kamar dimulai dari 301 sampai 305   ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    system("pause");
    system("cls");
    int pilih;
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ********    Pilihan Paket   ******** ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||   [1]    |      Malaman              ||\n");
    printf("\t\t\t\t||   [2]    |      Bulanan              ||\n");
    printf("\t\t\t\t||   [3]    |      Tahunan              ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t||                            [0]KELUAR ||\n");
    printf("\t\t\t\t||===================================== ||\n");
    printf("\t\t\t\t||Masukkan pilihan: ");
    pilih = validasi_angka(0, 3);
    switch (pilih)
    {
    case 1:
        sewa_keluarga_malam(tamu); // ini dia
        break;
    case 2:
        sewa_keluarga_bulan(tamu);
        break;
    case 3:
        sewa_keluarga_tahun(tamu);
        break;
    default:
        printf("\t\t\t\t Terima kasih karena telah menggunakan program ini.\n");
    }
}
// PROSEDUR UNTUK MENAMPILKAN FASILITAS KAMAR PRIBADI
void fasilitas_pribadi()
{
    struct Kamar tamu;
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||               Facility of Private Room             ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||                       Facility                     ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||   [1]  | One Bedroom                               ||\n");
    printf("\t\t\t\t||   [2]  | One Large Double Bed                      ||\n");
    printf("\t\t\t\t||   [3]  | Free Wi-Fi                                ||\n");
    printf("\t\t\t\t||   [4]  | Private Bathroom                          ||\n");
    printf("\t\t\t\t||   [5]  | Private Kitchen                           ||\n");
    printf("\t\t\t\t||   [6]  | Daily House Keeping                       ||\n");
    printf("\t\t\t\t||   [7]  | Digital television                        ||\n");
    printf("\t\t\t\t||   [8]  | Soffa                                     ||\n");
    printf("\t\t\t\t||   [9]  | Shower                                    ||\n");
    printf("\t\t\t\t||  [10]  | Cable Channels                            ||\n");
    printf("\t\t\t\t||  [11]  | Dinning Area                              ||\n");
    printf("\t\t\t\t||  [12]  | Desk                                      ||\n");
    printf("\t\t\t\t||  [13]  | Towels                                    ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t|| ****************    List Harga    **************** ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||        Harga           |        Per                ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t|| Rp 350.000,00          | per malam                 ||\n");
    printf("\t\t\t\t|| Rp 9.000.000,00        | per bulan                 ||\n");
    printf("\t\t\t\t|| Rp 98.000.000,00       | per tahun                 ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    system("pause");
    system("cls");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t|| ****************    List Kamar    **************** ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||   Kamar layanan Pribadi terdapat di Lantai Kedua   ||\n");
    printf("\t\t\t\t||   Dengan nomor kamar dimulai dari 201 sampai 205   ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||  Kamar layanan Pribadi terdapat di Lantai Pertama  ||\n");
    printf("\t\t\t\t||   Dengan nomor kamar dimulai dari 101 sampai 105   ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    system("pause");
    system("cls");
    int pilih;
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ********    Pilihan Paket   ******** ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||   [1]    |      Malaman              ||\n");
    printf("\t\t\t\t||   [2]    |      Bulanan              ||\n");
    printf("\t\t\t\t||   [3]    |      Tahunan              ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t||                            [0]KELUAR ||\n");
    printf("\t\t\t\t||===================================== ||\n");
    printf("\t\t\t\t||Masukkan pilihan: ");
    pilih = validasi_angka(0, 3);
    switch (pilih)
    {
    case 1:
        sewa_pribadi_malam(tamu);
        break;
    case 2:
        sewa_pribadi_bulan(tamu);
        break;
    case 3:
        sewa_pribadi_tahun(tamu);
        break;
    default:
        printf("\t\t\t\t Terima kasih karena telah menggunakan program ini.\n");
    }
}
// PROSEDUR PILIHAN PAKET KAMAR
void paketan()
{
    int pilih;
    system("cls");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ******   Pilihan Paket Kamar  ****** ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||   [1]    |     Keluarga              ||\n");
    printf("\t\t\t\t||   [2]    |     Pribadi               ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t||                            [0]KELUAR ||\n");
    printf("\t\t\t\t||===================================== ||\n");
    printf("\t\t\t\t||Masukkan pilihan: ");
    pilih = validasi_angka(0, 2);
    system("cls");
    switch (pilih)
    {
    case 1:
        fasilitas_keluarga();
        break;
    case 2:
        fasilitas_pribadi();
        break;
    default:
        printf("\t\t\t\t Terima kasih karena telah menggunakan program ini.\n");
    }
}
struct Laundry
{
    char nik[20];
    char username[1024];
    int nomor;
};
bool modulation_laundry(struct Laundry layan, FILE *fptr)
{
    struct Kamar tamu;
    fptr = fopen("datatamu.txt", "r");
    do
    {
        fscanf(fptr, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", tamu.nik, &tamu.nomor, &tamu.total, tamu.masuk, tamu.keluar);
        if (strcmp(layan.nik, tamu.nik) == 0 && layan.nomor == tamu.nomor)
        {
            return false;
        }
        else
        {
            return true;
        }
    } while (!feof(fptr));
    fclose(fptr);
}
void laundry()
{
    system("cls");
    bool checker;
    struct Laundry layan;
    struct Kamar tamu[15];
    FILE *bersih, *periksa;
    printf("\t\t\t\t || ==================================================================== ||\n");
    printf("\t\t\t\t ||                         WELCOME TO APART LAUNDRY                     ||\n");
    printf("\t\t\t\t || ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, ||\n");
    printf("\t\t\t\t ||                            I N F O R M A S I                         ||\n");
    printf("\t\t\t\t ||                              L A U N D R Y                           ||\n");
    printf("\t\t\t\t || ==================================================================== ||\n");
    printf("\t\t\t\t ||     Laundry ini merupakan layanan tambahan yang ada di Apartemen     ||\n");
    printf("\t\t\t\t ||                            J U N E K A R T A                         ||\n");
    printf("\t\t\t\t ||    Customer dapat menggunakan layanan ini apabila sudah melakukan    ||\n");
    printf("\t\t\t\t ||  registrasi di Apartment. Layanan laundry dihitung berdasarkan berat ||\n");
    printf("\t\t\t\t ||        dari pakaian customer, setiap kg serharga Rp. 7.999,00.       ||\n");
    printf("\t\t\t\t || ==================================================================== ||\n");
    system("pause");
    system("cls");
    printf("\t\t\t\t    SILAKAN MELAKUKAN  REGISTRASI\n");
    printf("\t\t\t\t || Masukkan NIK Anda               : ");
    scanf("%[^\n]", layan.nik);
    getchar();
    if (strlen(layan.nik) != 16)
    {
        printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        laundry();
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(layan.nik[i]))
        {
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            laundry();
        }
    }
    printf("\t\t\t\t || Masukkan nomor kamar Anda       : ");
    layan.nomor = validasi_angka(101, 305);
    printf("\t\t\t\t || Buat username yang Anda inginkan: ");
    scanf("%[^\n]", layan.username);
    getchar();
    int n = strlen(layan.username);
    int i = 0;
    periksa = fopen("datatamu.txt", "r");
    checker = modulation_laundry(layan, periksa);
    fclose(periksa);
    while (!feof(periksa))
    {
        fscanf(periksa, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", tamu[i].nik, &tamu[i].nomor, &tamu[i].total, tamu[i].masuk, tamu[i].keluar);
        if (strcmp(tamu[i].nik, layan.nik) != 0 || tamu[i].nomor != layan.nomor)
        {
            printf("\t\t\t\t Maaf kamu tidak bisa mendaftar.\n\t\t\t\t Kamu belum memesan apartemen.\n\t\t\t\t Silakan melakukan pemesanan terlebih dahulu!\n");
            system("pause");
            system("cls");
            mainmenu();
            exit(0);
            break;
            checker = true;
        }
        i++;
    }
    for (int i = 0; i < 15; i++)
    {
        if (strcmp(tamu[i].nik, layan.nik) == 0 || tamu[i].nomor == layan.nomor)
        {
            checker = false;
            break;
        }
        else
        {
            checker = true;
            break;
        }
    }
    if (checker == true)
    {
        system("cls");
        printf("\t\t\t\t Maaf kamu tidak bisa mendaftar.\n\t\t\t\t Kamu belum memesan apartemen.\n\t\t\t\t Silakan melakukan pemesanan terlebih dahulu!\n");
        system("pause");
    }
    else
    {
        if (layan.nomor == 101)
            bersih = fopen("kartulaundry101.txt", "w");
        else if (layan.nomor == 102)
            bersih = fopen("kartulaundry102.txt", "w");
        else if (layan.nomor == 103)
            bersih = fopen("kartulaundry103.txt", "w");
        else if (layan.nomor == 104)
            bersih = fopen("kartulaundry104.txt", "w");
        else if (layan.nomor == 105)
            bersih = fopen("kartulaundry105.txt", "w");
        else if (layan.nomor == 201)
            bersih = fopen("kartulaundry201.txt", "w");
        else if (layan.nomor == 202)
            bersih = fopen("kartulaundry202.txt", "w");
        else if (layan.nomor == 203)
            bersih = fopen("kartulaundry203.txt", "w");
        else if (layan.nomor == 204)
            bersih = fopen("kartulaundry204.txt", "w");
        else if (layan.nomor == 205)
            bersih = fopen("kartulaundry205.txt", "w");
        else if (layan.nomor == 301)
            bersih = fopen("kartulaundry301.txt", "w");
        else if (layan.nomor == 302)
            bersih = fopen("kartulaundry302.txt", "w");
        else if (layan.nomor == 303)
            bersih = fopen("kartulaundry303.txt", "w");
        else if (layan.nomor == 304)
            bersih = fopen("kartulaundry304.txt", "w");
        else
            bersih = fopen("kartulaundry305.txt", "w");
        printf("====================================================================\n");
        printf("                         KARTU LAUNDRY\n");
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf("\n");
        printf("   Username    : ");
        for (int i = 0; i < n; i++)
        {
            printf("%c", layan.username[i]);
            if (layan.username[i] == '\0')
                break;
        }
        printf("\n");
        printf("   NIK         : ");
        for (int i = 0; i < 16; i++)
        {
            if (i >= 16)
                break;
            else
                printf("%c", layan.nik[i]);
        }
        printf("\n");
        printf("   Nomor Kamar : %d\n", layan.nomor);
        printf("\n");
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf("\n");
        printf("====================================================================\n");
        fprintf(bersih, "====================================================================\n");
        fprintf(bersih, "                         KARTU LAUNDRY\n");
        fprintf(bersih, ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        fprintf(bersih, "\n");
        fprintf(bersih, "   Username    : ");
        for (int i = 0; i < n; i++)
        {
            fprintf(bersih, "%c", layan.username[i]);
            if (layan.username[i] == '\0')
                break;
        }
        fprintf(bersih, "\n");
        fprintf(bersih, "   NIK         : ");
        for (int i = 0; i < 16; i++)
        {
            if (i >= 16)
                break;
            else
                fprintf(bersih, "%c", layan.nik[i]);
        }
        fprintf(bersih, "\n");
        fprintf(bersih, "   Nomor Kamar : %d\n", layan.nomor);
        fprintf(bersih, "\n");
        fprintf(bersih, ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        fprintf(bersih, "\n");
        fprintf(bersih, "====================================================================\n");
        fclose(bersih);
        system("pause");
        system("cls");
    }
}
// BREAKFAST
bool modulation_breakfast(struct Kamar tamu, FILE *fptr)
{
    struct Kamar tempo;
    if (fptr == NULL)
    {
        return true;
    }
    else
    {
        do
        {
            fscanf(fptr, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", tempo.nik, &tempo.nomor, &tempo.total, tempo.masuk, tempo.keluar);
            if (strcmp(tempo.nik, tamu.nik) != 0 && tempo.nomor != tamu.nomor)
            {
                return true;
            }
            else if (strcmp(tempo.nik, tamu.nik) != 0 && tempo.nomor == tamu.nomor)
            {
                return true;
            }
            else if (strcmp(tempo.nik, tamu.nik) == 0 && tempo.nomor != tamu.nomor)
            {
                return true;
            }
            else
            {
                return false;
            }
        } while (!feof(fptr));
        fclose(fptr);
    }
}
bool modulation_breakfast_true()
{
    return true;
}
bool modulation_breakfast_false()
{
    return false;
}
void breakfast_print(struct Kamar tamu, FILE *tulis, int n, char nama_pengguna[1024]);
void breakfast()
{
    bool checker, checker2;
    struct Kamar tamu, tempo[15];
    FILE *tulis, *cekdata, *cekdata2, validasi;
    int n, i = 0, stop = 0;
    char nama[1024];
    system("cls");
    printf("\t\t\t\t || ==================================================================== ||\n");
    printf("\t\t\t\t ||                           LAYANAN BREAKFAST                          ||\n");
    printf("\t\t\t\t || ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, ||\n");
    printf("\t\t\t\t ||                           I N F O R M A S I                          ||\n");
    printf("\t\t\t\t ||                           B R E A K F A S T                          ||\n");
    printf("\t\t\t\t || ==================================================================== ||\n");
    printf("\t\t\t\t ||      Breakfast merupakan layanan tambahan yang ada di Apartemen      ||\n");
    printf("\t\t\t\t ||                           J U N E K A R T A                          ||\n");
    printf("\t\t\t\t ||    Customer dapat menggunakan layanan ini apabila sudah melakukan    ||\n");
    printf("\t\t\t\t ||   registrasi di Apartment. Layanan breakfast dihitung berdasarkan    ||\n");
    printf("\t\t\t\t ||  lama customer ingin memesan menggunakan layanan ini. Layanan dapat  ||\n");
    printf("\t\t\t\t ||  diperpanjang sesuai keinginan dengan biaya Rp. 129.999,00 per hari. ||\n");
    printf("\t\t\t\t || ==================================================================== ||\n");
    system("pause");
    system("cls");
    printf("\t\t\t\t || Masukkan nama lengkap Anda : ");
    scanf("%[^\n]", nama);
    getchar();
    printf("\t\t\t\t || Masukkan NIK Anda          : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Input kamu salah!\n\t\t\t\t Harap masukkan kembali!\n");
        system("pause");
        breakfast();
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tamu.nik[i]))
        {
            printf("\t\t\t\t Input kamu salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            breakfast();
        }
    }
    printf("\t\t\t\t || Masukkan nomor kamar Anda  : ");
    tamu.nomor = validasi_angka(101, 305);
    printf("\t\t\t\t || Masukkan lama penggunaan   : ");
    n = validasi_angka(1, 365);
    system("cls");
    cekdata = fopen("datatamu.txt", "r");
    checker = modulation_breakfast(tamu, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Kamu belum memesan layanan apartemen.\n\t\t\t\t Atau kamu salah memasukkan data.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        cekdata2 = fopen("datatamu.txt", "r");
        do
        {
            fscanf(cekdata2, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", tempo[i].nik, &tempo[i].nomor, &tempo[i].total, tempo[i].masuk, tempo[i].keluar);
            if (strcmp(tamu.nik, tempo[i].nik) == 0 && tempo[i].nomor == tempo[i].nomor)
            {
                fclose(cekdata2);
                tamu.total = tempo[i].total;
                sprintf(tamu.masuk, "%s", tempo[i].masuk);
                sprintf(tamu.keluar, "%s", tempo[i].keluar);
                checker2 = modulation_breakfast_false();
                stop = 0;
            }
            else
            {
                checker2 = modulation_breakfast_true();
                stop = 1;
                continue;
            }
            i++;
        } while (!feof(cekdata2) && stop == 1);
        fclose(cekdata2);
    }
    if (checker2 == true)
    {
        printf("\t\t\t\t Kamu belum memesan layanan apartemen.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        breakfast_print(tamu, tulis, n, nama);
        fclose(tulis);
        system("pause");
    }
}
void breakfast_print2(struct Kamar tamu, FILE *tulis, int n, char nama_pengguna[1024], int total);
void breakfast_print(struct Kamar tamu, FILE *tulis, int n, char nama_pengguna[1024])
{
    int total;
    total = (n * SARAPAN) + tamu.total;
    switch (tamu.nomor)
    {
    case 101:
        tulis = fopen("struk101.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 102:
        tulis = fopen("struk102.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 103:
        tulis = fopen("struk103.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 104:
        tulis = fopen("struk104.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 105:
        tulis = fopen("struk105.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 201:
        tulis = fopen("struk201.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 202:
        tulis = fopen("struk202.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 203:
        tulis = fopen("struk203.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 204:
        tulis = fopen("struk204.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 205:
        tulis = fopen("struk205.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 301:
        tulis = fopen("struk301.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 302:
        tulis = fopen("struk302.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 303:
        tulis = fopen("struk303.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 304:
        tulis = fopen("struk304.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    case 305:
        tulis = fopen("struk305.txt", "w");
        breakfast_print2(tamu, tulis, n, nama_pengguna, total);
        fclose(tulis);
        break;
    default:
        printf("Error\n");
    }
    fclose(tulis);
}
void breakfast_print2(struct Kamar tamu, FILE *tulis, int n, char nama_pengguna[1024], int total)
{
    printf("==================================================\n");
    printf("\n");
    printf("   Nama Pemilik    : %s\n", nama_pengguna);
    printf("   NIK (ID tamu)   : %s\n", tamu.nik);
    printf("\n");
    printf("   Nomor Kamar     : %d\n", tamu.nomor);
    printf("   Layanan Tambahan: Breakfast %d hari.\n", n);
    printf("   Total           : Rp. %d\n", total);
    printf("\n");
    printf("==================================================\n");
    printf("\n");
    printf("   Tanggal Memesan : %s\n", tamu.masuk);
    printf("   Jatuh Tempo     : %s\n", tamu.keluar);
    printf("\n");
    printf("==================================================\n");
    fprintf(tulis, "==================================================\n");
    fprintf(tulis, "\n");
    fprintf(tulis, "   Nama Pemilik    : %s\n", nama_pengguna);
    fprintf(tulis, "   NIK (ID tamu)   : %s\n", tamu.nik);
    fprintf(tulis, "\n");
    fprintf(tulis, "   Nomor Kamar     : %d\n", tamu.nomor);
    fprintf(tulis, "   Layanan Tambahan: Breakfast %d hari.\n", n);
    fprintf(tulis, "   Total           : Rp. %d\n", total);
    fprintf(tulis, "\n");
    fprintf(tulis, "==================================================\n");
    fprintf(tulis, "\n");
    fprintf(tulis, "   Tanggal Memesan : %s\n", tamu.masuk);
    fprintf(tulis, "   Jatuh Tempo     : %s\n", tamu.keluar);
    fprintf(tulis, "\n");
    fprintf(tulis, "==================================================\n");
    char buffer[255];
    fclose(tulis);
    FILE *breakfast = fopen("breakfastbook.txt", "a");
    sprintf(buffer, "%s,%d,%d,%s,%s\n", tamu.nik, tamu.nomor, total - tamu.total, tamu.masuk, tamu.keluar);
    fprintf(breakfast, "%s", buffer);
    fclose(breakfast);
}
// PROSEDUR UNTUK TAMBAHAN LAYANAN YANG ADA DI APARTMENT
void tambahanlayanan()
{
    system("cls");
    printf("\t\t\t\t|| ===================================================== ||\n");
    printf("\t\t\t\t||                  LAYANAN TAMBAHAN                     ||\n");
    printf("\t\t\t\t|| ===================================================== ||\n");
    printf("\t\t\t\t||         L A Y A N A N         |       H A R G A       ||\n");
    printf("\t\t\t\t|| ===================================================== ||\n");
    printf("\t\t\t\t||   [1]  | Laundry              |  Rp. 7.999 /kg        ||\n");
    printf("\t\t\t\t||   [2]  | Breakfast            |  Rp. 59.999 /pagi     ||\n");
    printf("\t\t\t\t||   [0]  | Kembali ke menu awal                         ||\n");
    printf("\t\t\t\t|| ===================================================== ||\n");
    int tambah;
    printf("\t\t\t\t|| Masukkan pilihan: ");
    tambah = validasi_angka(0, 2);
    switch (tambah)
    {
    case 1:
        laundry();
        break;
    case 2:
        breakfast();
        break;
    default:
        printf("\t\t\t\t Terima kasih karena telah menggunakan layanan kami.\n");
    }
}
// TAMPILAN SELAMAT DATANG LAUNDRY
//  PROSEDUR BATALKAN PESANAN
bool modulation_cancelation(struct Kamar tamu, FILE *fptr)
{
    struct Kamar tempo[15];
    int i;
    do
    {
        fscanf(fptr, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", tempo[i].nik, &tempo[i].nomor, &tempo[i].total, tempo[i].masuk, tempo[i].keluar);
        if (strcmp(tempo[i].nik, tamu.nik) == 0 && tempo[i].nomor == tamu.nomor)
        {
            return false;
            break;
        }
        else
        {
            return true;
        }
        i++;
    } while (!feof(fptr));
    fclose(fptr);
}
void renama();
void batalkan_case(int nomor);
void batalkan_pesanan()
{
    FILE *cekdata;
    FILE *temp;
    FILE *tulisdata;
    FILE *batal;
    time_t waktu;
    struct Kamar tamu, tempo[15];
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    bool checker;
    int i = 0;
    system("cls");
    printf("\t\t\t\t||Masukkan NIK Anda             : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t  Anda salah memasukkan input!\n");
        system("pause");
        batalkan_pesanan();
    }
    for (int j = 0; j < 16; j++)
    {
        if (!isdigit(tamu.nik[j]))
        {
            printf("\t\t\t\t  Anda salah memasukkan input!\n");
            system("pause");
            batalkan_pesanan();
        }
    }
    printf("\t\t\t\t||Masukkan nomor apartemen Anda : ");
    tamu.nomor = validasi_angka(101, 305);
    cekdata = fopen("datatamu.txt", "r");
    checker = modulation_cancelation(tamu, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Maaf Anda belum memesan apartemen.\n\t\t\t\t Atau Anda menginput data yang salah.\n\t\t\t\t Silakan kembali ke halaman awal.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }

    else
    {
        char buffer[1024];
        temp = fopen("datatamu.txt", "r");
        do
        {
            tulisdata = fopen("backup.txt", "a");
            fscanf(temp, "%19[^,],%d,%d,%19[^,],%19[^\n]\n", tempo[i].nik, &tempo[i].nomor, &tempo[i].total, tempo[i].masuk, tempo[i].keluar);
            if (strcmp(tempo[i].nik, tamu.nik) == 0 && tempo[i].nomor == tamu.nomor)
            {
                printf("\t\t\t\t Terima kasih telah menggunakan layanan kami.\n\t\t\t\t Pengembalian dana sebesar 49%%.\n");
                printf("|| Tanggal Memesan         : %s\n", tempo[i].masuk);
                printf("|| Tanggal Pembatalan      : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("|| Total Pengembalian Dana : %.0lf\n", (double)tempo[i].total - (double)((0.51) * tempo[i].total));
                sprintf(buffer, "%s,%d,%d,%s,%02d/%02d/%04d\n", tamu.nik, tamu.nomor, (double)tempo[i].total - (double)((0.51) * tempo[i].total), tempo[i].masuk, tm.tm_mday, tm.tm_mon, tm.tm_year);
                continue;
            }
            else
            {
                fprintf(tulisdata, "%s,%d,%d,%s,%s\n", tempo[i].nik, tempo[i].nomor, tempo[i].total, tempo[i].masuk, tempo[i].keluar);
            }
            i++;
        } while (!feof(temp));
        fclose(tulisdata);
        fclose(temp);
        batal = fopen("riwayatpembatalan.txt", "a");
        fprintf(batal, "%s", buffer);
        fclose(batal);
        // periksa = 1;
        //}
        // if (periksa != 1)
        //{
        // printf("\t\t\t\t Terjadi kesalahan dalam program.\n\t\t\t\t Harap hubungi admin di nomor:\n\t\t\t\t +62XXXXXXXXXXX\n");
        // system("pause");
        // system("cls");
        // mainmenu();
        // exit(0);
        //}
        batalkan_case(tamu.nomor);
        fclose(cekdata);
        fclose(temp);
        fclose(tulisdata);
        fclose(batal);
        renama();
    }
}
void renama()
{
    if (remove("datatamu.txt") != 0)
    {
        fprintf(stderr, "%d\n", errno);
        perror("Error msg");
    }
    else
        printf("ok");
    if (rename("backup.txt", "datatamu.txt") != 0)
    {
        fprintf(stderr, "%d\n", errno);
        perror("Error msg");
    }
    else
        printf("ok");
    printf("\t\t\t\t Pembatalan berhasil.\n\t\t\t\t Sampai jumpa di lain hari :)\n");
    system("pause");
    system("cls");
    mainmenu();
    exit(0);
}
void batalkan_case(int nomor)
{
    switch (nomor)
    {
    case 101:
        remove("struk101.txt");
        remove("kartulaundry101.txt");
        break;
    case 102:
        remove("struk102.txt");
        remove("kartulaundry102.txt");
        break;
    case 103:
        remove("struk103.txt");
        remove("kartulaundry103.txt");
        break;
    case 104:
        remove("struk104.txt");
        remove("kartulaundry104.txt");
        break;
    case 105:
        remove("struk105.txt");
        remove("kartulaundry105.txt");
        break;
    case 201:
        remove("struk201.txt");
        remove("kartulaundry201.txt");
        break;
    case 202:
        remove("struk202.txt");
        remove("kartulaundry202.txt");
        break;
    case 203:
        remove("struk203.txt");
        remove("kartulaundry203.txt");
        break;
    case 204:
        remove("struk204.txt");
        remove("kartulaundry204.txt");
        break;
    case 205:
        remove("struk205.txt");
        remove("kartulaundry205.txt");
        break;
    case 301:
        remove("struk301.txt");
        remove("kartulaundry301.txt");
        break;
    case 302:
        remove("struk302.txt");
        remove("kartulaundry302.txt");
        break;
    case 303:
        remove("struk303.txt");
        remove("kartulaundry303.txt");
        break;
    case 304:
        remove("struk304.txt");
        remove("kartulaundry304.txt");
        break;
    case 305:
        remove("struk305.txt");
        remove("kartulaundry305.txt");
        break;
    default:
        printf("Error ....");
    }
}
void ulang_ulang();
void mainmenu()
{
    FILE *buat = fopen("datatamu.txt", "a");
    fclose(buat);
    int ulang;
    do
    {
        menu();
        pilih = validasi_angka(0, 5);
        switch (pilih)
        {
        case 1:
            check_apartment();
            system("pause");
            break;
        case 2:
            pengecekan_tempo();
            system("pause");
            break;
        case 3:
            paketan();
            system("pause");
            break;
        case 4:
            tambahanlayanan();
            system("cls");
            system("pause");
            break;
        case 5:
            batalkan_pesanan();
            break;
        default:
            printf("\t\t\t\t Terima kasih karena telah menggunakan program ini.\n");
            system("pause");
        }
        ulang_ulang();
        ulang = validasi_angka(0, 1);
        system("cls");
        system("pause");
        system("cls");
    } while (ulang == 1);
}
// prosedur untuk pilihan ingin mengulang program
void ulang_ulang()
{
    system("cls");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| *****  Apakah ingin mengulang?  **** ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||   [0]    |     Tidak                 ||\n");
    printf("\t\t\t\t||   [1]    |     Iya                   ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t|| Masukkan pilihan: ");
}