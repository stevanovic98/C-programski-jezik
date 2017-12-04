#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXIME 22
#define MAX_INDEX 12
#define MAX_SIZE 100

typedef struct studenti{
	char indeks[MAX_INDEX];
	char ime[MAXIME];
	char prezime[MAXIME];
	unsigned int poeni;
} studenti;

void citanje(studenti *, char *, int *);
void sortiranje(studenti *, int);
void ispis(studenti *, int);
void maxp(studenti *, int);
void minp(studenti *, int);
void granica(studenti *, char *, int);
void imeprosek(studenti *, int);

//***************************************************************

int main(int brArg, char *Arg[]){
	if (brArg != 3) {
      puts("Niste dobro pozvali program!");
      exit(EXIT_FAILURE);	
	}
	int n=0;
	studenti student[MAX_SIZE];
	citanje(student, Arg[1] , &n);
	sortiranje(student, n);
	ispis(student, n);
	maxp(student, n);
	minp(student, n);
	granica(student, Arg[2], n);
	imeprosek(student, n);
	return 0;
}

//****************************************************************

void citanje(studenti student[], char *fajl, int *n){
	FILE *f = fopen(fajl, "r");
	if (f == NULL) {
	printf("Datoteka ne postoji ili je nije moguce otvoriti!\n");
	exit(EXIT_FAILURE);
	}
	while(fscanf(f, "%s %s %s %u", student[*n].indeks, student[*n].ime, student[*n].prezime, &student[*n].poeni)!=EOF){
		(*n)++;
	}
	fclose(f);
}

//****************************************************************

void sortiranje(studenti student[], int n){
	int i, j;
	int t, a, b;
	studenti temp;
	int tmp;
	for(i=0; i<n-1; i++){
			for(j=i+1; j<n; j++){
				t=strcmp(student[i].indeks, student[j].indeks);
				a=strlen(student[i].indeks);
				b=strlen(student[j].indeks);				

				if(a>b){
					strcpy(temp.indeks, student[i].indeks);
					strcpy(student[i].indeks, student[j].indeks);
					strcpy(student[j].indeks, temp.indeks);

					strcpy(temp.ime, student[i].ime);
					strcpy(student[i].ime, student[j].ime);
					strcpy(student[j].ime, temp.ime);

					strcpy(temp.prezime, student[i].prezime);
					strcpy(student[i].prezime, student[j].prezime);
					strcpy(student[j].prezime, temp.prezime);

					tmp=student[i].poeni;
					student[i].poeni=student[j].poeni;
					student[j].poeni=tmp;
				}
				if(a==b && t>0){
					strcpy(temp.indeks, student[i].indeks);
					strcpy(student[i].indeks, student[j].indeks);
					strcpy(student[j].indeks, temp.indeks);

					strcpy(temp.ime, student[i].ime);
					strcpy(student[i].ime, student[j].ime);
					strcpy(student[j].ime, temp.ime);

					strcpy(temp.prezime, student[i].prezime);
					strcpy(student[i].prezime, student[j].prezime);
					strcpy(student[j].prezime, temp.prezime);

					tmp=student[i].poeni;
					student[i].poeni=student[j].poeni;
					student[j].poeni=tmp;
				}
			}
	}
}

//****************************************************************

void ispis(studenti student[], int n){
	FILE *f = fopen("sortirani.txt", "w");
	if(f==NULL){
	printf("Fajl nije moguce otvoriti ili kreirati!\n");
	exit(EXIT_FAILURE);
	}
	int i;
	for(i=0; i<n; i++){
		fprintf(f, "%s %s %s %u\n", student[i].indeks, student[i].ime, student[i].prezime, student[i].poeni);
	}
	fclose(f);
}

//****************************************************************

void maxp(studenti student[], int n){
	int maxprez=0;
	int i;
	int max=strlen(student[0].prezime);
	for(i=1; i<n; i++){
		if(max<strlen(student[i].prezime)){
		maxprez=i;
		max=strlen(student[i].prezime);
		}
	}
	printf("Student sa najduzim prezimenom je: %s %s %s\n", student[maxprez].indeks, student[maxprez].ime, student[maxprez].prezime);
}
//****************************************************************

void minp(studenti student[], int n){
	int minprez=0;
	int i;
	int min=strlen(student[0].prezime);
	for(i=1; i<n; i++){
		if(min>strlen(student[i].prezime)){
		minprez=i;
		min=strlen(student[i].prezime);
		}
	}
	printf("Student sa najkracim prezimenom je: %s %s %s\n", student[minprez].indeks, student[minprez].ime, student[minprez].prezime);
}

//****************************************************************

void granica(studenti student[], char *brojpoena, int n){
	char preko[MAX_SIZE]="preko_"; 	
	char poena[MAX_SIZE]="_poena.txt";
	strcat(preko, brojpoena);
	strcat(preko, poena);
	FILE *f = fopen(preko, "w");
	if(f==NULL){
	printf("Fajl nije moguce otvoriti ili kreirati!\n");
	exit(EXIT_FAILURE);
	}
	int i;
	int br=atoi(brojpoena);
	for(i=0; i<n; i++){
		if(student[i].poeni>br){
			fprintf(f, "%s %s %s %u\n", student[i].indeks, student[i].ime, student[i].prezime, student[i].poeni);
		}
	}
	fclose(f);
}

//*****************************************************************

void imeprosek(studenti student[], int n){
	float suma=0;
	int i;
	for(i=0; i<n; i++){
	suma+=(float)strlen(student[i].ime);
	}

	printf("Prosecna duzina imena studenta je: %.2f\n", suma/(float)n);
}
