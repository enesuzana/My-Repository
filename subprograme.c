#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef int bool; //typedef , enum
enum{ false, true };

struct Erou{
    char nume[60]; //sir de caractere cu spatii
    char rasa[10]; //sir de caractere fara spatii
    char clasa[30];//
    char gender;//caracter
    int lvl;//numar intreg
    double hp;//numar in virgula mobila
    bool alive;//boolean
    unsigned nrArme : 2;  //camp pe biti
    struct Arma{ //structura in interiorul structurii
        union Luck{//uniune
            int luckInt;
            float luckFloat;
        }noroc;
        double damage;
        double bonusDamage;
    }arma;
};

// Citirea din fisier

//Statica, cunoscuta si necunoscuta:
int fReadStatic(struct Erou player[] , int n ){
    char fisierInt[20], fisierOut[20];
    printf("Dati fisierul de intrare:");
    scanf("%s", fisierInt);//fisierStatic.in
    FILE *f = fopen(fisierInt, "r");
    printf("Dati fisierul de iesire:");
    scanf("%s", fisierOut);//fisierStatic.out
    FILE *g = fopen(fisierOut, "w");
    int i = 0, cont = 0;
    char c;
    while( i < n && (c = fgetc(f)) != EOF ){
		while ( c != '\n' ){
			player[i].nume[cont] = c;
			c = fgetc(f);
			cont++;
		}
		player[i].nume[cont] = '\0';// am citit numele cu tot cu spatii
        cont = 0;
		while ( (c = fgetc(f))!= '\n' ){
			player[i].rasa[cont] = c;
			cont++;
		}
		player[i].rasa[cont] = '\0';// am citit rasa
		cont = 0;
		while ( (c = fgetc(f))!= '\n' ){
			player[i].clasa[cont] = c;
			cont++;
		}
		player[i].clasa[cont]='\0';//am citit clasa
        fscanf(f, "%c", &player[i].gender); //citit genul
		fscanf(f, "%d", &player[i].lvl); // citit nivelul
		fscanf(f, "%lf", &player[i].hp); // citit hp
		fscanf(f, "%d", &player[i].alive);
		player[i].nrArme = 1; // fiecarui player i se da o arma
		player[i].arma.noroc.luckInt = rand() % 100; // acesta primeste rata de noroc random
		fscanf(f, "%lf", &player[i].arma.damage);//damage
		fscanf(f, "%lf", &player[i].arma.bonusDamage);//am citit extra damage, lovitura critica
		c = fgetc(f);//enter + rand
		c = fgetc(f);
        cont = 0;
		i++;
	}
	fclose(f);
	fclose(g);
	return i;//returnam numarul de elemente player de tip struct Erou
};

//Dinamica, cunoscuta:

void fReadDinamicKnown(struct Erou *player,int n){
    char fisierInt[20], fisierOut[20];
    printf("Dati fisierul de intrare:");//fisierDinamicCunoscut.in
    scanf("%s", fisierInt);//
    FILE *f = fopen(fisierInt, "r");
    printf("Dati fisierul de iesire:");
    scanf("%s", fisierOut);//fisierDinamicCunoscut.out
    FILE *g = fopen(fisierOut, "w");
    int i = 0, cont = 0;
    char c;
    while(i < n && (c = fgetc(f)) != EOF ){ //se repeta acelasi procedeu la ca prima functie
		while ( c != '\n' ){
			player[i].nume[cont] = c;
			c = fgetc(f);
			cont++;
		}
		player[i].nume[cont] = '\0';// am citit numele cu tot cu spatii
        cont = 0;
		while ( (c = fgetc(f))!= '\n' ){
			player[i].rasa[cont] = c;
			cont++;
		}
		player[i].rasa[cont] = '\0';// am citit rasa
		cont = 0;
		while ( (c = fgetc(f))!= '\n' ){
			player[i].clasa[cont] = c;
			cont++;
		}
		player[i].clasa[cont]='\0';//citit clasa

        fscanf(f, "%c", &player[i].gender); //citit genul
		fscanf(f, "%d", &player[i].lvl); // citit lvl
		fscanf(f, "%lf", &player[i].hp); // citit hp
		fscanf(f, "%d", &player[i].alive);
		player[i].nrArme = 1; // fiecarui player i se da o arma
		player[i].arma.noroc.luckInt = rand() % 100;
		fscanf(f, "%lf", &player[i].arma.damage);
		fscanf(f, "%lf", &player[i].arma.bonusDamage);

		c = fgetc(f);//enter + rand
		c = fgetc(f);
        cont = 0;
		i++;
	}
	fclose(f);
	fclose(g);
}; //nu mai returnam, stim dimensiunea

//Dinamica, necunoscuta:

