#include <stdio.h>
#include <stdlib.h>
#define MAKS 8

typedef int itemType;
typedef struct
{
    itemType data[MAKS];
    int idx;
} stack;

void inisialisasi(stack *);
void push(stack *, itemType);
itemType pop(stack *);
int empty(stack *);
int full(stack *);
int decimal;
int konversi;

int main()
{
    int o=1;
    stack tumpuk;
    int pilih;
    printf("-------konversi desimal ke biner oktal dan heksadesimal------\n");
    inisialisasi(&tumpuk);
    printf("\nmasukkan bilangan desimal : ");
    scanf("%d", &decimal);
    printf("\n---MENU---\n");
    printf("1 untuk konversi ke biner\n");
    printf("2 untuk konversi ke oktal\n");
    printf("3 untuk konversi ke heksa\n");
    printf("4 untuk keluar");
    printf("\n\npilih :  ");
    scanf("%d",&pilih);
    switch(pilih)
    {
    case 1:
        while (decimal!=0)
        {
            konversi = decimal%2;
            decimal = decimal/2;
            push(&tumpuk, konversi);
        }
        printf("Hasil konversi ke biner : ");
        do
        {
            printf("%d",pop(&tumpuk));
        }
        while (empty(&tumpuk)!=1);
        break;
    case 2:
        while (decimal!=0)
        {
            konversi = decimal%8;
            decimal = decimal/8;
            push(&tumpuk, konversi);
        }
        printf("Hasil konversi ke oktal : ");
        do
        {
            printf("%d",pop(&tumpuk));
        }
        while (empty(&tumpuk)!=1);
        break;
    case 3:
        while (decimal!=0)
        {
            konversi = decimal%16;
            decimal = decimal/16;
            push(&tumpuk, konversi);
            o++;
        }
        int maksimal = o;
        printf("Hasil konversi ke heksadecimal : ");
        for(int i=maksimal; i>0; i--)
        {
            int p=pop(&tumpuk);
            if(p<=9)
                printf("%d",p);
            else if(p==10)
                printf("A");
            else if(p==11)
                printf("B");
            else if(p==12)
                printf("C");
            else if(p==13)
                printf("D");
            else if(p==14)
                printf("E");
            else if(p==15)
                printf("F");
        }
        return 0;
        break;
    case 4:
        printf("--silahkan tekan enter sekalilagi");
    }
}

void inisialisasi(stack *s)
{
    s->idx=0;
}

void push(stack *s, itemType x)
{
    if(full(s)==1)
        puts("Data sudah full");
    else
    {
        s->data[s->idx] = x;
        s->idx++;
    }
}

int full(stack *s)
{
    if(s->idx == MAKS)
        return 1;
    else
        return 0;
}

int empty(stack *s)
{
    if(s->idx==0)
        return 1;
    else
        return 0;
}

itemType pop(stack *s)
{
    itemType temp;
    if(empty(s)==1)
        exit(0);
    else
    {
        s->idx--;
        temp=s->data[s->idx];
    }
    return temp;
}



