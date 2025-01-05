#include <stdio.h>
#include <stdlib.h>
//al�sveris uygulamasi yapt�m giyim al�m�nda yan urunler indirimli 
//eger sali g�n� ise yan urunler hediye edilecek.gun icinde max 100 musteri.
//musteri say�s�n� d�ng� icinde kulland�m.uygun beden secimi icin fonksiyona dahil edip beden hesaplamas�n� yapt�rd�m.
//renk secimi icin switch case kulland�m.
//gun sonunda toplam musteri say�s�,toplam kazanci yazd�ran projemde kullan�c� verilerini dosyaya yazd�rmas�n� sa�lad�m.
// dosyalama kullanarak.dizileri katagoriler k�sm�nda kulland�m.
//karakter dizini karsilama metninde kulland�m.
// VKI hesaplama fonksiyonu
float hesapla_VKI(float boy, float kilo) {
    return kilo / (boy * boy);
}

int main() {
    int katagori, alt_katagori, renk, kemer, gun,saat;
    float boy, kilo, VKI;
    int kullanici_adi;
    int max_musteri = 100; // Maksimum m��teri say�s�
    int musteri_sayisi = 0; // �u anki m��teri say�s�
    float toplam_kazanc = 0; // G�nl�k toplam kazan�

    // Dosya a�ma
    FILE* dosya;
    dosya = fopen("kullaniciverileri.txt", "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }
    //karsilama metni
    char karsilama_metni[100]="MAGZAMIZA HOSGELD�N�Z";
    char karsilama_metni2[5];
    char karsilama_metni3[75]=" Patron cildirdi! sali g�nleri yapacak oldugunuz alisverislerde yan urun hediyemiz!";

    printf("%d\n",strcat(karsilama_metni,karsilama_metni3));

    // Diziler ile kategoriler ve alt kategoriler
    const char* ust_giyim[] = {"Bluz", "Kazak", "Ti��rt", "G�mlek"};
    const char* alt_giyim[] = {"Etek", "Pantolon", "�ort"};

    // Al��veri� d�ng�s�
    while (musteri_sayisi < max_musteri) {
        musteri_sayisi++;

        // Kullan�c� giri�i
        printf("L�tfen kullanici adinizi giriniz: ");
        scanf("%d", &kullanici_adi);
        printf("Ho�geldiniz %d\n", kullanici_adi);

        // Kategori se�imi
        printf("Almak istedi�iniz �r�n�n kategorisini se�iniz:\n");
        printf("1. �st Giyim (50 TL)\n");
        printf("2. Alt Giyim (70 TL)\n");
        scanf("%d", &katagori);

        if (katagori == 1) {
            // Alt kategori se�imi (�st Giyim)
            printf("L�tfen alt kategori se�imi yapiniz:\n");
            for (int i = 0; i < 4; i++) {
                printf("%d. %s\n", i + 1, ust_giyim[i]);
            }
            scanf("%d", &alt_katagori);

            if (alt_katagori >= 1 && alt_katagori <= 4) {
                printf("%s secimi yapiniz.\n", ust_giyim[alt_katagori - 1]);
                toplam_kazanc += 50; // Fiyat ekleme
                fprintf(dosya, "Kullanici: %d, Kategori: �st Giyim, �r�n: %s, Fiyat: 50 TL\n", 
                        kullanici_adi, ust_giyim[alt_katagori - 1]);
            } else {
                printf("Ge�ersiz se�im.\n");
                continue;
            }

            // Saat promosyonu
            printf("�ndirimli saat almak ister misiniz? (1: Evet, 0: Hay�r): ");
            scanf("%d", &kemer);
            if (kemer == 1) {
                printf("Saat aldini! Y�zde 50 indirim uygulanacak.\n");
                toplam_kazanc += 10; // �ndirimli fiyat
                fprintf(dosya, "Kullanici: %d, Promosyon: Saat, Fiyat: 10 TL\n", kullanici_adi);
            }
        } else if (katagori == 2) {
            // Alt kategori se�imi (Alt Giyim)
            printf("L�tfen alt kategori se�imi yapiniz:\n");
            for (int i = 0; i < 3; i++) {
                printf("%d. %s\n", i + 1, alt_giyim[i]);
            }
            scanf("%d", &alt_katagori);

            if (alt_katagori >= 1 && alt_katagori <= 3) {
                printf("%s se�imi yaptiniz.\n", alt_giyim[alt_katagori - 1]);
                toplam_kazanc += 70; // Fiyat ekleme
                fprintf(dosya, "Kullanici: %d, Kategori: Alt Giyim, �r�n: %s, Fiyat: 70 TL\n", 
                        kullanici_adi, alt_giyim[alt_katagori - 1]);
            } else {
                printf("Ge�ersiz se�im.\n");
                continue;
            }

            // Kemer promosyonu
            printf("�ndirimli kemer almak ister misiniz? (1: Evet, 0: Hay�r): ");
            scanf("%d", &kemer);
            if (kemer == 1) {
                printf("Kemer aldiniz! Y�zde 50 indirim uygulanacak.\n");
                toplam_kazanc += 10; // �ndirimli fiyat
                fprintf(dosya, "Kullanici: %d, Promosyon: Kemer, Fiyat: 10 TL\n", kullanici_adi);
            }

            // Promosyon �r�n� indirimi kontrol� 
     
     
    if (kemer==1 || saat==1) { 
        // Saat veya kemer promosyon se�imi 
        
            printf("Bug�n g�nlerden nedir? (1: Pazartesi, 2: Sali, ...)\n"); 
            scanf("%d", &gun); 
            if (gun == 2) { // 2 Sal�y� temsil ediyor 
                printf("Bug�n sali! Promosyon urunu hediyeniz olarak verilmektedir.\n"); 
                toplam_kazanc-=10;
                fprintf(dosya,"Kullanici: %d,Promosyon urunu hediye olarak verildi.",kullanici_adi);
            } else { 
                printf("Sali g�nleri magzamizda uygulanan promosyonlar hediye kampanyasindan yararlanmayi unutmayin.\n"); 
            } 
        
             
           
 
    // Renk se�imi 
    printf("Urun icin renk seciniz:\n");
printf("1. Kirmizi\n2. Sari\n3. Mavi\n4. Yesil\n");
scanf("%d", &renk);

switch(renk) {
    case 1:
        printf("Urununuz icin kirmizi rengini sectiniz.\n");
        break;
    case 2:
        printf("Urununuz icin sari rengini sectiniz.\n");
        break;
    case 3:
        printf("Urununuz icin mavi rengini sectiniz.\n");
        break;
    case 4:
        printf("Urununuz icin yesil rengini sectiniz.\n");
        break;
    default:
        printf("Bu renk mevcut degil.\n");
        break;
    } }
    else {
            printf("Ge�ersiz kategori.\n");
            continue;
        }

        // Boy ve kilo giri�i
        printf("Boyunuzu giriniz (metre cinsinden): ");
        scanf("%f", &boy);
        printf("Kilonuzu giriniz (kg): ");
        scanf("%f", &kilo);

        // VKI hesaplama
        VKI = hesapla_VKI(boy, kilo);
        printf("VKI: %.2f\n", VKI);

        // Beden �nerisi
        if (VKI >= 15 && VKI < 19) {
            printf("S bedeni uygun.\n");
        } else if (VKI >= 19 && VKI < 23) {
            printf("M bedeni uygun.\n");
        } else if (VKI >= 23 && VKI < 27) {
            printf("L bedeni uygun.\n");
        } else if (VKI >= 27 && VKI < 31) {
            printf("XL bedeni uygun.\n");
        } else {
            printf("Size uygun beden mevcut de�il.\n");
        }

        // Al��veri�e devam etme se�imi
        printf("Alisveri�e devam etmek istiyor musunuz? (1: Evet, 0: Hay�r): ");
        int devam;
        scanf("%d", &devam);
        if (devam == 0) {
            printf("Alisveri� i�in te�ekk�r ederiz.\n");
            break;
        }
    }

    if (musteri_sayisi >= max_musteri) {
        printf("G�nl�k maksimum m��teri sayisina ulasildi.\n");
    }

    // G�n sonu toplam kazan� ve m��teri say�s�
    printf("\nG�n sonu raporu:\n");
    printf("Toplam m��teri sayisi: %d\n", musteri_sayisi);
    printf("Toplam kazan�: %.2f TL\n", toplam_kazanc);

    // Dosya kapama
    fclose(dosya);

    return 0;
} }
  

}