int fReadDinamicUnknown(struct Erou *player){
    char fisierInt[20], fisierOut[20];
    printf("Dati fisierul de intrare:");
    scanf("%s", fisierInt);//fisierDinamicNecunoscut.out
    FILE *f = fopen(fisierInt, "r");
    printf("Dati fisierul de iesire:");
    scanf("%s", fisierOut);//fisierDinamicNecunoscut.out
    FILE *g = fopen(fisierOut, "w");
    int i = 0, cont = 0 ;
    char c;
    while((c = fgetc(f))!= EOF){
		while ( c != '\n' ){
			player[i].nume[cont] = c;
			c = fgetc(f);
			cont++;
		}
		player[i].nume[cont] = '\0';// am citit numele cu tot cu spatii
        cont = 0;
		while ( (c = fgetc(f))!= '\n' ){
			player[i].rasa[cont] = c;
			cont++;
		}
		player[i].rasa[cont] = '\0';// am citit rasa
		cont = 0;
		while ( (c = fgetc(f))!= '\n' ){
			player[i].clasa[cont] = c;
			cont++;
		}
		player[i].clasa[cont]='\0';
        fscanf(f, "%c", &player[i].gender); //citit genul
		fscanf(f, "%d", &player[i].lvl); // citit lvl
		fscanf(f, "%lf", &player[i].hp); // citit hp
		fscanf(f, "%d", &player[i].alive);
		player[i].nrArme = 1; // fiecarui player i se da o arma
		player[i].arma.noroc.luckInt = rand() % 100;
		fscanf(f, "%lf", &player[i].arma.damage);
		fscanf(f, "%lf", &player[i].arma.bonusDamage);
		c = fgetc(f);//enter + rand
		c = fgetc(f);
        cont = 0;
		i++;
		if( c == EOF){
            break;
        }
        player = realloc(player, (i+1)*sizeof(struct Erou)); //realocum spatiu daca decizia e pozitiva
	}
	fclose(f);
	fclose(g);
	/* //afisare optionala in fisier
	int j;
	FILE *g= fopen("fDinamicUnknown.out", "w");
	for( j = 0 ; j < i ; j++){
        fprintf(g, " Player %d\n", j+1);
		fprintf(g, "Nume : %s\n", player[j].nume);
		fprintf(g, "Rasa : %s\n", player[j].rasa);
		fprintf(g, "Clasa: %s\n", player[j].clasa);
		fprintf(g, "Gender: %c\n", player[j].gender);
		fprintf(g, "Nivel: %d\n", player[j].lvl);
		fprintf(g, "HP: %Lf\n", player[j].hp);
		if( player[j].alive == true ){
		fprintf(g, "Alive\n");
		}
		else{ printf("Dead\n");
		}
		fprintf(g, "Atack DMG: %Lf\n", player[j].arma.damage);
		fprintf(g, "Atack DMG bonus: %Lf\n\n", player[j].arma.bonusDamage);
	}
	fclose(g);*/
	return player;//returnam deoarece alocam dinamic si realocam
};

// Citirea din consola

// De la tastatura, static, cunoscut:

void cReadStaticKnown(struct Erou player[], int n){
    int i = 0 , cont = 0;
    char c;
    while( i < n ){
        fflush(stdin);
        printf("Player %d\n", i+1);
        printf("Nume: ");
        while( (c = getc(stdin)) != '\n'){
            player[i].nume[cont] = c;
            cont++;
        }
        player[i].nume[cont] = '\0';
        fflush(stdin);
        cont = 0;
        printf("Rasa: ");
        while( (c = getc(stdin)) != '\n'){
            player[i].rasa[cont] = c;
            cont++;
        }
        player[i].rasa[cont] = '\0';
        cont = 0;
        fflush(stdin);
        printf("Clasa: ");
		while ( (c = getc(stdin)) != '\n' ){
			player[i].clasa[cont] = c;
			cont++;
		}
		player[i].clasa[cont]='\0';
        fflush(stdin);
        cont = 0;
        printf("Gender: ");
        fflush(stdin);
        scanf("%c", &player[i].gender);
        fflush(stdin);
        printf("Nivel: ");
        scanf("%d", &player[i].lvl);
		fflush(stdin);
		printf("HP: ");
		scanf("%lf", &player[i].hp); // citit hp
		fflush(stdin);
		printf("Status( 0 - dead, 1 - alive ): ");
		scanf("%d", &player[i].alive);
		fflush(stdin);
		player[i].nrArme = 1; // fiecarui player i se da o arma
		player[i].arma.noroc.luckInt = rand() % 100;
		printf("Damage: ");
		scanf("%lf", &player[i].arma.damage);
		fflush(stdin);
		printf("Bonus Damage: ");
		scanf("%lf", &player[i].arma.bonusDamage);
        printf("\n");
        fflush(stdin);
        i++;
    }
    //afisare optionala:
    /*
    while( j < i ){
        printf(" Player %d\n", j+1);
		printf("Nume : %s\n", player[j].nume);
		printf("Rasa : %s\n", player[j].rasa);
		printf("Clasa: %s\n", player[j].clasa);
		printf("Gender: %c\n", player[j].gender);
		printf("Nivel: %d\n", player[j].lvl);
		printf("HP: %lf\n", player[j].hp);
		if( player[j].alive == true ){
		printf("Alive\n");
		}
		else{ printf("Dead\n");
		}
		printf("Atack DMG: %lf\n", player[j].arma.damage);
		printf("Atack DMG bonus: %lf\n\n", player[j].arma.bonusDamage);
		j++;
    }*/
};

