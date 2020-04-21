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

void addCdata(struct Branch C[], struct tempBranch Cp,int last_C, double Is,float Vs,char C_str[]){

    float Ip_temp = (Cp.value *Is)/(Cp.value+C[last_C].value);
    float Vp_temp = (Cp.value *Vs)/(Cp.value+C[last_C].value);
    
    if (isExistBracket(C_str)){

        if (Cp.conn_type == 'S'){
        
            C[Cp.key[0]].I = Ip_temp;
            C[Cp.key[1]].I = Ip_temp;
            C[last_C].I = Is - Ip_temp;

            C[Cp.key[0]].V = C[Cp.key[0]].value*Vs/(C[Cp.key[0]].value + C[Cp.key[1]].value);
            C[Cp.key[1]].V = C[Cp.key[1]].value*Vs/(C[Cp.key[0]].value + C[Cp.key[1]].value);
            C[last_C].V = Vs;

        }  

        if (Cp.conn_type == 'P'){

            C[Cp.key[0]].V = Vp_temp;
            C[Cp.key[1]].V = Vp_temp;
            C[last_C].V = Vs - Vp_temp;

            C[Cp.key[0]].I = C[Cp.key[0]].value*Is/(C[Cp.key[0]].value + C[Cp.key[1]].value);
            C[Cp.key[1]].I = C[Cp.key[1]].value*Is/(C[Cp.key[0]].value + C[Cp.key[1]].value);
            C[last_C].I = Is;

        }   
    }
    else{

        if (Cp.conn_type == 'S'){
            
            C[Cp.key[0]].I = Is;
            C[Cp.key[1]].I = Is;
            C[Cp.key[2]].I = Is;

            C[Cp.key[0]].V = C[Cp.key[0]].value*Vs/(C[Cp.key[0]].value + C[Cp.key[1]].value + C[Cp.key[2]].value );
            C[Cp.key[1]].V = C[Cp.key[1]].value*Vs/(C[Cp.key[0]].value + C[Cp.key[1]].value + C[Cp.key[2]].value );
            C[Cp.key[2]].V = C[Cp.key[2]].value*Vs/(C[Cp.key[0]].value + C[Cp.key[1]].value + C[Cp.key[2]].value );
        }

        if (Cp.conn_type == 'P'){

            C[Cp.key[0]].V = Vs;
            C[Cp.key[1]].V = Vs;
            C[Cp.key[2]].V = Vs;

            C[Cp.key[0]].V = C[Cp.key[0]].value*Is/(C[Cp.key[0]].value + C[Cp.key[1]].value + C[Cp.key[2]].value );
            C[Cp.key[1]].V = C[Cp.key[1]].value*Is/(C[Cp.key[0]].value + C[Cp.key[1]].value + C[Cp.key[2]].value );
            C[Cp.key[2]].V = C[Cp.key[2]].value*Is/(C[Cp.key[0]].value + C[Cp.key[1]].value + C[Cp.key[2]].value );

        }

    }

}

