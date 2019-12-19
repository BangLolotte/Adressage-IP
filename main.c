#include <stdio.h>

/**************** variables globales***************/

unsigned ip1, ip2, ip3, ip4;
unsigned mask1, mask2, mask3, mask4;


/************************ proto***********************/
void saisie ();
void classe(int);
void adrsr();
void nummachine();
void nbrmachine();

/*********************fonction saisie*******************/
void saisie() {
    int erreur = 0;

    do {
        erreur = 0;
        printf("Veuillez entrer votre adresse IP\n");
        scanf("%u.%u.%u.%u", &ip1, &ip2, &ip3, &ip4);
        if ( ip1 > 255 || ip2 > 255 || ip3 > 255 || ip4 > 255 || ip1<0 || ip2<0 || ip3<0 || ip4<0 ) {
            printf("Saisie érronée, veuillez recommencer\n");
            erreur++;
        } else {
        }
    }
        while (erreur > 0);
    do {
        erreur = 0;
        printf("Veuillez entrer votre mask de sous réseau\n");
        scanf("%u.%u.%u.%u", &mask1, &mask2, &mask3, &mask4);
        if (mask1 > 255 || mask2 > 255 || mask3 > 255 || mask4 > 255 || mask1<0) {
            printf("Saisie érronée, veuillez recommencer\n");
            erreur++;
        } else {
        }
    }
    while (erreur > 0);
}


/******************************************fonction deter classe*******************************/
void classe(int ip1) {
    if (ip1<127)
        printf("Adresse IP de classe A\n");
    else if (ip1>128 && ip1<192)
        printf("Adresse IP de classe B\n");
    else if (ip1<223 && ip1>191)
        printf("Adresse IP de classe C\n");

}


/******************************* fonction adresse de SR*******************************/
int sr1=0;
int sr2=0;
int sr3=0;
int sr4=0;
void adrsr() {
    sr1=ip1&mask1;
    sr2=ip2&mask2;
    sr3=ip3&mask3;
    sr4=ip4&mask4;
printf("Votre mask de sous réseau est le %i.%i.%i.%i\n", sr1,sr2,sr3,sr4);
}

/********************************** fonction numéro de machine ***********************/
void nummachine() {
    printf("Votre numéro de machine est le %i.%i.%i.%i\n",ip1-sr1,ip2-sr2,ip3-sr3,ip4-sr4);
}
/**************************** nombre de machines possibles dans un SR*********************/
void nbrmachine() {
    int nbmachine = 0;
    nbmachine = 254-sr4;
    printf("Vous avez %i connections possibles dans votre sous réseau\n ", nbmachine);


}


int main() {
    saisie();
    classe(ip1);
    adrsr();
    nummachine();
    return 0;
}