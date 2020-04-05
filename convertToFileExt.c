#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct Branch{
    float value;
    float V;
    float I;
    
};

int main(){

    struct Branch R[7];
    struct Branch C[7];
    struct Branch Rp;
    R[1].value = 1000;
    R[2].value = 10000;
    R[3].value = 5000;
    Rp.value = 0;
    float val_tmp;
    int j,k;

    int tmp1 = 0, tmp2 = 0;
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
    strcpy(R_str,"(R1 S R2 S R3) P R4");

    char C_str[50];
    strcpy(C_str,"(C1 S C2) P C3");


   
    for(int i =0;i<strlen(R_str);++i){

        if (R_str[i] == '('){
            j = i+1;
            
            while (R_str[j] != ')'){

                if(R_str[j] == 'S'){
                    tmp1 = atoi(&R_str[j-2]);
                    
                    val_tmp = val_tmp + R[tmp1].value;
                    tmp2 = atoi(&R_str[j+3]);
                    val_tmp = val_tmp + R[tmp2].value;
                    Rp.value = val_tmp;
                    val_tmp = val_tmp - R[tmp2].value;

                    // R[tmp1].I = 
                    
                    
                }
                // else{
                //     Rp.value = (Rp.value * R[tmp+3].value)/(Rp.value + R[tmp+3].value);
                // }

                j++;
            }


        }
    }

    


}