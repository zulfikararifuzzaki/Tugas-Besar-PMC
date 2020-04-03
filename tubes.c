#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct komponen{
	char jenis;
	int value;
	struct komponen *kiri;
	struct komponen *kanan;
	}

int main()
{	//DEKLARASI VARIABEL
	FILE *fptr;
	char* fname = (char*)malloc(sizeof(char));
	char cjenis;
	int cvalue;
	
	//INPUT FILE
	printf("Masukkan nama file external : ");
	gets(fname);
	fptr = fopen(filename, "r");
	//BACA FILE
	
}
