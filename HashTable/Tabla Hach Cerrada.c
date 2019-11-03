#include <string.h>
#include <stdio.h>
#include  <math.h>

typedef struct{
    char id[3];
    int seq;
    char cad;
    int ident;
}datos;

datos *Tabla(int b);
int H(char *id,int seq, char cad, int b);
int Buscar(char *id,int seq, char cad, int b, datos *tabla);
int Insertar(char *id, int seq, char cad, int b, datos *tabla);
int Eliminar(char *id, int seq, char cad, int b, datos *tabla);
void Listar(int b,datos *tabla);

int main(){
	datos cosa,*tabla;
	int b,op;
	
	scanf("%d",&b);
	tabla=Tabla(b);

    for(int i=0; i<b;i++){
        tabla[i].ident=0;
    }
    
	do{
	    scanf("%d",&op);
	    switch(op){
	        case 1:
	            scanf("%s %d %c",&cosa.id,&cosa.seq,&cosa.cad);
	            Insertar(cosa.id,cosa.seq,cosa.cad,b,tabla);
	            break;
	       case 2:
	            scanf("%s %d %c",&cosa.id,&cosa.seq,&cosa.cad);
	            Buscar(cosa.id,cosa.seq,cosa.cad,b,tabla);
	            break;
	       case 3:
	            scanf("%s %d %c",&cosa.id,&cosa.seq,&cosa.cad);
	            Eliminar(cosa.id,cosa.seq,cosa.cad,b,tabla);
	            break;
	       case 4:
	            Listar(b,tabla);
	            break;
	    }
    	
	}while(op!=4);
}

datos *Tabla(int b){
    datos *tabla;
    if((tabla=malloc(sizeof(datos)*b))==0){
        return 0;
    }
    
    return tabla;
}

int H(char *id,int seq, char cad, int b){
    int c;
    
    if(cad=='a'){
        c=1;
    }else if(cad=='b'){
        c=2;
    }else if(cad=='c'){
        c=3;
    }
    
    int d,p,m;
    d=id[0]*id[1]-id[2]+seq;
    p=pow(d,c);
    m=p%b;
    if(m<0){
        
        m=m*(-1);
    }
    
    return m;
}

int Buscar(char *id,int seq, char cad, int b, datos *tabla){
    int h,cont=0;
    h=H(id,seq,cad,b);
    while(cont<=b && strcmp(tabla[h].id,id)!=0 && tabla[h].ident!=0){
        h=(h+cont)%b;
        cont=cont+1;
    }
    
    if(cont>=b){
        printf("Dato no encontrado\n");
        return 0;
    }else{
        printf("Encontrado %d\n",h);
        return 1;
    }
    
}

int Insertar(char *id,int seq,char cad,int b, datos *tabla){
    int h,cont=0;
    h=H(id,seq,cad,b);
    
    while(tabla[h].ident==9 && cont<=b){
        h=(h+cont)%b;
        cont=cont+1;
    }
    
    if(cont>=b){
        printf("Error\n");
        return 0;
    }else{
        
        tabla[h].id[0]=id[0];
        tabla[h].id[1]=id[1];
        tabla[h].id[2]=id[2];
        tabla[h].seq=seq;
        tabla[h].cad=cad;
        tabla[h].ident=9;
        printf("%d\n",h);
        
        return 1;
        
    }
}

int Eliminar(char *id, int seq, char cad, int b, datos *tabla){
    int h,cont=0;
    h=H(id,seq,cad,b);
    
    while(cont<=b && strcmp(tabla[h].id,id)!=0 && tabla[h].ident!=0 ){
        
        h = (h+cont)%b;
        cont++;
    
    }
    
    if(strcmp(tabla[h].id,id)==0){
        tabla[h].ident=1;
        for(int i=0;i<b;i++){
            tabla[h].id[i]=0;
        }
        printf("Eliminado\n");
    }else{
        printf("El dato no existe\n");
    }
}

void Listar(int b,datos *tabla){
    int i;
    
    for(i=0; i<b; i++){
        if(tabla[i].ident==9){
            printf("%s\t%d\t%c\n",tabla[i].id,tabla[i].seq,tabla[i].cad);
        }else{
            printf("Vacio\n");
        }
    }
    
}
