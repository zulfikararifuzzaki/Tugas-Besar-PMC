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
	};

int main()
{	//DEKLARASI VARIABEL
	FILE *fptr;
	char* fname = (char*)malloc(sizeof(char));
	char data[50];
	
	//INPUT FILE
	printf("Masukkan nama file external : ");
	gets(fname);
	fptr = fopen(fname, "r");
	if (fptr == NULL)
		printf("Belum ada rangkaian yang diinput");
	else
	{	//BACA FILE
		while(!feof(fptr))
		{	fgets(data, sizeof(data), fptr);
			//DIBAWAH INI AKAN DIIMPLEMETASIKAN FUNGSI UNTUK MEMECAH "data" menjadi perbagian
		}
	}
  return 0;
}

komponen pecah(char* data)
{	char delimiter = ' ';
	int i = 0;
 	int j = 0;
 	char* temp = (char*)malloc(sizeof(char));
 	struct komponen *out;
 	
 	while(data[i]!=NULL)
	{	while(data[i] != delimiter)
		{	temp[i] = data[i];
			++i; }
	 	i = 0;
	 	if (j == 0)	out->jenis = temp[0];
	 	else if (j == 1)	out->value = atoi(temp);
	 	else if (j == 2)	out->kiri = temp;
	 	else	out->kanan = data;
	}
 	

}
