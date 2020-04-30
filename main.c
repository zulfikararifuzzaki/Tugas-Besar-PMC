#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
typedef struct ekivalen
{
	float V;
	float I;
	float R;
	float C;

}ekivalen;

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
    float t = 0.0001;
    if (VorI == 'V' && RorC =='R'){
        
        // print t mendekati 0 agar grafik mulus
        fprintf(*fptr,"%.4f",t);
        fprintf(*fptr,";");
        double y = exp(-t/tau);
        fprintf(*fptr,"%.4f\n",((R[cst].V)*y));
        t = tau/(double)88;
        while (t < 5*tau){
            
            fprintf(*fptr,"%.4f",t);
            fprintf(*fptr,";");
            double y = exp(-t/tau);
            fprintf(*fptr,"%.4f\n",((R[cst].V)*y));
            t = t + tau/(double)10;

        }
    }

    if (VorI == 'V' && RorC == 'C'){
        
        // print t mendekati 0 agar grafik mulus
        fprintf(*fptr,"%.4f",t);
        fprintf(*fptr,";");
        double y = exp(-t/tau);
        fprintf(*fptr,"%.4f\n",(C[cst].V - (C[cst].V)*y));
        t = tau/(double)88;
        while (t < 5*tau){
            
            fprintf(*fptr,"%.4f",t);
            fprintf(*fptr,";");
            double y = exp(-t/tau);
            fprintf(*fptr,"%.4f\n",(C[cst].V - (C[cst].V)*y));
            t = t + tau/(double)10;

        }
    }

    if (VorI == 'I' && RorC == 'R'){
        
        // print t mendekati 0 agar grafik mulus
        fprintf(*fptr,"%.4f",t);
        fprintf(*fptr,";");
        double y = exp(-t/tau);
        fprintf(*fptr,"%.4f\n",((R[cst].I)*y));
        t = tau/(double)88;
        while (t < 5*tau){
            
            fprintf(*fptr,"%.4f",t);
            fprintf(*fptr,";");
            double y = exp(-t/tau);
            fprintf(*fptr,"%.4f\n",((R[cst].I)*y));
            t = t + tau/(double)10;

        }
    }

    if (VorI == 'I' && RorC == 'C'){
        
        
        // print t mendekati 0 agar grafik mulus
        fprintf(*fptr,"%.4f",t);
        fprintf(*fptr,";");
        double y = exp(-t/tau);
        fprintf(*fptr,"%.4f\n",((C[cst].I)*y));
        t = tau/(double)88;
        while (t < 5*tau){
            
            fprintf(*fptr,"%.4f",t);
            fprintf(*fptr,";");
            double y = exp(-t/tau);
            fprintf(*fptr,"%.4f\n",((C[cst].I)*y));
            t = t + tau/(double)10;

        }
    }
}

float paralel (float X1, float X2){
	return((float)X1*X2/(float)(X1+X2));}

char bentukR[64];
char bentukC[64];

float cariNilaiEq(char* strinput, char jenis)
{

	// input berupa string dari file eksternal
	// jenis berupa R atau C untuk resistor atau kapasitor
	// keluaran R atau C ekivalen dari resistor
	
	char delim = ' ';
	char* temp = (char*)malloc(sizeof(char)); strcpy(temp, "");
	int bentuk;
	float X1;
	float X2;
	float X3;
	
	int i =0;
	int k = 0;
	
	float output;
	
	while(strinput[i] != '\0')
	{
		if(strinput[i] != delim){
			strncat(temp, &strinput[i], 1);
		}
		else{
			if(k==0){
				bentuk = atof(temp);}
			else if (k==1){
				X1 = atof(temp);}
			else if (k==2){
				X2 = atof(temp);}
			else if (k==3){
				X3 = atof(temp);}
			strcpy(temp, "");
			++k;
        }
		++i;
    }
	X3 = atof(temp);

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
			strcpy(bentukR, "R1 P (R2 S R3)");}
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

void cariNetList(char* filename,ekivalen input_dummy, ekivalen* output)
{   
    // menerima input nama file dalam bentuk string
	// memproses untuk mengisis V, R, dan C
	// output berupa V, R, dan C ekivalen
	
	FILE *stream;
	
	char* Vout = (char*)malloc(50*sizeof(char));
	char* Rout = (char*)malloc(50*sizeof(char));
	char* Cout = (char*)malloc(50*sizeof(char));
	
	stream = fopen(filename, "r");
	
	fgets(Vout, 100*sizeof(char), stream);
	fgets(Rout, 100*sizeof(char), stream);
	fgets(Cout, 100*sizeof(char), stream);

	input_dummy.V = atof(Vout);
	input_dummy.R = cariNilaiEq(Rout, 'R');
	input_dummy.C = cariNilaiEq(Cout, 'C');
	input_dummy.I = input_dummy.V/(float)input_dummy.R;
    *output = input_dummy;
	fclose(stream);
	
}

