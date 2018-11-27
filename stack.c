/* Nama/NIM : Resha Puspita D/18217014 */
/* Nama file : stack.c */

#include "stack.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
/* I.S. Sembarang
   F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl
   jadi indeksnya antara 1..MaxEl
   Ciri stack kosong : TOP bernilai Nil */
    Top(*S)=Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return Top(S)==Nil;
}
boolean IsFull(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return Top(S)==MaxEl;
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S,infotype X){
/* Menambahkan X sebagai elemen Stack S.
   I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
   F.S. X menjadi TOP yang baru, TOP bertambah 1 */
    Top(*S)+=1;
    InfoTop(*S)=X;
}
void Pop(Stack *S,infotype *X){
/* Menghapus X dari Stack S.
   I.S. S tidak kosong
   F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    (*X)=InfoTop(*S);
    Top(*S)-=1;
}