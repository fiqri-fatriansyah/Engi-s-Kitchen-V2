#ifndef VARIABEL_H
#define VARIABEL_H

#include "boolean.h"

//**********************PROGRAM UTAMA**********************//
Queue Antrian;
typedef struct {
    int RuangPlayer;      // posisi ruang player
    int Money;
    int Life;
    int Time;
    Stack FoodStack;        // stack makanan yg ada di tray
    Stack SBahanMentah;     // stack bahan mentah
    POINT PosisiPlayer;
    KataS Name;
} Player;

typedef struct {
    KataS Order;
    boolean isGone;
    int TickCust;
    int TickCustQ;
} Customer;

#define Ruang(P) (P).Ruang
#define Money(P) (P).Money
#define Life(P) (P).Life
#define Time(P) (P).Time
#define SMakanan(P) (P).SMakanan
#define SBahanMentah(P) (P).SBahanMentah
#define Titik(P) (P).Titik

//**********************POINT**********************//
typedef struct {
  int X;        // absis
  int Y;        // ordinat
} POINT;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y

//**********************JAM**********************//
typedef struct { 
  int HH; /* integer [0..23] */
  int MM; /* integer [0..59] */
  int SS; /* integer [0..59] */
} JAM;

#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS

//**********************MATRIKS**********************//
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */
// typedef int ElType; 
typedef struct { 
    char mat[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define MatriksElmt(M,i,j) (M).mat[(i)][(j)]

//**********************ARRAY**********************//
#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999

typedef char TabKata[10];
typedef int IdxType;
typedef TabKata ElTypeArray;
typedef struct {
    ElTypeArray TI[100+1];
    int Neff;
} TabInt;

#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define ElmtArray(T,i) (T).TI[(i)]

//**********************STACK**********************//
typedef char KataS[30];
typedef int addressStack;
typedef struct {
    KataS TI[IdxMax+1];
    addressStack Top;
} Stack;

#define MaxElStack 10
#define Nil 0
#define IdxMax10
#define Top(S) (S).Top
#define InfoTop(S) (S).TI[(S).Top]

//**********************QUEUE**********************//
typedef Customer infotypeCust;
typedef int addressQ;  
typedef struct {
    infotypeCust * T;  
    addressQ HEAD; 
    addressQ TAIL; 
    int MaxElQueue;  
} Queue;

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElQueue(Q) (Q).MaxElQueue

//**********************MESIN KATA**********************//
#define NMax 100
#define BLANK ' '

typedef struct {
    char TabKata[NMax+1];  //container penyimpan kata, indeks yang dipakai [1..NMax] 
    int Length;
} Kata;

extern boolean EndKata;
extern Kata CKata;

#endif