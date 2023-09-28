#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

int menu(void);
void yeni(void);
void ac(void);

int main(void){
    int secim=menu();
    
    //Çıkış yapılmadığı sürece seçim yapma hakkına sahipsiniz
    while (secim != 0) {
        switch (secim) {
            case 1:
                yeni();
                break;
            case 2:
                ac();
                break;
            default:
                printf("Hatalı seçim yaptınız!!\n");
        }
        secim=menu();
    }
    printf("\n\n");
    return 0;
}
int menu(void){
    int secim;
    
    //Menu adlı fonksiyonda seçenekleri yazdırdık
    printf("\nNOT DEFTERİ\n\n");
    printf("1-Yeni belge oluştur\n");
    printf("2-Oluşan belge'yi aç\n");
    printf("0-Çıkış\n");
    printf("Seçiminiz : ");
    scanf("%d",&secim);
    
    return secim;
}
void yeni(void){
    char dosyaAdi[40];
    char metin[1024];
    char ch;
    int secim;
    char devamMi='e';
    
    //Yeni adlı fonksiyon ise yeni belge oluşturmakta ve bu belgeye metin ekleme, dosya içeriğini gösterme, dosya içeriğini temizleme ve ana menüye dön seçenekleri bulunmaktadır.
    printf("\nYeni Belge oluşturma sayfası başlıyor...\n\n");
    printf("Dosya adı (/Users/bilgisayarAd/Desktop/txtIsmi ekleyin)  : ");
    scanf("%s",dosyaAdi);
    
    FILE *ptr=fopen(dosyaAdi,"w");
    
    if(ptr != NULL){
        //'e' harfine bastığın sürece devam eder
        while (devamMi != 'h') {
            printf("\n%s isimli dosyamız oluşturuldu\n\n",dosyaAdi);
            printf("1-Metin ekleme\n");
            printf("2-Dosya içeriğini göster\n");
            printf("3-Dosya içeriğini temizle\n");
            printf("4-Ana menüye dön\n");
            
            printf("\nSeçiminiz : ");
            scanf("%d",&secim);
            
            if(secim==1){
                printf("Metni girin : ");
                scanf(" %[^\n]s",metin);
                ptr=fopen(dosyaAdi,"a");
                fprintf(ptr,"%s\n",metin);
                fclose(ptr);
                printf("Metin eklendi \n");
            }
            else if (secim==2){
                ptr=fopen(dosyaAdi,"r");
                printf("Dosya içeriği \n\n");
                while (!feof(ptr)) {
                    ch=fgetc(ptr);
                    printf("%c",ch);
                }
                fclose(ptr);
            }
            else if(secim==3){
                ptr=fopen(dosyaAdi,"w");
                fclose(ptr);
                printf("Dosya içeriği temizlendi\n");
            }
            else if (secim==4){
                fclose(ptr);
                }
            else{
                fclose(ptr);
                printf("Hatalı seçim!!\n");
            }
            printf("\nDevam etmek istiyor musunuz(Evet:'e',Hayır:'h') : ");
            scanf(" %c",&devamMi);
        }
        
    }
    //Oluşmadığı takdirde oluşamadı der
    else{
        printf("Dosya oluşturulmadı!! \n");
    }
}
void ac(void){
    char dosyaAdi[40];
    char metin[1024];
    char ch;
    int secim;
    char devamMi='e';
    
    //Ac adlı fonksiyonda oluşan belgeye  metin ekleme, dosya içeriğini gösterme, dosya içeriğini temizleme ve ana menüye dön seçenekleri uygulayabiliriz.
    printf("\nBelge açma sayfası\n\n");
    printf("Açmak istediğiniz dosya adı(/Users/bilgisayarAd/Desktop/txtIsmi ekleyin) : ");
    scanf("%s",dosyaAdi);
    
    FILE *ptr=fopen(dosyaAdi,"r");
    
    if(ptr != NULL){
        //'e' harfine bastığın sürece devam eder
        while (devamMi !='h') {
            printf("\n%s isimli dosyamız açıldı\n\n",dosyaAdi);
            printf("1-Metin ekleme\n");
            printf("2-Dosya içeriğini göster\n");
            printf("3-Dosya içeriğini temizle\n");
            printf("4-Ana menüye dön\n");
            
            printf("\nSeçiminiz : ");
            scanf("%d",&secim);
            
            if(secim==1){
                printf("Metni girin : ");
                scanf(" %[^\n]s",metin);
                ptr=fopen(dosyaAdi,"a");
                fprintf(ptr,"%s\n",metin);
                fclose(ptr);
                printf("Metin eklendi \n");
            }
            else if (secim==2){
                ptr=fopen(dosyaAdi,"r");
                printf("Dosya içeriği \n\n");
                while (!feof(ptr)) {
                    ch=fgetc(ptr);
                    printf("%c",ch);
                }
                fclose(ptr);
            }
            else if(secim==3){
                ptr=fopen(dosyaAdi,"w");
                fclose(ptr);
                printf("Dosya içeriği temizlendi\n");
            }
            else if (secim==4){
                menu();
                fclose(ptr);
            }
            else{
                fclose(ptr);
                printf("Hatalı seçim!!\n");
            }
            printf("\nDevam etmek istiyor musunuz(Evet:'e',Hayır:'h') : ");
            scanf(" %c",&devamMi);
        }
    }
    //Bulunmadığı takdirde dosya bulunamadı der
    else{
        printf("%s isimli dosya bulunamadı!! \n",dosyaAdi);
    }
        
}
