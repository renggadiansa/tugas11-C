#include <stdio.h>

//1
int ganjil(int);
//2
long faktorial(long bil);
//3
int prima(int bil);
//4
#define PHI 3.14159f
float radian(float);
//5
float konversi(char, float, char);
//1
void ubah(int);
//2
int cekTanggal(int, int, int);

int main() {
    //1
    int bil;
    printf("Fungsi Mengechek Bilangan Genap dan Ganjil\n");
    printf("Masukkan bilangan:");
    scanf("%d",&bil);
    printf("");

    int isGanjil = ganjil(bil);

    if(isGanjil != 0) {
        printf("Bilangan %d adalah bilangan Ganjil\n",bil);
    } else {
        printf("Bilangan %d adalah bilangan Genap\n",bil);
    }


    //2
//    long Sum,bil;
//    printf("Fungsi Menampilkan Jumlah Faktorial\n");
//    printf("Masukkan bilangan:");
//    scanf("%ld",&bil);
//    Sum = faktorial(bil);
//    printf("Jumlah faktorial dari %ld adalah %ld\n",bil,Sum);

    //3
//    int bil, cekPrima;
//    printf("Mengecek Bilangan Prima dengan Fungsi\n");
//    printf("Masukkan bilangan = ");
//    scanf("%d", &bil);
//    cekPrima = prima(bil);
//    if (cekPrima)
//        printf("%d adalah bilangan Prima\n", bil);
//    else
//        printf("%d bukan bilangan Prima\n", bil);

    //4
    float derajad, hslRad;
    printf("Konversi dari besaran sudut Derajat ke Radian\n");
    printf("Tuliskan nilai Derajat =");
    scanf("%f", &derajad);
    hslRad = radian(derajad);
    printf("Hasil konversi RADIAN :%f\n", hslRad);

    //5
    char sumber, tujuan;
    float suhuSumber, suhuTujuan;

    printf("Masukkan suhu sumber = ");
    scanf("%f", &suhuSumber);

    printf("Masukkan satuan asal [C/F/R] = ");
    scanf(" %c", &sumber);

    printf("Masukkan satuan tujuan [C/F/R] = ");
    scanf(" %c", &tujuan);

    suhuTujuan = konversi(sumber, suhuSumber, tujuan);
    printf("%.2f %c = %.2f %c\n\n", suhuSumber, sumber, suhuTujuan, tujuan);

    //1
    int x;
    printf("Masukkan nilai x : ");
    scanf("%d", &x);
    ubah(x);
    printf("x = %d\n", x);

    //2
    int tanggal, bulan, tahun, isValid;

    printf("Masukkan tanggal = ");
    scanf("%d", &tanggal);

    printf("Masukkan bulan = ");
    scanf("%d", &bulan);

    printf("Masukkan tahun = ");
    scanf("%d", &tahun);

    printf("\n");

    isValid = cekTanggal(tanggal, bulan, tahun);
    if (isValid)
        printf("Tanggal tersebut VALID");
    else
        printf("Tanggal tersebut tidak VALID");
    return 0;
}
//1
int ganjil(int checking) {
    return checking % 2;
}
//2
long faktorial(long bil)
{
    int i,sumF = 1;
    for(i=bil;i>0;i--)
    {
        sumF = sumF * i;
    }
    return sumF;
}
//3
int prima(int bil) {
    int bagi, faktor = 0;
    for (bagi = 1; bagi <= bil; bagi++) {
        if (bil % bagi == 0)
            faktor++;
    }
    if (faktor <= 2)
        return 1;
    else
        return 0;
}

//4
float radian(float derajad) {
    return (derajad / 180.0f) * PHI;
}

//5
float konversi(char sumber, float suhuSumber, char tujuan) {
    float pembandingSumber, pembandingTujuan, suhuAwalSumber, suhuAwalTujuan, suhuTujuan;

    switch (sumber) {
        case 'C':
            pembandingSumber = 5;
            suhuAwalSumber = 0;
            break;
        case 'R':
            pembandingSumber = 4;
            suhuAwalSumber = 0;
            break;
        case 'F':
            pembandingSumber = 9;
            suhuAwalSumber = 32;
            break;
    }

    switch (tujuan) {
        case 'C':
            pembandingTujuan = 5;
            suhuAwalTujuan = 0;
            break;
        case 'R':
            pembandingTujuan = 4;
            suhuAwalTujuan = 0;
            break;
        case 'F':
            pembandingTujuan = 9;
            suhuAwalTujuan = 32;
            break;
    }

    suhuTujuan = (pembandingTujuan / pembandingSumber) * (suhuSumber - suhuAwalSumber) + suhuAwalTujuan;
    return suhuTujuan;
}

//1
void ubah(int y) {
    y = 85;
}

//2
int cekTanggal(int d, int m, int y) {
    int jumD, isValid = 0;

    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            jumD = 31;
            break;
        case 4: case 6: case 9: case 11:
            jumD = 30;
            break;
        case 2:
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                jumD = 29;
            else
                jumD = 28;
            break;
        default:
            jumD = 0;
            break;
    }

    if (m >= 1 && m <= 12 && d >= 1 && d <= jumD) {
        isValid = 1;
    }
    return isValid;
}

