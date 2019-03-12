#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

struct{
    char nama[50];
    char harga[25];
    char date[8];
    int nilaiDprs;
    int dprsNol;
}aset[100];

struct{
    int harga;
    int dd;
    int mm;
    int yy;
}konversi[100];

struct{
    float persentase;
    int tahun;
    int bulan;
    int residu;
    int pilihan;
}dprs;

void inputAset(); // CASE 1 //
void daftarAset(); // CASE 2 //
void hargaAset(); // CASE 3 //
void jumlahAset(); // CASE 4 //
void pembelianAset(); // CASE 5 //
void riwayatAset();// CASE 6 //
void nilaiAset(); // CASE 7 //
void rangeAset(); // CASE 8 //
void depresiasiAset(); // CASE 9 //
void cmpDepresiasi(); // CASE 10 //
void cmpDprsNol(); // CASE 11 //
void asetTerbanyak(); // CASE 12 //
void inventaris(); // CASE 13 //
void hapusAset(); // CASE 14 //
void konversiTanggal(int x); // PROSEDUR UNTUK KONVERSI TANGGAL //
void konversiHarga(int x); // PROSEDUR UNTUK KONVERSI HARGA //
void menu(); // MENAMPILKAN MENU UTAMA //
void file(); // MEMBACA FILE YANG SUDAH ADA SEBELUMNYA //
void depresiasi(); // MEMBACA KETENTUAN DEPRESIASI //
void rupiah(char *x); // MENAMPILKAN HARGA ASET LENGKAP DENGAN FORMAT RUPIAH //
void sorting(); // MENGURUTKAN DATA //
void counterArray(); // MENGHITUNG JUMLAH ARRAY YANG MEMILIKI DATA //
void hitungDepresiasi(); // MENGHITUNG SEMUA NILAI DEPRESIASI //
void saveFile(); // SAVE FILE //

int counterAset(int x); // MENGHITUNG JUMLAH ASET //
int konversiHari(char a,char b);
int konversiBulan(char a,char b);
int konversiTahun(char a,char b);

int sizeArr;

int main(){
    depresiasi();
    file();
    menu();
}

// PROSEDUR UNTUK MENGINPUT DATA-FATA ASET //
void file(){
    fstream r_file;
    string namaAset;
    char *konvAset;

    r_file.open("data_aset.dat");

    if(!r_file.fail()){
        while(!r_file.eof()){
            for(int i=0;i<100;i++){
                r_file >> aset[i].date;
                konversiTanggal(i);
                r_file >> aset[i].harga;
                konversiHarga(i);
                r_file.ignore();
                getline(r_file, namaAset);

                konvAset=strdup(namaAset.c_str());
                strcpy(aset[i].nama,konvAset);
            }
        } r_file.close();
    }
    else{
        r_file.open("data_aset.dat", ios::app);
        r_file.close();
    }
}

