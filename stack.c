#include "boolean.h"
#include "stackt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateStackEmpty (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStackt */
/* jadi indeksnya antara 1.. MaxElStackt+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
	Top(*S) = NilS;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	return (Top(S) == NilS);
}

boolean IsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return (Top(S) == MaxElStackt);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, KataS X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	Top(*S)++;
	strcpy(InfoTop(*S), X);
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, KataS X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	strcpy(X, InfoTop(*S));
	Top(*S)--;
}