#include <stdio.h>

#include <stdlib.h>

#include <string.h>

// tanimlanan fonksiyonlar burada bildirimi yapildi
void hakkinda ();
void anamenu ();
void departman ();
void departmanekle ();
void kaydet ();
void yukle ();

// tum departman listesi bu dizide saklanacak. 10 adet departman limiti var.
char departmanListesi[10][100] = {
  "insan kaynaklari",
  "bilgi islem",
  "muhasebe"
};

// tum calisan listesi bu dizide saklanacak. 10 adet calisan limiti var.
char calisanListesi[10][100] = {
  "Batuhan Sevýn",
  "Ozgur Berk Cukurova",
  "Sýla Tara Sel"
};

// calisanlarin hangi departmanda calistigi bilgisi bu dizide tutuluyor. {departmansirasi, calisansirasi} formatinda.
int pozisyon[100][2] = {
	{1,1},
	{2,0},
	{3,2} 
};

int main (int argc, char *argv[]) {

  // uygulamayi baslatan ilk fonksiyon ana menudur
  anamenu ();

  
  return 0;
}

//hakkinda
void hakkinda () {
  int seciminiziyapin = 1;
  system("CLS");		//ust ekrani temizlemek icin ekledim
  printf("PROJENIN AMACI : Projenin amaci insan kaynaklarinin departmanlar \n arasinda kolayca personel ekleme duzenleme ve kaldirmasina \n yardimci olmasidir. \n \n (0) Ana menu \n seciminizi yapin: ");
  scanf("%d", &seciminiziyapin);

  if (seciminiziyapin == 0)
  {
    anamenu ();
  }
}


// kullanicidan hangi menuye gececegi bilgisi aliniyor ve diger ekranlara gidiyoruz.
void anamenu () {
	 system("CLS");

	yukle ();
 
  printf("  << Hos geldiniz >> \n (1) Departman Secimi \n (2) Hakkinda \n (3) Cikis \n    Seciminiz : ");

  int seciminiziyapin = 0;

  scanf ("%d", &seciminiziyapin);

  switch (seciminiziyapin)
    {
    case 1:
      departman ();
      break;

    case 2:
      hakkinda ();
      break;

    case 3:
      printf ("Tesekkurler");
      kaydet ();
      // tum programi kapatmak icin cagirdim
      exit(1);
      break;

    default:
      printf ("gecersiz secim");
    }
  return;
}

// departman eklemek icin kullanicidan departman adi aliyorum
void departmanekle() {
    
  printf ("Eklenecek Departman Adi : ");
  int i = 0;
  for (i = 0; i < 10; i++)
    {
    	// departman listesindeki ilk bos yer bulunuyor ve strlen ile departmanListesi[i]. elemanýn uzunluguna bakýyorum, eger 0 ise oraya yeni departman ekliyorum
      if (strlen (departmanListesi[i]) == 0)
    	{
    		// okudugumuz degeri bos departman listesine ekle
    	  scanf ("%s", departmanListesi[i]);
    	  departman();
    	  break;
    	}
    }
}

// silinecek sira aliniyor ve listeden siliyorum
void departmansil() {
    
  printf ("Silinecek Departman Numarasý : ");
  int secim;
  scanf("%d", &secim);
  // sira numarasini ekrana +1 ile yazdigim icin kullanicinin verdigi sira numarasinin -1 ini alarak siliyorum
  // strcpy fonksiyonu ile verilen sagdaki degeri soldaki degiskene yazar
  strcpy(departmanListesi[secim-1],"");    
  departman();
}

// guncelleme icin sira bilgisi aliniyor ve alinan yeni isim ile guncelleme yapiliyor
void departmanguncelle() {
    
  printf ("Guncellenecek Departman Numarasi : ");
  int secim;
  scanf("%d", &secim);
  char yeniad[100];
  printf ("Yeni Departman Adi : ");
  scanf("%s", &yeniad);
  // alinan yeni ad secilen departman sirasina yazilarak guncelleme yapiliyor
  strcpy(departmanListesi[secim-1],yeniad);    
  departman();
}

