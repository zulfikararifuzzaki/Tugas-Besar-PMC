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
    char conn_type;
};

void addRdata(struct Branch R[], struct tempBranch Rp,int last_R, float Is,float Vs,char R_str[]){

    float Ip_temp = (R[last_R].value *Is)/(Rp.value+R[last_R].value);
    float Vp_temp = (Rp.value *Vs)/(Rp.value+R[last_R].value);
    
    if (isExistBracket(R_str)){

        if (Rp.conn_type == 'S'){

            R[Rp.key[0]].I = Ip_temp;
            R[Rp.key[1]].I = Ip_temp;
            R[last_R].I = Is - Ip_temp;

            R[Rp.key[0]].V = Ip_temp * R[Rp.key[0]].value;
            R[Rp.key[1]].V = Ip_temp * R[Rp.key[1]].value;
            R[last_R].V = R[last_R].I * R[last_R].value;

        }  

        if (Rp.conn_type == 'P'){

            R[Rp.key[0]].V = Vp_temp;
            R[Rp.key[1]].V = Vp_temp;
            R[last_R].V = Vs - Vp_temp;

            R[Rp.key[0]].I = Vp_temp / R[Rp.key[0]].value;
            R[Rp.key[1]].I = Vp_temp / R[Rp.key[1]].value;
            R[last_R].I = R[last_R].V / R[last_R].value;

        }   
    }
    else{

        if (Rp.conn_type == 'S'){
            
            R[Rp.key[0]].I = Is;
            R[Rp.key[1]].I = Is;
            R[Rp.key[2]].I = Is;

            R[Rp.key[0]].V = Is * R[Rp.key[0]].value;
            R[Rp.key[1]].V = Is * R[Rp.key[1]].value;
            R[Rp.key[2]].V = Is * R[Rp.key[2]].value;
        }

        if (Rp.conn_type == 'P'){

            R[Rp.key[0]].V = Vs;
            R[Rp.key[1]].V = Vs;
            R[Rp.key[2]].V = Vs;

            R[Rp.key[0]].I = Vs / R[Rp.key[0]].value;
            R[Rp.key[1]].I = Vs / R[Rp.key[1]].value;
            R[Rp.key[2]].I = Vs / R[Rp.key[2]].value;

        }

    }

}

int isExistBracket(char R_str[]){
    for(int i = 0; i<strlen(R_str);++i){
        if(R_str[i] =='('){
            return 1;
        }
    }
    return 0;
}
int getEqCircuit(struct Branch R[],char R_str[],struct tempBranch Rx,struct tempBranch *Ro){
    int last_R;
    float val_tmp;
    
    int i=0,j,k,x = 0,n = 0;
    int b_count = 0,count = 0;
    int tmp1 = 0, tmp2 = 0;
    if (isExistBracket(R_str)){

        while(i < strlen(R_str)){

            if (R_str[i] == 'R'){
                tmp1 = atoi(&R_str[i+1]);
                Rx.key[2] = tmp1;
                last_R = tmp1;
            }
            if (R_str[i] == '('){
            
                j = i+1;
                
                while (R_str[j] != ')'){
                    
                    if(R_str[j] == 'S'){
                        tmp1 = atoi(&R_str[j-2]);
                        
                        val_tmp = val_tmp + R[tmp1].value;
                        tmp2 = atoi(&R_str[j+3]);
                        val_tmp = val_tmp + R[tmp2].value;
                        Rx.value = val_tmp;
                        Rx.isReq = 1;
                        Rx.key[x]= tmp1;
                        Rx.key[x+1] = tmp2;
                        Rx.conn_type = 'S';
                        val_tmp = val_tmp - R[tmp2].value;
                        
        
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
                        Rx.value = val_tmp;
                        Rx.isReq = 1;
                        Rx.key[x]= tmp1;
                        Rx.key[x+1] = tmp2;
                        Rx.conn_type = 'P';
                        
                        
                    }
                    
                    j++;
                }
                count = 0;
                i = j;
            }
            ++i;
        }
    }
    else{
        for(int i = 0;i<strlen(R_str);i++){
            
            if (R_str[i] == 'R'){
                tmp1 = atoi(&R_str[i+1]);
                Rx.key[n] = tmp1;
                n++;
                last_R = tmp1;
            }

            if (R_str[i]=='S') {Rx.conn_type = 'S';}
            if (R_str[i]=='P') {Rx.conn_type = 'P';}
        }

    }
    *Ro = Rx;
    
    return last_R;
}

int main(){

    struct Branch R[5];
    struct Branch C[5];
    struct tempBranch Rp,Ro;
    struct tempBranch Cp;
    R[1].value = 10;
    R[2].value = 20;
    R[3].value = 30;
    C[1].value = 2000;
    C[2].value = 6000;
    C[3].value = 3000;
    C[4].value = 5000;

    int lastidx;
    // Dua besaran Vs dan Is didapat dari proses simplifikasi RC (bagian zulfikar)
    // Vs dalam satuan V
    float Vs = 30;

    // Req dalam satuan Ohm
    float Req = 60;

    // Ceq dalam satuan nF
    float Ceq = 470;

    // tau dalam satuan nanosecond
    float tau = Req*Ceq;

    // Is dalam satuan A
    float Is = Vs/Req;

    // Masih Test awal, command seri dan paralel di hard code
    char R_str[50];
    strcpy(R_str,"R1 S R2 S R3");

    char C_str[50];
    strcpy(C_str,"(C1 S C2) P C3");
    

    /* Menyederhanakan rangkaian agar bisa dipecah (menghilangkan bracket dari string)
    
        Struct Branch Rp akan berbentuk array yang berisi nilai nilai R (sudah disederhanakan) 
        agar I bisa dipecah

    */

   
    lastidx = getEqCircuit(R,R_str,Rp,&Ro);

    addRdata(R,Ro,lastidx,Is,Vs,R_str);

    
    
    printf("V = %.2f %.2f %.2f\n",R[1].V,R[2].V,R[3].V);

    printf("I = %.2f %.2f %.2f\n",R[1].I,R[2].I,R[3].I);

    return 0;


}