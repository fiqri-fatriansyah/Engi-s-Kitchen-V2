/* Nama File : mesinkar.c */
/* Nama/NIM : Resha Puspita Dewi/18217014 */
/* Pra Praktikum 2 */

#include "mesinkar.h"

/* definisi states */
char CC;
boolean EOP;

/* definisi pita */
static char x; //variable penyimpan reading
static FILE *pita; //variable penampung file

void START(char* filename){
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita

Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */
    pita = fopen (filename,"r");
    ADV();
}

void ADV(){
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,

CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */
    x = fscanf(pita,"%c",&CC);
    if (IsEOP()) {
        fclose(pita);
    }
}

char GetCC(){
/* Mengembalikan karakter yang sedang terbaca di jendela.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : mengembalikan karakter yang sedang terbaca di jendela
*/
    return CC;
}

boolean IsEOP(){
/* Mengecek apakah pita telah selesai dibaca
I.S. : Pita telah terbaca
F.S. : Menegmbalikan true jika pita telah selesai terbaca, false jika sebaliknya
*/
    return (CC==MARK);
}