void depresiasi(){
    fstream r_depresiasi;
    float persentase;
    int tahun, bulan, residu, pilihan;

    r_depresiasi.open("system_data.dat");

    if(!r_depresiasi.fail()){
        r_depresiasi >> pilihan;
        dprs.pilihan=pilihan;
        if(pilihan==1){
            r_depresiasi >> tahun;
            bulan=tahun*12;
            dprs.bulan=bulan;
            r_depresiasi >> residu;
            dprs.residu=residu;
        }
        else if(pilihan==2){
            r_depresiasi >> tahun;
            dprs.tahun=tahun;
            r_depresiasi >> residu;
            dprs.residu=residu;
        }
        else if(pilihan==3){
            r_depresiasi >> persentase;
            dprs.persentase=persentase;
            r_depresiasi >> tahun;
            bulan=tahun*12;
            dprs.bulan=bulan;
            r_depresiasi >> residu;
            dprs.residu=residu;
        }
        r_depresiasi.close();
    }
    else{
        int pilihan;
        cout << "Ketentuan Depresiasi Belum Ditetapkan." << endl << endl;
        menuDepresiasi:
        cout << "Metode Depresiasi yang Dapat dijalankan:" << endl;
        cout << "1. Garis Lurus per Bulan." << endl;
        cout << "2. Garis Lurus per Tahun." << endl;
        cout << "3. Persentase Tetap." << endl;
        cout << "*Metode persentase tetap menggunakan sistem depresiasi per bulan." << endl;
        cout << "Pilih metode depresiasi: ";
        cin >> pilihan;
        dprs.pilihan=pilihan;

        switch(pilihan){
        case 1:
            cout << "Tentukan masa pakai aset (dalam tahun): "; cin >> tahun;
            dprs.tahun=tahun;
            cout << "Tentukan nilai residu aset            : "; cin >> residu;
            dprs.residu=residu;
            break;
        case 2:
            cout << "Tentukan masa pakai aset (dalam tahun): "; cin >> tahun;
            dprs.tahun=tahun;
            cout << "Tentukan nilai residu aset            : "; cin >> residu;
            dprs.residu=residu;
            break;
        case 3:
            cout << "Tentukan persentase depresiasi aset   : "; cin >> persentase;
            dprs.persentase=persentase;
            cout << "Tentukan masa pakai aset (dalam tahun): "; cin >> tahun;
            dprs.tahun=tahun;
            cout << "Tentukan nilai residu aset            : "; cin >> residu;
            dprs.residu=residu;
            break;
        default:
            goto menuDepresiasi;
            break;
        }

        r_depresiasi.open("system_data.dat", ios::app);

        if(!r_depresiasi.fail()){
            if(pilihan==1){
                r_depresiasi << pilihan << endl;
                r_depresiasi << tahun << endl;
                r_depresiasi << residu << endl;
            }
            else if(pilihan==2){
                r_depresiasi << pilihan << endl;
                r_depresiasi << tahun << endl;
                r_depresiasi << residu << endl;
            }
            else if(pilihan==3){
                r_depresiasi << pilihan << endl;
                r_depresiasi << persentase << endl;
                r_depresiasi << tahun << endl;
                r_depresiasi << residu << endl;
            }
        }
        r_depresiasi.close();
    }
}

void saveFile(){
    ofstream s_file;

    s_file.open("data_aset.dat", ios::trunc);

    if(!s_file.fail()){
        for(int i=0;i<sizeArr;i++){
            s_file << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << " ";
            s_file << konversi[i].harga << endl;
            s_file << aset[i].nama << endl;
        }
        s_file.close();
    }
    else{
        cout << "error";
    }
}

void inputAset(){
    cout << "Anda sedang menjalankan menu untuk pendataan aset." << endl;
    cout << "Ketentuan pendataan:" << endl;
    cout << "*Input tanggal pembelian aset dengan format dd-mm-yy." << endl;
    cout << "*Input harga aset tanpa tanda '.'" << endl;
    cout << "*Input '-' untuk menyelesaikan pendataan aset." << endl;
    cout << "Pendataan Aset:" << endl;
    for(int i=0;i<100;i++){
        if(strlen(aset[i].date)!=0){ // VALIDASI ADA ATAU TIDAKNYA DATA DISUATU ARRAY //
            if(aset[i].date[0]=='-'){
                goto pendataan;
            }else{
                goto pendataan_end;
            }
        }
        if(i!=0 && i%5==0){
            char pilihan;
            konfirmasi:
            cout << "Apakah masih ada aset yang akan didata? (Y/N)" << endl;
            cin >> pilihan;
            if(pilihan=='y'||pilihan=='Y'){
                goto pendataan;
            }
            else if(pilihan=='n'||pilihan=='N'){
                break;
            }
            else{
                goto konfirmasi;
            }
        }
        pendataan:
        cout << i+1 << ". ";
        cout << "Tanggal Pembelian: "; cin >> aset[i].date;
        if(aset[i].date[0]=='-'){
            cout << endl;
            break;
        }
        else if(aset[i].date[2]!='-'||aset[i].date[5]!='-'){
            cout << "Perhatikan format pendataan!." << endl;
            goto pendataan;
        }
        // CEK VALIDITAS TANGGAL //
        if(konversi[i].mm>12){
            cout << "Tanggal Tidak Valid" << endl;
            goto pendataan;
        }
        else if(konversi[i].mm==2){ // VALIDASI BULAN FEBRUARI //
            if(konversi[i].yy%2!=0 && konversi[i].dd>28){
                cout << "Tanggal Tidak Valid" << endl;
                goto pendataan;
            } else if(konversi[i].dd>29){
                cout << "Tanggal Tidak Valid" << endl;
                goto pendataan;
            }
        }
        else if(konversi[i].mm%2==0 && konversi[i].dd>30){ // VALIDASI BULAN DENGAN MAKSIMAL 30 //
            cout << "Tanggal Tidak Valid" << endl;
            goto pendataan;
        }
        else if(konversi[i].dd>31){
            cout << "Tanggal Tidak Valid" << endl;  // VALIDASI BULAN DENGAN MAKSIMAL 31 //
            goto pendataan;
        }
        konversiTanggal(i);
        cout << "   Harga Aset       : "; cin >> aset[i].harga;
        konversiHarga(i);
        cin.ignore(); /* UNTUK REFRESH CIN.
        KARENA SETELAH CIN >> VARIABEL, COMPILER AKAN SKIPPING JENIS CIN LAINNYA */
        cout << "   Nama Aset        : "; gets(aset[i].nama);
        cout << endl;
        pendataan_end:
        cout << "";
    }
}

