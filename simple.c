#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct ekivalen
{
	int V;
	float I;
	float R;
	float C;
	}ekivalen;

float paralel (int X1, int X2){
	return(X1*X2/(X1+X2));}

char bentukR[64];
char bentukC[64];

float cariReq(char* input, char jenis){
	// input berupa string dari file eksternal
	// jenis berupa R atau C untuk resistor atau kapasitor
	// keluaran R atau C ekivalen dari resistor
	
	char delim = ' ';
	char* temp = (char*)malloc(sizeof(char)); strcpy(temp, "");
	int bentuk;
	int X1;
	int X2;
	int X3;
	
	int i =0;
	int k = 0;
	
	int output;
	
	while(input[i] != '\0')
	{
		if(input[i] != delim){
			strncat(temp, &input[i], 1);
			++i;}
		else{
			if(k==0){
				bentuk = atoi(temp);}
			else if (k==1){
				X1 = atoi(temp);}
			else if (k==2){
				X2 = atoi(temp);}
			else{
				X3 = atoi(temp);}
			strcpy(temp, "");
			++k;
			++i;}
		}
	
	if(jenis == 'R'){
		if (bentuk == 1){
			output = X1;
			strcpy(bentukR, "R1");}
		else if(bentuk == 2){
			output = X1 + X2;
			strcpy(bentukR, "R1 S R2");}
		else if(bentuk == 3){
			output = paralel(X1, X2);
			strcpy(bentukR, "R1 P R2");}
		else if(bentuk == 4){
			output = X1 + X2 + X3;
			strcpy(bentukR, "R1 S R2 S R3");}
		else if(bentuk == 5){
			output = paralel(X1, X2+X3);
			strcpy(bentukR, "R1 P (R1 S R2)");}
		else if(bentuk == 6){
			output = paralel(X1, X2) + X3;
			strcpy(bentukR, "(R1 P R2) S R3");}
		else{
			output = paralel(paralel(X1, X2), X3);
			strcpy(bentukR, "R1 P R2 P R3");}
		}
	else
	{
		if (bentuk == 1){
			output = X1;
			strcpy(bentukC, "C1");}
		else if (bentuk == 2){
			output = paralel(X1, X2);
			strcpy(bentukC, "C1 S C2");}
		else if (bentuk == 3){
			output = X1 + X2;
			strcpy(bentukC, "C1 P C2");}
		else if (bentuk == 4){
			output = paralel(paralel(X1, X2), X3);
			strcpy(bentukC, "C1 S C2 S C3");}
		else if (bentuk == 5){
			output = X1 + paralel(X2, X3);
			strcpy(bentukC, "C1 P (C2 S C3)");}
		else if (bentuk == 6){
			output = paralel(X1+X2, X3);
			strcpy(bentukC, "(C1 P C2) S C3");}
		else{
			output = X1 + X2 + X3;
			strcpy(bentukC, "C1 P C2 P C3");}
		}
	return(output);
}

ekivalen* cariNetList(char* filename)
{	// menerima input nama file dalam bentuk string
	// memproses untuk mengisis V, R, dan C
	// output berupa V, R, dan C ekivalen
	
	FILE *stream;
	ekivalen* output = (ekivalen*)malloc(sizeof(ekivalen));
	
	char* Vout = (char*)malloc(10*sizeof(char));
	char* Rout = (char*)malloc(10*sizeof(char));
	char* Cout = (char*)malloc(10*sizeof(char));
	
	stream = fopen(filename, "r");
	
	fgets(Vout, 20*sizeof(char), stream);
	fgets(Rout, 20*sizeof(char), stream);
	fgets(Cout, 20*sizeof(char), stream);
	printf("%s\n", Vout);
	printf("%s\n", Rout);
	printf("%s\n", Cout);
	
	output->V = atoi(Vout);
	output->R = cariReq(Rout, 'R');
	output->C = cariReq(Cout, 'C');
	output->I = output->V/output->R;
	
	fclose(stream);
	return(output);
	}

char* getString()
{	char* output = (char*)malloc(sizeof(char));
	strcpy(output, "");
	char S = 'S';
	char space = ' ';
	
	strcat(output, bentukR);
	strncat(output, &space, 1);
	strncat(output, &S, 1);
	strncat(output, &space, 1);
	strcat(output, bentukC);
	return(output);
	}

int main()
{
	cariNetList("contoh.txt");
	printf("%s\n", getString());
	return(0);
	}
