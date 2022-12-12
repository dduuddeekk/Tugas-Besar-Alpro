#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

struct Kamar{ //struct untuk regis kamar
    int nomor;
    char nik[16];
};
int validasi_angka(int range1, int range2){ //validasi 
    char buff[1024], invalid;
    int valid;
    scanf("%[^\n]", buff);
    if(sscanf(buff, "%d%c", &valid, invalid) == 1 && valid >= range1 && valid <= range2){
        return valid;
    }else{
        printf("\t\t\t\t Maaf, input Anda salah!\n\t\t\t\t Silakan input kembali!\n");
        validasi_angka(range1, range2);
    }
}
void pilihan_tamu(int pilih){ //prosedur untuk menampilkan pilihan customer saat awal mengakses program 
	printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ********   Pilihan Halaman  ******** ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||   [1]    |   Pengecekan Apartemen    ||\n");
    printf("\t\t\t\t||   [2]    |   Penyewaan Apartemen     ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t||                            [0]KELUAR ||\n");
    printf("\t\t\t\t||===================================== ||\n");
    printf("\t\t\t\t Masukkan pilihan: ");
    pilih = validasi_angka(0, 2);
}
void pengecekan_tamu(int pilih){ //prosedur jika customer meimilih pengecekan kamar
    struct Kamar tamu;
    pilihan_tamu(pilih);
    switch(pilih){
        case 1:
            pengecekkan_tamu2(tamu);
            break;
        case 2:
            paket(pilih);
            break;
        default:
            //terima kasih
    }
}
//pemilihan paket pribadi atau keluarga.
void paket(int pilih){  
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
    printf("\t\t\t\t Masukkan pilihan: ");
    pilih = validasi_angka(0, 2);
    switch(pilih){
        case 1:
            keluarga();
            break;
        case 2:
            pribadi();
            break;
        default:
            //terima kasih.
    }
}
//mengecek tamu
void pengecekkan_tamu2(struct Kamar tamu){
    int nomor_kamar;
    char nik[16];
    printf("\t\t\t\t ||_________________________________________________|| \n");
    printf("\t\t\t\t ||                                                 || \n");
    printf("\t\t\t\t ||======  Halo, pelanggan kami yang tercinta  =====||\n");
    printf("\t\t\t\t ||                                                 ||\n");
    printf("\t\t\t\t ||=================================================||\n");
    printf("\t\t\t\t ||Silakan masukkan NIK Anda:     ");
    scanf("%[^\n]", nik);
    getchar();
    for(int i = 0; i < 16; i++){
        if((int)nik[i] < 48 && (int)nik[i] > 57){
            system("cls");
            printf("\t\t\t\t Maaf, masukkan Anda salah!\n\t\t\t\t Silakan masukkan kembali!\n");
            pengecekkan_tamu2(tamu);
        }
    }
    printf("\t\t\t\t Silakan masukkan nomor kamar Anda: ");
    nomor_kamar = validasi_angka(100, 305);
    FILE *cekdata = fopen("datatamu.txt","r");
    if(cekdata == NULL){
        printf("\t\t\t\t Maaf, kamu belum terdaftar di dalam buku tamu.\n");
    }else{
        while(!feof(cekdata)){
            fscanf(cekdata, "%16[^,],%d\n", tamu.nik, &tamu.nomor);
            if(strcmp(tamu.nik,nik)==0){
                //menuju ke fungsi menampilkan data.
            }
        }fclose(cekdata);
    }
}
//fasilitas paket keluarga
void keluarga(){
    int pilih;
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
    printf("\t\t\t\t|| Rp 500.000,00          | per night                 ||\n");
    printf("\t\t\t\t|| Rp 13.500.000,00       | per month                 ||\n");
    printf("\t\t\t\t|| Rp 156.000.000,00      | per year                  ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    system("pause");
    system("cls");
    pilih_paket(pilih);
}

//fasilitas paket pribadi
void pribadi(){
    int pilih;
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
    printf("\t\t\t\t|| Rp 350.000,00          | per night                 ||\n");
    printf("\t\t\t\t|| Rp 9.000.000,00        | per month                 ||\n");
    printf("\t\t\t\t|| Rp 98.000.000,00       | per year                  ||\n");
    printf("\t\t\t\t|| ================================================== ||\n");
    system("pause");
    system("cls");
    pilih_paket(pilih);
}

//pilihan lama sewa
void pilih_paket(int pilih){
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
    printf("\t\t\t\t Masukkan pilihan: ");
    pilih = validasi_angka(0, 2);
    switch(pilih){
        case 1:
            keluarga();
            break;
        case 2:
            pribadi();
            break;
        default:
            //terima kasih.
    }
}
void mainmenu(){
    int pilih;
    pilihan_tamu(pilih);
    return 0;
}