void daftarAset(){
    int n=1;
    cout << "Daftar Aset: " << endl;
    for(int i=0;i<sizeArr;i++){
        if(strcmp(aset[i].nama,aset[i-1].nama)!=0){
            cout << n << ". " << aset[i].nama << endl;
            n++;
        }
    }
    cout << endl;
}

void hargaAset(){
    cout << "Harga Beli Aset: " << endl;
    for(int i=0;i<sizeArr;i++){
        cout << i+1 << ". " << aset[i].nama << " Rp";
        rupiah(aset[i].harga);
    }
    cout << endl;
}

void jumlahAset(){
    int n;
    char cari[50];
    char data[50];
    daftarAset();
    cout << "Nama aset: ";
    cin.ignore();
    gets(cari);
    for(int i=0;i<sizeArr;i++){
        strcpy(data,aset[i].nama);
        if(strcmp(strupr(data),strupr(cari))==0){
            cout << "> Tersedia " << counterAset(i) << " Unit" << endl;
            break;
        }
    }
    cout << endl;
}

void pembelianAset(){
    char cari[50];
    char data[50];
    int n=1;

    daftarAset();
    cout << "Nama aset yang akan diinspeksi riwayat pembeliannya: ";
    cin.ignore();
    gets(cari);
    for(int i=0;i<sizeArr;i++){
        strcpy(data,aset[i].nama);
        if(strcmp(strupr(data),strupr(cari))==0){
            cout << "Data Pembelian " << n << endl;
            cout << "Tanggal Pembelian: " << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl;
            cout << "Harga Pembelian  : Rp";
            rupiah(aset[i].harga);
            cout << endl;
            n++;
        }
    }
}

void nilaiAset(){
    char cari[50];
    char data[50];
    char num[25];
    int nilai=0;

    daftarAset();
    cout << "Nama aset yang akan dihitung nilainya: ";
    cin.ignore();
    gets(cari);
    cout << endl;
    for(int i=0;i<sizeArr;i++){
        strcpy(data,aset[i].nama);
        if(strcmp(strupr(data),strupr(cari))==0){
            cout << aset[i].nama << endl;
            cout << "Jumlah aset total     : " << counterAset(i) << " Unit." << endl;
            cout << "Aset tersebut bernilai: ";
            for(int j=i;j<sizeArr;j++){
                if(strcmp(aset[i].nama,aset[j].nama)==0){
                    nilai=nilai+konversi[j].harga;
                }
            }
            itoa(nilai, num, 10);
            cout << "Rp";
            rupiah(num);
            cout << endl;
            break;
        }
    }
}

