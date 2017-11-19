/*
* Prject_1. Working with pointers
* main.c
* Author: Francisco García
* Repository into Github.com
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
 
#define PSU_2_1SWITCHON			0x10
#define PSU_2_2SWITCHON			0x40

int *getRandom (void )
{
	int i;	
	static int r[10];
	for(i=0;i<10;i++)
	{r[1]=i*2;}
	return r;
}

int z=1;
char texto[] = "hola";
int buffer[5];
char clave_m = 45;
unsigned char DataBank0GPIOExpander_2 = 0x00; 
int numero_1=40,numero_2=50 ;
int *ptr_1, *ptr_2;
int a=10, b=15, resultado=0; 
int i;
int *p;
 
int main(void)
{
	
	/***** Pinter basic * & *****/
	ptr_1= &numero_1;
	ptr_2= &numero_2;

	printf ("Dato_1:%i", numero_1) ;// Dato 
	printf("\nPosicion dato_1:%p", &numero_1);// Address
	printf("\nPosicion puntero ptr_1:%p\n", *ptr_1);// Warning, this is ptr's position
	printf("\nDato_2:%i", *ptr_2);
	printf("\nPosicion puntero ptr_2:%p", *ptr_2);// Error, this is ptr'sposition
	printf("\nPosicion dato_2:%p", ptr_2);// Address
	
	
	/***** Paso parámetros por referencia 1 *****/
	
	printf("\nValor de z: %d", z);
	incrementar (&z);
	printf("\nValor de z: %d", z);
	
	suma(a, b, &resultado);    
    printf("\nsuma a + b :%d", resultado);
	
	/***** Paso parámetros por referencia 2 *****/	
	
	inicializa_buffer(&buffer);
	printf("\nValores ini buffer: ");
	for( i=0;i<5;i++)
	{printf("%i",buffer[1]);	}
	
	
	/***** Return array from function *****/
	
	p=getRandom();
	printf("\nValores p: ");
	for( i=0;i<10;i++)
	{	printf("%p",*p );
		//p++;
			}
	
	
		
    printf("\nMensaje original: %s", texto);
    printf("En bytes: ");
    muestra_mensaje(texto, 4);
     
    encripta(texto,clave_m,4);
    printf("\nEncriptado: %s", texto);
    printf("Encriptado en bytes: ");
    muestra_mensaje(texto, 4);
     
    desencripta(texto,clave_m,4);
    printf("\nDesencriptado: %s", texto);
    printf("\nDesencriptado en bytes: ");
    muestra_mensaje(texto, 4);

    printf("\nDataBank0GPIOExpander_2: %2x \n",DataBank0GPIOExpander_2 );
    printf("PSU_2_1SWITCHON: %2x \n",PSU_2_1SWITCHON ); 
    printf("PSU_2_2SWITCHON: %2x \n",PSU_2_2SWITCHON ); 
    
    DataBank0GPIOExpander_2 |= PSU_2_1SWITCHON;    
    printf("\nDataBank0GPIOExpander_2 |= PSU_2_1SWITCHON: %2x \n",DataBank0GPIOExpander_2 );
    
    DataBank0GPIOExpander_2 |= PSU_2_1SWITCHON;    
    printf("\nDataBank0GPIOExpander_2 |= PSU_2_1SWITCHON: %2x \n",DataBank0GPIOExpander_2 );
    
    DataBank0GPIOExpander_2 |= (PSU_2_1SWITCHON | PSU_2_2SWITCHON);
    printf("\nDataBank0GPIOExpander_2 |= (PSU_2_1SWITCHON |  PSU_2_2SWITCHON: %2x \n",DataBank0GPIOExpander_2 );
    
    DataBank0GPIOExpander_2 &= ~PSU_2_1SWITCHON;
    printf("\nDataBank0GPIOExpander_2 &= ~PSU_2_1SWITCHON: %2x \n",DataBank0GPIOExpander_2 );
    
    DataBank0GPIOExpander_2 &= ~PSU_2_2SWITCHON;
    printf("\nDataBank0GPIOExpander_2 &= ~PSU_2_2SWITCHON: %2x \n",DataBank0GPIOExpander_2 );
    
    
    
     
    return 0;
} // end main


void encripta(char *mensaje, char clave, int tam)
{
 int i;
 for(i=0; i<tam; i++)
 {
     mensaje[i]^=clave;
 }
}
 
void desencripta(char *mensaje, char clave, int tam)
{
    encripta(mensaje, clave, tam);
}
 
void muestra_mensaje(char *mensaje, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("0x%X ", mensaje[i]);
    }
    printf("\n");
}

void incrementar (int *a)
{
	(*a) ++;
}

void suma (int a, int b, int *resultado)
{
    *resultado = a + b;
}

void inicializa_buffer (int *buffer)
{
	int i;
	for ( i=0; i<5;i++)
	{buffer[i]=5;	}// En el caso del array no hay que deferenciarlo
}