void departman () {
    
  system("CLS");
  printf("Departmanlar Listesi :\n");

  int i = 0;
  // tum departman listesine bakiyoruz
  for (i = 0; i < 10; i++)
    {
    	// departman listesinde uzunlugu en az 1 olan departmanlari ekrana yaziyorum
        if (strlen(departmanListesi[i]) >= 1)
    	{
    	  // i+1 dememizin nedeni diziler 0 dan basliyor. kullanici ilk elelmani 1 gorsun diye +1 ile yaziyoruz. bu yuzden silerken -1 ile sildiriyoruz
    	  printf("(%d) {%s}\n", i + 1, departmanListesi[i]);
    	}
    }

  printf(" \n (+) Ekle \n (-) Sil  \n (*) Guncelle \n (0) Ana Menu \n Seciminizi Yapiniz : ");
  char secim;
  // char tipinde secim aliyoruz. +-*012 oldugu icin char kullandim.
  scanf("%s", &secim);
  switch (secim)
    {
    case '+':
      departmanekle();
      break;
    case '-':
    	departmansil();
    case '*':
    	departmanguncelle();
    case '0':
      anamenu();
      break;
    default:
	   printf("defaulta girdi");
       int sayi;
       // sscanf ile char tipindeki secim degiskeni int tipine donusup sayi degiskenine ataniyor.
       sscanf(&secim, "%d", &sayi);
       // sayi degiskeni departman sirasini tutuyor. secilen departman ile calisanlar listesi cagriliyor
       calisanlar(sayi);
      break;
    }
}

// calisan silme islemini yapar
void calisansil(int departman) {
    
  printf ("Silinecek Calisan Numarasi : ");
  int secim;
  scanf("%d", &secim);
  // secilen calisan numarasindaki kayit bosluk ile degistirilerek silinir
  strcpy(calisanListesi[secim-1],"");  
  
  int j = 0;
  for (j = 0; j < 100; j++)
    {
    	// pozsiyon dizisindeki 1. index calisan sirasini tutar. o yuzden secim-1 pozisyon dizisini 1. elemanina esitse degerleri silinir
      if (pozisyon[j][1]== secim-1)
    	{
    	  pozisyon[j][0] = 0;
    	  pozisyon[j][1]= 0;
    	  break;
    	}
    }
  
  
  calisanlar(departman);
}

// secilen departmana yeni calisan ekleme yapilir
void calisanekle(int departman) {
    
  printf ("Eklenecek calisan adi : ");
  int i = 0;
  for (i = 0; i < 10; i++)
    {
    	// bos calisan yeri bulunur
      if (strlen (calisanListesi[i]) == 0)
    	{
    		// alinanan yeni isim bos calisan yerine yazilir
    	  scanf ("%s", calisanListesi[i]);
    	  break;
    	}
    }
  
  int j = 0;
  // pozisyon dizisine yeni calisanin departman bilgis eklenir.
  for (j = 0; j < 100; j++)
    {
    	// ilk bos pozsiyon bulunur. 
      if (pozisyon[j][0]== 0)
    	{
    		// bos degerin departman bilgisi fonksiyon parametresinde alinan departman atanir
    	  pozisyon[j][0] = departman;
    	  // yeni eklenen elemanin sirabilgisi yukaridaki for dongusunde kullanilan i degiskeninden alinir ve pozsiyon dizisine kaydedilir.
    	  pozisyon[j][1]=i;
    	  calisanlar (departman);
    	  break;
    	}
    }
  
  calisanlar(departman);
}