int isExistBracket(char str[]){
    for(int i = 0; i<strlen(str);++i){
        if(str[i] =='('){
            return 1;
        }
    }
    return 0;
}
int getREquivalent(struct Branch R[],char R_str[],struct tempBranch Rx,struct tempBranch *Ro){
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

int getCEquivalent(struct Branch C[],char C_str[],struct tempBranch Cx,struct tempBranch *Co){
    int last_C;
    float val_tmp;
    
    int i=0,j,k,x = 0,n = 0;
    int b_count = 0,count = 0;
    int tmp1 = 0, tmp2 = 0;
    if (isExistBracket(C_str)){
        while(i < strlen(C_str)){

            if (C_str[i] == 'C'){
                tmp1 = atoi(&C_str[i+1]);
                Cx.key[2] = tmp1;
                last_C = tmp1;
            }
            if (C_str[i] == '('){
            
                j = i+1;
                
                while (C_str[j] != ')'){
                    
                    if(C_str[j] == 'P'){
                        tmp1 = atoi(&C_str[j-2]);
                        
                        val_tmp = val_tmp + C[tmp1].value;
                        tmp2 = atoi(&C_str[j+3]);
                        val_tmp = val_tmp + C[tmp2].value;
                        Cx.value = val_tmp;
                        Cx.isReq = 1;
                        Cx.key[x]= tmp1;
                        Cx.key[x+1] = tmp2;
                        Cx.conn_type = 'P';
                        val_tmp = val_tmp - C[tmp2].value;
                        
        
                    }

                    if(C_str[j] == 'S'){

                        tmp1 = atoi(&C_str[j-2]);
                        tmp2 = atoi(&C_str[j+3]);

                        if (!count){
                            int y = C[tmp1].value;
                        
                            val_tmp = y;
                            count++;
                        }
                        
                        val_tmp = (val_tmp * C[tmp2].value)/(val_tmp + C[tmp2].value);
                        Cx.value = val_tmp;
                        Cx.isReq = 1;
                        Cx.key[x]= tmp1;
                        Cx.key[x+1] = tmp2;
                        Cx.conn_type = 'S';
                        
                        
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
        for(int i = 0;i<strlen(C_str);i++){
            
            if (C_str[i] == 'C'){
                tmp1 = atoi(&C_str[i+1]);
                Cx.key[n] = tmp1;
                n++;
                last_C = tmp1;
            }

            if (C_str[i]=='S') {Cx.conn_type = 'S';}
            if (C_str[i]=='P') {Cx.conn_type = 'P';}
        }
        
    }
    *Co = Cx;
    
    return last_C;
}

void printToFileExt(FILE** fptr,struct Branch R[], struct Branch C[], char VorI, char RorC, int cst, float tau, float Is, float Vs){
    float t = 0;
    if (VorI == 'V' && RorC =='R'){
        
        t = tau/(double)88;
        // print t mendekati 0 agar grafik mulus
        fprintf(*fptr,"%.2f",t);
        fprintf(*fptr,";");
        double y = exp(-t/tau);
        fprintf(*fptr,"%.2f\n",Vs-((R[cst].V)*y));
        
        while (t < 5*tau){
            
            fprintf(*fptr,"%.2f",t);
            fprintf(*fptr,";");
            double y = exp(-t/tau);
            fprintf(*fptr,"%.2f\n",Vs-((R[cst].V)*y));
            t = t + tau/(double)10;

        }
    }

    if (VorI == 'V' && RorC == 'C'){
        
        t = tau/(double)88;
        // print t mendekati 0 agar grafik mulus
        fprintf(*fptr,"%.2f",t);
        fprintf(*fptr,";");
        double y = exp(-t/tau);
        fprintf(*fptr,"%.2f\n",(C[cst].V - (C[cst].V)*y));
        
        while (t < 5*tau){
            
            fprintf(*fptr,"%.2f",t);
            fprintf(*fptr,";");
            double y = exp(-t/tau);
            fprintf(*fptr,"%.2f\n",(C[cst].V - (C[cst].V)*y));
            t = t + tau/(double)10;

        }
    }

    if (VorI == 'I' && RorC == 'R'){
        
        t = tau/(double)88;
        // print t mendekati 0 agar grafik mulus
        fprintf(*fptr,"%.2f",t);
        fprintf(*fptr,";");
        double y = exp(-t/tau);
        fprintf(*fptr,"%.2f\n",((R[cst].I)*y));
        
        while (t < 5*tau){
            
            fprintf(*fptr,"%.2f",t);
            fprintf(*fptr,";");
            double y = exp(-t/tau);
            fprintf(*fptr,"%.2f\n",((R[cst].I)*y));
            t = t + tau/(double)10;

        }
    }

    if (VorI == 'I' && RorC == 'C'){
        
        t = tau/(double)88;
        // print t mendekati 0 agar grafik mulus
        fprintf(*fptr,"%.2f",t);
        fprintf(*fptr,";");
        double y = exp(-t/tau);
        fprintf(*fptr,"%.2f\n",((C[cst].I)*y));
        
        while (t < 5*tau){
            
            fprintf(*fptr,"%.2f",t);
            fprintf(*fptr,";");
            double y = exp(-t/tau);
            fprintf(*fptr,"%.2f\n",((C[cst].I)*y));
            t = t + tau/(double)10;

        }
    }
}

int main(){

    struct Branch R[5];
    struct Branch C[5];
    struct tempBranch Rp,Ro;
    struct tempBranch Cp,Co;
    R[1].value = 10;
    R[2].value = 20;
    R[3].value = 30;
    C[1].value = 5;
    C[2].value = 30;
    C[3].value = 6;
    int lastidx;
    // Dua besaran Vs dan Is didapat dari proses simplifikasi RC (bagian zulfikar)
    // Vs dalam satuan V
    float Vs = 30;

    float a = 3;
    float b = 2;
  
    // Req dalam satuan Ohm
    float Req = 60/(double)11;
    
    // Ceq dalam satuan nF
    float Ceq = 10;

    // tau dalam satuan nanosecond
    double tau = Req*Ceq;

    // Is dalam satuan A
    float Is = Vs/Req;
    

    // Masih Test awal, command seri dan paralel di hard code
    char R_str[50];
    strcpy(R_str,"R1 P R2 P R3");

    char C_str[50];
    strcpy(C_str,"C1 P (C2 S C3)");
    

    /* Menyederhanakan rangkaian agar bisa dipecah (menghilangkan bracket dari string)
    
        Struct Branch Rp akan berbentuk array yang berisi nilai nilai R (sudah disederhanakan) 
        agar I bisa dipecah

    */

   
    lastidx = getREquivalent(R,R_str,Rp,&Ro);

    addRdata(R,Ro,lastidx,Is,Vs,R_str);

    lastidx = getCEquivalent(C,C_str,Cp,&Co);
    addCdata(C,Co,lastidx,Is,Vs,C_str);

    FILE * fptrVR1 = fopen("VR1.txt","w");
    FILE * fptrVR2 = fopen("VR2.txt","w");
    FILE * fptrVR3 = fopen("VR3.txt","w");
    FILE * fptrIR1 = fopen("IR1.txt","w");
    FILE * fptrIR2 = fopen("IR2.txt","w");
    FILE * fptrIR3 = fopen("IR3.txt","w");
    FILE * fptrVC1 = fopen("VC1.txt","w");
    FILE * fptrVC2 = fopen("VC2.txt","w");
    FILE * fptrVC3 = fopen("VC3.txt","w");
    FILE * fptrIC1 = fopen("IC1.txt","w");
    FILE * fptrIC2 = fopen("IC2.txt","w");
    FILE * fptrIC3 = fopen("IC3.txt","w");
    printToFileExt(&fptrVR1,R,C,'V','R',1,tau,Is,Vs);
    printToFileExt(&fptrVR2,R,C,'V','R',2,tau,Is,Vs);
    printToFileExt(&fptrVR3,R,C,'V','R',3,tau,Is,Vs);
    printToFileExt(&fptrVC1,R,C,'V','C',1,tau,Is,Vs);
    printToFileExt(&fptrVC2,R,C,'V','C',2,tau,Is,Vs);
    printToFileExt(&fptrVC3,R,C,'V','C',3,tau,Is,Vs);
    printToFileExt(&fptrIR1,R,C,'I','R',1,tau,Is,Vs);
    printToFileExt(&fptrIR2,R,C,'I','R',2,tau,Is,Vs);
    printToFileExt(&fptrIR3,R,C,'I','R',3,tau,Is,Vs);
    printToFileExt(&fptrIC1,R,C,'I','C',1,tau,Is,Vs);
    printToFileExt(&fptrIC2,R,C,'I','C',2,tau,Is,Vs);
    printToFileExt(&fptrIC3,R,C,'I','C',3,tau,Is,Vs);
    fclose(fptrVR1);
    fclose(fptrVR2);
    fclose(fptrVR3);
    fclose(fptrVC1);
    fclose(fptrVC2);
    fclose(fptrVC3);
    fclose(fptrIR1);
    fclose(fptrIR2);
    fclose(fptrIR3);
    fclose(fptrIC1);
    fclose(fptrIC2);
    fclose(fptrIC3);
    
    
    
    printf("VR = %.2f %.2f %.2f\n",R[1].V,R[2].V,R[3].V);

    printf("IR = %.2f %.2f %.2f\n",R[1].I,R[2].I,R[3].I);

    printf("VC = %.2f %.2f %.2f\n",C[1].V,C[2].V,C[3].V);

    printf("IC = %.2f %.2f %.2f\n",C[1].I,C[2].I,C[3].I);

    return 0;


}