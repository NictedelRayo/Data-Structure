#include <stdio.h>

typedef struct nodoi{
   char elem[30];
   struct nodoi *next;
}nodoi;

char *Crear(int nf);
int H(char *palabra, int tam);
int Insertar(char item, char *mat, int tam);

int main()
{
    nodoi *tabla;
    int cosa;
    char palabra[20];
    tabla=Crear(5);
    
    printf("%p%p",tabla[0].next,tabla[0]);
    scanf("%s",palabra);
    cosa=H(palabra,8);
    printf("%d",cosa);
    
    return 0;
}

char *Crear(int nf){
    nodoi *matriz=0;
    nodoi *T=0;

   if((matriz= malloc(sizeof(nodoi)*nf))==0){
       printf("error");
       return 1;
   }
    
    for(int i=0;i<nf;i++){
        matriz[i].next=&matriz[i];
    }
    return matriz;
}

int H(char *palabra, int tam){
    char k[2]={'0','0'};
    int l;
    
    l=strlen(palabra);
    
    for(int j=0;j<l;j++){
            
            if(palabra[j]=='a' || palabra[j]=='e' || palabra[j]=='i' || palabra[j]=='o' || palabra[j]=='u'){
                if(k[0]=='0'){
                   k[0]=palabra[j]; 
                }
            }else if(k[1]=='0'){
                
                k[1]=palabra[j];
                
            }
            
        
    }
    
    for(int j=0;j<l;j++){
        
            
        if(palabra[j]=='a' || palabra[j]=='e' || palabra[j]=='i' || palabra[j]=='o' || palabra[j]=='u'){
            if(k[1]=='0' && palabra[j]!=k[0]){
               k[1]=palabra[j]; 
            }
        }else if(k[0]=='0' && palabra[j]!=k[1]){
            
            k[0]=palabra[j];
            
        }
    }
    
    return (k[0]+k[1]+l)%tam; 
   
}