//De la tastatura, static, necunoscut:

int cReadStaticUnknown(struct Erou player[], int n){
    int i = 0 , cont = 0;
    char c;
    int decizie ;
    while( i < n ){ // nu pot citi un numar mai mare decat cel alocat initial , dar daca tastes 0 ies
        fflush(stdin);
        printf("Player %d\n", i+1);
        printf("Nume: ");
        while( (c = getc(stdin)) != '\n'){
            player[i].nume[cont] = c;
            cont++;
        }
        player[i].nume[cont] = '\0';
        fflush(stdin);
        cont = 0;
        printf("Rasa: ");
        while( (c = getc(stdin)) != '\n'){
            player[i].rasa[cont] = c;
            cont++;
        }
        player[i].rasa[cont] = '\0';
        cont = 0;
        fflush(stdin);
        printf("Clasa: ");
		while ( (c = getc(stdin)) != '\n' ){
			player[i].clasa[cont] = c;
			cont++;
		}
		player[i].clasa[cont]='\0';
        fflush(stdin);
        cont = 0;
        printf("Gender: ");
        fflush(stdin);
        scanf("%c", &player[i].gender);
        fflush(stdin);
        printf("Nivel: ");
        scanf("%d", &player[i].lvl);
		fflush(stdin);
		printf("HP: ");
		scanf("%lf", &player[i].hp); // citit hp
		fflush(stdin);
		printf("Status( 0 - dead, 1 - alive ): ");
		scanf("%d", &player[i].alive);
		fflush(stdin);
		player[i].nrArme = 1; // fiecarui player i se da o arma
		player[i].arma.noroc.luckInt = rand() % 100;
		printf("Damage: ");
		scanf("%lf", &player[i].arma.damage);
		fflush(stdin);
		printf("Bonus Damage: ");
		scanf("%lf", &player[i].arma.bonusDamage);
        printf("\n");
        fflush(stdin);
        i++;
        printf("Exit = 0 , Add Hero != 0\n");
        scanf("%d",&decizie);
        if ( decizie == 0 ){
            break;
        }
    }
    return i;//returnam dimensiunea vectorului de structuri
};

//De la tastatura, dinamic, cunoscut:

int cReadDinamicKnown(struct Erou *player,int n){
    int i = 0, cont = 0 ;
    char c;
    while(i < n){
        fflush(stdin);
        printf("Player %d\n", i+1);
        printf("Nume: ");
        while( (c = getc(stdin)) != '\n'){
            player[i].nume[cont] = c;
            cont++;
        }
        player[i].nume[cont] = '\0';
        fflush(stdin);
        cont = 0;
        printf("Rasa: ");
        while( (c = getc(stdin)) != '\n'){
            player[i].rasa[cont] = c;
            cont++;
        }
        player[i].rasa[cont] = '\0';
        cont = 0;
        fflush(stdin);
        printf("Clasa: ");
		while ( (c = getc(stdin)) != '\n' ){
			player[i].clasa[cont] = c;
			cont++;
		}
		player[i].clasa[cont]='\0';
        fflush(stdin);
        cont = 0;
        printf("Gender: ");
        fflush(stdin);
        scanf("%c", &player[i].gender);
        fflush(stdin);
        printf("Nivel: ");
        scanf("%d", &player[i].lvl);
		fflush(stdin);
		printf("HP: ");
		scanf("%lf", &player[i].hp); // citit hp
		fflush(stdin);
		printf("Status( 0 - dead, 1 - alive ): ");
		scanf("%d", &player[i].alive);
		fflush(stdin);
		player[i].nrArme = 1; // fiecarui player i se da o arma
		player[i].arma.noroc.luckInt = rand() % 100;
		printf("Damage: ");
		scanf("%lf", &player[i].arma.damage);
		fflush(stdin);
		printf("Bonus Damage: ");
		scanf("%lf", &player[i].arma.bonusDamage);
        printf("\n");
        fflush(stdin);
        i++;
	}
    return i;
};

