float paralel(int r1, int r2)
{
	return(r1*r2/(r1+r2))
	}

int main()
{
	char resistor[50];
	char kapasitor[50];
	
	printf("Masukkan rangkaian resistor : ");
	scanf("%s", resistor);
	printf("Masukkan rangkaian kapasitor : ");
	scanf("%s", kapasitor);
	/* Nah sampe sini tinggal ngolah string resistor sama kapasitor
	 * (R1 S R2) P (R3)
	 * (C1 S C2) P (C3)
	 * Nah buat resistor, S tinggal diganti plus
	 * Kalo P, ntar diganti paralel, pake function paralel
	 * */
	}
