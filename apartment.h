#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define KELUARGA_MALAM 500000
#define KELUARGA_BULAN 13500000
#define KELUARGA_TAHUN 156000000
#define PRIVATE_MALAM 350000
#define PRIVATE_BULAN 9000000
#define PPRIVATE_TAHUN 98000000
int validasi_angka(int range1, int range2){
    char buff[1024], invalid;
    int valid;
    scanf("%[^\n]",buff);
    getchar();
    if(sscanf(buff, "%d%c", &valid, &invalid) == 1 && valid >= range1 && valid <= range2){
        return valid;
    }else{
        printf("\n\t\t\t\t Inputan Salah!\n\t\t\t\t Masukkan kembali.!\n\t\t\t\t >> ");
        validasi_angka(range1, range2);
    }
}
struct Kamar{
    char nik[16];
    int nomor;
    int nomork[15];
};
int pilih;
void menu(){
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ********   Pilihan Halaman  ******** ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||   [1]    |   Pengecekan Apartemen    ||\n"); 
    printf("\t\t\t\t||   [2]    |   Pengecekan Jatuh Tempo  ||\n");
    printf("\t\t\t\t||   [3]    |   Penyewaan Apartemen     ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t||                  [4]BATALKAN PESANAN ||\n");
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
//menampilkan kamar yang tersedia
void check_apartment(){
    struct Kamar tamu[15]; //array of struct (gg boys)
    FILE *masuk;
    int kamar[15];
    masuk = fopen("datatamu.txt","r");
    if(masuk == NULL){
        printf("\t\t\t\t Berkas belum ada atau belum dibuat, terima kasih.\n");
    }else{
        while(!feof(masuk)){
            for(int i = 0; i < 15; i++){
                fscanf(masuk, "%99[^,],%d\n", tamu[i].nik, &kamar[i]);
            }
        }
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 15 - i - 1; j++){
                if(kamar[j] < kamar[j+1]){
                    int temp = kamar[j];
                    kamar[j] = kamar[j+1];
                    kamar[j+1] = temp;
                }
            }
        }
        //jadi, kamar diurutkan dari nomor yang terbesar.
        printf("\t\t\t\t Kamar yang sudah dipesan: \n");
        for(int i = 0; i < 15; i++){
            if(kamar[i] == 0) printf("\0");
            else printf("\t\t\t\t %d. %d\n",i+1,kamar[i]);
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
void tampilkan_tempo(int nomor){ //menampilkan jatuh tempo, tapi belum semua.
    FILE *buka;
    switch(nomor){
        case 101:
            buka = fopen("struk101.txt","r");
            break;
        case 102:
            buka = fopen("struk102.txt","r");
            break;
        case 103:
            buka = fopen("struk103.txt","r");
            break;
        case 104:
            buka = fopen("struk104.txt","r");
            break;
        case 105:
            buka = fopen("struk105.txt","r");
            break;
        case 201:
            buka = fopen("struk201.txt","r");
            break;
        case 202:
            buka = fopen("struk202.txt","r");
            break;
        case 203:
            buka = fopen("struk203.txt","r");
            break;
        case 204:
            buka = fopen("struk204.txt","r");
            break;
        case 205:
            buka = fopen("struk205.txt","r");
            break;
        case 301:
            buka = fopen("struk301.txt","r");
            break;
        case 302:
            buka = fopen("struk302.txt","r");
            break;
        case 303:
            buka = fopen("struk303.txt","r");
            break;
        case 304:
            buka = fopen("struk304.txt","r");
            break;
        case 305:
            buka = fopen("struk305.txt","r");
            break;
        default:
            printf("\t\t\t\t Tidak ada.\n");
    }
}
void pengecekan_tempo(){ //jatuh tempo
    FILE *cekdata = fopen("datatamu.txt","r");
    struct Kamar tamu;
    char nik[16];
    int nomor;
    system("cls");
    printf("\t\t\t\t||_________________________________________________||\n");
    printf("\t\t\t\t||                                                 ||\n");
    printf("\t\t\t\t||======  Halo, pelanggan kami yang tercinta  =====||\n");
    printf("\t\t\t\t||                                                 ||\n");
    printf("\t\t\t\t||=================================================||\n");
    printf("\t\t\t\t||Silakan masukkan NIK Anda: ");
    scanf("%[^\n]",nik);
    getchar();
    printf("\t\t\t\t||Silakan masukkan nomor kamar Anda: ");
    nomor = validasi_angka(101, 305);
    if(cekdata == NULL){
        printf("\t\t\t\t Maaf data tamu tidak ada!\n");
    }else{
        do{
            fscanf(cekdata, "%16[^,],%d\n", tamu.nik, &tamu.nomor);
            if(strcmp(tamu.nik,nik)==1 && tamu.nomor == nomor){
                printf("\t\t\t\t Data Terverifikasi.\n"); //no kamar belom terverif
                tampilkan_tempo(nomor);
                break;
            }
            else{
                printf("\t\t\t\t Mohon maaf data tidak ada, mungkin Anda belum registrasi!.\n");
                break;
            }
        }while(!feof(cekdata));
    }
    fclose(cekdata);
}
void family_machine_night(struct Kamar tamu){
    FILE *cekdata = fopen("datatamu.txt","r");
    FILE *tulis;
    char nik[16], nama_pengguna[1024];
    int nomor, n, harga;
    system("cls");
    printf("\t\t\t\t||Masukkan nama lengkap Anda: ");
    scanf("%[^\n]",nama_pengguna);
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
    scanf("%[^\n]", tamu.nik);
    getchar();
    for(int i = 0; i < 16; i++){
        if(strlen(tamu.nik) > 16){
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            family_machine_night(tamu);
        }else if(strlen(tamu.nik) < 16){
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            family_machine_night(tamu);
        }else if((int)tamu.nik[i] < '0' || (int)tamu.nik[i] > '9'){
            printf("\t\t\t\t Inputan salah!\n\t\t\t\t Harap masukkan kembali!\n");
            system("pause");
            family_machine_night(tamu);
        }
    }
    printf("\t\t\t\t||Masukkan nomor kamar yang diinginkan: ");
    tamu.nomor = validasi_angka(101, 305);
    if(cekdata == NULL){
        printf("\t\t\t\t Maaf program masih dalam pengembangan.\n");
    }else{
        while(!feof(cekdata)){
            fscanf(cekdata, "%16[^,],%d\n", nik, &nomor);
            if(strcmp(nik, tamu.nik) == 1 || nomor == tamu.nomor){
                printf("\t\t\t\t Maaf kamar sudah dipesan,\n\t\t\t\t Silakan memesan kamar yang lain.\n");
                break;
            }else{
                switch(tamu.nomor){
                    case 101:
                        tulis = fopen("struk101.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 102:
                        tulis = fopen("struk102.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 103:
                        tulis = fopen("struk103.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 104:
                        tulis = fopen("struk104.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 105:
                        tulis = fopen("struk105.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 201:
                        tulis = fopen("struk201.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 202:
                        tulis = fopen("struk202.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 203:
                        tulis = fopen("struk203.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 204:
                        tulis = fopen("struk204.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 205:
                        tulis = fopen("struk205.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 301:
                        tulis = fopen("struk301.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 302:
                        tulis = fopen("struk302.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 303:
                        tulis = fopen("struk303.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 304:
                        tulis = fopen("struk304.txt","w");
                        harga = n * KELUARGA_MALAM;
                        fclose(tulis);
                        break;
                    case 305:
                        tulis = fopen("struk305.txt","w");
                        harga = n * KELUARGA_MALAM; 
                        fclose(tulis);
                        break;
                    default:
                        printf("Dadaaaaa....");
                }
            }
        }
    }
    fclose(cekdata);
}

//PROSEDUR UNTUK MENAMPILKAN FASILITAS KAMAR KELUARGA 
void fasilitas_keluarga(){
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
    switch(pilih){
        case 1:
            family_machine_night(tamu); //ini dia
            break;
        case 2:
            //family_machine_month(tamu);
            break;
        case 3:
            //family_machine_year(tamu);
        default:
            printf("\t\t\t\t Terima kasih karena telah menggunakan program ini.\n");
    }
}
//PROSEDUR UNTUK MENAMPILKAN FASILITAS KAMAR PRIBADI 
void fasilitas_pribadi(){
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
    switch(pilih){
        case 1:
            break;
        case 2:
            break;
        default:
            printf("\t\t\t\t Terima kasih karena telah menggunakan program ini.\n");
    }
}
//PROSEDUR PILIHAN PAKET KAMAR 
void paketan(){
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
    switch(pilih){
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
//PROSEDUR UNTUK TAMBAHAN LAYANAN YANG ADA DI APARTMENT 
void tambahanlayanan (){ 
    printf("\t\t\t\t|| ===================================================== ||\n");
    printf("\t\t\t\t||                  LAYANAN TAMBAHAN                     ||\n");
    printf("\t\t\t\t|| ======================================================||\n");
    printf("\t\t\t\t||         L A Y A N A N         |       H A R G A       ||\n");
    printf("\t\t\t\t|| ===================================================== ||\n");
    printf("\t\t\t\t||   [1]  | Laundry              |  Rp. 8.000 /kg        ||\n");
    printf("\t\t\t\t||   [2]  | Housekeeping         |  Rp. 5.000 /hari      ||\n");
    printf("\t\t\t\t||   [3]  | Breakfast            |  Rp. 50.000 /porsi    ||\n");
    printf("\t\t\t\t||   [5]  | Kembali ke menu awal                         ||\n");
    printf("\t\t\t\t|| ===================================================== ||\n");
}
//TAMPILAN SELAMAT DATANG LAUNDRY 
void laundry () {
    printf("\t\t\t\t ==========================================================================\n");
    printf("\t\t\t\t ||                         WELCOME TO APART LAUNDRY                     ||\n");
    printf("\t\t\t\t || ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, ||\n");
    printf("\t\t\t\t ||                            I N F O R M A S I                         ||\n");
    printf("\t\t\t\t ||                              L A U N D R Y                           ||\n");
    printf("\t\t\t\t || ==================================================================== ||\n");
    printf("\t\t\t\t || Laundry ini merupakan layanan tambahan yang ada di Dudek's Apartment ||\n");
    printf("\t\t\t\t ||   customer dapat menggunakan layanan ini apabila sudah melakukan     ||\n");
    printf("\t\t\t\t ||  registrasi di Apartment. Layanan laundry dihitung berdasarkan berat ||\n");
    printf("\t\t\t\t ||        dari pakaian customer, setiap kg serharga Rp. 8.000,00.       ||\n");
    printf("\t\t\t\t || ==================================================================== ||\n");
}
void ulang_ulang();

void mainmenu(){
    int ulang;
    do{
        menu();
        pilih = validasi_angka(0, 3);
        switch(pilih){
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
            default:
                printf("\t\t\t\t Terima kasih karena telah menggunakan program ini.\n");
                system("pause");
        }
        ulang_ulang();
        ulang = validasi_angka(0, 1);
        system("cls");
        system("pause");
        system("cls");
    }while(ulang == 1);
}
//prosedur untuk pilihan ingin mengulang program 
void ulang_ulang(){
    system("cls"); 
	printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| *****  Apakah ingin mengulang?  **** ||\n");
    printf("\t\t\t\t||                                      ||\n");
    printf("\t\t\t\t|| ==================================== ||\n");
    printf("\t\t\t\t||   [0]    |     Tidak                 ||\n");
    printf("\t\t\t\t||   [1]    |     Iya                   ||\n");
    printf("\t\t\t\t||===================================== ||\n");
    printf("\t\t\t\t||Masukkan pilihan: ");
}