//De la tastatura, dinamic, necunoscut:

int cReadDinamicUnknown(struct Erou *player){
    int i = 0, cont = 0 ;
    char c;
    int decizie ;
    while( 1 < 2 ){
		fflush(stdin);
        printf("Player %d\n", i+1);
        printf("Nume: ");
        while( (c = getc(stdin)) != '\n'){
            player[i].nume[cont] = c;
            cont++;
        }
        player[i].nume[cont] = '\0';
        fflush(stdin);
        cont = 0;
        printf("Rasa: ");
        while( (c = getc(stdin)) != '\n'){
            player[i].rasa[cont] = c;
            cont++;
        }
        player[i].rasa[cont] = '\0';
        cont = 0;
        fflush(stdin);
        printf("Clasa: ");
		while ( (c = getc(stdin)) != '\n' ){
			player[i].clasa[cont] = c;
			cont++;
		}
		player[i].clasa[cont]='\0';
        fflush(stdin);
        cont = 0;
        printf("Gender: ");
        fflush(stdin);
        scanf("%c", &player[i].gender);
        fflush(stdin);
        printf("Nivel: ");
        scanf("%d", &player[i].lvl);
		fflush(stdin);
		printf("HP: ");
		scanf("%lf", &player[i].hp); // citit hp
		fflush(stdin);
		printf("Status( 0 - dead, 1 - alive ): ");
		scanf("%d", &player[i].alive);
		fflush(stdin);
		player[i].nrArme = 1; // fiecarui player i se da o arma
		player[i].arma.noroc.luckInt = rand() % 100;
		printf("Damage: ");
		scanf("%lf", &player[i].arma.damage);
		fflush(stdin);
		printf("Bonus Damage: ");
		scanf("%lf", &player[i].arma.bonusDamage);
        printf("\n");
        fflush(stdin);
        i++;
        printf("Exit = 0 , Add Hero != 0\n"); // oferim decizia de a continua sau nu
        scanf("%d",&decizie);
        if ( decizie == 0 ){
            break;
        }
        player = realloc(player, (i+1)*sizeof(struct Erou)); //realocam spatiu
	}
    return player;
};

//Functie pentru numarul de elemente tip player, alocarea dinamica

int nrElem( struct Erou *player){
    int contor = 0;
    while( player[contor].alive == 1 || player[contor].alive == 0){
        contor++;
    }
    printf("%d", contor);
    return contor;
}

//9.Afisarea unor informatii din date memorate: Afisati toate fetele:

//a.static
void afisareFeteStatic( struct Erou player[]){
    printf("9.Sa se afiseze toate numele si clasa fetelor din joc:\n");
    int i = 0;
    printf("Fetele sunt:\n");
    while( player[i].alive == 1){
        if( player[i].gender == 'F'){
            printf("Nume : %s\n", player[i].nume);
            printf("Clasa: %s\n", player[i].clasa);
        }
        i++;
    }
    printf("\n");
};

//b.dinamic
void afisareFeteDinamic(struct Erou *player, int n){
    printf("9.Sa se afiseze toate numele si clasa fetelor din joc:\n");
    int i = 0;
    printf("Fetele sunt:\n");
    while(i < n){
        if( player[i].gender == 'F'){
            printf("Nume : %s\n", player[i].nume);
            printf("Clasa: %s\n", player[i].clasa);
        }
        i++;
    }
    printf("\n");
};

//10a. Modificarea unui camp intreg, static si dinamic

void addLevelStatic( struct Erou *player){
    printf("10.a)Totii baietii din joc primesc un lvl in plus.\n");
    int i = 0;
    while( player[i].alive == 1){
        if( player[i].gender == 'M'){
            player[i].lvl++;
            printf("%s are nivelul %d\n", player[i].nume, player[i].lvl);
        }
        i++;
    }
    printf("\n");
};

void addLevelDinamic( struct Erou *player, int n){
    printf("10.a)Totii baietii din joc primesc un lvl in plus.\n");
    int i = 0, contor = 0;
    while(i < n){
        if( player[i].gender == 'M'){
            player[i].lvl++;
            printf("%s are nivelul %d\n", player[i].nume, player[i].lvl);
            contor++;
        }
        i++;
    }
    if( contor == 0 ){
        printf("Nu exista baieti\n");
    }
    printf("\n");
};

//10a. Modificarea unui camp sir de caractere, static si dinamic 1

void changeClasaStatic( struct Erou player[], int n){
    printf("10.b)Regatul avanseaza si toti Gardienii devin Lanceri.\n");
    int i = 0, contor = 0;
    char schimb[]="Lancer";
    char cautat[]="Guardian";
    while( i < n){
        if( strcmp(player[i].clasa, cautat) == 0 ){
            strcpy(player[i].clasa, schimb);
            printf("%s a devenit Lancer\n", player[i].nume);
            contor++;
        }
        i++;
    }
    if( contor == 0 ){
        printf("Nu exista Guardian\n");
    }
    printf("\n");
};

