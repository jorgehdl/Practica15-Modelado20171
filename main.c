#include "main.h"
// No hagas #include aquí, hazlos en main.h

int main(int argc, char const *argv[])
{
    // Verifica si hay al menos de 3 parametros
    // sino entonces se imprimen las instrucciones
    // y se para la ejecución del programa
    
    if (argc < 3)
    {
        imprime_instrucciones();
        return 0;
    }
	
int o;
for(o=1;o<argc-1;o++){
FILE* input;
input = fopen(argv[o], "r");

if (input==NULL){
	printf("El nombre de unos de los archivos de entrada es invalido\n");
	return 0;
}

char buffer[200];  
int numwords=-1;
int a=0;
int i, j;
int ocurrencias;
int max=0;

char *word;
char **words = NULL;

char *most=NULL;

    while(fgets(buffer, 200 , input)){ //obtenemos la primera linea

    	word = strtok(buffer, " ,.-\n"); //dividimos en tokens

    	while(word!=NULL){

    		words = (char**)realloc(words, 100000);
    		words[a] = (char*)malloc(sizeof(word)); //iteramos en todas las palabras y las guardamos en un arreglo de caracteres
    		strcpy(words[a], word);

    		word = strtok(NULL, " ,.-\n");
    		numwords++;
    		a++;

    	}
    }

    for(i=0;i<numwords;i++){//iteramos en todo el arreglo
    	ocurrencias=0;
    	for(j=0;j<numwords;j++){
    		if(!strcmp(*(words+i),*(words+j))){//comparamos cada str, y si la misma palabra se encuentra repetida, aumentamos las ocurrencias
    			ocurrencias++;
    		}
    	}
    	if(ocurrencias>max){//si las ocurrencias son mayores al maximo, significa que es la palabra que mas se repite
    		max=ocurrencias;
    		most=*(words+i);
    	}
    }
	printf("Nombre del archivo      Palabra mas repetida         Numero de repeticiones\n%s                 %s                                %d\nSe guardo en el archivo %s\n",argv[o],most,max,argv[argc-1]);

FILE* output;
output=fopen(argv[argc-1],"a+");
fprintf(output,"Nombre del archivo      Palabra mas repetida         Numero de repeticiones\n %s                    %s                         %d\n",argv[o],most,max);
fclose(output);
}
	free(words);
    return 0;
}

/* ------ Aquí va la implementación de tus funciones ------ */
void imprime_instrucciones(){
	printf("El formato de entrada es incorrecto. El formato correcto es: /.main <archivodeentrada1.txt> <archivodeentrada2.txt> ... <archivodeentradaN.txt> <archivodesalida.txt>\n");
}