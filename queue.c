#include "queue.h"
#include "boolean.h"
#include "variabel.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsQueueEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsQueueFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQueue */
{
	return (((Head(Q) - Tail(Q)) == 1) || (Tail(Q) == MaxElQueue(Q) && Head(Q) == 1));
}

int NBElmtQueue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if (IsQueueEmpty(Q)) {
		return 0;
	}
	else{
		if (Tail(Q) - Head(Q) + 1 <= 0) {
			return(Tail(Q) - Head(Q) + 1 + MaxElQueue(Q));
		} 
		else {
			return(Tail(Q) - Head(Q) + 1);
		}
	}
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotypeCust *) malloc ((Max+1) * sizeof(infotypeCust)); 
	if ((*Q).T != NULL) {
		MaxElQueue(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else {
		MaxElQueue(*Q) = 0;
	}
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQueue(Q) diset 0 */
{	/* Kamus Lokal */
	/* Algoritma */
	MaxElQueue(*Q) = 0;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotypeCust X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
	/* Kamus Lokal */
	/* Algoritma */
	if (IsQueueEmpty(*Q)) {
		Head(*Q) = 1;
		Tail(*Q)++;
	} 
	else {
		if (Tail(*Q) == MaxElQueue(*Q)) { 
			Tail(*Q) = 1;
		} 
		else {
			Tail(*Q)++;
		}
	}
	InfoTail(*Q)=X;
}

void Del (Queue * Q, infotypeCust * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
	/* Kamus Lokal */
	/* Algoritma */
	*X = InfoHead(*Q);
	if (Head(*Q) == Tail(*Q)) { 
		Head(*Q) = Nil; 
		Tail(*Q) = Nil; 
	}
	else if (Head(*Q) == MaxElQueue(*Q)) {
		Head(*Q) = 1;
	}
	else {
		Head(*Q)++;
	}
}