void changeClasaDinamic( struct Erou *player, int n){
    printf("10.b)Regatul avanseaza si toti Gardienii devin Lanceri.\n");
    int i = 0, contor = 0;
    char schimb[]="Lancer";
    char cautat[]="Guardian";
    while(i < n){
        if( strcmp(player[i].clasa, cautat) == 0 ){
            strcpy(player[i].clasa, schimb);
            printf("%s a devenit Lancer\n", player[i].nume);
            contor++;
        }
        i++;
    }
    if( contor == 0 ){
        printf("Nu exista Guardian\n");
    }
    printf("\n");
};

//10a. Modificarea unui camp caracter, static si dinamic

void changeCharStatic( struct Erou player[]){
    printf("10.c) Toti baietii devin fete:\n");
    int i = 0, contor = 0;
    while( player[i].alive == 1 ){
        if( player[i].gender == 'M'){
            contor = 1;
            player[i].gender = 'F';
            printf("%s a devenit %c\n", player[i].nume, player[i].gender);
        }
        i++;
    }
    if( contor == 0 ){
        printf("Nu exista baieti.\n");
    }
    printf("\n");
};

void changeCharDinamic( struct Erou *player, int n){
    printf("10.c) Toti baietii devin fete:\n");
    int i = 0, contor = 0;
    while( i < n ){
        if( player[i].gender == 'M'){
            contor = 1;
            player[i].gender = 'F';
            printf("%s a devenit %c\n", player[i].nume, player[i].gender);
        }
        i++;
    }
    if( contor == 0 ){
        printf("Nu exista baieti.\n");
    }
    printf("\n");
};

//11a. qsort cu un simplu intreg

int comparaIntreg( int *a, int *b){
    struct Erou *ia = ( struct Erou *) a;
    struct Erou *ib = (struct Erou *) b;
    return (int)( ia->lvl - ib->lvl);
};

//11b. qsort dupa doua criterii, camp de caractere si unul valori intregi

int comparaChar( char *a, char *b){//comparam sirurile de caractere
    struct Erou *ca = ( struct Erou *) a;
    struct Erou *cb = (struct Erou *) b;
    return (int)(strcmp(ca->nume,cb->nume));
}

int comparaComb( char *a, char *b){//comparam initial nivelele
    struct Erou *ia = ( struct Erou *) a;
    struct Erou *ib = (struct Erou *) b;
    int t = (int)( ia->lvl - ib->lvl );//daca sunt egala, t = 0;
    if( t == 0 ){//cand nivelul e egal, apelam compararea dupa nume
        comparaChar(a, b);
    }
    else return t;
};

void sortareStatic( struct Erou player[], int n){
    printf("11b) Sortarea in fuctie de nivel si nume:\n");
    qsort(player, n, sizeof(struct Erou), comparaComb); //le sortam in functie de nivel, nume
    int j = 0; //Afisam datele sortate:
	while( j < n ){
        printf(" Player %d\n", j+1);
		printf("Nume : %s\n", player[j].nume);
		printf("Rasa : %s\n", player[j].rasa);
		printf("Clasa: %s\n", player[j].clasa);
		printf("Gender: %c\n", player[j].gender);
		printf("Nivel: %d\n", player[j].lvl);
		printf("HP: %lf\n", player[j].hp);
		if( player[j].alive == true ){
		printf("Alive\n");
		}
		else{ printf("Dead\n");
		}
		printf("Atack DMG: %lf\n", player[j].arma.damage);
		printf("Atack DMG bonus: %lf\n\n", player[j].arma.bonusDamage);
        j++;
    }
};

void sortareDinamic( struct Erou *player, int n){
    printf("11.b) Sortarea in fuctie de nivel si nume:\n");
    qsort(player, n, sizeof(struct Erou), comparaComb);//sortam
    int j = 0;//afisare
	while( j < n ){
        printf(" Player %d\n", j+1);
		printf("Nume : %s\n", player[j].nume);
		printf("Rasa : %s\n", player[j].rasa);
		printf("Clasa: %s\n", player[j].clasa);
		printf("Gender: %c\n", player[j].gender);
		printf("Nivel: %d\n", player[j].lvl);
		printf("HP: %lf\n", player[j].hp);
		if( player[j].alive == true ){
		printf("Alive\n");
		}
		else{ printf("Dead\n");
		}
		printf("Atack DMG: %lf\n", player[j].arma.damage);
		printf("Atack DMG bonus: %lf\n\n", player[j].arma.bonusDamage);
        j++;
    }
};

//Sortarea doar in functie de intreg( nivel )

