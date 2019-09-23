/*Una empresa naviera tiene 10 destinos en el caribe y su barco realiza viajes circulares entre ellos, 
o sea que sale de un puerto y retorna al mismo pasando por todos los puertos intermedios.
Los pasajeros pueden tomar este tipo de viaje o subir en uno y bajar en otro.
 
                     Se tiene la siguiente información:

    • Número de puerto
    • Nombre

         Además: 

    • Número de puerto de salida 
    • Número de puerto de llegada
    • Cantidad de pasajeros
       
Se desea saber: 

    a. Cantidad de pasajeros que salieron de un puerto
    b. Cantidad de pasajeros que llegaron a un puerto
    c. Cantidad de pasajeros que hicieron viajes circulares
    d. Puerto donde arribaron más pasajeros 
    e. Puerto de donde salieron menos pasajeros
    f. Porcentual que representan los pasajeros que hicieron viajes circulares sobre el total
    g. Imprimir ordenado en forma ascendente el punto b 
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//DECLARO FUNCIONES

void CARGA(char [][30], int [], int [], int [][11]);
void puntoA(int []);
void puntoB(int []);
void puntoC(int [][11]);
void puntoD(int [11]);
void puntoE(int [11]);
void puntoF(int [][11], int []);
void puntoG(int [11]);
void menu();

int main() {
int pentrada, psalida, cantp, np, vsalida[11]={0}, vcantidad[11]={0};
int  varribo[11]={0}, mcircular[11][11]={0};

char mnomb[11][30];

CARGA(mnomb, &np, &psalida, &cantp, &pentrada);
puntoA(vsalida);
puntoB(varribo);
puntoC(mcircular);
puntoD(varribo);
puntoE(vsalida);
puntoF(mcircular, vcantidad);
puntoG(varribo);
menu();

}
//DEFINIMOS FUNCIONES

void CARGA(char mnomb[10][30], int vsalida[11], int varribo[11], int mcircular[11][11],int vcantidad[11])
{
	int np, psalida, pentrada, cantp, i;
system("cls");

	for(i=1;i<=10;i++) 
	{

		printf("ingrese numero de puerto: ");
		scanf("%d",&np);
		printf("ingrese nombre del puerto: ");
		fflush(stdin);
		gets(mnomb[np]);

	}

		printf("\ningrese puerto de salida :");
		scanf("%d",&psalida);
	while(psalida!=0)
	{

		printf("\ningrese cantidad de pasajeros :");
		scanf("%d",&cantp);
	
		printf("\ningrese puerto de entrada :");
		scanf("%d",&pentrada);
		
		vcantidad[cantp]=vcantidad[cantp]+cantp;
		vsalida[psalida]=vsalida[psalida]+cantp;
		mcircular[psalida][pentrada]=mcircular[psalida][pentrada]+cantp;
		varribo[pentrada]=varribo[pentrada]+cantp;

		printf("\ningrese puerto de salida :");
		scanf("%d",&psalida);
	}
system("pause");
system("cls");
}

void puntoA(int vsalida[11])
{
	int i;
	system("cls");
	for(i=1;i<=10;i++){

		printf("\nla cantidad de pasajeros que salieron del puerto %d es: %d",i,vsalida[i]);
	}
system("pause");
system("cls");
}

void puntoB(int varribo[11])
{
	int i;
	system("cls");
	for(i=1;i<=10;i++){
	
	printf("\nla cantidad de pasajeros que llegaron al puerto %d es: %d",i,varribo[i]);
	}
system("pause");
system("cls");
}

void puntoC(int mcircular[11][11])
{
	int f, tot;
	system("cls");
	for(f=1;f<=10;f++){
			
		tot=tot+mcircular[f][f];
			
	}	

		printf("\nla cantidad de pasajeros que hicieron viajes circulares  es: %d",tot);

system("pause");
system("cls");
}

void puntoD(int varribo[11])
{
	int i, aux, max, mnomb[aux];
	system("cls");
	for(i=1;i<=10;i++){

		if(varribo[i]>max){
			max=varribo[i];
			aux=i;
		}
	}
		printf("\nel puerto con mas arribo es el: %s", mnomb[aux]); 

system("pause");
system("cls");		
}	

void puntoE(int vsalida[11])
{
	int i, aux, mnomb[aux], min;
	system("cls");
	for(i=1;i<=10;i++){
		
		if(vsalida[i]<min){
			min=vsalida[i];
			aux=i;
		}
	
	}
		
		printf("\nel puerto con menos salidas es el: %s", mnomb[aux]);	

system("pause");
system("cls");		
}

void puntoF(int mcircular[11][11], int vcantidad[11])
{	
	int f, tot=0, circulares, i;
	float por; 
	system("cls");
	for(f=1;f<=10;f++)
	{
			
		circulares=circulares+mcircular[f][f];
	
	}
		for(i=1;i<=10;i++)
		{
			tot += vcantidad[i];
		}
		
	
		por = circulares*100/tot;
		
			printf("\nporcentual que representan los pasajeros que hicieron viajes circulares sobre el total es: %5.2f", por);
}

void puntoG(int varribo[11])
{
	int i, j, aux;
	system("cls");
	for (i=1;i<=9;i++){ //metodo burbuja 
		for (j=i+1;j<=10;j++){ 
			if (varribo[j]>varribo[i]){  
				
                aux=varribo[i]; 
                varribo[i]=varribo[j]; 
                varribo[j]=aux; 

			}
		}
		
	}
		for(i=1;i<=10;i++){
			printf("\nla cantidad de pasajeros que llegaron al puerto %d es: %d",i, varribo[i]); 
		}
		
system("pause");
system("cls");		
}

void menu(){
	int option=0;
	do{
		printf("A.\tCantidad de pasajeros que salieron de un puerto.\n");
		printf("B.\tCantidad de pasajeros que llegaron a un puerto.\n");
		printf("C.\tCantidad de pasajeros que hicieron viajes circulares.\n");
		printf("D.\tPuerto donde arribaron mas pasajeros.\n");
		printf("E.\tPuerto de donde salieron menos pasajeros.\n");
		printf("F.\tPorcentual que representan los pasajeros que hicieron viajes circulares sobre el total.\n");
		printf("G.\tImprimir ordenado en forma ascendente el punto 2.\n");
		printf("8.\tSalir del programa.");
		printf("\nElegir opcion: "); 
		scanf("%d",&option);


	switch(option){
			case 1:{
				puntoA(int []);
				break;
			}
			case 2:{
				puntoB(int []);
				break;
			}
			case 3:{
				puntoC(int [][11]);
				break;
			}
			case 4:{
				puntoD(int [11]);
				break;
			}
			case 5:{
				puntoE(int vsalida[11]);
				break;
			}
			case 6:{
				puntoF(int mcircular[11][11], int vcantidad[11]);
				break;
			}
			case 7:{
				puntoG(int varribo[11]);
				break;
			}
			default:
			system("pause");
			printf("Ingresar una opcion correcta(1-7)");
			system("cls");
			break;
		}
		
	}while(option!=8);
}
