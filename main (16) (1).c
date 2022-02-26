#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>
#include <math.h>
#define KRED  "\x1B[31m"
int main()
{
    float Matrice[50][50], b[50], guess[50];
    int L, C, i, j,h, Xn=0, iter =0;
    float num = 0;

    HANDLE  hConsole;
    int k;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    do{
        SetConsoleTextAttribute(hConsole, 4);
        printf("%3d  %s\n",1, "Matrice doit etre caree (exp: matrice 3X3) \n");
        SetConsoleTextAttribute(hConsole, 15);
        printf("Saisir la taille: ");
        scanf("%d", &C);
    }while( C<0);

    do{
        printf("Combien d'iteration ? :");
        scanf("%d", &iter);
    }while(iter <0);

    SetConsoleTextAttribute(hConsole, 4);
    printf("%3d  %s\n",2, "Remplir le matrice:  \n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("");
    for(i=0; i<C; i++){
        for(j=0; j<C; j++){
            printf("Matrice[%d][%d] = ", i+1, j+1);
            scanf("%f",&Matrice[i][j]);
        }
    }
    printf("\n");
    SetConsoleTextAttribute(hConsole, 1);
    printf("%3d  %s\n",3, "Matrice : \n");
    SetConsoleTextAttribute(hConsole, 15);
    for(i=0; i<C; i++){
        for(j=0; j<C; j++){
            printf("%f \t", Matrice[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    SetConsoleTextAttribute(hConsole, 4);
    printf("%3d  %s\n",3, "Saisir right hand vectors : \n");
    SetConsoleTextAttribute(hConsole, 15);
    for(i=0; i<C; i++){
        printf("B[%d] = ", i);
        scanf("%f",&b[i]);
    }
    printf("\n");
    SetConsoleTextAttribute(hConsole, 4);
    printf("%3d  %s\n",3, " Saisir x0 : \n");
    SetConsoleTextAttribute(hConsole, 15);
    for(i=0; i<C; i++){
            printf("x0[%d]= ", i);
            scanf("%f", &guess[i]);
    }
    while(Xn != iter){
        for(i=0; i<C; i++){
        num =b[i];
            if(i==0){
              for (j=i+1; j<C; j++){
                num -= fabs(guess[j]*Matrice[i][j]);

              }
            }else{
                float temp=0;
                for (h=i; h>=0; h--){
                    if(h != i){
                        num -= guess[h]*fabs(Matrice[i][h]);
                    }
              }

                for (j=i; j<C; j++){
                    if(j != i){
                        num -= guess[j]*Matrice[i][j];
                    }
              }
            }
        num = num/Matrice[i][i];
        guess[i]=num;

    }
    SetConsoleTextAttribute(hConsole, 1);
    printf(" \n %d Interation . ", Xn);
    printf("  %s\n", "Resultat du methode Gauss-Seidel : \n", Xn);
    SetConsoleTextAttribute(hConsole, 15);
    for(i=0; i<C; i++){
        printf("x%d= %.6f \t",i+1, guess[i]);
    }
    Xn ++;
    }


    return 0;
}