void sortareDupaIntregST(struct Erou player[], int n){
    printf("11.a)Sortarea in functie de nivel:\n");
    qsort(player, n, sizeof(struct Erou), comparaIntreg);
    int j = 0;
	while( j < n ){//afisare
        printf(" Player %d\n", j+1);
		printf("Nume : %s\n", player[j].nume);
		printf("Rasa : %s\n", player[j].rasa);
		printf("Clasa: %s\n", player[j].clasa);
		printf("Gender: %c\n", player[j].gender);
		printf("Nivel: %d\n", player[j].lvl);
		printf("HP: %lf\n", player[j].hp);
		if( player[j].alive == true ){
		printf("Alive\n");
		}
		else{ printf("Dead\n");
		}
		printf("Atack DMG: %lf\n", player[j].arma.damage);
		printf("Atack DMG bonus: %lf\n\n", player[j].arma.bonusDamage);
        j++;
    }
};

void sortareDupaIntregDI(struct Erou *player, int n){
    printf("11.a)Sortarea in functie de nivel:\n");
    qsort(player, n, sizeof(struct Erou), comparaIntreg);
    int j = 0;
	while( j < n ){//afisare
        printf(" Player %d\n", j+1);
		printf("Nume : %s\n", player[j].nume);
		printf("Rasa : %s\n", player[j].rasa);
		printf("Clasa: %s\n", player[j].clasa);
		printf("Gender: %c\n", player[j].gender);
		printf("Nivel: %d\n", player[j].lvl);
		printf("HP: %lf\n", player[j].hp);
		if( player[j].alive == true ){
		printf("Alive\n");
		}
		else{ printf("Dead\n");
		}
		printf("Atack DMG: %lf\n", player[j].arma.damage);
		printf("Atack DMG bonus: %lf\n\n", player[j].arma.bonusDamage);
        j++;
    }
};

//12. Manipularea blocurilor de memorie:

void modifClasaST( struct Erou player[], int n){//manipularea blocurilor de memorie
    printf("Sa se adauge la finalul Clasei un spatiu si primele 3 litere de la inceput combinate cu primele 2 din Nume:\n");
    //memcpy( player[0].nume+6, player[0].nume+3, 5);
    int i = 0;
    while( i < n){
        int p = strlen(player[i].clasa);
        memcpy(player[i].clasa+p, " ", 1);
        memcpy(player[i].clasa+p+1, player[i].clasa, 4);
        memcpy(player[i].clasa+p+4, player[i].nume, 2);
        player[i].clasa[p+6]='\0';
        printf("%s\n", player[i].clasa);
        i++;
    }
};

void modifClasaDI( struct Erou *player, int n){
    printf("Sa se adauge la finalul Clasei un spatiu si primele 3 litere de la inceput combinate cu primele 2 din Nume:\n");
    //memcpy( player[0].nume+6, player[0].nume+3, 5);
    int i = 0;
    while( i < n){
        int p = strlen(player[i].clasa);
        memcpy(player[i].clasa+p, " ", 1);
        memcpy(player[i].clasa+p+1, player[i].clasa, 4);
        memcpy(player[i].clasa+p+4, player[i].nume, 2);
        player[i].clasa[p+6]='\0';
        printf("%s\n", player[i].clasa);
        i++;
    }
};

//12. Manipularea sirurilor de caractere 2

void deadST( struct Erou player[], int n){//manip sirurilor de caractere
    printf("Playerilor morti li se schimba numele in Am murit:\n");
    int i = 0, contor = 0;
    char s[]="Am murit";
    char temp[30];
    while ( i < n ){
        if(player[i].alive == false ){
            contor = 1;
            strcpy(temp, player[i].nume);
            strcpy(player[i].nume, s);
            printf("%s is dead.\n", temp);
        }
        i++;
    }
    if( contor == 0 ){
        printf("Toata lumea e vie!");
    }
    printf("\n");
};

void deadDI( struct Erou *player, int n){
    printf("Playerilor morti li se schimba numele in Am murit:\n");
    int i = 0, contor = 0;
    char s[]="Am murit";
    char temp[30];
    while ( i < n ){
        if(player[i].alive == false ){
            contor = 1;
            strcpy(temp, player[i].nume);
            strcpy(player[i].nume, s);
            printf("%s is dead.\n", temp);
        }
        i++;
    }
    if( contor == 0 ){
        printf("Toata lumea e vie!");
    }
    printf("\n");
};

//12. Manipularea sirurilor de caractere 3

