 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
#include <stdio.h>  
#include <math.h>
#include <string.h> 
long long hexadecimal(char hex[]);
long long decimalNumber,longExp,expo,longMod,mod;
char clongExp[12],cexpo[12],clongMod[12],cmod[600];
int main()
{
	FILE *fp;
	char caracter;
  	fp = fopen ("llaveHexadecimal.txt", "r");
	if (fp == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {
	int aux=1,aux1=0,aux2=0,aux3=0,aux4=0;
            while (feof(fp) == 0)
	    {
                caracter = fgetc(fp);
		if(aux>22&&aux<31){
			if(aux==30){
				clongExp[aux1]=caracter;
				longExp=hexadecimal(clongExp);
			}else{			
				clongExp[aux1]=caracter;
			}
			aux1++;
		}
		if(aux>30&&aux<37){
			if(aux==36){
				cexpo[aux2]=caracter;
				expo=hexadecimal(cexpo);
			}else{			
				cexpo[aux2]=caracter;
			}
			aux2++;
		}
		if(aux>36&&aux<45){
			if(aux==44){
				clongMod[aux3]=caracter;
				longMod=hexadecimal(clongMod);
			}else{
				clongMod[aux3]=caracter;
			}
			aux3++;
		}
		if(aux>44){
			cmod[aux4]=caracter;
			aux4++;
		}
		aux++;
		
	    }
		mod=hexadecimal(cmod);
		printf("\n\tLongitud del exponente:\nHexadecimal %s\nDecimal: %ld\n",clongExp,longExp);
		printf("\n\tExponente:\nHexadecimal: %s\nDecimal: %ld\n",cexpo,expo);
		printf("\n\tLongitud del modulo:\nHexadecimal: %s\nDecimal: %ld\n",clongMod,longMod);
		printf("\n\tModulo:\nHexadecimal: %s\nDecimal: %ld\n",cmod,mod);
		
        }
  	fclose (fp);
	return 0;
}

long long hexadecimal(char hex[]){
	decimalNumber=0;
	char hexDigits[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	int i, j, power=0, digit;
    	for(i=strlen(hex)-1; i >= 0; i--) {
        for(j=0; j<16; j++){
            if(hex[i] == hexDigits[j]){
                decimalNumber += j*pow(16, power);
            }
        }
        power++;
    	}  
	return decimalNumber;
}




