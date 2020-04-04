#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct Branch{
    float value;
    float V;
    float I;
    float Tau;
};

int main(){

    struct Branch R[7];
    struct Branch C[7];
    int j;
    // Dua besaran Vs dan Is didapat dari proses simplifikasi RC (bagian zulfikar)
    // Vs dalam satuan V
    float Vs = 9;

    // Req dalam satuan Ohm
    float Req = 10;

    // Ceq dalam satuan nF
    float Ceq = 470;

    // tau dalam satuan nanosecond
    float tau = Req*Ceq;

    // Is dalam satuan mA
    float Is = Vs/Req;

    // Masih Test awal, command seri dan paralel di hard code
    char R_str[50];
    strcpy(R_str,"(R1 S R2) P R3 P (R4 S R5)");

    char C_str[50];
    strcpy(C_str,"(C1 S C2) P C3");

    /* Memisahkan string yang terdapat di dalam kurung untuk dikerjakan 
        terlebih dahulu
    */
   
    for(int i =0;i<strlen(R_str);++i){
        if (R_str[i] == '('){
            j = i+1;
            
            while (R_str[j] != ')'){

                printf("%c",R_str[j]);
                j++;
            }
            printf("\n");
        }
    }

    


}