void cautareST( struct Erou player[], int n ){
    printf("Eliminati vocalele din Rasa si afisati cuvantul nou\n");
    int i, k = 0, dim;
    char vocale[]="AEIOUaeiou";
    while( k < n ){
        dim = strlen(player[k].rasa);
        for( i = 0; i < dim; i++){
            if (strchr( vocale, player[k].rasa[i]) != 0 ){
                strcpy(player[k].rasa+i, player[k].rasa+i+1 );
                dim--;
                i--;
            }
        }
        printf("Dupa eliminare: %s\n", player[k].rasa);
    k++;
    }
};

void cautareDI( struct Erou *player, int n ){
    printf("Eliminati vocalele din Rasa si afisati cuvantul nou\n");
    int i, k = 0, dim;
    char vocale[]="AEIOUaeiou";
    while( k < n ){
        dim = strlen(player[k].rasa);
        for( i = 0; i < dim; i++){
            if (strchr( vocale, player[k].rasa[i]) != 0 ){
                strcpy(player[k].rasa+i, player[k].rasa+i+1 );
                dim--;
                i--;
            }
        }
        printf("Dupa eliminare: %s\n", player[k].rasa);
    k++;
    }
};

//12. Manipularea sirurilor de caractere 4

void stergereST(struct Erou player[], int n){
    printf("Eliminati prima aparitie a lui ie din Clasa:\n");
    char c[] = "ie";
    int i = 0;
    char temp[30];
    while( i < n ){
        char *p = strstr(player[i].clasa, c);
        if( p ){
            strncpy( temp, player[i].clasa, p - player[i].clasa);
            temp[p-player[i].clasa]='\0';
            strcat(temp, p + 2);
            strcpy(player[i].clasa, temp);
        }
        printf("%s \n", player[i].clasa);
        i++;
    }
    printf("\n");
};

void stergereDI(struct Erou *player, int n){
     printf("Eliminati prima aparitie a lui ie din Clasa:\n");
    char c[] = "ie";
    int i = 0;
    char temp[30];
    while( i < n ){
        char *p = strstr(player[i].clasa, c);
        if( p ){
            strncpy( temp, player[i].clasa, p - player[i].clasa);
            temp[p-player[i].clasa]='\0';
            strcat(temp, p + 2);
            strcpy(player[i].clasa, temp);
        }
        printf("%s \n", player[i].clasa);
        i++;
    }
    printf("\n");
};

void numeST( struct Erou player[], int n){
    printf("Adaugati sexul in dreptul numelui eroului:\n");
    int i = 0;
    char temp[30];
    while( i < n ){
        strcpy(temp, player[i].nume);
        int nr = strlen(temp);
        temp[nr] = ' ';
        temp[nr+1] = player[i].gender;
        temp[nr+2] = '\0';
        strcpy(player[i].nume, temp);
        printf("%s\n", player[i].nume);
        i++;
    }

};

void numeDI( struct Erou *player, int n){
    printf("Adaugati sexul in dreptul numelui eroului:\n");
    int i = 0;
    char temp[30];
    while( i < n ){
        strcpy(temp, player[i].nume);
        int nr = strlen(temp);
        temp[nr] = ' ';
        temp[nr+1] = player[i].gender;
        temp[nr+2] = '\0';
        strcpy(player[i].nume, temp);
        printf("%s\n", player[i].nume);
        i++;
    }

};

