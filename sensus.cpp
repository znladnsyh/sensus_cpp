 #include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
struct daerah {
    char kel[50];
    char kec[50];
    char kota[50];
};
struct data {
    int nomor;
    char nama[50];
    char agama[20];
    char status[20];
    char pekerjaan[20];
    char tempat[20];
    char tanggal[20];
    char almt[20];
    daerah alamat;
};
typedef struct {
 int base[100];
 char base1[100][20];
 int depan;
 int belakang;
}queue;
queue antrian;
queue nama;
char base1[20];
int base, i, j;
int isEmpty () {
 if (antrian.belakang == -1)
  return 1;
  else
  return 0;
}
int isFull () {
 if (antrian.belakang == 100)
  return 1;
  else
  return 0;
}
void enqueu (int base, char base1[20]) { //tambah elemen
 if (isEmpty() == 1) {
  antrian.depan = antrian.belakang = 0;
    nama.depan = nama.belakang = 0;
    antrian.base[antrian.belakang] = base;
    for (i=0; i<20; i++) {
      nama.base1[nama.belakang][i] = base1[i];
    }
  cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|           Silahkan menunggu panggilan          |" << endl;
  }
  else if (isFull() == 0) {
    antrian.belakang++;
    nama.belakang++;
    antrian.base[antrian.belakang] = base;
    for (i=0; i<20; i++) {
      nama.base1[nama.belakang][i] = base1[i];
    }
  cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|           Silahkan menunggu panggilan          |" << endl;
  }
}
int dequeue () { //keluar elemen
 if (isEmpty() == 0) {
  int i, e;
  char a[20];
    e = antrian.base[antrian.depan];
    for (i=0; i<20; i++) {
   a[i] = nama.base1[nama.depan][i];
    }
  for (i=antrian.depan; i<antrian.belakang; i++) {
   antrian.base[i] = antrian.base[i+1];
      for (j=0; j<20; j++) {
       nama.base1[i][j] = nama.base1[i+1][j];
      }
    }
    antrian.belakang--;
    nama.belakang--;
    printf ("\t\t|\tAntrian dengan no %i                     |",e);
  printf ("\n\t\t|\tDengan nama %s                         ",a);
 printf ("\n\t\t|\tSilahkan masuk                          |");
    return e;
    return a[20];
 }
  else {
    printf ("\t\t|\tAntrian kosong                            |");
  }
}
void buat () {
 antrian.depan = antrian.belakang = -1;
 nama.depan = nama.belakang = -1;
}
int list(){
 int i;
 int list_int[20];
 for (i=0; i<base; i++){
       list_int[i] = i + 1;
      cout << "\t\t|\tAntrian dengan NO "<<list_int[i]<<"                     |"<<endl;
 }
 return 0;
}


int dequeue1 () { //keluar elemen
 if (isEmpty() == 0) {
  int i, e;
  char a[20];
    e = antrian.base[antrian.depan];
    for (i=0; i<20; i++) {
   a[i] = nama.base1[nama.depan][i];
    }
  for (i=antrian.depan; i<antrian.belakang; i++) {
   antrian.base[i] = antrian.base[i+1];
      for (j=0; j<20; j++) {
       nama.base1[i][j] = nama.base1[i+1][j];
      }
    }
    antrian.belakang--;
    nama.belakang--;
    printf ("\t\t|\tSisa antrian %i                          |\n",e);
    return e;
    return a[20];
 }
  else {
    printf ("\t\t|\tSisa Antrian kosong                     |\n");
  }
}
void head(){
 cout << "\t\t|===============================================|"<<endl;
 cout << "\t\t|                                               |"<<endl;
cout << "\t\t|         APLIKASI SENSUS PENDUDUK              |"<<endl;
cout << "\t\t|   Kantor kecamatan torgamba - LABUSEL         |"<<endl;
 cout << "\t\t|       by github.com/znladnsyh                 |"<<endl;
 cout << "\t\t|===============================================|"<<endl;
 cout << "\t\t|                                               |"<<endl;
}

