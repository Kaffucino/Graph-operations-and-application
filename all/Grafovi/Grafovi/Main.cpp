#include "dzp2.cpp"

int main() {
	Graf g;
	
	while (true) {
		cout << "Izbareite zadatak:\n";
		cout << "1 1. zadatak\n";
		cout << "2 2.zadatak:\n";
		cout << "0 Izadji\n";
		int k; cin >> k;
		switch (k) {
		case 1: {







			bool provera = false;
			while (true) {
				cout << "0. izadjite iz menija\n";
				cout << "1. kreiranje praznog grafa\n";
				cout << "2. dodavanje  cvora u graf\n";
				cout << "3. uklanjanje cvora iz grafa\n";
				cout << "4. dodavanje granje\n";
				cout << "5. uklanjanje grane\n";
				cout << "6. ispis grafa\n";
				cout << "7. brisanje grafa iz memorije\n";
				int c; cin >> c;
				if (c != 1 && c != 0)
					while (!provera) {
						cout << "Graf ne postoji!\n";
						cout << "1. kreiranje praznog grafa\n";
						cin >> c;
						if (c == 1)
							provera = true;
					}
				else
					provera = true;


				switch (c) {
				case 0: break;
				case 1: {cout << "Unesite broj cvorova grafa\n";
					int n;
					cin >> n;
					g.napravi(n);
					break;

				}
				case 2: {
					cout << "Unesite cvor koji zelite da dodate u graf\n"; int k; cin >> k;
					g.dodaj_cvor(k);
					break;

				}
				case 3: {
					cout << "Unesite cvor koji zelite da uklonite iz grafa\n"; int k; cin >> k;
					g.ukloni_cvor(k);
					break;
				}
				case 4: {
					cout << "Unesite cvorove koje zelite da spojite\n"; int i, j; cin >> i >> j;
					g.dodaj_granu(i, j);
					break;

				}
				case 5: {
					cout << "Unesite cvorove ciju granu zelite da uklonite\n"; int i, j; cin >> i >> j;
					g.ukloni_granu(i, j);
					break;

				}
				case 6:
				{
					cout << "Ispis  rezultujuceg grafa\n";
					g.ispisi();
					break;
				}
				case 7:
				{
					g.brisi();
					cout << "Obrisali ste graf iz memorije\n";
					break;
				}


				}
				if (c == 0)
					break;
				if (c == 7)
					provera = false;
			}
			break;
		}
		case 2:{
			Lavirint l;  int n, m, xu, yu, xi, yi;
			bool izbor = false;
			while (true) {
				cout << "0. kraj rada\n";
				cout << "1. kreiranje lavirinta\n";
				cout << "2. dodavanje prolaza\n";
				cout << "3. ispisite inicijalnu matricu dostiznost\n";
				cout << "4. ispitie finalnu matricu dostiznost\n";
				cout << "5. proverite da li je izlaz dostizan\n";
				cout << "6. ispisite resenje lavirinta\n";
				cout << "7. obrisite sve iz memorije\n";
				int c; cin >> c;
				if (c != 1 && c != 0)
					while (!izbor) {
						cout << "Lavirint ne postoji!\n";
						cout << "1. kreiranje lavirinta\n";
						cin >> c;
						if (c == 1)
							izbor = true;
					}

				else
					izbor = true;








				switch (c) {
				case 1:
				{
					cout << "Unesite dimenzije lavirinta\n";
					cin >> n >> m;
					if (n > 80 || m > 50 || n < 1 || m < 1) {
						cout << "Unete dimenzije nisu validne\n";
						izbor = false;
						break;

					}
					bool provera1 = true; bool provera2 = true;
					cout << "Unesite koordinate ulaza lavirinta\n";
					while (provera1) {
						cin >> xu >> yu;
						if (xu != 0 && yu != 0) {
							cout << "Ulaz mora biti na ivicama\n";

						}
						else
							provera1 = false;

					}
					cout << "Unesite koordinate izlaza lavirinta\n";
					while (provera2) {
						cin >> xi >> yi;
						if (xi != 0 && yi != 0) {
							cout << "Izlaz mora biti na ivicama\n";

						}
						else
							provera2 = false;

					}


					l.pravi_lavirint(n, m, xu, yu, xi, yi);
					l.pisi_lavirint();
					l.p.napravi(m*n);
					l.tez.napravi(m*n);
					break;


				}
				case 2: {
					while (true) {
						cout << "Unesite kooridnate prolaza ili -1 ako zelite da izadjete\n";
						int i, j;
						cin >> i;
						if (i == -1)
							break;
						cin >> j;
						if (i == xi && j == yi) {
							cout << "Na tim koordinatama je izlaz\n";
							continue;
						}
						if (i == xu && j == yu) {
							cout << "Na tim koordinatama je ulaz\n";
							continue;
						}
						l.dodaj_prolaz(i, j);
						l.pisi_lavirint();
						cout << endl;
					}
					l.napravi_mat_sus();
					l.update_p();
					l.promeni_tez_matricu();

					break;

				}
				case 3: {
					cout << "Inicijalna matrica dostiznosti\n";
					l.p.ispisi(); cout << endl;

					break;
				}
				case 4: {
					cout << "Finalna matrica dostiznosti\n";
					l.update_p2();
					cout << "Finalna matrica dostiznosti\n";
					l.p.ispisi();
					cout << endl;
					l.update_tez();
					break;

				}
				case 5: {
					l.update_p2();
					l.update_tez();
					if (l.proveri_dostiznost())
						cout << "Moguce je naci izlaz\n";
					else
						cout << "Nije moguce naci izlaz\n";
					break;
				}
				case 6: {
					l.update_p2();
					l.update_tez();
					if (l.proveri_dostiznost())
						l.resi_lavirint();
					else
						cout << "Lavirint se ne moze resiti\n";
					cout << endl;
					break;
				}
				case 7: {

					l.brisi_sve();
					cout << "Obrisali ste sve alocirano iz memorije\n";

				}
						if (c == 0)
							break;
						if (c == 7)
							izbor = false;

				}
				break;
                }



			}
			case 0: {
				exit(1);

			}



		}

}




	system("pause");
	return 0;
}