void menu(){
    startMenu:
    counterArray(); // MENGHITUNG JUMLAH ARRAY YANG MEMILIKI VALUE //
    sorting();
    hitungDepresiasi();
    cout << "Menu yang tersedia: " << endl;
    cout << "1. Pendataan Aset." << endl;
    cout << "2. Daftar Aset." << endl;
    cout << "3. Harga Beli Aset." << endl;
    cout << "4. Jumlah Aset (Satuan)." << endl;
    cout << "5. Riwayat Pembelian Aset." << endl;
    cout << "6. Riwayat Aset." << endl;
    cout << "7. Nilai per Satuan Aset." << endl;
    cout << "8. Daftar Aset dirange Harga Tertentu." << endl;
    cout << "9. Nilai Depresiasi per Aset." << endl;
    cout << "10.Aset Dengan Nilai Depresiasi Terbesar/Terkecil." << endl;
    cout << "11.Nilai Depresiasi Nol Terbesar/Terkecil." << endl;
    cout << "12.Aset Dengan Jumlah Terbanyak." << endl;
    cout << "13.Total Inventaris." << endl;
    cout << "14.Hapus Aset." << endl;
    cout << "15.Exit." << endl;
    cout << "Menu yang akan dijalankan: ";

    int pilihan;
    cin >> pilihan;

    cout << endl;

    switch(pilihan){
    case 1:
        inputAset();
        system("CLS");
        goto startMenu;
        break;
    case 2:
        daftarAset();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 3:
        hargaAset();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 4:
        jumlahAset();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 5:
        pembelianAset();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 6:
        riwayatAset();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 7:
        nilaiAset();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 8:
        rangeAset();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 9:
        depresiasiAset();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 10:
        cmpDepresiasi();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 11:
        cmpDprsNol();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 12:
        asetTerbanyak();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 13:
        inventaris();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 14:
        hapusAset();
        system("PAUSE");
        system("CLS");
        goto startMenu;
        break;
    case 15:
        saveFile();
        system("PAUSE");
        system("CLS");
        break;
    default:
        goto startMenu;
        break;
    }
}

void sorting(){
    int bd;
    for(int i=0;i<sizeArr;i++){
        for(int j=i+1;j<sizeArr;j++){
            bd=strcmp(aset[i].nama,aset[j].nama);
            if(bd==1){
                swap(aset[i].nama,aset[j].nama);
                swap(aset[i].harga,aset[j].harga);
                swap(aset[i].date,aset[j].date);
                swap(konversi[i].harga,konversi[j].harga);
                swap(konversi[i].dd,konversi[j].dd);
                swap(konversi[i].mm,konversi[j].mm);
                swap(konversi[i].yy,konversi[j].yy);
            }
        }
    }
}

void rupiah(char *x){
    char a[25];
    int num=strlen(x);

    for(int i=0;i<num;i++){
        a[num-i-1]=x[i];
    }
    for(int i=num-1;i>=0;i--){
        cout << a[i];
        if(i%3==0){
            if(i!=0){
                cout << ".";
            }
        }
    }
    cout << ",00" << endl;
}

int counterAset(int x){
    int counter=1;
    for(int i=x+1;i<sizeArr;i++){
        if(strcmp(aset[x].nama,aset[i].nama)==0){
            counter++;
        }
    }
    return counter;
}

void counterArray(){
    sizeArr=0;
    for(int i=0;i<100;i++){
        if(strlen(aset[i].harga)!=0)sizeArr++;
    }
}

void rangeAset(){
    int atas, bawah;

    cout << "Input batas harga atas : "; cin >> atas;
    cout << "Input batas harga bawah: "; cin >> bawah;
    cout << endl;
    cout << "List aset yang berada di range tersebut:" << endl;
    for(int i=0;i<sizeArr;i++){
        if(konversi[i].harga>bawah && konversi[i].harga<atas){
            cout << "> " << aset[i].nama << endl;
            cout << "Tanggal Pembelian: " << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl;
            cout << "Harga Pembelian  : Rp"; rupiah(aset[i].harga);
            cout << endl;
        }
    }
}

void asetTerbanyak(){
    int jumlah[sizeArr];
    int max=0;

    cout << "Aset dengan jumlah terbanyak:" << endl;
    for(int i=0;i<sizeArr;i++){
        jumlah[i]=0;
        for(int j=0;j<sizeArr;j++){
            if(strcmp(aset[i].nama,aset[j].nama)==0){
                jumlah[i]++;
            }
        }
    }

    for(int i=0;i<sizeArr;i++){
        if(jumlah[i]>max){
            max=jumlah[i];
        }
    }

    for(int i=0;i<sizeArr;i++){
        if(strcmp(aset[i].nama,aset[i-1].nama)!=0){
            if(jumlah[i]==max){
                cout << "> " << aset[i].nama << " sebanyak " << max << " Unit" << endl;
            }
        }
    }
    cout << endl;
}

