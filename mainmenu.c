// mainmenu.c

#include "boolean.h"
#include <stdio.h>

int main() {
// KAMUS
    char Name[10]; //WARN: udah ada di main.c
    boolean input=false;
    int com_menu; //command menu
    void TulisEG(); //End Game
    void TulisSG(); //Start Game

// ALGORITMA
    TulisSG();
    while (input==false) {
        printf("Masukkan pilihan menu : ");
        scanf("%d",&com_menu);
        switch (com_menu) {
            case 1 :printf("Your Name : ");
                    scanf("%10s",&Name);
                    if (Name!=NULL) {
                        printf("Hi %s!\nAfter you create your name, let's play!\n",Name);
                    }
                    break;
            case 2 : if (Name!=NULL){
                    input=true;
                    } else {
                    printf("Don't forget to insert your name!\nChoose 'New Game' to create a name.");
                    }
                    break;
            case 3 : return 0;
            default : printf("Wrong input! Please type number of menu : 1/2/3\n");
                    break;
        }
    }
}

void TulisSG(){
    printf(" | -------------------------------------------------------------------------------------------------------- | \n");
	printf(" |                                           ENGI'S KITCHEN EXPANSION                                       | \n");
	printf(" | -------------------------------------------------------------------------------------------------------- | \n");
	printf("    		            NEW GAME                       START                          EXIT                    \n");
	printf("    	        (Create your name here!)       (Let's play the game!)          (Good to see you!)             \n");
    printf("                          (1)                           (2)                            (3)                    \n");
	printf("    	                                                                                                      \n");
    printf(" | -------------------------------------------------------------------------------------------------------- | \n");
}

void TulisEG () {
    printf(" | --------------------------------------------------------------------------------------------- | \n");
	printf("                                     sampai jumpa lagi :)) !                                       \n");
	printf(" | --------------------------------------------------------------------------------------------- | \n");
	printf("               M. FIQI FATRIANSYAH                                 ALMYRA RAMADHINA                \n");
	printf("                   (16517000)                                         (16517000)                   \n");
	printf("                                                                                                   \n");
	printf("                                                                                                   \n");
    printf("                ADINI SAFIA ZAHRA                                  RESHA PUSPITA D                 \n");
	printf("                   (16517000)                                         (16517000)                   \n");
	printf(" | --------------------------------------------------------------------------------------------- | \n");
}