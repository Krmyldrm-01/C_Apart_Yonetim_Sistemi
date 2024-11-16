
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OGRENCI 100

struct Ogrenci
{
  char isim[50];
  char soyIsim[50];
  int id;
  float kiraBorcu;
  float elektrikBorcu;
};

struct Ogrenci ogrenciler[MAX_OGRENCI];

int ogrenci_sayisi = 0;

void ogrenciEkle()
{
  if (ogrenci_sayisi == MAX_OGRENCI)
  {
    printf("Hata: Ogrenci sinirina ulasildi!\n");
    return;
  }
    FILE *dosya = fopen("Ogrenciler.txt","a");
  
  printf("Ogrenci id giriniz: ");
  scanf("%d", &ogrenciler[ogrenci_sayisi].id);
	  fprintf(dosya,"[ID: %d]. ",ogrenciler[ogrenci_sayisi].id);
  printf("Ogrenci ismini giriniz: ");
  scanf("%s", ogrenciler[ogrenci_sayisi].isim);
  	fprintf(dosya,"%s ",ogrenciler[ogrenci_sayisi].isim);
  printf("Ogrenci soyismini giriniz: ");
  scanf("%s", ogrenciler[ogrenci_sayisi].soyIsim);
  	fprintf(dosya,"%s ",ogrenciler[ogrenci_sayisi].soyIsim);
  printf("Ogrenci kira borcunu giriniz: ");
  scanf("%f", &ogrenciler[ogrenci_sayisi].kiraBorcu);
	  fprintf(dosya,"- Kira borcu: %0.2f, ",ogrenciler[ogrenci_sayisi].kiraBorcu);
  printf("Ogrenci elektrik borcunu giriniz: ");
  scanf("%f", &ogrenciler[ogrenci_sayisi].elektrikBorcu);
  	fprintf(dosya,"Elektrik borcu: %0.2f\n",ogrenciler[ogrenci_sayisi].elektrikBorcu);

  ogrenci_sayisi++;
  	fclose(dosya);
}

void ogrenciSil()
{
  int id;
  printf("Ogrenci id giriniz: ");
  scanf("%d", &id);
	
  int i;
  for (i = 0; i < ogrenci_sayisi; i++)
  {
    if (ogrenciler[i].id == id)
    {
      break;
    }
  }

  if (i == ogrenci_sayisi)
  {
    printf("Hata: id %d olan ogrenci bulunamadi!\n", id);
    return;
  }

  // Shift all the following students one position to the left
  for (; i < ogrenci_sayisi - 1; i++)
  {
    ogrenciler[i] = ogrenciler[i + 1];
  }
  ogrenci_sayisi--;
}

void ogrenciGuncelle()
{
  int id;
  printf("Ogrenci id giriniz: ");
  scanf("%d", &id);

  int i;
  for (i = 0; i < ogrenci_sayisi; i++)
  {
    if (ogrenciler[i].id == id)
    {
      break;
    }
  }

  if (i == ogrenci_sayisi)
  {
    printf("Hata: id %d olan ogrenci bulunamadi!\n", id);
    return;
  }
	
  printf("Ogrencinin yeni ismini giriniz: ");
  scanf("%s", ogrenciler[i].isim);
  
  printf("Ogrencinin yeni soyismini giriniz: ");
  scanf("%s", ogrenciler[i].soyIsim);

  printf("Ogrenci yeni kira borcunu giriniz: ");
  scanf("%f", &ogrenciler[i].kiraBorcu);

  printf("Ogrenci yeni elektrik borcunu giriniz: ");
  scanf("%f", &ogrenciler[i].elektrikBorcu);
  

  
}

int ogrenciKarsilastir(const void *a, const void *b)
{
  struct Ogrenci *s1 = (struct Ogrenci *)a;
  struct Ogrenci *s2 = (struct Ogrenci *)b;
  return strcmp(s1->isim, s2->isim); // karsilastirma
}

void ogrenciListele()
{
  qsort(ogrenciler, ogrenci_sayisi, sizeof(struct Ogrenci), ogrenciKarsilastir);

  for (int i = 0; i < ogrenci_sayisi; i++)
  {
    printf("%s %s (ID: %d) \n", ogrenciler[i].isim, ogrenciler[i].soyIsim, ogrenciler[i].id);
  }
}

void borcListele()
{
  for (int i = 0; i < ogrenci_sayisi; i++)
  {
    printf("%s %s (ID: %d) - Kira borcu: %.2f, Elektrik borcu: %.2f\n", ogrenciler[i].isim, ogrenciler[i].soyIsim,ogrenciler[i].id, ogrenciler[i].kiraBorcu, ogrenciler[i].elektrikBorcu);
  }
}

void kiraOde()
{
  int id;
  printf("Ogrenci id giriniz: ");
  scanf("%d", &id);

  int i;
  for (i = 0; i < ogrenci_sayisi; i++)
  {
    if (ogrenciler[i].id == id)
    {
      break;
    }
  }

  if (i == ogrenci_sayisi)
  {
    printf("Hata: id %d olan ogrenci bulunamadi!\n", id);
    return;
  }

  printf("Odenecek tutari girin: ");
  float miktar;
  scanf("%f", &miktar);

  if (miktar > ogrenciler[i].kiraBorcu)
  {
    printf("Hata: Girilen tutar borctan az!\n");
    return;
  }

  ogrenciler[i].kiraBorcu -= miktar;
  printf("Kira borcu basariyla odendi. Kalan borc: %.2f\n", ogrenciler[i].kiraBorcu);
}

void elektrikBorcu()
{
  int id;
  printf("Ogrenci id giriniz: ");
  scanf("%d", &id);

  int i;
  for (i = 0; i < ogrenci_sayisi; i++)
  {
    if (ogrenciler[i].id == id)
    {
      break;
    }
  }

  if (i == ogrenci_sayisi)
  {
     printf("Hata: id %d olan ogrenci bulunamadi!\n", id);
    return;
  }

  printf("Odenecek tutari girin: ");
  float miktar;
  scanf("%f", &miktar);

  if (miktar > ogrenciler[i].elektrikBorcu)
  {
    printf("Hata: Girilen tutar borctan az!\n");
    return;
  }

  ogrenciler[i].elektrikBorcu -= miktar;
  printf("Elektrik borcu basariyla odendi. Kalan borc: %.2f\n", ogrenciler[i].elektrikBorcu);
}

int main()
{
	FILE *dosya;
	dosya = fopen("Ogrenciler.txt","a");
	
	
  
  while (1)
  {
    printf(	"..........................."
      "\n.  APART YONETIM SISTEMI  .\n"
      "...........................\n"
      "[1]. Yeni kiraci kaydi.\n"
      "[2]. Ogrenci kaydini sil.\n"
      "[3]. Ogrenci bilgilerini guncelle.\n"
      "[4]. Ogrenci bilgilerini isim sirasi A-Z'ye olacak bicimde listele.\n"
      "[5]. Ogrenci borc bilgilerini listele.\n"
      "[6]. Kira borcu ode.\n"
      "[7]. Elektrik borcu ode.\n"
      "[8]. Cikis.\n"
      "\n-> Select: ");
    int select;
    scanf("%d", &select);

    if (select == 1)
      ogrenciEkle();
    else if (select == 2)
      ogrenciSil();
    else if (select == 3)
      ogrenciGuncelle();
    else if (select == 4)
      ogrenciListele();
    else if (select == 5)
      borcListele();
    else if (select == 6)
      kiraOde();
    else if (select == 7)
      elektrikBorcu();
    else if (select == 8){
     	break;
	  }

  }
  return 0;
}