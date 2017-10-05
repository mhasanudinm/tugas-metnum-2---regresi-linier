#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main (){
	int i,j,n;
	//input
	float x[10],y[10],m,c,hasil;
	//temp
	float x2[10],y2[10],xy[10];
	float error[10],y1[10];
	//jumlah
	float Sx=0,Sy=0,Sx2=0,Sy2=0,Sxy=0;
	float Serror=0,Sy1=0;
	
	printf("\t\t Tugas Metode Numerik \n \t\t    Regresi Linier \n\n");
	
	printf("n max = 10\n\n");
	printf("Masukan Nilai n = "); scanf("%d",&n);
	//input deret nilai
	for (i=1;i<=n;i++){
		printf("Masukan Nilai x %d:",i); scanf("%f",&x[i]);
		printf("Masukan Nilai y %d:",i); scanf("%f",&y[i]);
	}
	
	system("cls");
	
	printf("|no|\tx\t|\t y \t |\t x^2\t |\t y^2\t |\t xy\t |\t error\t|\t y^1\t|\n");
	for (j=1;j<=n;j++){	
		// isi nilai var iterasi
		x2[j] = x[j]*x[j];
		y2[j] = y[j]*y[j];
		xy[j] = x[j]*y[j];
		// isi jumlah keseluruhan
		Sx = Sx+x[j];
		Sy = Sy+y[j];
		Sxy = Sxy+xy[j];
		Sx2 = Sx2+x2[j];
		Sy2 = Sy2+y2[j];
		//hitungan m dan c
		m = ((n*Sxy)-(Sx*Sy))/((n*Sx2)-(Sx*Sx));
		c = ((Sy*Sx2)-(Sx*Sxy))/((n*Sx2)-(Sx*Sx));
		
		y1[j]= m*x[j]+c;
		error[j]= y[j]-y1[j];	
		Serror= Serror+error[j];
		Sy1= Sy1+y1[j];
		//cek agar absolut
		if(c<=0){
			c=c*(-1);
		}
		if(y1[j]<0){
			y1[j]=y1[j]*(-1);
		}
		if(error[j]<0){
			error[j]=error[j]*(-1);
			
		}
		//cetak Nilai
		printf (" %d\t",j);
		printf ("%f\t",x[j]);
		printf ("%f\t",y[j]);
		printf ("%f\t",x2[j]);
		printf ("%f\t",y2[j]);
		printf ("%f\t",xy[j]);
		printf ("%f\t",error[j]);
		printf ("%f\n",y1[j]);
	
	}
	
	
	
	printf("Jumlah x = %f\t",Sx);
	printf("y = %f\t",Sy);
	printf("x^2 = %f\t",Sx2);
	printf("y^2 = %f\t",Sy2);
	printf("xy = %f\t",Sxy);
	printf("error = %f\t",Serror);
	printf("y^1 = %f\t",Sy1);
	printf("\n\n Fungsi Utamanya\n F(x) = %f(x) + %f",m,c);
	printf("\n maka untuk F(%d) = %f(%d) + %f",n,m,n,c);
	hasil=(m*n)+c;
	printf("\n Hasilnya  +- %f",hasil);
		
	
	getch();
	
	return 0;
}
