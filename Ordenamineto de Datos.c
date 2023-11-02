//Programa que ordena datos 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenamientoSeleccion(int arreglo[], int num) {
    int i, j, min, temp;
    
    for (i = 0; i < num - 1; i++) {
        min = i;
        for (j = i + 1; j < num; j++) {
            if (arreglo[j] < arreglo[min]) {
                min = j;
            }
        }
        
        temp = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = temp;
    }
}

float Media(int arreglo[], int num) {
    float suma = 0;
    int i;
    for ( i = 0; i < num; i++) {
        suma += arreglo[i];
    }
    return suma / num;
}

float Mediana(int arreglo[], int num) {
    if (num % 2 == 0) {
        int valor1 = num / 2;
        int valor2 = valor1 - 1;
        return (arreglo[valor1] + arreglo[valor2]) / 2.0;
    } else {
        return arreglo[num / 2];
    }
}

float Moda(int arreglo[], int num) {
    int moda = 0;
    int i,j;
    int max = 0;
    
    for ( i = 0; i < num; i++) {
        int count = 0;
        for ( j = 0; j < num; j++) {
            if (arreglo[j] == arreglo[i]) {
                count++;
            }
        }
        if (count > max) {
            max = count;
            moda = arreglo[i];
        }
    }
    return moda;
}

void Histograma(int arreglo[], int num){

    printf("\nHistograma:\n");
    int i,j,k;
    int min = 1;
    int max = 30;
    
    for (i = min; i <= max; i++) {
        int count = 0;
        for ( j = 0; j < num; j++) {
            if (arreglo[j] == i) {
                count++;
            }
        }
        float normalized = (float)count / num;
        printf("%2d: ", i);
        for (k = 0; k < normalized*100; k++) {
            printf("*");
        }
        printf("\n");
    }
}





int main() {
    printf("Programa que ordena datos y calcula media, mediana y moda\n\n");
    
    int num, i;
    
    printf("Ingrese el numero de elementos que desea en el arreglo: ");
    scanf("%d", &num);
    
    int arreglo[num];
    srand(time(NULL));
    
    for (i = 0; i < num; i++) {
        arreglo[i] = rand() % (30 + 1 - 1) + 1;
        printf("%d ", arreglo[i]);
    }

    ordenamientoSeleccion(arreglo, num);
    printf("\n\nArreglo ordenado por selección:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", arreglo[i]);
    }
    
    printf("\n\nValores estadisticos:\n");
    
    printf("\nEl valor menor del arreglo es: %d\n", arreglo[0]);
    
    printf("El valor mayor del arreglo es: %d\n", arreglo[num - 1]);
    
    float media = Media(arreglo, num);
    printf("La media es: %0.2f\n", media);
    
    float mediana = Mediana(arreglo, num);
    printf("La mediana es: %0.2f\n", mediana);
    
    float moda = Moda(arreglo, num);
    printf("La moda es: %0.2f\n", moda);
    
    Histograma(arreglo, num);


    return 0;
}

