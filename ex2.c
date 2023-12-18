#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void lire(float *A, int d) {
	int i;
	for(i = 0; i < d; i++) {
		printf("Enter element at index %d: ", i);
		scanf("%f", A + i);
	}
	printf("Done writing elements ✅\n");
}

void afficher(float *A, int d) {
	int i;
	printf("{");
	for(i = 0; i < d; i++) {
		printf("%f ", A[i]);
		if (i != d - 1) printf(", ");
	}
	printf("}");
}

float produit(float *A, float *B, int d) {
	float sum = 0;
	int i;
	for(i = 0; i < d; i++) {
		sum += A[i] * B[i];
	}
	return sum;
}

float* somme(float *A, float *B, int d) {
	int i;
	float *New = malloc(d * sizeof(float));
	for(i = 0; i < d; i++) {
		New[i] = A[i] + B[i];
	}
	return New;
}

float* scalaire(float *A, int d, int k) {
	int i;
	float *New = malloc(d * sizeof(float));
	for(i = 0; i < d; i++) {
		New[i] = A[i] * k;
	}
	return New;
}
	
void distance(float *A, float *B, int d) {
	float dis = 0;
	int i;
	for(i = 0; i < d; i++) {
		dis += pow(A[i] - B[i], 2);
	}
	printf("The distance between A & B is %f.\n", sqrt(dis));
}

void main() {
	float A[4], B[4], prod;
	printf("Enter elements of A: \n");
	lire(A, 4);
	printf("Enter elements of B: \n");
	lire(B, 4);
	afficher(A,4);printf(" "); afficher(B,4);printf("\n");
	prod = produit(A, B, 4);
	printf("The product of A and B is %f.\n", prod);
	float *Sum;
	Sum = somme(A, B, 4);
	afficher(Sum, 4);printf(" is the sum vector of A & B.\n");
	float *Sca = scalaire(Sum, 4, 4);
	afficher(Sca, 4);printf(" is the scalaire vector of Sum (Sum * 4).\n");
	distance(A, B, 4);
}
