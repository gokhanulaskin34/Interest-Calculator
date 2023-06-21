#include <stdio.h>
#include <math.h>

void vakit(int ay) {
    int yil = ay / 12;
    ay = ay % 12;
    printf("yil: %d, ay: %d\n", yil, ay);
}

void para_miktar(float para) {
    printf("%.1f $\n", para);
}

void bilgi_giris(float kredi_tutari, float int_rate, int ay) {
    printf("Kredi tutari: ");
    para_miktar(kredi_tutari);
    printf("Faiz orani: %.2f\n", int_rate);
    printf("Sure: ");
    vakit(ay);

    // Aylık ödemeyi hesapla
    float aylik_odeme = (kredi_tutari * int_rate) / (1 - pow(1 + int_rate, -ay));

    // Toplam ödemeyi hesapla
    float toplam_odeme = aylik_odeme * ay;

    printf("Aylik odeme: ");
    para_miktar(aylik_odeme);
    printf("Toplam odeme: ");
    para_miktar(toplam_odeme);
    printf("\n");
}

void rapor(float kredi_tutari, float int_rate, int maks_yil, int maks_ay, int yineleme) {
    printf("----- Rapor -----\n");
    for (int i = 0; i <= maks_yil * 12 + maks_ay; i += yineleme) {
        printf("Giris %d:\n", i / yineleme + 1);
        bilgi_giris(kredi_tutari, int_rate, i);
    }
}

int main() {
    char kullaniciAdi[50];
    float yillikFaizOrani, aylikFaizOrani, krediMiktari;
    int maksYil, maksAy, iterasyonAraligi;

    // Kullanıcıdan adı giriş al
    printf("Adinizi girin: ");
    scanf("%s", kullaniciAdi);

    // Kullanıcıdan girişleri al
    printf("Yillik faiz oranini girin: ");
    scanf("%f", &yillikFaizOrani);

    printf("Kredi miktarini girin: ");
    scanf("%f", &krediMiktari);

    printf("Maksimum yil: ");
    scanf("%d", &maksYil);

    printf("Maksimum ay: ");
    scanf("%d", &maksAy);

    printf("Iterasyon araligi (ay): ");
    scanf("%d", &iterasyonAraligi);

    // Aylık faiz oranını hesapla
    aylikFaizOrani = yillikFaizOrani / 12.0;

    // Raporu yazdır
    printf("\nKullanici Adi: %s\n", kullaniciAdi);
    rapor(krediMiktari, yillikFaizOrani, maksYil, maksAy, iterasyonAraligi);

    return 0;
}
