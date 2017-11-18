#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
 
#define PSU_2_1SWITCHON			0x10
#define PSU_2_2SWITCHON			0x40
// Comment to see how work in tortoise
 
char texto[] = "hola";
char clave_m = 45;
unsigned char DataBank0GPIOExpander_2 = 0x00;

 
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
 
int main(void)
{
    printf("Mensaje original: %s\n", texto);
    printf("En bytes: ");
    muestra_mensaje(texto, 4);
     
    encripta(texto,clave_m,4);
    printf("Encriptado: %s\n", texto);
    printf("Encriptado en bytes: ");
    muestra_mensaje(texto, 4);
     
    desencripta(texto,clave_m,4);
    printf("Desencriptado: %s\n", texto);
    printf("Desencriptado en bytes: ");
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
}


