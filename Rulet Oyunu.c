#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int i, rulet, bakiye, bahis, tahmin, bahisMiktar, karar, esitlik;
    //int sayilar[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
    int red[] = { 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 };
    int black[] = { 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };
    //int green[] = { 0 };
    int tek[] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35 };
    int cift[] = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36 };
    int yariIlk[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
    int yariSon[] = { 19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
    printf("    Rulet Nasil Oynanir:\n-Rulette birden fazla bahis secenegi vardir. \nRulette; \n-Tek rakamlara (odd), \n-Cift rakamlara (even), \n-Renklere, \n-1 ile 18 arasina, \n-19 ile 36 arasina bahis oynanabilir. \n-Bu sekilde oynanan bahis miktarinin 2 misli kazanilir. \n-Eger oyuncu direkt olarak bir sayiya oynarsa ve top o sayida durursa oyuncu bahis miktarinin 36 katini kazanir.\nNot: Normal rulete gore kisaltilmistir.\n\n");
    srand(time(NULL));
devam0:
    printf("Kac $ bakiye istiyorsunuz?\n");
    scanf_s("%d", &bakiye);
devam1:
    do {
        printf("Bahis yonteminizi secin:\n(0) = Sayi Tahmini Ile Bahis Yapmak Icin \n(1) = Kirmiziya Bahis Yapmak Icin\n(2) = Siyaha Bahis Yapmak Icin\n(3) = Tek Sayilara (odd) Bahis Yapmak Icin\n(4) = Cift Sayilara Bahis Yapmak Icin\n(5) = 1 Ile 18 Arasina Bahis Yapmak Icin\n(6) = 19 Ile 36 Arasina Bahis Yapmak Icin\n");
        scanf_s("%d", &bahis);
        if (bahis < 0 || bahis>6) {
            printf("Gecersiz Bahis Yontemi Sectiniz, Lutfen Tekrar Deneyin.\n");
        }
    } while (bahis < 0 || bahis>6);
    do {
        printf("Kac $ bahis yapmak istiyorsunuz?\n");
        scanf_s("%d", &bahisMiktar);
        if (bahisMiktar > bakiye) {
            printf("Bakiyenizden fazlasini bahis yapamazsiniz. Lutfen daha kucuk miktarda bahis yapin.\n");
        }
    } while (bahisMiktar > bakiye);
    bakiye = bakiye - bahisMiktar;
    rulet = rand() % 36;
    switch (bahis) {
    case 0:
        printf("0 ile 36 arasindan bahis yapmak istediginiz sayiyi secin:\n");
        scanf_s("%d", &tahmin);
        if (tahmin == rulet) {
            bakiye = bakiye + 36 * bahisMiktar;
            printf("Ruletten Cikan Sayi = %d.\nTebrikler, ruleti dogru tahmin ettiniz. %d$ kazandiniz. Yeni bakiyeniz %d$.\n", rulet, 36 * bahisMiktar, bakiye);
        }
        else {
            printf("Ruletten Cikan Sayi = %d.\nMaalesef, ruleti yanlis tahmin ettiniz. Kalan bakiyeniz %d$.\n", rulet, bakiye);
        }
        if (bakiye > 0) {
            printf("Su anki bakiyenizle (%d$) devam etmek icin '1'e, yeniden bakiye belirlemek icin '0'a basin.\n", bakiye);
            scanf_s("%d", &karar);
            if (karar == 1) {
                goto devam1;
            }
            else {
                goto devam0;
            }
        }
        else {
            printf("Bakiyeniz 0$ oldugu icin oyununuz sonlanmistir. Otomatik olarak basa dondurluyorsunuz.\n");
            //sleep(4);
            goto devam0;
        }
    case 1:
        esitlik = 0;
        for (i = 0; i <= 17; i++) {
            if (rulet == red[i]) {
                esitlik = 1;
                bakiye = bakiye + 2 * bahisMiktar;
                printf("Ruletten Cikan Sayi = %d (kirmizi).\nTebrikler, ruletten cikan sayinin rengini dogru tahmin ettiniz. %d$ kazandiniz. Yeni bakiyeniz %d$.\n", rulet, 2 * bahisMiktar, bakiye);
            }
        }
        if (esitlik == 0) {
            printf("Ruletten Cikan Sayi = %d. (siyah).\nMaalesef, ruletten cikan sayinin rengini yanlis tahmin ettiniz. Kalan bakiyeniz %d$.\n", rulet, bakiye);
        }
        if (bakiye > 0) {
            printf("Su anki bakiyenizle (%d$) devam etmek icin '1'e, yeniden bakiye belirlemek icin '0'a basin.\n", bakiye);
            scanf_s("%d", &karar);
            if (karar == 1) {
                goto devam1;
            }
            else {
                goto devam0;
            }
        }
        else {
            printf("Bakiyeniz 0$ oldugu icin oyununuz sonlanmistir. Otomatik olarak basa dondurluyorsunuz.\n");
            //sleep(4);
            goto devam0;
        }
    case 2:
        esitlik = 0;
        for (i = 0; i <= 17; i++) {
            if (rulet == black[i]) {
                esitlik = 1;
                bakiye = bakiye + 2 * bahisMiktar;
                printf("Ruletten Cikan Sayi = %d (siyah).\nTebrikler, ruletten cikan sayinin rengini dogru tahmin ettiniz. %d$ kazandiniz. Yeni bakiyeniz %d$.\n", rulet, 2 * bahisMiktar, bakiye);
            }
        }
        if (esitlik == 0) {
            printf("Ruletten Cikan Sayi = %d. (kirmizi).\nMaalesef, ruletten cikan sayinin rengini yanlis tahmin ettiniz. Kalan bakiyeniz %d$.\n", rulet, bakiye);
        }
        if (bakiye > 0) {
            printf("Su anki bakiyenizle (%d$) devam etmek icin '1'e, yeniden bakiye belirlemek icin '0'a basin.\n", bakiye);
            scanf_s("%d", &karar);
            if (karar == 1) {
                goto devam1;
            }
            else {
                goto devam0;
            }
        }
        else {
            printf("Bakiyeniz 0$ oldugu icin oyununuz sonlanmistir. Otomatik olarak basa dondurluyorsunuz.\n");
            //sleep(4);
            goto devam0;
        }
    case 3:
        esitlik = 0;
        for (i = 0; i <= 17; i++) {
            if (rulet == tek[i]) {
                esitlik = 1;
                bakiye = bakiye + 2 * bahisMiktar;
                printf("Ruletten Cikan Sayi = %d.\nTebrikler, ruletten cikan sayi tek sayi dogru tahmin ettiniz. %d$ kazandiniz. Yeni bakiyeniz %d$.\n", rulet, 2 * bahisMiktar, bakiye);
            }
        }
        if (esitlik == 0) {
            printf("Ruletten Cikan Sayi = %d.\nMaalesef, ruletten cikan sayi cift sayi yanlis tahmin ettiniz. Kalan bakiyeniz %d$.\n", rulet, bakiye);
        }
        if (bakiye > 0) {
            printf("Su anki bakiyenizle (%d$) devam etmek icin '1'e, yeniden bakiye belirlemek icin '0'a basin.\n", bakiye);
            scanf_s("%d", &karar);
            if (karar == 1) {
                goto devam1;
            }
            else {
                goto devam0;
            }
        }
        else {
            printf("Bakiyeniz 0$ oldugu icin oyununuz sonlanmistir. Otomatik olarak basa dondurluyorsunuz.\n");
            //sleep(4);
            goto devam0;
        }
    case 4:
        esitlik = 0;
        for (i = 0; i <= 17; i++) {
            if (rulet == cift[i]) {
                esitlik = 1;
                bakiye = bakiye + 2 * bahisMiktar;
                printf("Ruletten Cikan Sayi = %d.\nTebrikler, ruletten cikan sayi cift sayi dogru tahmin ettiniz. %d$ kazandiniz. Yeni bakiyeniz %d$.\n", rulet, 2 * bahisMiktar, bakiye);
            }
        }
        if (esitlik == 0) {
            printf("Ruletten Cikan Sayi = %d.\nMaalesef, ruletten cikan sayi tek sayi yanlis tahmin ettiniz. Kalan bakiyeniz %d$.\n", rulet, bakiye);
        }
        if (bakiye > 0) {
            printf("Su anki bakiyenizle (%d$) devam etmek icin '1'e, yeniden bakiye belirlemek icin '0'a basin.\n", bakiye);
            scanf_s("%d", &karar);
            if (karar == 1) {
                goto devam1;
            }
            else {
                goto devam0;
            }
        }
        else {
            printf("Bakiyeniz 0$ oldugu icin oyununuz sonlanmistir. Otomatik olarak basa dondurluyorsunuz.\n");
            //sleep(4);
            goto devam0;
        }
    case 5:
        esitlik = 0;
        for (i = 0; i <= 17; i++) {
            if (rulet == yariIlk[i]) {
                esitlik = 1;
                bakiye = bakiye + 2 * bahisMiktar;
                printf("Ruletten Cikan Sayi = %d.\nTebrikler, ruletten cikan sayi 1 ile 18 arasinda dogru tahmin ettiniz. %d$ kazandiniz. Yeni bakiyeniz %d$.\n", rulet, 2 * bahisMiktar, bakiye);
            }
        }
        if (esitlik == 0) {
            printf("Ruletten Cikan Sayi = %d.\nMaalesef, ruletten cikan sayi 1 ile 18 arasinda degil yanlis tahmin ettiniz. Kalan bakiyeniz %d$.\n", rulet, bakiye);

        }
        if (bakiye > 0) {
            printf("Su anki bakiyenizle (%d$) devam etmek icin '1'e, yeniden bakiye belirlemek icin '0'a basin.\n", bakiye);
            scanf_s("%d", &karar);
            if (karar == 1) {
                goto devam1;
            }
            else {
                goto devam0;
            }
        }
        else {
            printf("Bakiyeniz 0$ oldugu icin oyununuz sonlanmistir. Otomatik olarak basa dondurluyorsunuz.\n");
            //sleep(4);
            goto devam0;
        }
    case 6:
        esitlik = 0;
        for (i = 0; i <= 17; i++) {
            if (rulet == yariSon[i]) {
                esitlik = 1;
                bakiye = bakiye + 2 * bahisMiktar;
                printf("Ruletten Cikan Sayi = %d.\nTebrikler, ruletten cikan sayi 19 ile 36 arasinda dogru tahmin ettiniz. %d$ kazandiniz. Yeni bakiyeniz %d$.\n", rulet, 2 * bahisMiktar, bakiye);
            }
        }
        if (esitlik == 0) {
            printf("Ruletten Cikan Sayi = %d.\nMaalesef, ruletten cikan sayi 19 ile 36 arasinda degil yanlis tahmin ettiniz. Kalan bakiyeniz %d$.\n", rulet, bakiye);

        }
        if (bakiye > 0) {
            printf("Su anki bakiyenizle (%d$) devam etmek icin '1'e, yeniden bakiye belirlemek icin '0'a basin.\n", bakiye);
            scanf_s("%d", &karar);
            if (karar == 1) {
                goto devam1;
            }
            else {
                goto devam0;
            }
        }
        else {
            printf("Bakiyeniz 0$ oldugu icin oyununuz sonlanmistir. Otomatik olarak basa dondurluyorsunuz.\n");
            //sleep(4);
            goto devam0;
        }
    }
}