// verilen departman parametresi ile departmanda calisanlari ekrana yazar
	void calisanlar (int departman) {

  system("CLS");
  printf("Calisanlar Listesi :\n");

  int i = 0;
  for (i = 0; i < 100; i++)
    {
    	// calisan departman degiskeni, pozisyon dizisinde bulunan calisanin hangi departmanda oldugu bilgisini tutar. departmanlistesindeki sirasini verir.
    	int calisandepartman = pozisyon[i][0];
    	// departman sirasi +1 verilerek kaydedildi cunku varsayilan degerleri 0 oldugu icin hata olusuyor ayirt edilemiyor. boslari atliyoruz.
		if(calisandepartman > 0){
			// calisanlar fonksiyonundaki departman sirasi ile calisan departman sirasi esit ise ekrana yazdirabiliriz.
			if(calisandepartman == departman){
				// calisan sirasi degiskeni pozisyon dizisindeki calisanin, calisanListesindeki sira bilgisini tutar.
				int calisansirasi=pozisyon[i][1];
    	        printf("(%d) %s \n", calisansirasi+1, calisanListesi[calisansirasi]);
    	    }
		}   	
    }

  printf(" \n (+) Ekle \n (-) Sil  \n (0) Ana Menu \n Seciminizi Yapiniz : ");
  char secim;
  scanf("%s", &secim);
  switch (secim)
    {
    case '+':
      	calisanekle(departman);
      break;
    case '-':
		calisansil(departman);
		break;    
    case '0':
      anamenu();
      break;
    }
	 }
void kaydet ()
	{
    FILE *dosya;
    dosya = fopen("veriler.txt", "w");

    if (dosya == NULL)
    {
        printf("Dosya acilamadi.");
        return;
    }

    // Departman listesini kaydet
    fprintf(dosya, "%s\n", "Departmanlar:");
    int i = 0;
    for (i=0; i < 10; i++)
    {
        if (strlen(departmanListesi[i]) != 0)
        {
            fprintf(dosya, "%s\n", departmanListesi[i]);
        }
    }

    // Calisan listesini ve pozisyonlarini kaydet
    fprintf(dosya, "%s\n", "Calisanlar:");
    int j = 0;
    for ( i = 0; j < 10; j++)
    {
        if (strlen(calisanListesi[j]) != 0)
        {
            fprintf(dosya, "%s,%d,%d\n", calisanListesi[j],pozisyon[j][0],pozisyon[j][1]);
           
        }
    }

    fclose(dosya);
}

void yukle ()
{

    FILE *dosya;
    dosya = fopen("veriler.txt", "r");

    if (dosya == NULL)
    {
        printf("Yuklenecek veri bulunamadi.\n");
        return;
    }

    char satir[100];
    int departmanIndex = 0;
    int calisanIndex = 0;
    int satirSayisi = 0;

    while (fgets(satir, sizeof(satir), dosya) != NULL)
    {
        satirSayisi++;
		
        // Departmanlar bolumunu oku
        if (strcmp(satir, "Departmanlar:\n") == 0)
        {
    
		    departmanIndex = satirSayisi;
            continue;
        }
		
		 // Calisanlar bolumunu oku
        // Calisanlar bolumunu oku
        if (strcmp(satir, "Calisanlar:\n") == 0)
        {
          
			calisanIndex = satirSayisi;
            continue;
        }
		
        if (departmanIndex != 0 && calisanIndex == 0 && satirSayisi > departmanIndex)
        {
        	
           
			int departmanListesiIndex = satirSayisi - departmanIndex - 1;
            satir[strcspn(satir, "\n")] = '\0'; // Newline karakterini kaldýr
	
            strcpy(departmanListesi[departmanListesiIndex], satir);
        }

       

        if (calisanIndex != 0 && satirSayisi > calisanIndex)
        {
        	
       	
			int calisanListesiIndex = (satirSayisi - calisanIndex - 1) ;
            
			
			
				
			
			
            satir[strcspn(satir, "\n")] = '\0'; // Newline karakterini kaldýr

            
            	char isim[100];
    			int deger1;
				int deger2;
    
    			sscanf(satir, "%[^,],%d,%d", isim, &deger1, &deger2);
    
                strcpy(calisanListesi[calisanListesiIndex], isim);
        
                pozisyon[calisanListesiIndex][0] = deger1;
          
                pozisyon[calisanListesiIndex][1] = deger2;
            
        
    }
        
    }

    fclose(dosya);
}


