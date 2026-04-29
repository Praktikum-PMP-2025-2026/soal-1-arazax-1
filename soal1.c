//Nama     : Afdhal Razaq
//NIM      : 13224004
//Soa      : 01

#include <stdio.h>
#include <string.h>

typedef struct Artefak{
    char nama[50];
    char kategori[50];
    int tahun;
    int nilai;
} Artefak;

void swap(Artefak *a, Artefak *b){
    Artefak temp = *a;
    *a = *b;
    *b = temp;
}

void sort(Artefak *artefak, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(strcmp(artefak[j].kategori, artefak[j+1].kategori) > 0){
                swap(&artefak[j], &artefak[j+1]);
            }else if(strcmp(artefak[j].kategori, artefak[j+1].kategori) == 0){
                if(artefak[j].tahun > artefak[j+1].tahun){
                    swap(&artefak[j], &artefak[j+1]);
                }else if(artefak[j].tahun == artefak[j+1].tahun){
                    if(artefak[j].nilai < artefak[j+1].nilai){
                        swap(&artefak[j], &artefak[j+1]);
                    }else if(artefak[j].nilai == artefak[j+1].nilai){
                        if(strcmp(artefak[j].nama, artefak[j+1].nama) > 0){
                            swap(&artefak[j], &artefak[j+1]);
                        }
                    }
                }
            }
        }
    }
}
void display(Artefak *artefak, int n){
    for(int i = 0; i < n; i++){
        printf("%s %s %d %d\n", artefak[i].nama, artefak[i].kategori, artefak[i].tahun, artefak[i].nilai);
    }
}
int main(void) {
    int n;
    scanf("%d", &n);
    Artefak artefak[n];
    for(int i = 0; i < n; i++){
        scanf("%s", artefak[i].nama);
        scanf("%s", artefak[i].kategori);
        scanf("%d", &artefak[i].tahun);
        scanf("%d", &artefak[i].nilai);
    }
   
    sort(artefak, n);
    display(artefak, n);
    return 0;
}