void getValueComponent(char* filename, struct Branch Rd[5],struct Branch Cd[5], struct Branch **Routput,struct Branch **Coutput){

    // mencari stringinput
    FILE *stream;
	
	char* Vout = (char*)malloc(50*sizeof(char));
	char* Rout = (char*)malloc(50*sizeof(char));
	char* Cout = (char*)malloc(50*sizeof(char));
	
	stream = fopen(filename, "r");
	
	fgets(Vout, 100*sizeof(char), stream);
	fgets(Rout, 100*sizeof(char), stream);
	fgets(Cout, 100*sizeof(char), stream);


    // Memulai proses assign ke struct R
	char delim = ' ';
	char* temp = (char*)malloc(sizeof(char)); strcpy(temp, "");
	int bentuk;
    float X1,X2,X3;
	int i =0;
	int k = 0;
	
    while(Rout[i] != '\0')
	{
		if(Rout[i] != delim){
			strncat(temp, &Rout[i], 1);
		}
		else{
			if(k==0){
				bentuk = atof(temp);}
			else if (k==1){
				X1 = atof(temp);
                Rd[1].value = X1;}
			else if (k==2){
				X2 = atof(temp);
                Rd[2].value = X2;}
			else if (k==3){
				X3 = atof(temp);}
			strcpy(temp, "");
			++k;
        }
		++i;
    }
	X3 = atof(temp);
    Rd[3].value = X3;

    *Routput = Rd;

    // Mengassign value ke struct C
    i =0;
	k = 0;
	strcpy(temp, "");
    while(Cout[i] != '\0')
	{
		if(Cout[i] != delim){
			strncat(temp, &Cout[i], 1);
		}
		else{
			if(k==0){
				bentuk = atof(temp);}
			else if (k==1){
				X1 = atof(temp);
                Cd[1].value = X1;}
			else if (k==2){
				X2 = atof(temp);
                Cd[2].value = X2;}
			else if (k==3){
				X3 = atof(temp);}
			strcpy(temp, "");
			++k;
        }
		++i;
    }
	X3 = atof(temp);
    Cd[3].value = (float)X3;

    *Coutput = Cd;
    fclose(stream);
}

char* getString()
{	
    char* output = (char*)malloc(sizeof(char));
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

void executeAllProcess(){

    ekivalen dummy; ekivalen dataEq;
    char R_str[50], C_str[50];

    // data data dari netlist diassign ke dataEq
    cariNetList("contoh.txt",dummy,&dataEq);
    strcpy(R_str,bentukR);
    strcpy(C_str,bentukC);

    // Inisialisasi variabel untuk mencari tegangan arus masing masing branch
    struct Branch R_dummy[5],C_dummy[5], *R,*C;
    struct tempBranch Rp,Ro;
    struct tempBranch Cp,Co;
    int lastidx;
    
    float Vs = dataEq.V;                // Volt
    float Req = (float)dataEq.R;        // K Ohm
    float Is = Vs/(float)Req;           // mA
    float Ceq = (float)dataEq.C;        // uF
    double tau = (double)Req*Ceq;       // millisecond

    //assign value masing masing komponen ke struct Branch R dan C.
    getValueComponent("contoh.txt",R_dummy,C_dummy,&R,&C);

    // Memulai proses memecah branch dan mencetak sample point grafik ke file eksternal
    lastidx = getREquivalent(R,R_str,Rp,&Ro);
    addRdata(R,Ro,lastidx,Is,Vs,R_str);

    lastidx = getCEquivalent(C,C_str,Cp,&Co);
    addCdata(C,Co,lastidx,Is,Vs,C_str);

    printf("VR = %.4f %.4f %.4f\n",R[1].V,R[2].V,R[3].V);

    printf("IR = %.4f %.4f %.4f\n",R[1].I,R[2].I,R[3].I);

    printf("VC = %.4f %.4f %.4f\n",C[1].V,C[2].V,C[3].V);

    printf("IC = %.4f %.4f %.4f\n",C[1].I,C[2].I,C[3].I);
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

}
int main(){

    executeAllProcess();
	return(0);
    
}
