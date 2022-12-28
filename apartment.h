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
#define SARAPAN 59999
struct Apartemen
{
    char nik[20], masuk[20], keluar[20];
    int nomor, total, hari;
};
void mainmenu();
void case_hapus_struk(int nomor);
void case_tempo(int nomor, FILE *buka);
void struk_breakfast(struct Apartemen tamu, char nama[1024], int harga, int day, FILE *fptr);
void case_breakfast(struct Apartemen tamu, char nama[1024], int harga, int day, FILE *fptr);
int validasi_angka(int range1, int range2)
{
    char buffer[255], invalid;
    int valid;
    scanf("%[^\n]", buffer);
    getchar();
    if (sscanf(buffer, "%d%c", &valid, invalid) == 1 && valid >= range1 && valid <= range2)
    {
        return valid;
    }
    else
    {
        printf("\t\t\t\t Input Anda salah!\n\t\t\t\t Silakan masukkan kembali!\n\t\t\t\t >> ");
        validasi_angka(range1, range2);
    }
}
int validasi_tahun(int minimum)
{
    char buffer[255], invalid;
    int valid;
    scanf("%[^\n]", buffer);
    getchar();
    if (sscanf(buffer, "%d%c", &valid, invalid) == 1 && valid >= minimum)
    {
        return valid;
    }
    else
    {
        printf("\t\t\t\t Input Anda salah!\n\t\t\t\t Silakan masukkan kembali!\n\t\t\t\t >> ");
        validasi_tahun(minimum);
    }
}
void pengecekkan_apartemen()
{
    struct Apartemen tempo;
    FILE *ambil = fopen("datatamu.txt", "r");
    int i = 0, nomor[15];
    char line[255];
    while (fgets(line, sizeof(line), ambil) != NULL)
    {
        sscanf(line, "%19[^,],%d,%d,%19[^,],%19[^,],%d\n", tempo.nik, &tempo.nomor, &tempo.total, tempo.masuk, tempo.keluar, &tempo.hari);
        nomor[i] = tempo.nomor;
        i++;
    }
    fclose(ambil);
    int n = sizeof(nomor) / sizeof(nomor[0]);
    for (int j = 0; j < n - 1; j++)
    {
        for (int k = 0; k < n - j - 1; k++)
        {
            if (nomor[k] < nomor[k + 1])
            {
                int temp = nomor[k];
                nomor[k] = nomor[k + 1];
                nomor[k + 1] = temp;
            }
        }
    }
    printf("\t\t\t\t|| Apartemen yang sudah berpenghuni: \n");
    int x = 0;
    while (nomor[x] == 101 || nomor[x] == 102 || nomor[x] == 103 || nomor[x] == 104 || nomor[x] == 105 || nomor[x] == 201 || nomor[x] == 202 || nomor[x] == 203 || nomor[x] == 204 || nomor[x] == 205 || nomor[x] == 301 || nomor[x] == 302 || nomor[x] == 303 || nomor[x] == 304 || nomor[x] == 305)
    {
        printf("\t\t\t\t|| %d\n", nomor[x]);
        x++;
    }
}
void struk_malam(int day, int month, int year, int n, char nama[1024], struct Apartemen tamu, FILE *tulisdata)
{
    system("cls");
    time_t tiktok = time(NULL);
    int a_day = tiktok / 86400;
    char buffer[1024];
    FILE *datatamu = fopen("datatamu.txt", "a");
    int tanggal = n + day;
    if (year % 4 == 0)
    {
        if (month == 12)
        {
            if (tanggal > 31)
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 31, (month + 1) - 12, year + 1);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 31, (month + 1) - 12, year + 1);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal - 31, (month + 1) - 12, year + 1);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
            else
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal, month, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
        }
        else if (month == 2)
        {
            if (tanggal > 29)
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 29, month + 1, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 29, month + 1, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal - 29, month + 1, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
            else
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Jatuh Tempo      : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", tanggal, month, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal, month, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
        }
        else if (month == 1 || 3 || 5 || 7 || 8 || 10)
        {
            if (tanggal > 31)
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 31, month + 1, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 31, month + 1, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal - 31, month + 1, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
            else
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal, month, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
        }
        else
        {
            if (tanggal > 31)
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 31, month + 1, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 30, month + 1, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal - 30, month + 1, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
            else
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal, month, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
        }
    }
    else
    {
        if (month == 12)
        {
            if (tanggal > 31)
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 31, (month + 1) - 12, year + 1);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 31, (month + 1) - 12, year + 1);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal - 31, (month + 1) - 12, year + 1);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
            else
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal, month, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
        }
        else if (month == 2)
        {
            if (tanggal > 28)
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 28, month + 1, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 28, month + 1, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal - 28, month + 1, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
            else
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal, month, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
        }
        else if (month == 1 || 3 || 5 || 7 || 8 || 10)
        {
            if (tanggal > 31)
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 31, month + 1, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 31, month + 1, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal - 31, month + 1, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
            else
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal, month, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
        }
        else
        {
            if (tanggal > 30)
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 30, month + 1, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal - 30, month + 1, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal - 30, month + 1, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
            else
            {
                printf("=====================================================\n");
                printf("\n");
                printf("    Nama Pemilik     : %s\n", nama);
                printf("    NIK Pemilik      : %s\n", tamu.nik);
                printf("    Nomor Apartemen  : %d\n", tamu.nomor);
                printf("    Layanan Tambahan : - \n");
                printf("    Total Pembayaran : %d\n", tamu.total);
                printf("\n");
                printf("=====================================================\n");
                printf("\n");
                printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                printf("    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                printf("\n");
                printf("=====================================================\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
                fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
                fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
                fprintf(tulisdata, "    Layanan Tambahan : - \n");
                fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
                fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", tanggal, month, year);
                fprintf(tulisdata, "\n");
                fprintf(tulisdata, "=====================================================\n");
                fclose(tulisdata);
                sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, tanggal, month, year);
                datatamu = fopen("datatamu.txt", "a");
                fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
                fclose(datatamu);
            }
        }
    }
    fclose(tulisdata);
    fclose(datatamu);
}
void case_pesan_malam(struct Apartemen tamu, struct tm tm, int n, char nama[1024], FILE *tulisdata)
{
    switch (tamu.nomor)
    {
    case 101:
        tulisdata = fopen("struk101.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 102:
        tulisdata = fopen("struk102.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 103:
        tulisdata = fopen("struk103.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 104:
        tulisdata = fopen("struk104.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 105:
        tulisdata = fopen("struk105.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 201:
        tulisdata = fopen("struk201.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 202:
        tulisdata = fopen("struk202.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 203:
        tulisdata = fopen("struk203.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 204:
        tulisdata = fopen("struk204.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 205:
        tulisdata = fopen("struk205.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 301:
        tulisdata = fopen("struk301.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 302:
        tulisdata = fopen("struk302.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 303:
        tulisdata = fopen("struk303.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 304:
        tulisdata = fopen("struk3304.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 305:
        tulisdata = fopen("struk305.txt", "w");
        struk_malam(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    default:
        printf("\t\t\t\t Error 404.\n");
    }
}
void struk_bulan(int day, int month, int year, int n, char nama[1024], struct Apartemen tamu, FILE *tulisdata)
{
    system("cls");
    time_t tiktok = time(NULL);
    int a_day = tiktok / 86400;
    char buffer[1024];
    FILE *datatamu = fopen("datatamu.txt", "a");
    int bulan = n + month;
    if (month == 12)
    {
        printf("=====================================================\n");
        printf("\n");
        printf("    Nama Pemilik     : %s\n", nama);
        printf("    NIK Pemilik      : %s\n", tamu.nik);
        printf("    Nomor Apartemen  : %d\n", tamu.nomor);
        printf("    Layanan Tambahan : - \n");
        printf("    Total Pembayaran : %d\n", tamu.total);
        printf("\n");
        printf("=====================================================\n");
        printf("\n");
        printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
        printf("    Jatuh Tempo      : %02d/%02d/%04d\n", day, bulan, year + 1);
        printf("\n");
        printf("=====================================================\n");
        fprintf(tulisdata, "=====================================================\n");
        fprintf(tulisdata, "\n");
        fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
        fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
        fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
        fprintf(tulisdata, "    Layanan Tambahan : - \n");
        fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
        fprintf(tulisdata, "\n");
        fprintf(tulisdata, "=====================================================\n");
        fprintf(tulisdata, "\n");
        fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
        fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", day, bulan, year + 1);
        fprintf(tulisdata, "\n");
        fprintf(tulisdata, "=====================================================\n");
        fclose(tulisdata);
        sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, day, bulan, year + 1);
        datatamu = fopen("datatamu.txt", "a");
        fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
        fclose(datatamu);
    }
    else
    {
        if (bulan > 12)
        {
            printf("=====================================================\n");
            printf("\n");
            printf("    Nama Pemilik     : %s\n", nama);
            printf("    NIK Pemilik      : %s\n", tamu.nik);
            printf("    Nomor Apartemen  : %d\n", tamu.nomor);
            printf("    Layanan Tambahan : - \n");
            printf("    Total Pembayaran : %d\n", tamu.total);
            printf("\n");
            printf("=====================================================\n");
            printf("\n");
            printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
            printf("    Jatuh Tempo      : %02d/%02d/%04d\n", day, bulan, year + 1);
            printf("\n");
            printf("=====================================================\n");
            fprintf(tulisdata, "=====================================================\n");
            fprintf(tulisdata, "\n");
            fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
            fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
            fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
            fprintf(tulisdata, "    Layanan Tambahan : - \n");
            fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
            fprintf(tulisdata, "\n");
            fprintf(tulisdata, "=====================================================\n");
            fprintf(tulisdata, "\n");
            fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
            fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", day, bulan, year + 1);
            fprintf(tulisdata, "\n");
            fprintf(tulisdata, "=====================================================\n");
            fclose(tulisdata);
            sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, day, bulan, year + 1);
            datatamu = fopen("datatamu.txt", "a");
            fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
            fclose(datatamu);
        }
        else
        {
            printf("=====================================================\n");
            printf("\n");
            printf("    Nama Pemilik     : %s\n", nama);
            printf("    NIK Pemilik      : %s\n", tamu.nik);
            printf("    Nomor Apartemen  : %d\n", tamu.nomor);
            printf("    Layanan Tambahan : - \n");
            printf("    Total Pembayaran : %d\n", tamu.total);
            printf("\n");
            printf("=====================================================\n");
            printf("\n");
            printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
            printf("    Jatuh Tempo      : %02d/%02d/%04d\n", day, bulan, year);
            printf("\n");
            printf("=====================================================\n");
            fprintf(tulisdata, "=====================================================\n");
            fprintf(tulisdata, "\n");
            fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
            fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
            fprintf(tulisdata, "    Nomor Apartemen  : %s\n", tamu.nomor);
            fprintf(tulisdata, "    Layanan Tambahan : - \n");
            fprintf(tulisdata, "    Total Pembayaran : %s\n", tamu.total);
            fprintf(tulisdata, "\n");
            fprintf(tulisdata, "=====================================================\n");
            fprintf(tulisdata, "\n");
            fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
            fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", day, bulan, year);
            fprintf(tulisdata, "\n");
            fprintf(tulisdata, "=====================================================\n");
            fclose(tulisdata);
            sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, day, bulan, year);
            datatamu = fopen("datatamu.txt", "a");
            fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
            fclose(datatamu);
        }
    }
    fclose(tulisdata);
    fclose(datatamu);
}
void case_pesan_bulan(struct Apartemen tamu, struct tm tm, int n, char nama[1024], FILE *tulisdata)
{
    switch (tamu.nomor)
    {
    case 101:
        tulisdata = fopen("struk101.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 102:
        tulisdata = fopen("struk102.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 103:
        tulisdata = fopen("struk103.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 104:
        tulisdata = fopen("struk104.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 105:
        tulisdata = fopen("struk105.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 201:
        tulisdata = fopen("struk201.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 202:
        tulisdata = fopen("struk202.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 203:
        tulisdata = fopen("struk203.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 204:
        tulisdata = fopen("struk204.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 205:
        tulisdata = fopen("struk205.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 301:
        tulisdata = fopen("struk301.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 302:
        tulisdata = fopen("struk302.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 303:
        tulisdata = fopen("struk303.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 304:
        tulisdata = fopen("struk304.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 305:
        tulisdata = fopen("struk305.txt", "w");
        struk_bulan(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    default:
        printf("\t\t\t\t Error 404.\n");
    }
}
void struk_tahun(int day, int month, int year, int n, char nama[1024], struct Apartemen tamu, FILE *tulisdata)
{
    system("cls");
    time_t tiktok = time(NULL);
    int a_day = tiktok / 86400;
    char buffer[1024];
    FILE *datatamu = fopen("datatamu.txt", "a");
    int tahun = n + year;
    printf("=====================================================\n");
    printf("\n");
    printf("    Nama Pemilik     : %s\n", nama);
    printf("    NIK Pemilik      : %s\n", tamu.nik);
    printf("    Nomor Apartemen  : %d\n", tamu.nomor);
    printf("    Layanan Tambahan : - \n");
    printf("    Total Pembayaran : %d\n", tamu.total);
    printf("\n");
    printf("=====================================================\n");
    printf("\n");
    printf("    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
    printf("    Jatuh Tempo      : %02d/%02d/%04d\n", day, month, tahun);
    printf("\n");
    printf("=====================================================\n");
    fprintf(tulisdata, "=====================================================\n");
    fprintf(tulisdata, "\n");
    fprintf(tulisdata, "    Nama Pemilik     : %s\n", nama);
    fprintf(tulisdata, "    NIK Pemilik      : %s\n", tamu.nik);
    fprintf(tulisdata, "    Nomor Apartemen  : %d\n", tamu.nomor);
    fprintf(tulisdata, "    Layanan Tambahan : - \n");
    fprintf(tulisdata, "    Total Pembayaran : %d\n", tamu.total);
    fprintf(tulisdata, "\n");
    fprintf(tulisdata, "=====================================================\n");
    fprintf(tulisdata, "\n");
    fprintf(tulisdata, "    Tanggal Pemesanan: %02d/%02d/%04d\n", day, month, year);
    fprintf(tulisdata, "    Jatuh Tempo      : %02d/%02d/%04d\n", day, month, tahun);
    fprintf(tulisdata, "\n");
    fprintf(tulisdata, "=====================================================\n");
    fclose(tulisdata);
    sprintf(buffer, "%02d/%02d/%04d,%02d/%02d/%04d", day, month, year, day, month, tahun);
    datatamu = fopen("datatamu.txt", "a");
    fprintf(datatamu, "%s,%d,%d,%s,%d\n", tamu.nik, tamu.nomor, tamu.total, buffer, a_day);
    fclose(datatamu);
}
void case_pesan_tahun(struct Apartemen tamu, struct tm tm, int n, char nama[1024], FILE *tulisdata)
{
    switch (tamu.nomor)
    {
    case 101:
        tulisdata = fopen("struk101.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 102:
        tulisdata = fopen("struk102.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 103:
        tulisdata = fopen("struk103.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 104:
        tulisdata = fopen("struk104.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 105:
        tulisdata = fopen("struk105.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 201:
        tulisdata = fopen("struk201.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 202:
        tulisdata = fopen("struk202.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 203:
        tulisdata = fopen("struk203.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 204:
        tulisdata = fopen("struk204.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 205:
        tulisdata = fopen("struk205.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 301:
        tulisdata = fopen("struk301.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 302:
        tulisdata = fopen("struk302.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 303:
        tulisdata = fopen("struk303.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 304:
        tulisdata = fopen("struk304.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    case 305:
        tulisdata = fopen("struk305.txt", "w");
        struk_tahun(tm.tm_mday, tm.tm_mon, tm.tm_year, n, nama, tamu, tulisdata);
        fclose(tulisdata);
        break;
    default:
        printf("\t\t\t\t Error 404.\n");
    }
}
bool modulasi_pemesanan(char nik[20], int nomor, FILE *cekdata)
{
    struct Apartemen tempo;
    int flag;
    do
    {
        fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^,],%d\n", tempo.nik, &tempo.nomor, &tempo.total, tempo.masuk, tempo.keluar, &tempo.hari);
        if (strcmp(tempo.nik, nik) != 0 && tempo.nomor != nomor)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    } while (!feof(cekdata) && flag == 1);
    fclose(cekdata);
    if (flag == 0)
        return false;
    else
        return true;
}
void sewa_keluarga_malam()
{
    char buff[255];
    struct Apartemen tamu;
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    bool checker;
    char nama[1024];
    int n, a;
    FILE *cekdata;
    FILE *tulisdata;
    system("cls");
    printf("\t\t\t\t|| Masukkan nama lengkap Anda              : ");
    scanf("%[^\n]", nama);
    getchar();
    int lenama = strlen(nama);
    for (int j = 0; j < lenama; j++)
    {
        if (!isalpha(nama[j]) && (int)nama[j] != 32)
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_keluarga_malam();
        }
    }
    printf("\t\t\t\t|| Masukkan NIK Anda                       : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        system("pause");
        system("cls");
        sewa_keluarga_malam();
    }
    for (int j = 0; j < 16; j++)
    {
        if (!isdigit(tamu.nik[j]))
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_keluarga_malam();
        }
    }
    printf("\t\t\t\t|| Masukkan nomor kamar yang Anda inginkan : ");
    tamu.nomor = validasi_angka(301, 305);
    printf("\t\t\t\t|| Berapa malam Anda hendak menyewa        : ");
    n = validasi_angka(1, 29);
    tamu.total = n * KELUARGA_MALAM;
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_pemesanan(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Identitas dengan NIK tersebut sudah ada yang menggunakan\n\t\t\t\t atau apartemen yang kamu pilih sudah ditempati.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        case_pesan_malam(tamu, tm, n, nama, tulisdata);
        fclose(tulisdata);
    }
}
void sewa_keluarga_bulan()
{
    char buff[255];
    struct Apartemen tamu;
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    bool checker;
    char nama[1024];
    int n, a;
    FILE *cekdata;
    FILE *tulisdata;
    system("cls");
    printf("\t\t\t\t|| Masukkan nama lengkap Anda              : ");
    scanf("%[^\n]", nama);
    getchar();
    int lenama = strlen(nama);
    for (int j = 0; j < lenama; j++)
    {
        if (!isalpha(nama[j]) && (int)nama[j] != 32)
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_keluarga_bulan();
        }
    }
    printf("\t\t\t\t|| Masukkan NIK Anda                       : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        system("pause");
        system("cls");
        sewa_keluarga_bulan();
    }
    for (int j = 0; j < 16; j++)
    {
        if (!isdigit(tamu.nik[j]))
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_keluarga_bulan();
        }
    }
    printf("\t\t\t\t|| Masukkan nomor kamar yang Anda inginkan : ");
    tamu.nomor = validasi_angka(301, 305);
    printf("\t\t\t\t|| Berapa bulan Anda hendak menyewa        : ");
    n = validasi_angka(1, 12);
    tamu.total = n * KELUARGA_BULAN;
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_pemesanan(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Identitas dengan NIK tersebut sudah ada yang menggunakan\n\t\t\t\t atau apartemen yang kamu pilih sudah ditempati.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        case_pesan_bulan(tamu, tm, n, nama, tulisdata);
        fclose(tulisdata);
    }
}
void sewa_keluarga_tahun()
{
    char buff[255];
    struct Apartemen tamu;
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    bool checker;
    char nama[1024];
    int n, a;
    FILE *cekdata;
    FILE *tulisdata;
    system("cls");
    printf("\t\t\t\t|| Masukkan nama lengkap Anda              : ");
    scanf("%[^\n]", nama);
    getchar();
    int lenama = strlen(nama);
    for (int j = 0; j < lenama; j++)
    {
        if (!isalpha(nama[j]) && (int)nama[j] != 32)
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_keluarga_tahun();
        }
    }
    printf("\t\t\t\t|| Masukkan NIK Anda                       : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        system("pause");
        system("cls");
        sewa_keluarga_tahun();
    }
    for (int j = 0; j < 16; j++)
    {
        if (!isdigit(tamu.nik[j]))
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_keluarga_tahun();
        }
    }
    printf("\t\t\t\t|| Masukkan nomor kamar yang Anda inginkan : ");
    tamu.nomor = validasi_angka(301, 305);
    printf("\t\t\t\t|| Berapa tahun Anda hendak menyewa        : ");
    n = validasi_tahun(1);
    tamu.total = n * KELUARGA_TAHUN;
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_pemesanan(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Identitas dengan NIK tersebut sudah ada yang menggunakan\n\t\t\t\t atau apartemen yang kamu pilih sudah ditempati.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        case_pesan_tahun(tamu, tm, n, nama, tulisdata);
        fclose(tulisdata);
    }
}
void sewa_pribadi_malam()
{
    char buff[255];
    struct Apartemen tamu;
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    bool checker;
    char nama[1024];
    int n, a;
    FILE *cekdata;
    FILE *tulisdata;
    system("cls");
    printf("\t\t\t\t|| Masukkan nama lengkap Anda              : ");
    scanf("%[^\n]", nama);
    getchar();
    int lenama = strlen(nama);
    for (int j = 0; j < lenama; j++)
    {
        if (!isalpha(nama[j]) && (int)nama[j] != 32)
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_pribadi_malam();
        }
    }
    printf("\t\t\t\t|| Masukkan NIK Anda                       : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        system("pause");
        system("cls");
        sewa_pribadi_malam();
    }
    for (int j = 0; j < 16; j++)
    {
        if (!isdigit(tamu.nik[j]))
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_pribadi_malam();
        }
    }
    printf("\t\t\t\t|| Masukkan nomor kamar yang Anda inginkan : ");
    tamu.nomor = validasi_angka(101, 205);
    if (tamu.nomor != 101 && tamu.nomor != 102 && tamu.nomor != 103 && tamu.nomor != 104 && tamu.nomor != 105 && tamu.nomor != 201 && tamu.nomor != 202 && tamu.nomor != 203 && tamu.nomor != 204 && tamu.nomor != 205)
    {

        printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        system("pause");
        system("cls");
        sewa_pribadi_malam();
    }
    printf("\t\t\t\t|| Berapa malam Anda hendak menyewa        : ");
    n = validasi_angka(1, 29);
    tamu.total = n * PRIVATE_MALAM;
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_pemesanan(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Identitas dengan NIK tersebut sudah ada yang menggunakan\n\t\t\t\t atau apartemen yang kamu pilih sudah ditempati.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        case_pesan_malam(tamu, tm, n, nama, tulisdata);
        fclose(tulisdata);
    }
}
void sewa_pribadi_bulan()
{
    char buff[255];
    struct Apartemen tamu;
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    bool checker;
    char nama[1024];
    int n, a;
    FILE *cekdata;
    FILE *tulisdata;
    system("cls");
    printf("\t\t\t\t|| Masukkan nama lengkap Anda              : ");
    scanf("%[^\n]", nama);
    getchar();
    int lenama = strlen(nama);
    for (int j = 0; j < lenama; j++)
    {
        if (!isalpha(nama[j]) && (int)nama[j] != 32)
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_pribadi_bulan();
        }
    }
    printf("\t\t\t\t|| Masukkan NIK Anda                       : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        system("pause");
        system("cls");
        sewa_pribadi_bulan();
    }
    for (int j = 0; j < 16; j++)
    {
        if (!isdigit(tamu.nik[j]))
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_pribadi_bulan();
        }
    }
    printf("\t\t\t\t|| Masukkan nomor kamar yang Anda inginkan : ");
    tamu.nomor = validasi_angka(101, 205);
    if (tamu.nomor != 101 && tamu.nomor != 102 && tamu.nomor != 103 && tamu.nomor != 104 && tamu.nomor != 105 && tamu.nomor != 201 && tamu.nomor != 202 && tamu.nomor != 203 && tamu.nomor != 204 && tamu.nomor != 205)
    {
        printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        system("pause");
        system("cls");
        sewa_pribadi_bulan();
    }
    printf("\t\t\t\t|| Berapa bulan Anda hendak menyewa        : ");
    n = validasi_angka(1, 12);
    tamu.total = n * PRIVATE_BULAN;
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_pemesanan(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Identitas dengan NIK tersebut sudah ada yang menggunakan\n\t\t\t\t atau apartemen yang kamu pilih sudah ditempati.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        case_pesan_bulan(tamu, tm, n, nama, tulisdata);
        fclose(tulisdata);
    }
}
void sewa_pribadi_tahun()
{
    char buff[255];
    struct Apartemen tamu;
    time_t waktu;
    waktu = time(NULL);
    struct tm tm = *localtime(&waktu);
    tm.tm_year = tm.tm_year + 1900;
    tm.tm_mon = tm.tm_mon + 1;
    bool checker;
    char nama[1024];
    int n, a;
    FILE *cekdata;
    FILE *tulisdata;
    system("cls");
    printf("\t\t\t\t|| Masukkan nama lengkap Anda              : ");
    scanf("%[^\n]", nama);
    getchar();
    int lenama = strlen(nama);
    for (int j = 0; j < lenama; j++)
    {
        if (!isalpha(nama[j]) && (int)nama[j] != 32)
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_pribadi_tahun();
        }
    }
    printf("\t\t\t\t|| Masukkan NIK Anda                       : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        system("pause");
        system("cls");
        sewa_pribadi_tahun();
    }
    for (int j = 0; j < 16; j++)
    {
        if (!isdigit(tamu.nik[j]))
        {
            printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            system("pause");
            system("cls");
            sewa_pribadi_tahun();
        }
    }
    printf("\t\t\t\t|| Masukkan nomor kamar yang Anda inginkan : ");
    tamu.nomor = validasi_angka(101, 205);
    if (tamu.nomor != 101 && tamu.nomor != 102 && tamu.nomor != 103 && tamu.nomor != 104 && tamu.nomor != 105 && tamu.nomor != 201 && tamu.nomor != 202 && tamu.nomor != 203 && tamu.nomor != 204 && tamu.nomor != 205)
    {
        printf("\t\t\t\t Maaf kamu menginputkan data yang salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        system("pause");
        system("cls");
        sewa_pribadi_tahun();
    }
    printf("\t\t\t\t|| Berapa tahun Anda hendak menyewa        : ");
    n = validasi_angka(1, 29);
    tamu.total = n * PRIVATE_TAHUN;
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_pemesanan(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Identitas dengan NIK tersebut sudah ada yang menggunakan\n\t\t\t\t atau apartemen yang kamu pilih sudah ditempati.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        case_pesan_tahun(tamu, tm, n, nama, tulisdata);
        fclose(tulisdata);
    }
}
bool modulasi_pembatalan(char nik[20], int nomor, FILE *cekdata)
{
    struct Apartemen tempo;
    int flag;
    do
    {
        fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^,],%d\n", tempo.nik, &tempo.nomor, &tempo.total, tempo.masuk, tempo.keluar, &tempo.hari);
        if (strcmp(tempo.nik, nik) == 0 && tempo.nomor == nomor)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    } while (!feof(cekdata) && flag == 1);
    fclose(cekdata);
    if (flag == 0)
        return false;
    else
        return true;
}
void batalkan_pesanan()
{
    time_t waktu = time(NULL);
    int a_day = waktu / 86400;
    time_t wita = time(NULL);
    struct tm tm = *localtime(&wita);
    struct Apartemen tamu, tempo;
    int flag;
    FILE *cekdata;
    FILE *temporary;
    FILE *tulisdata;
    FILE *tulisriwayat;
    bool checker;
    system("cls");
    printf("|| Masukkan NIK Anda             : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Input yang Anda masukkan salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        batalkan_pesanan();
    }
    for (int j = 0; j < 16; j++)
    {
        if (!isdigit(tamu.nik[j]))
        {
            printf("\t\t\t\t Input yang Anda masukkan salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            batalkan_pesanan();
        }
    }
    printf("|| Masukkan nomor apartemen Anda : ");
    tamu.nomor = validasi_angka(101, 305);
    system("cls");
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_pembatalan(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Kamu belum memesan apartemen\n\t\t\t\t atau kamu menginput data yang salah.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        char buf[255];
        temporary = fopen("datatamu.txt", "r");
        tulisdata = fopen("backup.txt", "a");
        tulisriwayat = fopen("riwayatpembatalan.txt", "a");
        do
        {
            fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^,],%d\n", tempo.nik, &tempo.nomor, &tempo.total, tempo.masuk, tempo.keluar, &tempo.hari);
            if (strcmp(tempo.nik, tamu.nik) == 0 && tempo.nomor == tamu.nomor)
            {
                system("cls");
                double potongan = (0.51) * tempo.total;
                tempo.hari = a_day - tempo.hari;
                printf("||    Tanggal Memesan          : %s\n", tempo.keluar);
                printf("||    Tanggal Pembatalan       : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon, tm.tm_year);
                sprintf(buf, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon, tm.tm_year);
                printf("||    Pengembalian Dana (49%%) : Rp %.0lf\n", (double)(tempo.total - potongan));
                printf("||    Lama Menggunakan Layanan : %d\n", tempo.hari);
                fprintf(tulisriwayat, "%s,%d,%.0lf,%s,%s,%d\n", tempo.nik, tempo.nomor, (double)(tempo.total - potongan), tempo.masuk, buf, tempo.hari);
                system("pause");
                continue;
            }
            else
            {
                fprintf(tulisdata, "%s,%d,%d,%s,%s,%d\n", tempo.nik, tempo.nomor, tempo.total, tempo.masuk, tempo.keluar, tempo.hari);
            }
        } while (!feof(temporary));
        fclose(temporary);
        fclose(tulisdata);
        fclose(tulisriwayat);
        int bendera, pagar;
        if (remove("datatamu.txt") != 0)
        {
            fprintf(stderr, "Errno: %d\n", errno);
            perror("Error msg");
            bendera = 1;
        }
        else
        {
            printf("ok");
            bendera = 0;
        }
        if (rename("backup.txt", "datatamu.txt") != 0)
        {
            fprintf(stderr, "Errno: %d\n", errno);
            perror("Error msg");
            pagar = 1;
        }
        else
        {
            printf("ok");
            pagar = 0;
        }
        if (bendera == 1 || pagar == 1)
        {
            system("cls");
            printf("\t\t\t\t Terjadi sebuah kesalahan, silakan hubungi Admin.\n");
            system("pause");
        }
        else
        {
            case_hapus_struk(tamu.nomor);
        }
    }
}
void case_hapus_struk(int nomor)
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
        printf("Error 404.");
    }
}
bool modulasi_tempo(char nik[20], int nomor, FILE *cekdata)
{
    struct Apartemen tempo;
    int flag;
    do
    {
        fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^,],%d\n", tempo.nik, &tempo.nomor, &tempo.total, tempo.masuk, tempo.keluar, &tempo.hari);
        if (strcmp(tempo.nik, nik) == 0 && tempo.nomor == nomor)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    } while (!feof(cekdata) && flag == 1);
    fclose(cekdata);
    if (flag == 0)
        return false;
    else
        return true;
}
void pengecekkan_tempo()
{
    struct Apartemen tamu;
    FILE *cekdata;
    FILE *buka;
    bool checker;
    system("cls");
    printf("|| Masukkan NIK Anda             : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Input yang Anda masukkan salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        pengecekkan_tempo();
    }
    for (int j = 0; j < 16; j++)
    {
        if (!isdigit(tamu.nik[j]))
        {
            printf("\t\t\t\t Input yang Anda masukkan salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            pengecekkan_tempo();
        }
    }
    printf("|| Masukkan nomor apartemen Anda : ");
    tamu.nomor = validasi_angka(101, 305);
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_tempo(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Kamu belum memesan apartemen\n\t\t\t\t atau kamu menginput data yang salah.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        case_tempo(tamu.nomor, buka);
        fclose(buka);
    }
}
void case_tempo(int nomor, FILE *buka)
{
    char buffer[1024];
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
        printf("Error 404.\n");
    }
}
bool modulasi_laundry(char nik[20], int nomor, FILE *cekdata)
{
    struct Apartemen tempo;
    int flag;
    do
    {
        fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^,],%d\n", tempo.nik, &tempo.nomor, &tempo.total, tempo.masuk, tempo.keluar, &tempo.hari);
        if (strcmp(tempo.nik, nik) == 0 && tempo.nomor == nomor)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    } while (!feof(cekdata) && flag == 1);
    fclose(cekdata);
    if (flag == 0)
        return false;
    else
        return true;
}
void laundry()
{
    struct Apartemen tamu;
    char nama[1024];
    FILE *cekdata;
    FILE *tulisdata;
    bool checker;
    system("cls");
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
    printf("\t\t\t\t\t SILAKAN MELAKUKAN PENDAFTARAN\n");
    printf("\t\t\t\t|| Buat nama pengguna Anda       : ");
    scanf("%[^\n]", nama);
    getchar();
    int len = strlen(nama);
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(nama[i]) && !isdigit(nama[i]))
        {
            printf("\t\t\t\t Harap memasukkan karakter dengan benar!\n");
            laundry();
        }
    }
    printf("\t\t\t\t|| Masukkan NIK Anda             : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Input yang Anda masukkan salah!\n\t\t\t\t Silakan masukkan kembali!\n");
        laundry();
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tamu.nik[i]))
        {
            printf("\t\t\t\t Input yang Anda masukkan salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            laundry();
        }
    }
    printf("\t\t\t\t|| Masukkan nomor Apartemen Anda : ");
    tamu.nomor = validasi_angka(101, 305);
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_laundry(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Kamu belum memesan apartemen\n\t\t\t\t atau kamu menginput data yang salah.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        system("cls");
        if (tamu.nomor == 101)
            tulisdata = fopen("kartulaundry101.txt", "w");
        else if (tamu.nomor == 102)
            tulisdata = fopen("kartulaundry102.txt", "w");
        else if (tamu.nomor == 103)
            tulisdata = fopen("kartulaundry103.txt", "w");
        else if (tamu.nomor == 104)
            tulisdata = fopen("kartulaundry104.txt", "w");
        else if (tamu.nomor == 105)
            tulisdata = fopen("kartulaundry105.txt", "w");
        else if (tamu.nomor == 201)
            tulisdata = fopen("kartulaundry201.txt", "w");
        else if (tamu.nomor == 202)
            tulisdata = fopen("kartulaundry202.txt", "w");
        else if (tamu.nomor == 203)
            tulisdata = fopen("kartulaundry203.txt", "w");
        else if (tamu.nomor == 204)
            tulisdata = fopen("kartulaundry204.txt", "w");
        else if (tamu.nomor == 205)
            tulisdata = fopen("kartulaundry205.txt", "w");
        else if (tamu.nomor == 301)
            tulisdata = fopen("kartulaundry301.txt", "w");
        else if (tamu.nomor == 302)
            tulisdata = fopen("kartulaundry302.txt", "w");
        else if (tamu.nomor == 303)
            tulisdata = fopen("kartulaundry303.txt", "w");
        else if (tamu.nomor == 304)
            tulisdata = fopen("kartulaundry304.txt", "w");
        else if (tamu.nomor == 305)
            tulisdata = fopen("kartulaundry305.txt", "w");
        else
            printf("Error 404\n");
        system("cls");
        printf("====================================================================\n");
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf("\n");
        printf("                     K A R T U   L A U N D R Y\n");
        printf("\n");
        printf("--------------------------------------------------------------------\n");
        printf("\n");
        printf("    Nama Pengguna : %s\n", nama);
        printf("    Nomor Kamar   : %d\n", tamu.nomor);
        printf("\n");
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf("\n");
        printf("====================================================================\n");
        system("pause");
        fprintf(tulisdata, "====================================================================\n");
        fprintf(tulisdata, ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        fprintf(tulisdata, "\n");
        fprintf(tulisdata, "                     K A R T U   L A U N D R Y\n");
        fprintf(tulisdata, "\n");
        fprintf(tulisdata, "--------------------------------------------------------------------\n");
        fprintf(tulisdata, "\n");
        fprintf(tulisdata, "    Nama Pengguna : %s\n", nama);
        fprintf(tulisdata, "    Nomor Kamar   : %d\n", tamu.nomor);
        fprintf(tulisdata, "\n");
        fprintf(tulisdata, ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        fprintf(tulisdata, "\n");
        fprintf(tulisdata, "====================================================================\n");
        fclose(tulisdata);
    }
}
bool modulasi_sarapan(char nik[20], int nomor, FILE *cekdata)
{
    struct Apartemen tempo;
    int flag;
    do
    {
        fscanf(cekdata, "%19[^,],%d,%d,%19[^,],%19[^,],%d\n", tempo.nik, &tempo.nomor, &tempo.total, tempo.masuk, tempo.keluar, &tempo.hari);
        if (strcmp(tempo.nik, nik) == 0 && tempo.nomor == nomor)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    } while (!feof(cekdata) && flag == 1);
    fclose(cekdata);
    if (flag == 0)
        return false;
    else
        return true;
}
void breakfast()
{
    struct Apartemen tamu;
    char nama[1024];
    FILE *cekdata;
    FILE *membaca;
    FILE *menimpa;
    bool checker;
    int harga, day;
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
    printf("\t\t\t\t ||  diperpanjang sesuai keinginan dengan biaya Rp. 59.999,00 per hari.  ||\n");
    printf("\t\t\t\t || ==================================================================== ||\n");
    system("pause");
    system("cls");
    printf("\t\t\t\t|| Masukkan nama lengkap Anda    : ");
    scanf("%[^\n]", nama);
    getchar();
    int len = strlen(nama);
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(nama[i]) && (int)nama[i] != 32)
        {
            printf("\t\t\t\t Harap memasukkan karakter yang benar!\n");
            system("pause");
            system("cls");
            breakfast();
        }
    }
    printf("\t\t\t\t|| Masukkan NIK Anda             : ");
    scanf("%[^\n]", tamu.nik);
    getchar();
    if (strlen(tamu.nik) != 16)
    {
        printf("\t\t\t\t Maaf, Anda salah memasukkan input.\n\t\t\t\t Silakan masukkan kembali.\n");
        system("pause");
        system("cls");
        breakfast();
    }
    for (int i = 0; i < 16; i++)
    {
        if (!isdigit(tamu.nik[i]))
        {
            printf("\t\t\t\t Maaf, Anda salah memasukkan input.\n\t\t\t\t Silakan masukkan kembali.\n");
            system("pause");
            system("cls");
            breakfast();
        }
    }
    printf("\t\t\t\t|| Masukkan nomor apartemen Anda : ");
    tamu.nomor = validasi_angka(101, 305);
    printf("\t\t\t\t|| Berapa hari Anda hendak menggunakan layanan ini?\n");
    printf("\t\t\t\t|| >> ");
    day = validasi_angka(1, 29);
    cekdata = fopen("datatamu.txt", "r");
    checker = modulasi_sarapan(tamu.nik, tamu.nomor, cekdata);
    fclose(cekdata);
    if (checker == true)
    {
        printf("\t\t\t\t Maaf, Anda belum memesan layanan apartemen\n\t\t\t\t atau Anda menginputkan data yang salah.\n");
        system("pause");
        system("cls");
        mainmenu();
        exit(0);
    }
    else
    {
        struct Apartemen tempo;
        int flag;
        membaca = fopen("datatamu.txt", "r");
        do
        {
            fscanf(membaca, "%19[^,],%d,%d,%19[^,],%19[^,],%d\n", tempo.nik, &tempo.nomor, &tempo.total, tempo.masuk, tempo.keluar, &tempo.hari);
            if (strcmp(tempo.nik, tamu.nik) == 0 && tempo.nomor == tamu.nomor)
            {
                tamu.total = tempo.total;
                strcpy(tamu.masuk, tempo.masuk);
                strcpy(tamu.keluar, tempo.keluar);
                tamu.hari = tempo.hari;
                flag = 0;
            }
            else
            {
                flag = 1;
            }
        } while (!feof(membaca) && flag == 1);
        fclose(membaca);
        if (flag == 1)
        {
            printf("Error 404.\n");
        }
        else
        {
            harga = tamu.total + (day * SARAPAN);
            case_breakfast(tamu, nama, harga, day, menimpa);
            fclose(menimpa);
            system("pause");
            system("cls");
        }
    }
}
void case_breakfast(struct Apartemen tamu, char nama[1024], int harga, int day, FILE *fptr)
{
    switch (tamu.nomor)
    {
    case 101:
        fptr = fopen("struk101.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 102:
        fptr = fopen("struk102.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 103:
        fptr = fopen("struk103.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 104:
        fptr = fopen("struk104.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 105:
        fptr = fopen("struk105.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 201:
        fptr = fopen("struk201.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 202:
        fptr = fopen("struk202.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 203:
        fptr = fopen("struk203.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 204:
        fptr = fopen("struk204.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 205:
        fptr = fopen("struk205.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 301:
        fptr = fopen("struk301.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 302:
        fptr = fopen("struk302.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 303:
        fptr = fopen("struk303.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 304:
        fptr = fopen("struk304.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    case 305:
        fptr = fopen("struk305.txt", "w");
        struk_breakfast(tamu, nama, harga, day, fptr);
        fclose(fptr);
        break;
    default:
        printf("Error 404.\n");
        break;
    }
    fclose(fptr);
}
void struk_breakfast(struct Apartemen tamu, char nama[1024], int harga, int day, FILE *fptr)
{
    system("cls");
    printf("=====================================================");
    printf("\n");
    printf("    Nama Pemilik     : %s\n", nama);
    printf("    NIK Pemilik      : %s\n", tamu.nik);
    printf("    Nomor Apartemen  : %s\n", tamu.nomor);
    printf("    Layanan Tambahan : Breakfast %d hari\n", day);
    printf("    Total Pembayaran : %s\n", harga);
    printf("\n");
    printf("=====================================================");
    printf("\n");
    printf("    Tanggal Pemesanan: %s\n", tamu.masuk);
    printf("    Jatuh Tempo      : %s\n", tamu.keluar);
    printf("\n");
    printf("=====================================================");
    fprintf(fptr, "=====================================================");
    fprintf(fptr, "\n");
    fprintf(fptr, "    Nama Pemilik     : %s\n", nama);
    fprintf(fptr, "    NIK Pemilik      : %s\n", tamu.nik);
    fprintf(fptr, "    Nomor Apartemen  : %s\n", tamu.nomor);
    fprintf(fptr, "    Layanan Tambahan : Breakfast %d hari\n", day);
    fprintf(fptr, "    Total Pembayaran : %s\n", harga);
    fprintf(fptr, "\n");
    fprintf(fptr, "=====================================================");
    fprintf(fptr, "\n");
    fprintf(fptr, "    Tanggal Pemesanan: %s\n", tamu.masuk);
    fprintf(fptr, "    Jatuh Tempo      : %s\n", tamu.keluar);
    fprintf(fptr, "\n");
    fprintf(fptr, "=====================================================");
    fclose(fptr);
    FILE *pagi = fopen("databreakfast.txt", "a");
    char buffer[1024];
    sprintf(buffer, "%s,%d,%d,%s,%s,%d\n", tamu.nik, tamu.nomor, harga - tamu.total, tamu.masuk, tamu.keluar, tamu.hari);
    fprintf(pagi, "%s", buffer);
    fclose(pagi);
}
void fasilitas_keluarga()
{
    system("cls");
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
    printf("\t\t\t\t|| **************    List Apartemen    ************** ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||Apartemen layanan Keluarga terdapat di Lantai Ketiga||\n");
    printf("\t\t\t\t|| Dengan nomor apartemen dimulai dari 301 sampai 305 ||\n");
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
        sewa_keluarga_malam();
        break;
    case 2:
        sewa_keluarga_bulan();
        break;
    case 3:
        sewa_keluarga_tahun();
        break;
    default:
        mainmenu();
        exit(0);
    }
}
void fasilitas_pribadi()
{
    system("cls");
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
    printf("\t\t\t\t|| **************    List Apartemen    ************** ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t|| Apartemen layanan Pribadi terdapat di Lantai Kedua ||\n");
    printf("\t\t\t\t|| Dengan nomor apartemen dimulai dari 201 sampai 205 ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    printf("\t\t\t\t||Apartemen layanan Pribadi terdapat di Lantai Pertama||\n");
    printf("\t\t\t\t|| Dengan nomor apartemen dimulai dari 101 sampai 105 ||\n");
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
        sewa_pribadi_malam();
        break;
    case 2:
        sewa_pribadi_bulan();
        break;
    case 3:
        sewa_pribadi_tahun();
        break;
    default:
        mainmenu();
        exit(0);
    }
}
void penyewaan_apartemen()
{
    int pilih;
    printf("\t\t\t\t| ============================== |\n");
    printf("\t\t\t\t||                              ||\n");
    printf("\t\t\t\t||      SILAKAN PILIH JENIS     ||\n");
    printf("\t\t\t\t||        APARTEMEN ANDA        ||\n");
    printf("\t\t\t\t||                              ||\n");
    printf("\t\t\t\t| ============================== |\n");
    printf("\t\t\t\t||                              ||\n");
    printf("\t\t\t\t||   [1] Apartemen Keluarga     ||\n");
    printf("\t\t\t\t||   [2] Apartemen Pribadi      ||\n");
    printf("\t\t\t\t||                              ||\n");
    printf("\t\t\t\t||                    [0]KELUAR ||\n");
    printf("\t\t\t\t| ============================== |\n");
    printf("\t\t\t\t|| Masukkan pilihan Anda: ");
    pilih = validasi_angka(0, 2);
    switch (pilih)
    {
    case 1:
        fasilitas_keluarga();
        system("pause");
        break;
    case 2:
        fasilitas_pribadi();
        system("pause");
        break;
    default:
        printf("\t\t\t\t Terima kasih karena telah menggunakan layanan kami :)\n");
        system("pause");
    }
}
void layanan_tambahan()
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
        system("pause");
        mainmenu();
        exit(0);
    }
}
int ulang_ulang();
void mainmenu()
{
    int pilih, ulang;
    do
    {
        system("cls");
        printf("\t\t\t\t| ============================== |\n");
        printf("\t\t\t\t||                              ||\n");
        printf("\t\t\t\t||       SILAKAN MASUKKAN       ||\n");
        printf("\t\t\t\t||         PILIHAN ANDA         ||\n");
        printf("\t\t\t\t||                              ||\n");
        printf("\t\t\t\t| ============================== |\n");
        printf("\t\t\t\t||                              ||\n");
        printf("\t\t\t\t||   [1] Memeriksa Apartemen    ||\n");
        printf("\t\t\t\t||   [2] Menyewa Apartemen      ||\n");
        printf("\t\t\t\t||   [3] Memeriksa Jatuh Tempo  ||\n");
        printf("\t\t\t\t||   [4] Layanan Tambahan       ||\n");
        printf("\t\t\t\t||                              ||\n");
        printf("\t\t\t\t||          [5]BATALKAN PESANAN ||\n");
        printf("\t\t\t\t||          [0]KELUAR           ||\n");
        printf("\t\t\t\t| ============================== |\n");
        printf("\t\t\t\t|| Masukkan pilihan Anda: ");
        pilih = validasi_angka(0, 5);
        system("cls");
        switch (pilih)
        {
        case 1:
            pengecekkan_apartemen();
            system("pause");
            break;
        case 2:
            penyewaan_apartemen();
            system("pause");
            break;
        case 3:
            pengecekkan_tempo();
            system("pause");
            break;
        case 4:
            layanan_tambahan();
            system("pause");
            break;
        case 5:
            batalkan_pesanan();
            system("pause");
            break;
        default:
            system("cls");
            printf("\t\t\t\t Terima kasih karena telah menggunakan layanan kami :)\n");
            system("pause");
        }
        ulang = ulang_ulang();
    } while (ulang == 1);
    system("pause");
    system("cls");
}
int ulang_ulang()
{
    system("cls");
    int ulang;
    printf("\t\t\t\t| ============================== |\n");
    printf("\t\t\t\t||                              ||\n");
    printf("\t\t\t\t||   APAKAH ANDA INGIN KELUAR   ||\n");
    printf("\t\t\t\t||      DARI PROGRAM INI?       ||\n");
    printf("\t\t\t\t||                              ||\n");
    printf("\t\t\t\t| ============================== |\n");
    printf("\t\t\t\t||                              ||\n");
    printf("\t\t\t\t||   [0] IYA                    ||\n");
    printf("\t\t\t\t||   [1] TIDAK                  ||\n");
    printf("\t\t\t\t||                              ||\n");
    printf("\t\t\t\t| ============================== |\n");
    printf("\t\t\t\t|| Masukkan pilihan Anda : ");
    ulang = validasi_angka(0, 1);
    return ulang;
}
// END OF FILE.