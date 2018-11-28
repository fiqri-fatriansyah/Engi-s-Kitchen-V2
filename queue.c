/* Nama/NIM : Resha Puspita D/18217014 */
/* Nama file : queue.c */
/* Implementasi queue.h */

#include "queue.h"

/* *** Predikat Pemeriksaan Kondisi Queue *** */
boolean IsEmpty(Queue Q){
/* Mengirim true jika Q kosong */
    return (Head(Q)==Nil && Tail(Q)==Nil);
}

boolean IsFull(Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung
MaxEl elemen */
    return (Tail(Q)==MaxEl(Q));
}

int NBElmt(Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q)) {
        return 0;
    } else {
        return Tail(Q);
    }
}

/* *** Konstruktor *** */
void CreateEmpty(Queue *Q,int Max){
/* I.S. Max terdefinisi }
   F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
   Jika alokasi berhasil, tabel memori dialokasi berukuran Max
   atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
   Proses : Melakukan alokasi memori dan membuat sebuah Q kosong */
   (*Q).T = (infotype *) malloc ((Max+1) * sizeof (infotype));
   if ((*Q).T == NULL) {
       MaxEl(*Q)=0;
   } else {
       MaxEl(*Q)=Max;
       Head(*Q)=Nil;
       Tail(*Q)=Nil;
   }
}

/* *** Destruktor *** */
void DeAlokasi(Queue *Q){
/* Proses : Mengembalikan memori Q
   I.S. Q pernah dialokasi
   F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    free((*Q).T);
    MaxEl(*Q)=0;
}

/* *** Operator-Operator Dasar Queue *** */
void Add(Queue *Q,infotype X){
/* Proses : Menambahkan X pada Q dengan aturan FIFO
   I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
   F.S. X menjadi TAIL yang baru, TAIL "maju" */
    if (IsEmpty(*Q)) {
        Head(*Q)=1;
        Tail(*Q)=1;
    } else {
        Tail(*Q)++;
    }
    InfoTail(*Q)=X;
}

void Del(Queue *Q,infotype *X){
/* Proses: Menghapus elemen pertama pada Q dengan aturan FIFO
   I.S. Q tidak kosong
   F.S. X = nilai elemen HEAD pada I.S.,
        Jika Queue masih isi : HEAD diset tetap = 1, elemen-elemen setelah
        HEAD yang lama digeser ke "kiri", TAIL = TAIL � 1;
        Jika Queue menjadi kosong, HEAD = TAIL = Nil. */
/* Kamus lokal */
    int i;

/* Algoritma */
    *X=InfoHead(*Q);
    if (Head(*Q)==Tail(*Q)) {
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
    } else {
        for (i=Head(*Q);i<Tail(*Q);i++) {
            (*Q).T[i]=(*Q).T[i+1];
        }
        Tail(*Q)--;
    }
}