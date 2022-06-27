#pragma once
#include <iostream>
using namespace std;
struct Graf {
private:
	int n;
	int***mat;
	
	bool proveri_cvor(int k) const {
		if (mat[0][k] == nullptr)
			return false;
		else
			return true;
	}
public:
	void napravi(int nn) {
		n = nn;
		mat = new int**[n];
		for (int i = 0; i < n; i++) {
			mat[i] = new int*[n];
			for (int j = 0; j < n; j++)
				mat[i][j] = new int(0);
		}

		

	}
	void brisi() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (mat[i][j] != nullptr) {
					delete mat[i][j];
					mat[i][j] = nullptr;
				}
			delete[] mat[i];

		}

		delete[] mat;
		mat = nullptr;

		
	}
	void ispisi() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (mat[i][j] != nullptr)
					cout << *mat[i][j]<<" ";
				else cout << " ";
			cout << endl;
		}
		

	}
 void dodaj(int k1, int k2) {
		if (k1<0 || k2<0 || k1> n - 1 || k2> n - 1) {
			return;
		}

		*mat[k1][k2] = 1;
		




	}






	void dodaj_cvor(int k) {

		if (k > n-1) {
			n++;
			int***pom = new int **[n];
			for (int i = 0; i < n; i++) {
				pom[i] = new int*[n];
				for (int j = 0; j < n; j++)
					if (j == n - 1 || i == n - 1)
						if (proveri_cvor(i) && proveri_cvor(j))
							pom[i][j] = new int(0);
						else
							pom[i][j] = nullptr;
					else
						if (mat[i][j] != nullptr)
							pom[i][j] = new int(*mat[i][j]);
						else
							pom[i][j] = nullptr;

			}
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - 1;j++)
					if (mat[i][j] != nullptr)
						delete mat[i][j];
				delete[] mat[i];
			}
			delete[]mat;

			mat = pom;
		}
		else {
			if (!proveri_cvor(k)) {

				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if (j == k || i == k)
							mat[i][j] = new int(0);
			}
			else
				cout << "Zadati cvor vec postoji u grafu!\n";
		}



		



	}
	void ukloni_cvor(int k) {
		if (k < 0 || k > n - 1 || !proveri_cvor(k)) {
			cout << "Dati cvor ne postoji\n";
			return;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i == k || j == k)
					if (mat[i][j] != nullptr) {
						delete mat[i][j];
						mat[i][j] = nullptr;
					}



		





	}
	void dodaj_granu(int k1, int k2) {
		if (proveri_cvor(k1) && proveri_cvor(k2) && (*mat[k1][k2]) == 0) {
			(*mat[k1][k2]) = 1; (*mat[k2][k1]) = 1;
		}
		


	}
	void ukloni_granu(int k1, int k2) {
		if (proveri_cvor(k1) && proveri_cvor(k2) && (*mat[k1][k2]) == 1) {
			(*mat[k1][k2]) = 0; (*mat[k2][k1]) = 0;
		}
		else
			cout << "Zadati cvorovi  ili nisu povezani ili ne postoje\n";



	



	}
	int dohv_dim() const {
		return n;
	}
	void promeni_vrednost(int i , int j, int n) {
		*mat[i][j] = n;

		

	}
	int dohv_vrednost(int i, int j) const{
		return *mat[i][j];
	}















};