void depresiasiAset(){
    char cari[50];
    char data[50];
    char num[25];
    int n=1;

    daftarAset();
    cout << "Nama aset yang akan diinspeksi nilai depresiasinya: ";
    cin.ignore();
    gets(cari);
    for(int i=0;i<sizeArr;i++){
        strcpy(data,aset[i].nama);
        if(strcmp(strupr(data),strupr(cari))==0){
            cout << "Data Depresiasi " << n << endl;
            cout << "Tanggal Pembelian: " << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl;
            cout << "Nilai Depresiasi : ";
            itoa(aset[i].nilaiDprs, num, 10);
            cout << "Rp";
            rupiah(num);
            cout << endl << endl;
            n++;
        }
    }
}

void hitungDepresiasi(){
    for(int x=0;x<sizeArr;x++){
        if(dprs.pilihan==1){
            aset[x].nilaiDprs=(konversi[x].harga-dprs.residu)/dprs.bulan;
            aset[x].dprsNol=konversi[x].harga-(aset[x].nilaiDprs*dprs.bulan);
            if(aset[x].dprsNol<0){
                aset[x].dprsNol=0;
            }
        }
        else if(dprs.pilihan==2){
            aset[x].nilaiDprs=(konversi[x].harga-dprs.residu)/dprs.tahun;
            aset[x].dprsNol=konversi[x].harga-(aset[x].nilaiDprs*dprs.tahun);
            if(aset[x].dprsNol<0){
                aset[x].dprsNol=0;
            }
        }
        else if(dprs.pilihan==3){
            aset[x].nilaiDprs=(konversi[x].harga-dprs.residu)*(dprs.persentase/100);
            aset[x].dprsNol=konversi[x].harga-(aset[x].nilaiDprs*dprs.bulan);
            if(aset[x].dprsNol<0){
                aset[x].dprsNol=0;
            }
        }
    }
}

void riwayatAset(){
    char cari[50];
    char data[50];
    char num[25];
    int n=1;

    daftarAset();
    cout << "Nama aset yang akan diinspeksi riwayat lengkapnya: ";
    cin.ignore();
    gets(cari);
    for(int i=0;i<sizeArr;i++){
        strcpy(data,aset[i].nama);
        if(strcmp(strupr(data),strupr(cari))==0){
            cout << "Data Pembelian " << n << endl;
            cout << "Tanggal Pembelian: " << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl;
            cout << "Harga Pembelian  : Rp";
            rupiah(aset[i].harga);
            cout << "Nilai Depresiasi : Rp";
            itoa(aset[i].nilaiDprs, num, 10);
            rupiah(num);
            cout << endl << endl;
            n++;
        }
    }
}

void cmpDepresiasi(){
    int max=0, min=0, pilihan;
    char num[25];

    for(int i=0;i<sizeArr;i++){
        if(aset[i].nilaiDprs>max){
            max=aset[i].nilaiDprs;
        }
    }

    for(int i=0;i<sizeArr;i++){
        if(min==0){
            min=aset[i].nilaiDprs;
        }
        if(aset[i].nilaiDprs<min){
            min=aset[i].nilaiDprs;
        }
    }
    cout << "1. Nilai Depresiasi Terbesar." << endl;
    cout << "2. Nilai Depresiasi Terkecil." << endl;
    cout << "Menu yang dijalankan: "; cin >> pilihan;
    cout << endl;

    switch(pilihan){
    case 1:
        cout << "Aset dengan nilai depresiasi terbesar:" << endl;
        for(int i=0;i<sizeArr;i++){
            if(aset[i].nilaiDprs==max){
                cout << "> " << aset[i].nama << endl;
                cout << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl;
                itoa(aset[i].nilaiDprs, num, 10);
                cout << "Rp";
                rupiah(num);
                cout << endl;
            }
        }
        break;
    case 2:
        cout << "Aset dengan nilai depresiasi terkecil:" << endl;
        for(int i=0;i<sizeArr;i++){
            if(aset[i].nilaiDprs==min){
                cout << "> " << aset[i].nama << endl;
                cout << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl;
                itoa(aset[i].nilaiDprs, num, 10);
                cout << "Rp";
                rupiah(num);
                cout << endl;
            }
        }
        break;
    }
    cout << endl;
}