int main() {
 int menu;
 int nik=-1,x,y;
 int n;
 int prio;
 buat();
 n=1;
 int pilih;
 int namedit;
 data ktp[20];
 char get[1];
 bool ketemu;

    menuutama:
    system("cls");
    system ("color a");
 head();
 cout << "\t\t|\tMENU UTAMA :                            |"<<endl;
 cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[1] Registrasi Antrian                  |"<<endl;
 cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[2] Panggil Antrian                     |"<<endl;
 cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[0] Pendaftaran Online                  |"<<endl;
 cout << "\t\t|                                               |"<<endl;
 cout << "\t\t|\t[3] List Antrian                        |"<<endl;
 cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[4] Menambah Data PASWORD               |"<<endl;
 cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[5] Mencari Data PASWORD                |"<<endl;
 cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[6] Menghapus Data PASWORD              |"<<endl;
 cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[7] Menampilkan Data PASWORD            |"<<endl;
 cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|\t[8] Keluar                              |"<<endl;
 cout << "\t\t|                                               |"<<endl;
 cout << "\t\t|===============================================|"<<endl;
    cout << "\n\tMasukan Pilihan Anda (1-8) : "; cin >> menu;

    if(menu==1) {
  system("cls");
  head();
       cout << "\t\t|              REGISTRASI ANTRIAN               |"<<endl;
     cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
      cout << "\t\t|\tNomor antrian anda adalah : " << n <<"           |"<< endl;
      dequeue1 ();
  cout << "\t\t|                                               |"<<endl;
      base = n;
      printf("\t\t|\tMasukkan nama  : ");scanf("%s", &base1);
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
    enqueu(base, base1);
      n++;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
        cout << "\t\t|\t[1] Kembali ke Menu Utama               |"<<endl;
       cout << "\t\t|\t[2] Keluar dari program                 |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
        cout << "\n\tMasukan Pilihan Anda : "; cin >> pilih;
       cout << endl;
   
      if(pilih == 1) {
         goto menuutama;
      }
       else if(pilih == 2) {
         goto keluar;
       }
 }

    else if(menu == 2) {
  system ("cls");
  head();
     cout << "\t\t|             PEMANGGILAN ANTRIAN               |"<<endl;
     cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;;
       dequeue();
  cout << "\n\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
        cout << "\t\t|\t[1] Kembali ke Menu Utama               |"<<endl;
       cout << "\t\t|\t[2] Keluar dari program                 |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
        cout << "\n\tMasukan Pilihan Anda : "; cin >> pilih;
 
     if(pilih == 1) {
         goto menuutama;
       }
       else if(pilih == 2) {
         goto keluar;
       }
   }
 
    else if(menu == 3) {
    system("cls");
      head();
      list();
      cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
        cout << "\t\t|\t[1] Kembali ke Menu Utama               |"<<endl;
       cout << "\t\t|\t[2] Keluar dari program                 |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
        cout << "\n\tMasukan Pilihan Anda : "; cin >> pilih;
       cout << endl;
   
      if(pilih == 1) {
         goto menuutama;
      }
       else if(pilih == 2) {
         goto keluar;
       }
  }
          else if(menu == 4) {
     system("cls");
      nik++;
      head();
      cout << "\t\t| NIK (max 5 karakter)       : "; cin >> ktp[nik].nomor; cin.getline(get,1);
      cout << "\t\t| Nama Lengkap               : "; cin.getline(ktp[nik].nama,50);
        cout << "\t\t| Agama                      : "; cin.getline(ktp[nik].agama,20);
        cout << "\t\t| Status Perkawinan          : "; cin.getline(ktp[nik].status,20);
        cout << "\t\t| Pekerjaan                  : "; cin.getline(ktp[nik].pekerjaan,20);
        cout << "\t\t| Tempat Lahir               : "; cin.getline(ktp[nik].tempat,20);
        cout << "\t\t| Tanggal Lahir (DD MM YYYY) : "; cin.getline(ktp[nik].tanggal,20);
        cout << "\t\t| Alamat                     : "; cin.getline(ktp[nik].almt,20);
        cout << "\t\t| Kelurahan                  : "; cin.getline(ktp[nik].alamat.kel,20);
        cout << "\t\t| Kecamatan                  : "; cin.getline(ktp[nik].alamat.kec,20);
        cout << "\t\t| Kota                       : "; cin.getline(ktp[nik].alamat.kota,20);
   
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
        cout << "\t\t|\t[1] Kembali ke Menu Utama               |"<<endl;
       cout << "\t\t|\t[2] Keluar dari program                 |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
        cout << "\n\tMasukan Pilihan Anda : "; cin >> pilih;
       cout << endl;
   
      if(pilih == 1) {
         goto menuutama;
      }
       else if(pilih == 2) {
         goto keluar;
       }
    }

    else if(menu == 5) {
     system ("cls");
     head();
     cout << "\t\t|           PENCARIAN DATA PASWORD             |"<<endl;
     cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;;
       cout << "\t\t|\tMasukan NIK : "; cin>>namedit;
 
     for(x=0;x<=nik;x++) {
       if(namedit==ktp[x].nomor) {
        cout << "\t\t|                                               |"<<endl;
    cout << "\t\t|===============================================|"<<endl;
        cout << "\t\t|                                               |"<<endl;
          cout << "\t\t|\tData di temukan                         |"<<endl;
    cout << "\t\t|\tRegistrasi data penduduk ke-" << x+1 <<"           |"<< endl;
        cout << "\t\t|                                               |"<<endl;
          cout << "\t\t|\tNama Lengkap      : " << ktp[x].nama << endl;
          cout << "\t\t|\tAgama             : " << ktp[x].agama << endl;
          cout << "\t\t|\tStatus perkawinan : " << ktp[x].status << endl;
          cout << "\t\t|\tPekerjaan         : " << ktp[x].pekerjaan << endl;
          cout << "\t\t|\tTempat Lahir      : " << ktp[x].tempat << endl;
          cout << "\t\t|\tTanggal Lahir     : "<< ktp[x].tanggal << endl;
          cout << "\t\t|\tAlamat            : "<< ktp[x].almt << endl;
          cout << "\t\t|\tKelurahan         : "<< ktp[x].alamat.kel << endl;
          cout << "\t\t|\tKecamatan         : "<< ktp[x].alamat.kec << endl;
          cout << "\t\t|\tKota              : "<< ktp[x].alamat.kota << endl;
    
          goto menu0;
         }
     }
   
     cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
     cout << "\t\t|    DATA YANG ANDA CARI TIDAK DI TEMUKAN !!!   |"<<endl;
        menu0:
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
        cout << "\t\t|\t[1] Kembali ke Menu Utama               |"<<endl;
       cout << "\t\t|\t[2] Keluar dari program                 |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
        cout << "\n\tMasukan Pilihan Anda : "; cin >> pilih;
       cout << endl;
 
        if(pilih == 1) {
         goto menuutama;
       }
       else if(pilih == 2) {
         goto keluar;
       }
   }
  else if(menu == 6) {
     system ("cls");
  head();
     cout << "\t\t|    PENGHAPUSAN DATA PASWORD PADA DATABASE    |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
     cout << "\t\t|\tNIK : "; cin >> namedit;
 
      for(x=0;x<=nik;x++) {
         if(namedit==ktp[x].nomor) {
          ketemu=true;
          if(ketemu) {
            for(y=x;y<=nik+1;y++) {
               ktp[y]=ktp[y+1];
            }
            cout << "\t\t|                                               |"<<endl;
     cout << "\t\t|===============================================|"<<endl;
     cout << "\t\t|                                               |"<<endl;
           cout << "\t\t|            DATA BERHASIL DI HAPUS             |"<<endl;
           nik--;
           goto menu;
          }
        }
     }
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|  DATA YANG AKAN DI HAPUS TIDAK DITEMUKAN !!!  |"<<endl;
 
      menu:
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
        cout << "\t\t|\t[1] Kembali ke Menu Utama               |"<<endl;
       cout << "\t\t|\t[2] Keluar dari program                 |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
        cout << "\n\tMasukan Pilihan Anda : "; cin >> pilih;
       cout << endl;
      if(pilih == 1) {
        goto menuutama;
      }
      else if(pilih == 2) {
        goto keluar;
      }
   }

  else if(menu == 7) {
    system ("cls");
    head();
     cout << "\t\t|           MENAMPILKAN DATA PASWORD           |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
    for(x=0;x<=nik;x++) {
      cout << "\t\t|\tDatabase Data Penduduk ke-" << x+1 << endl;
   cout << "\t\t|                                               "<<endl;
        cout << "\t\t|\tNIK : " << ktp[x].nomor << endl;
        cout << "\t\t|\tNama : " << ktp[x].nama << endl;
        cout << "\t\t|\tAgama : " << ktp[x].agama << endl;
        cout << "\t\t|\tStatus perkawinan : " << ktp[x].status << endl;
        cout << "\t\t|\tPekerjaan : " << ktp[x].pekerjaan << endl;
        cout << "\t\t|\tTempat Lahir : " << ktp[x].tempat << endl;
        cout << "\t\t|\tTanggal Lahir : " << ktp[x].tanggal << endl;
        cout << "\t\t|\tAlamat : " << ktp[x].almt << endl;
        cout << "\t\t|\tKelurahan : " << ktp[x].alamat.kel << endl;
        cout << "\t\t|\tKecamatan : " << ktp[x].alamat.kec << endl;
        cout << "\t\t|\tKota : " << ktp[x].alamat.kota << endl;
    }

  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
  cout << "\t\t|                                               |"<<endl;
        cout << "\t\t|\t[1] Kembali ke Menu Utama               |"<<endl;
       cout << "\t\t|\t[2] Keluar dari program                 |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
        cout << "\n\tMasukan Pilihan Anda : "; cin >> pilih;
       cout << endl;
      if(pilih == 1) {
       goto menuutama;
      }
    else if(pilih == 2) {
       goto keluar;
    } 
     keluar:
      system("cls");
      head();
      cout << "\t\t|                  TERIMA KASIH                 |" << endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
      getch();
      return 0;
  }
    else if(menu == 0 ){
   system("cls");
  int i, e;
  char a[20];
    e = antrian.base[antrian.depan];
    for (i=0; i<20; i++) {
   a[i] = nama.base1[nama.depan][i];
    }
  for (i=antrian.depan; i<antrian.belakang; i++) {
   antrian.base[i] = antrian.base[i+1];
      for (j=0; j<20; j++) {
       nama.base1[i][j] = nama.base1[i+1][j];
      }
    }
    antrian.belakang--;
    nama.belakang--;
   printf ("\t\t|\t[1] Priority Dengan no %i               |",e);
   printf ("\n\t\t|\t    Dengan Nama %s                      ",a);
       cout << "\n\t\t|\t[2] Tidak Priority                      |"<<endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
        cout << "\n\tMasukan Pilihan Anda : "; cin >> prio;
   if(prio == 1) {
       printf ("\t\tNo %i tersebut Priorty\n",e);
       system("pause");
       goto menuutama;
      }
    else if(prio == 2) {
       cout << " NIK tersebut Tidak Priorty"<<endl;
       system("pause");
       goto quit;
    }
     }
       else if(menu == 8) {
    system("cls");
      head();
      quit:
      cout << "\t\t|                  TERIMA KASIH                 |" << endl;
  cout << "\t\t|                                               |"<<endl;
  cout << "\t\t|===============================================|"<<endl;
      getch();
      return 0;
  }
}