void meniu(){
    int modCitire, modMemorare;
    int n;
    printf("Alegeti modul de citire/afisare:\n");
    printf("1. Fisiere\n");
    printf("2. Consola\n");
    scanf("%d", &modCitire); // memoram modul de citire dorit
    printf("Alegeti modul de memorare a datelor:\n");
    printf("1. Vector cu n elemente de tip structura\n");
    printf("2. Vector fara a cunoaste numarul de elemente\n");
    printf("3. Alocare dinamica pentru n elemente\n");
    printf("4. Alocare dinamica pentru un numar necunoscut de elemente\n");
    scanf("%d", &modMemorare);// retinem modul de memorare
    //Alocam spatiu, apelam functiile specifice pentru fiecare mod de citire si memorare
    switch(modCitire){
        case 1:{//din fisier
            printf(" Ati ales citirea din fisier si modul de memorare ");
            switch(modMemorare){
                case 1:{
                    printf("statica cu numar cunoscut \n");
                    printf("Cati jucatori?\n");
                    scanf("%d", &n);
                    struct Erou player[n];
                    int dim = fReadStatic(player,n);
                    afisareFeteStatic(player);//afisarea unor informatii
                    addLevelStatic(player);// modificarea campurilor de intregi
                    changeClasaStatic(player, n); // manip sir de caractere 1
                    changeCharStatic(player);//modificarea unui caracter
                    sortareStatic(player, n );//qsort
                    modifClasaST(player, n);//manipularea blocurilor de memorie
                    deadST(player, n); // manip sir de caract 2
                    cautareST(player, n); //manip sir de caract  3
                    stergereST(player, n);//manip sir de caract 4
                    numeST(player, n);
                    break;
                }
                case 2:{
                    printf("statica cu numar necunoscut \n");
                    struct Erou player[MAX];
                    int dim = fReadStatic(player,MAX);
                    afisareFeteStatic(player);//afisarea unor informatii
                    addLevelStatic(player);// modificarea campurilor de intregi
                    changeClasaStatic(player, dim);//manip sir de caract
                    changeCharStatic(player);// modificarea unui caracter
                    sortareStatic(player, dim);// qsort
                    modifClasaST(player, dim);//manip sir de caract
                    deadST(player, dim);//manip sir de caract
                    cautareST(player, dim);//manip sir de caract
                    stergereST(player, dim);//manip sir de caract
                    numeST(player, dim);
                    break;
                }
                case 3:{
                    printf("dinamica cu numar cunoscut \n");
                    printf("Cati jucatori?\n");
                    scanf("%d", &n);
                    struct Erou *player;
                    player = malloc( n * sizeof( struct Erou));
                    fReadDinamicKnown(player,n);
                    afisareFeteDinamic(player, n);
                    addLevelDinamic(player, n);
                    changeClasaDinamic(player, n);
                    changeCharDinamic(player, n);
                    sortareDinamic(player, n);
                    modifClasaDI(player, n);
                    deadDI(player, n);
                    cautareDI(player, n);
                    stergereDI(player, n);
                    numeDI(player, n);
                    free(player);
                    break;
                }
                case 4:{
                    printf("dinamica cu numar necunoscut \n");
                    struct Erou *player;
                    player = malloc(sizeof(struct Erou));
                    player = fReadDinamicUnknown(player);
                    int dim = nrElem(player);
                    afisareFeteDinamic(player, dim);
                    addLevelDinamic(player, dim);
                    changeClasaDinamic(player, dim);
                    changeCharDinamic(player, dim);
                    sortareDinamic(player, dim);
                    modifClasaDI(player, dim);
                    deadDI(player, dim);
                    cautareDI(player, dim);
                    stergereDI(player, dim);
                    numeDI(player, dim);
                    free(player);
                    break;
                }
            }
            break;
        }
        case 2:{//de la tastatura
            printf(" Ati ales citirea din consola si modul de memorare ");
            switch(modMemorare){
                case 1:{
                    printf("statica cu numar cunoscut \n");
                    printf("Cati jucatori?\n");
                    scanf("%d", &n);
                    struct Erou player[n];
                    cReadStaticKnown(player,n);
                    afisareFeteStatic(player);
                    addLevelStatic(player);
                    changeClasaStatic(player, n);
                    changeCharStatic(player);
                    sortareStatic(player,n);
                    modifClasaST(player, n);
                    deadST(player, n);
                    cautareST(player, n);
                    stergereST(player, n);
                    numeST(player, n);
                    break;
                }//
                case 2:{
                    printf("statica cu numar necunoscut \n");
                    struct Erou player[MAX];
                    int dim = cReadStaticUnknown(player,MAX);
                    afisareFeteStatic(player);
                    addLevelStatic(player);
                    changeClasaStatic(player, dim);
                    changeCharStatic(player);
                    sortareStatic(player,dim);
                    modifClasaST(player, dim);
                    deadST(player, dim);
                    cautareST(player, dim);
                    stergereST(player, dim);
                    numeST(player, dim);
                    break;
                }
                case 3:{
                    printf("dinamica cu numar cunoscut \n");
                    printf("Cati jucatori?\n");
                    scanf("%d", &n);
                    struct Erou *player;
                    player = malloc( n * sizeof( struct Erou));
                    cReadDinamicKnown(player,n);
                    afisareFeteDinamic(player, n);
                    addLevelDinamic(player, n);
                    changeClasaDinamic(player, n);
                    changeCharDinamic(player, n);
                    sortareDinamic(player, n);
                    modifClasaDI(player, n);
                    deadDI(player, n);
                    cautareDI(player, n);
                    stergereDI(player, n);
                    numeDI(player, n);
                    free(player);
                    break;
                }
                case 4:{
                    printf("dinamica cu numar necunoscut \n");
                    struct Erou *player;
                    player = malloc(sizeof(struct Erou));
                    player = cReadDinamicUnknown(player);
                    int dim = nrElem( player );
                    afisareFeteDinamic(player, dim);
                    addLevelDinamic(player, dim);
                    changeClasaDinamic(player, dim);
                    changeCharDinamic(player, dim);
                    sortareDinamic(player, dim);
                    modifClasaDI(player, dim);
                    deadDI(player, dim);
                    cautareDI(player, dim);
                    stergereDI(player, dim);
                    numeDI(player, dim);
                    free(player);
                    break;
                }
            }
            break;
        }
    }
};