void cmpDprsNol(){
    int max=0, min=0, pilihan;
    char num[25];

    for(int i=0;i<sizeArr;i++){
        if(aset[i].dprsNol>max){
            max=aset[i].dprsNol;
        }
    }

    for(int i=0;i<sizeArr;i++){
        if(min==0){
            min=aset[i].dprsNol;
        }
        if(aset[i].dprsNol<min){
            min=aset[i].dprsNol;
        }
    }

    cout << "1. Nilai Depresiasi Nol Terbesar." << endl;
    cout << "2. Nilai Depresiasi Nol Terkecil." << endl;
    cout << "Menu yang dijalankan: "; cin >> pilihan;
    cout << endl;


    switch(pilihan){
    case 1:
        cout << "Aset dengan nilai depresiasi terbesar:" << endl;
        for(int i=0;i<sizeArr;i++){
            if(aset[i].dprsNol==max){
                cout << "> " << aset[i].nama << endl;
                cout << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl;
                itoa(aset[i].dprsNol, num, 10);
                cout << "Rp";
                rupiah(num);
                cout << endl;
            }
        }
        break;
    case 2:
        cout << "Aset dengan nilai depresiasi terkecil:" << endl;
        for(int i=0;i<sizeArr;i++){
            if(aset[i].dprsNol==min){
                cout << "> " << aset[i].nama << endl;
                cout << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl;
                itoa(aset[i].dprsNol, num, 10);
                cout << "Rp";
                rupiah(num);
                cout << endl;
            }
        }
        break;
    }
    cout << endl;
}

void inventaris(){
    int jumlah=0;
    char num[25];

    for(int i=0;i<sizeArr;i++){
        jumlah=jumlah+konversi[i].harga;
    }

    cout << "Total Invetaris: " << endl;
    itoa(jumlah, num, 10);
    cout << "Rp";
    rupiah(num);
    cout << endl;
}

void hapusAset(){
    int n;

    cout << "Data Aset:" << endl;

    for(int i=0;i<sizeArr;i++){
        cout << "Data Aset Ke-" << i+1 << endl;
        cout << aset[i].nama << endl;
        cout << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl << endl;
    }
    cout << "Pilih Indek Aset (Data Aset Ke- ): "; cin >> n;

    for(int i=n-1;i<sizeArr;i++){
        strcpy(aset[i].nama,aset[i+1].nama);
        strcpy(aset[i].harga,aset[i+1].harga);
        strcpy(aset[i].date,aset[i+1].date);
        aset[i].dprsNol=aset[i+1].dprsNol;
        aset[i].nilaiDprs=aset[i+1].nilaiDprs;
        konversi[i].dd=konversi[i+1].dd;
        konversi[i].mm=konversi[i+1].mm;
        konversi[i].yy=konversi[i+1].yy;
        konversi[i].harga=konversi[i+1].harga;
    }
    sizeArr--;
    cout << "Daftar Aset Lengkap Terbaru: " << endl;
    for(int i=0;i<sizeArr;i++){
        cout << "Data Aset Ke-" << i+1 << endl;
        cout << aset[i].nama << endl;
        cout << konversi[i].dd << "-" << konversi[i].mm << "-" << konversi[i].yy << endl << endl;
    }
    cout << endl;
}

// KONVERSI //
void konversiHarga(int x){
    konversi[x].harga=atoi(aset[x].harga);
}

void konversiTanggal(int x){
    konversi[x].dd=konversiHari(aset[x].date[0],aset[x].date[1]);
    konversi[x].mm=konversiBulan(aset[x].date[3],aset[x].date[4]);
    konversi[x].yy=konversiBulan(aset[x].date[6],aset[x].date[7]);
}

int konversiHari(char a, char b){
    int c;
    if(a=='0'){
        c=int(b)-48;
    }
    else{
        c=((int(a)-48)*10)+(int(b)-48);
    }
    return c;
}

int konversiBulan(char a, char b){
    int c;
    if(a=='0'){
        c=int(b)-48;
    }
    else if(a>='1'){
        c=(int(a)-39)+(int(b)-48);
    }
    return c;
}

int konversiTahun(char a, char b){
    int c;
    c=((int(a)-48)*10)+(int(b)-48);
    return c;
}
