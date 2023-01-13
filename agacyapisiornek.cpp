#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Agaclar{
	int data;
	struct Agaclar *sag,*sol;
	}Agac;
Agac *kok=NULL;


Agac *degeral(){
	Agac*yeni;
	yeni=(Agac*)malloc(sizeof(Agac));
	
	if(yeni==NULL){
	printf("bellek dolu");
	return NULL;}
	
	printf("\nsayilari giriniz:");
	scanf("%d",&(yeni->data));
	yeni->sag=NULL;
	yeni->sol=NULL;
	return yeni;
}


void ekle(Agac*agackok, Agac *yeni){
	if(kok==NULL)
	kok=yeni;
	
	else{
		if(yeni->data < agackok->data)//kucukse
		{ if(agackok->sol==NULL)//sol boþ ise sola ekle
		  agackok->sol=yeni;
		
		  else
		  ekle(agackok->sol ,yeni); //sol doluysa
		}
		
		else //buyukse
		{ if(agackok->sag==NULL)//sað boþ ise
		  agackok->sag=yeni;
		  
		  else//sað doluysa
		  ekle(agackok->sag,yeni);
		}
	}	
}


Agac *arama(Agac*kok,int aranan){
	if(kok==NULL)
	return NULL;//baþarýsýz arama
	
	if(aranan < kok->data)//kucuk olma durumunda soldakilere
	return arama(kok->sol,aranan);
	else if(aranan > kok->data)//buyuk olma durumda sagdakilere
	return arama(kok->sag,aranan);
	else return kok;//baþarýlý arama	
}


Agac *enk(Agac*kok){
	if(kok->sol==NULL)
	return kok;
	return enk(kok->sol);
}


Agac *enb(Agac*kok){
	if(kok->sag==NULL)
	return kok;
	return enk(kok->sag);
}

void listele(Agac *kok){
	if(kok!=NULL){
		listele(kok->sol);
		printf("%d\n",kok->data);
		listele(kok->sag);
	}
}


int main(){
	Agac *yeni,*bul,*ekucuk,*ebuyuk;
	int data,aranan,sil,tut;
	
	char secim;
	while(1){
		printf("\n1- Ekleme\n2- InOrder Listeleme\n3- Arama\n4- En kucuk\n5- En buyuk\n6-Cikis\nSeciminiz...: ");
		secim=getch();
		switch(secim){
			case '1':
				yeni=degeral();
				ekle(kok,yeni);
				break;
				
			case '2':
				if(kok!=NULL){
				listele(kok);
				getch();
				}
				else
				printf("bos liste");
				break;
			
			case '3':
				printf("aranan eleman:");
				scanf("%d",&aranan);
				
				if(kok!=NULL){
				bul=arama(kok,aranan);
				if(bul!=NULL)
				printf("bulunan eleman:%d",bul->data);
				else printf("eleman bulunamadý");
				getch();
				}
				else
				printf("liste bostur");
				break;
				
			case '4':
					if(kok!=NULL){
					ekucuk=enk(kok);
					printf("\nen kucuk eleman:%d",ekucuk->data);
					getch();
					}
					else
					printf("liste bos");
					break;
			
			case '5':
				if(kok!=NULL){
					ebuyuk=enb(kok);
					printf("\nen buyuk eleman:%d",ebuyuk->data);
					getch();
				}
				else
				printf("liste bos");
				break;
				
			case '6': exit(0);
			default: printf("\nYanlis Secim...");
	}

	}
	
	
}




















