/* Deskripsi	:  Fungsi Primitif*/
#include "array.h"
#include <stdio.h>



/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T){
	((*T).Neff=0);
}
	
/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
	/* Mengirimkan banyaknya elemen efektif tabel */
	/* Mengirimkan nol jika tabel kosong */
	return (T.Neff);
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
	/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	return (IdxMax);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen pertama */
	return (IdxMin);
}
	
IdxType GetLastIdx (TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen terakhir */
	return (T.Neff);
}
	
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i){
	/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
	/* Mengirimkan elemen tabel yang ke-i */
	return (T.TI[i]);
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout){
	/* I.S. Tin terdefinisi, sembarang */
	/* F.S. Tout berisi salinan Tin */
	/* Assignment THsl -> Tin */
	/** Kamus */
	int i;
	for (i = IdxMin; i <= Tin.Neff; i++){
		(*Tout).TI[i] = Tin.TI[i];
	}
}
	
void SetEl (TabInt *T, IdxType i, ElType v){
	/* I.S. T terdefinisi, sembarang */
	/* F.S. Elemen T yang ke-i bernilai v */
	/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
	(*T).TI[i] = v;
}
void SetNeff (TabInt *T, IdxType N){
	/* I.S. T terdefinisi, sembarang */
	/* F.S. Nilai indeks efektif T bernilai N */
	/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
	(*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
	/* Prekondisi : i sembarang */
	/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
	/* yaitu antara indeks yang terdefinisi utk container*/
	if ((i >= IdxMin) && (i <= T.Neff)){
		return true;
	}
	else{
		return false;
	}
}
	
boolean IsIdxEff (TabInt T, IdxType i){
	/* Prekondisi : i sembarang*/
	/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
	/* yaitu antara FirstIdx(T)..LastIdx(T) */
	if ((i >= IdxMin) && (i <= IdxMax)){
		return true;
	}
	else{
		return false;
	}
}	

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
	/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	/* *** Test tabel penuh *** */
	if (T.Neff == 0){
		return true;
	}
	else{
		return false;
	}
}
		
boolean IsFull (TabInt T){
	/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	if (T.Neff == IdxMax){
		return true;
	}
	else{
		return false;
	}
}