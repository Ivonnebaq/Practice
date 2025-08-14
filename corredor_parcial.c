#include <stdio.h>

int validar_datos(int tiempo,int distancia,int ritmo);
void calcular_tiempo(double distancia_dada,int minutos_dados,int segundos_dados,int *horas,int *minutos,int *segundos);
double calcular_distancia(int horas_dadas_tiempo,int minutos_dados_tiempo,int segundos_dados_tiempo,int minutos_dados,int segundos_dados);

int main(){
	int tiempo,distancia,ritmo,validar,distancia_dada,minutos_dados,segundos_dados;
	int horas_dadas_tiempo,minutos_dados_tiempo,segundos_dados_tiempo;
	int horas,minutos,segundos;
	double distancia_hallada;
	printf ("Debe ingresar solos dos de los ttres datos de entrada\n");
	printf ("Calcular tiempo (0:No | 1:Si):");
	scanf ("%d", &tiempo);
	printf("Calcular distancia (0:No | 1:Si):");
	scanf ("%d", &distancia);
	printf("Calcular ritmo (0:No | 1:Si):");
	scanf ("%d", &ritmo);
	
	validar=validar_datos(tiempo,distancia,ritmo);
	if(validar){
		if(distancia==0 && ritmo==0){
			printf ("Leer distancia (km):\n");
			scanf ("%lf", &distancia_dada);
			printf ("Leer ritmo 1km x mm-ss:\n");
			scanf ("%d",&minutos_dados);
			scanf ("%d",&segundos_dados);

			calcular_tiempo(distancia_dada,minutos_dados,segundos_dados,&horas,&minutos,&segundos);
			printf ("El tiempo calculado es %d horas, %d minutos y %d segundos",horas,minutos,segundos);
		}
		else{
			if(tiempo==0 && ritmo==0){
				printf ("Leer tiempo hh-mm-ss:\n");
				scanf ("%d", &horas_dadas_tiempo);
				scanf ("%d", &minutos_dados_tiempo);
				scanf ("%d", &segundos_dados_tiempo);
				printf ("Leer ritmo 1km x mm-ss:\n");
				scanf ("%d",&minutos_dados);
				scanf ("%d",&segundos_dados);
				distancia_hallada=calcular_distancia(horas_dadas_tiempo,minutos_dados_tiempo,segundos_dados_tiempo,minutos_dados,segundos_dados);
				printf ("La distancia calculada es %lf km", distancia_hallada);
			}
		}
	}
	else{
		printf ("Combinación incorrecta de valores");
	}
	return 0;
}

int validar_datos(int tiempo,int distancia,int ritmo){
	int valTiempo, valDistancia,valRitmo;
	valTiempo= (tiempo==1 && distancia==0 && ritmo==0);
	valDistancia = (distancia==1 && tiempo==0 && ritmo==0);
	valRitmo =(ritmo==1 && tiempo==0 && ritmo==0);
	return valTiempo||valDistancia||valRitmo;
	}
	
void calcular_tiempo(double distancia_dada,int minutos_dados,int segundos_dados,int *horas,int *minutos,int *segundos){
	int min_a_segundos,segundos_total,tiempo;
	min_a_segundos=minutos_dados*60;
	segundos_total=min_a_segundos+segundos_dados;
	tiempo=(int)distancia_dada*segundos_total;
	*horas=tiempo/3600;
	*minutos=(tiempo/60)%60;
	*segundos=tiempo%60;


}
double calcular_distancia(int horas_dadas_tiempo,int minutos_dados_tiempo,int segundos_dados_tiempo,int minutos_dados,int segundos_dados){
	double horas_a_segundos,minutos_a_segundos,minutos_a_segundos_ritmo;
	double segundos_total_tiempo,segundos_total_ritmo;
	double distancia_hallada;
	
	horas_a_segundos=horas_dadas_tiempo*3600;
	minutos_a_segundos=minutos_dados_tiempo*60;
	segundos_total_tiempo=horas_a_segundos+minutos_a_segundos+segundos_dados_tiempo;
	minutos_a_segundos_ritmo=minutos_dados*60;
	segundos_total_ritmo=minutos_a_segundos_ritmo+segundos_dados;
	distancia_hallada=segundos_total_tiempo/segundos_total_ritmo;
	return distancia_hallada;
}
