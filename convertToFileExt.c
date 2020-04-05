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

struct tempBranch{
    float value;
    int isReq;
    int key[5];
};

int main(){

    struct Branch R[7];
    struct Branch C[7];
    struct tempBranch Rp[7];
    R[1].value = 48000;
    R[2].value = 48000;
    R[3].value = 48000;
    R[4].value = 38000;
    C[1].value = 2000;
    C[2].value = 6000;
    C[3].value = 3000;
    C[4].value = 5000;
    float val_tmp;
    int i=0,j,k,x;
    int b_count = 0,count = 0;
    int tmp1 = 0, tmp2 = 0,key;
    int isRNoBracket = 1;
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
    strcpy(R_str,"(R1 P R2 P R3) S R4");

    char C_str[50];
    strcpy(C_str,"(C1 S C2) P C3");
    count = 0;

    /* Menyederhanakan rangkaian agar bisa dipecah (menghilangkan bracket dari string)
    
        Struct Branch Rp akan berbentuk array yang berisi nilai nilai R (sudah disederhanakan) 
        agar I bisa dipecah

    */
    while(i < strlen(R_str)){

        if (R_str[i] == 'R'){
            tmp1 = atoi(&R_str[i+1]);
            Rp[b_count].value = R[tmp1].value;
            Rp[b_count].isReq = 0;
            b_count++;
            key = tmp1;
        }
        if (R_str[i] == '('){
           
            j = i+1;
            
            while (R_str[j] != ')'){
                
                if(R_str[j] == 'S'){
                    tmp1 = atoi(&R_str[j-2]);
                    
                    val_tmp = val_tmp + R[tmp1].value;
                    tmp2 = atoi(&R_str[j+3]);
                    val_tmp = val_tmp + R[tmp2].value;
                    Rp[b_count].value = val_tmp;
                    Rp[b_count].isReq = 1;
                    Rp[b_count].key[x]= tmp1;
                    Rp[b_count].key[x+1] = tmp2;
                    val_tmp = val_tmp - R[tmp2].value;
                    x++;
       
                }

                if(R_str[j] == 'P'){

                    tmp1 = atoi(&R_str[j-2]);
                    tmp2 = atoi(&R_str[j+3]);

                    if (!count){
                        int y = R[tmp1].value;
                       
                        val_tmp = y;
                        count++;
                    }
                    
                    val_tmp = (val_tmp * R[tmp2].value)/(val_tmp + R[tmp2].value);
                    Rp[b_count].value = val_tmp;
                    Rp[b_count].isReq = 1;
                    Rp[b_count].key[x]= tmp1;
                    Rp[b_count].key[x+1] = tmp2;
                    x++;
                    
                }
                
                j++;
            }
            count = 0;
            // printf("%.2f",Rp[0].value);
            i = j;
            b_count++;
        }
        ++i;
    }

    for(k = 0; k<b_count;k++){
        printf("%.2f\n",Rp[k].value);
    }
    
    k = 0;
    while (k < strlen(R_str)){
        
    }

    // printf("%.2f",Rp[0].value);
    return 0;


}