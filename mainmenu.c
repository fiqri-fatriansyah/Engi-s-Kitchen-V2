// mainmenu.c

#include "boolean.h"
#include <stdio.h>

int main() {
// KAMUS
    int com_menu;
    void TulisEG(); //End Game
    void TulisSG(); //Start Game

// ALGORITMA
    TulisSG();
    printf("Masukkan pilihan menu : ");
    do {
        scanf("%d\n",com_menu);
        switch (com_menu) {
            case 1 : scanf("%s/n",Name);
                    break;
            case 2 : if (Name!=NULL) {
                    //masukin prosedur setup
                    }
                    break;
            case 3 : exit=true;
            default : printf("Pilihan menu salah. Ketikkan angka menu : 1/2/3\n");
                      break; 
        }
    }
    while(!exit);
return 0;
}

TulisSG(){
    printf(" | -------------------------------------------------------------------------------------------------------- | /n");
	printf(" |                                           ENGI S KITCHEN SIMULATION                                      | /n");
	printf(" | -------------------------------------------------------------------------------------------------------- | /n");
	printf("    		         NEW GAME                        START                         EXIT                       /n");
	printf("    	      (Mempersiapkan simulasi)        (Memulai simulasi)      (Keluar dari program simulasi)          /n");
    printf("                        (1)                           (2)                          (3)                        /n");
	printf("    	                                                                                                      /n");
    printf(" | -------------------------------------------------------------------------------------------------------- | /n");
}

TulisEG () {
    printf(" | --------------------------------------------------------------------------------------------- | /n");
	printf("                                     sampai jumpa lagi :)) !                                       /n");
	printf(" | --------------------------------------------------------------------------------------------- | /n");
	printf("               M. FIQI FATRIANSYAH                                 ALMYRA RAMADHINA                /n");
	printf("                   (16517000)                                         (16517000)                   /n");
	printf("                                                                                                   /n");
	printf("                                                                                                   /n");
    printf("               ADINI SAFIRA ZAHRA                             RESHA PUSPITA D                      /n");
	printf("                   (16517000)                                     (16517000)                       /n");
	printf(" | --------------------------------------------------------------------------------------------- | /n");
}