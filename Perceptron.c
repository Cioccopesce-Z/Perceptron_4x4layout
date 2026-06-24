#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

int y=0;
int leve[16],l=0,v=0;
int value[16],a=0,z=0;
int check[16],h=0,s=0;
int output=0,c=0;
int actparaval=0,bias=0,n=0; 
// u,i,p,d,f,

void drawlev(){ //disegna le leve sullo schermo mostrando se accesa o spenta nella posizione della rispettiva leva in leve[16]
	system("cls"); // esempio se in selectleve() e stata attivata la leva 5 quindi input(5,1) --> leve[5]==1
	printf("lever \n"); 
	for(int i = 0 ; i<16; i++){
		printf ("%d ",leve[i]); 
		if(i%4==3){
			printf("\n");
		}
	}
}

void selectlev(){ //richiede in ingresso la posizione della leva che si vuole attivare e se la si vuole attivare  
	printf("choose number lev and theyr value: \n"); // salva in leve[] alla posizione x (leve[x]) lo stao della leva
	scanf("%d ",&l); scanf("%d",&v); // se input 5 e 1 allora leve[5]==1
	leve[l-1]=v;
}

void drawval(){ // disegna alla posizione della leva scelta l'importanza associata in value[] nella sua rispettiva posizione sulla griglia 
	printf ("\nimportance \n"); // se si ha dato 10 di importanza alla leva 5 allora --> value[5]==10 
		for(int p = 0; p<16; p++){
			printf ("%d ",value[p]); 
			if(p%4==3){
				printf("\n");
		
		}
	}
}

void selectval(){ // richiede in ingresso la posizione della leva alla quale si vuole assegnare una importanza e il valore della importanza
	printf("choose number lev and theyr importance: \n"); // salva in value[] alla posizione desiderata (value[x]) l'importanza assegnata
	scanf ("%d ",&a); scanf ("%d",&z); // esempio input(5,10) allora value[5]==10
	value[a-1] += z;
	printf("\n");
}

 void drawcheck(){ // disegna a schermo, alla posizione della leva desiderata salvata come x in check[x], il suo stato (1,0)
 		system("cls");
 		printf ("\ncheck \n");
		for(int d=0; d<16; d++){
			printf ("%d ",check[d]); 
			if(d%4==3){
				printf("\n");
		
		}
	}
 }
 
 void checkval(){ //chiede di associare uno stato o attiva(1) o spenta(0) a ciascuna leva, la posizione della leva e' indicata in check[x]
	printf("choose number lev and set if on: \n"); // lo stato(y) della leva alla posizione x e' salvato in check[x]==y
	scanf ("%d ",&h); scanf ("%d",&s);
	check[h-1] += s;
	printf("\n");
}

void caloutput(){
	printf("insert bias:"); //uoutput==check[tutte le leve con stato 1]*value[valore corrispondente a ciascuna leva con stato 1 in check]
	scanf("%d", &bias);
	system("cls");
	for(int u = 0; u<16; u++){
		c=check[u]; // se u==5 e check[5]==1
		if(c==1){
			output += value[u]; // ma value[5]==0 allora anche se è stata attiva una leva in check non è detto che l'output aumenti 
		} //poiche per assegnare i valori all'output la macchina fa riferimenta a cio che ha imparato
	}
	output += bias;
}

void actpara(){
	for(int f = 0; f<16; f++){
		n += value[f];
	}
	actparaval= n/16;
	if( output < actparaval){
		printf("%d pattern recognised or pattern 1 \n", actparaval);
	} else {
		printf("%d pattern not recognised or pattern 2 \n", actparaval);
	}	
}
 
int main(){
	start: ;
	while(y != 1){
		drawlev();
		selectlev();
		printf("done switching? ");
		scanf("%d", &y);
	}
	y=0;
	while(y != 1){
		drawlev();
		drawval();
		selectval();
		printf("done giving value? ");
		scanf("%d", &y);
	}
	y=0;
	while(y != 1){
		drawcheck();
		checkval();
		printf("done testing? ");
		scanf("%d", &y);
	}
	y=0;
	
	system("cls");
	caloutput();
	printf("%d \n", output);
	actpara();
	
	printf("do you want to test again? ");
	scanf("%d", &y);
	if(y==1){
		system("cls");
		goto start;
	} else {
		return 0;
	}
}