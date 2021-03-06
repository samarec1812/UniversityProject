#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
#define NMAX 10
using namespace std; 

void Zapolnenie(FILE *fin,int mas1[][NMAX], int &m, int &n) {
	//ввод размеров матрицы
	fscanf(fin, "%d", &m);
	fscanf(fin, "%d", &n); 
    //заполнение
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			fscanf(fin, "%d", &mas1[i][j]); 
		}
	}

	return; 
}

bool Proverka1(int mas1[], int n) {
	bool f1 = false; 
	//int j = 0;
	
	for (int i = 0; i < n; ++i) {
		if (mas1[i]== 0) { f1 = true;  }
	}
	
	
	return f1; 
}

double SredArifm1(int mas1[], int n, double k) {
	for (int j = 0; j < n; ++j) {
		if (mas1[j] > 0) k += mas1[j];
	}
	return k;
}

void VivodOtveta(FILE *fout, double sr[], int m, int n){
	fprintf(fout, "\n");
	for (int i = 0; i < m; ++i) {
		if (sr[i] == 0) { fprintf(fout, " Все элементы неположительны в строке %d\n", i + 1); }
		else {
			fprintf(fout, "Среднее арифметической строки %d =", i + 1);
			fprintf(fout, " %4.4f\n", sr[i] / n);
		}
	}
	return;
}
bool Matrica(int mas1[][NMAX], int m, int n){
for (int i = 0; i < m; i++) {
			Proverka1(mas1[i], n);
		 if (Proverka1(mas1[i], n) == true) { f1 = true;  }
	
	}

}

void SredDopolnit(FILE *fout, int m, int n, int mas1[][NMAX]) {
	double *sr1;
	int k22 = 0;
	sr1 = new double[m];
	
	//for (int i = 0; i < m; ++i) {
		//sr1[i] = SredArifm1(mas1[i], n, k22);
	//}

	for (int i = 0; i < m; i++) {
		SredArifm1(mas1[i], n, k22);
		VivodMatriciDin2(fout, mas1[i], n);

	}

	VivodOtvetaDin(fout, sr1, m, n);
}

int main(int argc, char *argv[])
{
	SetConsoleOutputCP(1251);
	FILE *fin, *fout; 
	if ((fin = fopen(argv[1], "rt")) == NULL) {
		printf("Errror: Ошибка при открытии файла %s для чтения\nPress any key\n", argv[1]);
		system("Pause");
		return 0;
	}
	if ((fout = fopen(argv[2], "wt")) == NULL) {
		printf("Errror: Ошибка при открытии файла %s для записи\nPress any keyn\n", argv[2]);
		fclose(fin);
		system("Pause");
		return 0;
	}
	
	int mas1[NMAX][NMAX], mas2[NMAX][NMAX]; 
	int m, n, m1, n1;
	double sr1[NMAX], sr2[NMAX];
	double k1 = 0, k2 = 0;
	Zapolnenie(fin, mas1, m, n);
	
	//построчная проверка
		bool k[NMAX],f1,f2; 
		
		if (f1 == false) { fprintf(fout, "У матрицы 1 нет хотя бы одного нулевого элемента\n"); }
	else {
		fprintf(fout, "В матрице 1:\n");
		for (int i = 0; i < m; ++i) {
		sr1[i] = SredArifm1(mas1[i], n, k1);
	}
		VivodMatrici(fout, mas1, m, n);
		VivodOtveta(fout, sr1, m, n)
	}
	Zapolnenie(fin, mas2, m1, n1);
	/*
	//1 способ построчной проверки
	for (int i = 0; i < m1; i++) {
		k[i] = Proverka1(mas2[i], n1);
		if (k[i] == true) { f2 = true; }

	}
	if (f2 == false) { fprintf(fout, "У матрицы 2 нет хотя бы одного нулевого элемента\n"); }
	else {

		fprintf(fout, "В матрице 2:\n");
		for (int i = 0; i < m1; ++i) {
		sr2[i] = SredArifm1(mas2[i], n1, k2);
	}
		VivodMatrici1(fout, mas2, m1, n1);
	VivodOtveta(fout, sr2, m1, n1); 
	}*/
	
    fclose(fin); 
	fclose(fout); 
	return 0; 


}