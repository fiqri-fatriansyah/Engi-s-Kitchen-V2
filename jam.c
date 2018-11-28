/* ************************************************ */
/*              DEFINISI PRIMITIF                   */
/* ************************************************ */
/*         KELOMPOK VALIDASI TERHADAP TYPE          */
/* ************************************************ */
#include "jam.h"
#include <stdio.h>

boolean IsJValid (int H,int M, int S){
/* Mengirim true jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    return (((H>=0)&&(H<=23)) && ((M>=0)&&(M<=59)) && ((S>=0)&&(S<=59)));
}

/* Konstruktor : Membentuk sebuah JAM dari komponen-komponennya */
JAM MakeJam (int HH, int MM, int SS){
/* Membentuk sebuah JAM dari komponen-komponen yang valid */
/* Pre cond : HH,MM,SS valid untuk membentuk JAM */

/* Kamus lokal */
    JAM J;

/* Algoritma */
    Hour(J)=HH;
    Minute(J)=MM;
    Second(J)=SS;

    return J;
}

/** Operasi terhadap komponen : selektor Get dan Set **/
/** Selektor **/
int GetHour (JAM J){
/* Mengirimkan bagian HH (Hour) dari JAM */
    return Hour(J);
}

int GetMinute (JAM J){
/* Mengirimkan bagian Menit (MM) dari JAM */
    return Minute(J);
}

int GetSecond (JAM J){
/* Mengirimkan bagian Second (SS) dari JAM */
    return Second(J);
}

/** Pengubah nilai Komponen **/
void SetHour (JAM *J, int newHH){
/* Mengubah nilai komponen HH dari J */ 
    Hour(*J)=newHH;
}

void SetMinute (JAM *J, int newMM){
/* Mengubah nilai komponen MM dari J */
    Minute(*J)=newMM;
}

void SetSecond (JAM *J, int newSS){
/* Mengubah nilai komponen SS dari J */
    Second(*J)=newSS;
}

/****************************************************/
/*          KELOMPOK BACA/TULIS                     */
/****************************************************/
void BacaJam (JAM *J){
/* I.S : J tidak terdefinisi */
/* F.S : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH,MM,SS sehingga
            membentuk J yang valid. Tidak mungkin menghasilkan
            J yang tidak valid. */
/* Kamus lokal */
    int H,M,S;
    do {
        scanf("%d %d %d",&H,&M,&S);
        if (IsJValid(H,M,S)) {
            (*J)=MakeJam(H,M,S);
        }
    }
    while (!(IsJValid(H,M,S)));
}
/****************************************************/
void TulisJam (JAM J){
/* I.S : J sembarang */
/* F.S : Nilai J ditulis dengan format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar */
    printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}

/****************************************************/
/*          KELOMPOK KONVERSI TERHADAP TYPE         */
/****************************************************/
long JamToDetik (JAM J){
/* Diberikan sebuah JAM, mengkonversi menjadi detik */
/* Rumus : detik = 3600*hour*menit*60 + detik */
/* nilai maksimum = 3600*23+59*60+59*60 */
/* hati-hati dengan representasi integer pada bahasa implementasi */
/* kebanyakan sistem mengimplementasi integer, bernilai maksimum
   kurang dari nilai maksimum hasil konversi */

/* Kamus lokal */
    long detik = 3600*Hour(J)+60*Minute(J)+60*Second(J);
    
    return detik;
}
/****************************************************/
JAM DetikToJam (long N){
/* Mengirim konversi detik ke JAM */
/* pada beberapa bahasa, representasi integer tidak cukup untuk */
/* menampung N */

/* Kamus lokal */
    int Jam = N/3600;
    int Menit = (N%3600)/60;
    int Detik = N%60;

/* Algoritma */
    return MakeJam(Jam,Menit,Detik); 
}
/****************************************************/
/*          KELOMPOK OPERASI TERHADAP TYPE          */
/****************************************************/
/**     Kelompok Operator Relational                */
boolean JEQ(JAM J1, JAM J2){
/* Mengirimkan true jika J1=J2, false jika tidak */
    return ((Hour(J1)==Hour(J2)) && (Minute(J1)==Minute(J2)) && (Second(J1)==Second(J2)));
}

boolean JNEQ(JAM J1, JAM J2){
/* Mengirimkan true jika J1 tidak sama dengan J2 */
    return (!JEQ(J1,J2));
}

boolean JLT(JAM J1, JAM J2){
/* Mengirimkan true jika J1<J2, false jika tidak */
    return (JamToDetik(J1)<JamToDetik(J2));
}

boolean JGT(JAM J1, JAM J2){
/* Mengirimkan true jika J1>J2, false jika tidak */
    return (JamToDetik(J1)>JamToDetik(J2));
}

/************** Operator aritmatika JAM *************/
JAM JPlus (JAM J1, JAM J2){
/* Menghasilkan J1+J2, dalam bentuk JAM */
    return DetikToJam(JamToDetik(J1)+JamToDetik(J2));
}

JAM JMinus (JAM J1, JAM J2){
/* Menghasilkan J1-J2, dalam bentuk JAM */
/* Precond : J1>=J2 */
    return DetikToJam(JamToDetik(J1)+JamToDetik(J2));
}

JAM NextDetik (JAM J){
/* Mengirim 1 detik setelah J dalam bentuk JAM */
    return DetikToJam(JamToDetik(J)+1);
}

JAM NextNDetik (JAM J, int N){
/* Mengirim N detik setelah J dalam bentuk JAM */
    return DetikToJam(JamToDetik(J)+N);
}

JAM PrevDetik (JAM J){
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
    return DetikToJam(JamToDetik(J)-1);
}

JAM PrevNDetik (JAM J, int N){
/* Mengirim N detik sebelum J dalam bentuk JAM */
    return DetikToJam(JamToDetik(J)-N);
}

/** Kelompok Operator Aritmatika **/
long Durasi (JAM Jaw, JAM Jakh){
/* Mengirim JAkh-Jaw dalam detik, dengan kalkulasi */
/* Hasilnya negatif jika Jaw>JAkhir */
    return(JamToDetik(Jakh)-JamToDetik(Jaw));
}