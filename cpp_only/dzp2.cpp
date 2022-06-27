#include "dzp1.cpp"
struct Stack {

private:
	int n, kap, top;
	int *stek;
public:
	void napravi_stack(int kapp) {
		kap = kapp;
		stek = new int[kap];
		n = 0; top = -1;
		
	}
        void push_stack(int v) {
		top++;
		stek[top] = v;
		n++;
		
	}
	int pop_stack() {
		int v = stek[top];
		top--;
		return v;
	}
	bool empty_stack() {
		if (top == -1)
			return true;
		else
			return false;
	}
	int dohv_top()const {
		return top;
	}

	void brisi_stek() {
		delete[] stek;
	}
	










};






struct Lavirint {
	int n, m, xi, xu, yi, yu;
	char**mat;
	Graf p,tez,sus;
	

  void update_p() {
	  int t = -1;
	  for (int i = 0; i < n; i++) 
		  for (int j = 0; j < m; j++) {
			  t++;
			  if (mat[i][j] == '_' || mat[i][j]=='o' || mat[i][j]=='x') {
				  if (((j + 1) < m) && (mat[i][j + 1] == '_' || mat[i][j + 1] == 'o' || mat[i][j + 1] == 'x')) { // da li ima prolaz desno
					  p.dodaj_granu(t, t + 1);  sus.promeni_vrednost(t, t + 1, t); sus.promeni_vrednost(t+1, t, t+1);
				  }
				  if (((j - 1) > 0) && (mat[i][j - 1] == '_' || mat[i][j - 1] == 'o' || mat[i][j - 1] == 'x')) {
					  p.dodaj_granu(t, t - 1);  sus.promeni_vrednost(t, t - 1, t); sus.promeni_vrednost(t - 1, t, t - 1);
				  } // da li ima prolaz levo
				  if (((i - 1) > 0) && (mat[i - 1][j] == '_' || mat[i - 1][j] == 'o' || mat[i - 1][j] == 'x')) {
					  p.dodaj_granu(t - m, t); sus.promeni_vrednost(t-m, t, t-m); sus.promeni_vrednost(t, t-m, t);
				  }// da li ima prolaz  gore
				   if (((i + 1) < n) && (mat[i + 1][j] == '_' || mat[i + 1][j] == 'o' || mat[i + 1][j] == 'x')) { // da li ima prolaz dole
					   p.dodaj_granu(t, t + m);  sus.promeni_vrednost(t, t + m, t); sus.promeni_vrednost(t + m, t, t + m);
				   }

			  }



		  }


	  
	}
   void promeni_tez_matricu() {
	  for (int i = 0; i < n*m; i++)
		  for (int j = 0; j < n*m; j++)
			  tez.promeni_vrednost(i, j, p.dohv_vrednost(i, j));
	  for (int i = 0; i < n*m; i++)
		  for (int j = 0; j < n*m; j++) {
			  if (tez.dohv_vrednost(i, j) == 0 )
				  tez.promeni_vrednost(i, j, 100);
			  if (i == j)
				  tez.promeni_vrednost(i, j, 0);

		  }
	  
  }
 
  void napravi_mat_sus() {
	  sus.napravi(m*n);
	  for (int i = 0; i < n*m; i++)
		  for (int j = 0; j < n*m; j++)
			  sus.promeni_vrednost(i, j, -1);


  }
  void update_tez() { // trazenje najkraceg puta
	  for (int k = 0; k < n*m;k++)
		  for (int i = 0; i < n*m;i++)
			  for (int j = 0; j < n*m;j++)
				  if ((tez.dohv_vrednost(i, j)) > (tez.dohv_vrednost(i, k) + tez.dohv_vrednost(k, j)) && i!=j) {
					  sus.promeni_vrednost(i, j, sus.dohv_vrednost(k, j));
					  tez.promeni_vrednost(i, j, (tez.dohv_vrednost(i, k) + tez.dohv_vrednost(k, j)));
				  
				  }
	  
  }




  
  void update_p2() { // pravljenje konace matrice dostiznosti

	  for (int k = 0; k < n*m; k++)
		  for (int i = 0; i < n*m; i++)
			  for (int j = 0; j < n*m; j++)
				  if (i != j) 
					  p.promeni_vrednost(i, j, p.dohv_vrednost(i, j) | (p.dohv_vrednost(i, k) & p.dohv_vrednost(k, j)));	  
				  
				  


  }
		  

  int dohv_ulaz() const {
	  int t = -1;
	  for(int i=0 ; i< n ; i++)
		  for (int j = 0; j < m;j++) {
			  t++;
			  if (mat[i][j] == 'o')
				  return t;
		  }
}
  int dohv_izlaz() const {
	  int t = -1;
	  for (int i = 0; i < n; i++)
		  for (int j = 0; j < m;j++) {
			  t++;
			  if (mat[i][j] == 'x')
				  return t;
		  }
  }
  bool proveri_dostiznost() const {
	  
	  int ulaz = dohv_ulaz(); int izlaz = dohv_izlaz();

	  if (p.dohv_vrednost(ulaz, izlaz) == 1)
		  return true;
	  else
		  return false;




  }













  void resi_lavirint() {
	  int i = dohv_ulaz(); int j = dohv_izlaz(); Stack s;
	  s.napravi_stack(n*m);

	  int k = j;

	  while (true) {
		  int t = -1;
		  for (int i = 0; i < n; i++) {
			  for (int j = 0; j < m; j++) {
				  t++;
				  if (k == t) {
					  s.push_stack(i);
					  s.push_stack(j);
					  break;
				  }


			  }
			  if (k == t)
				  break;
		  }
		  int y = k;
	 k = sus.dohv_vrednost(i, y);
	 if (k == i) {
		 t = -1;
		 for (int i = 0; i < n; i++) {
			 for (int j = 0; j < m; j++) {
				 t++;
				 if (k == t) {
					 s.push_stack(i);
					 s.push_stack(j);
					 break;
				 }


			 }
			 if (k == t)
				 break;
		 }
		 
		 
		 
		 
		 break;

	 }
		  
		  
	  }
	  while (s.dohv_top() > 1)
		  cout << '(' << s.pop_stack() << ',' <<s.pop_stack()<<")->";
	  cout << '(' << s.pop_stack() << ',' << s.pop_stack() << ")";

	  s.brisi_stek();

  }




	void pravi_lavirint(int nn, int mm, int xuu, int yuu, int xii, int yii) {
		n = nn; m = mm; xu = xuu; yu = yuu; xi = xii; yi = yii;
		mat = new char*[n];
		for (int i = 0; i < n; i++) {
			mat[i] = new char[m];
			for (int j = 0; j < m; j++)
				if (i == xu && j == yu)
					mat[i][j] = 'o';
				else if (i == xi && j == yi)
					mat[i][j] = 'x';
				else
					mat[i][j] = '#';

		}
		
		



		

	}
	void pisi_lavirint() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m;j++)
				cout << mat[i][j];
			cout << endl;

		}
	}
	void dodaj_prolaz(int x, int y) {
		if (x<0 || y<0 || x> n - 1 || y>m - 1) {
			cout << "Kooridnate prolaza nisu dosegu lavirinta\n";
			return;
		}
		
		if (mat[x][y] == '_') {
			cout << "Na tim koordinatam vec postoji prolaz\n";
			return;
		}
		
		mat[x][y] = '_';
		




		
		

	}
	void brisi_sve() {
		for (int i = 0; i < n; i++)
			delete[] mat[i];
		delete[] mat;
		mat = nullptr;
		p.brisi();
		sus.brisi();
		tez.brisi();
		


	}










};