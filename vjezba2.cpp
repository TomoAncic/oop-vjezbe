#include<iostream>
#include<iomanip>
using namespace std;


struct vektor {
	int* podatak;
	int velicina;
	int kapaciteta;

	vektor() {
		podatak = new int[1];
		velicina = 0;
		kapaciteta = 1;
	};

	void vector_push_back(vektor& v, int a) {
		if (v.velicina >= v.kapaciteta) {
			v.kapaciteta = v.kapaciteta * 2;
			int* novi_podatak = new int[v.kapaciteta];
			for (int i = 0; i < v.velicina; i++)
				novi_podatak[i] = v.podatak[i];
			delete[] v.podatak;
			v.podatak = novi_podatak;
		}
		v.podatak[v.velicina] = a;
		v.velicina++;
	}

	void vector_pop_back(vektor& v) {
		if (v.velicina > 0)
			v.velicina--;
	}

	int& vector_front(vektor& v) {
		if (v.velicina > 0)
			return v.podatak[0];
	}

	int& vector_back(vektor& v) {
		if (v.velicina > 0)
			return v.podatak[v.velicina - 1];
	}

	int vector_size(vektor& v) {
		return v.velicina;
	}

	void vector_delete(vektor& v) {
		delete[] v.podatak;
	}
};


struct matrica {
	int stupci;
	int redci;
	float** podatci;

	static void unos_matrice(matrica& m) {
		cout << "Unesite matricu: " << m.redci << " " << m.stupci << endl;
		for (int i = 0; i < m.redci; i++) {
			for (int j = 0; j < m.stupci; j++) {
				cin >> m.podatci[i][j];
			}
		}
	}

	static void generiranje_matrice(matrica& m, float a, float b) {
		for (int i = 0; i < m.redci; i++) {
			for (int j = 0; j < m.stupci; j++) {
				m.podatci[i][j] = a + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (b - a));
			}
		}
	}

	static matrica zbrajanje(const matrica& A, const matrica& B) {
		if (A.redci != B.redci || A.stupci != B.stupci) {
			cout << "Matrice nemaju iste dimenzije.";
			exit(1); // Exit the program if matrices have different dimensions
		}
		matrica rezultat;
		rezultat.redci = A.redci;
		rezultat.stupci = A.stupci;
		rezultat.podatci = new float* [A.redci];
		for (int i = 0; i < A.redci; i++) {
			rezultat.podatci[i] = new float[A.stupci];
			for (int j = 0; j < A.stupci; j++) {
				rezultat.podatci[i][j] = A.podatci[i][j] + B.podatci[i][j];
			}
		}
		return rezultat;
	}

	static matrica oduzimanje(const matrica& A, const matrica& B) {
		if (A.redci != B.redci || A.stupci != B.stupci) {
			cout << "Matrice nisu iste dimenzije.";
			exit(1); // Exit the program if matrices have different dimensions
		}
		matrica rezultat;
		rezultat.redci = A.redci;
		rezultat.stupci = A.stupci;
		rezultat.podatci = new float* [A.redci];
		for (int i = 0; i < A.redci; i++) {
			rezultat.podatci[i] = new float[A.stupci];
			for (int j = 0; j < A.stupci; j++) {
				rezultat.podatci[i][j] = A.podatci[i][j] - B.podatci[i][j];
			}
		}
		return rezultat;
	}

	static matrica mnozenje(const matrica& A, const matrica& B) {
		if (A.stupci != B.redci) {
			cout << "Matice se ne mogu mnoziti";
			exit(1); // Exit the program if matrices cannot be multiplied
		}
		matrica rezultat;
		rezultat.redci = A.redci;
		rezultat.stupci = B.stupci;
		rezultat.podatci = new float* [A.redci];
		for (int i = 0; i < A.redci; i++) {
			rezultat.podatci[i] = new float[B.stupci];
			for (int j = 0; j < B.stupci; j++) {
				float sum = 0.0;
				for (int k = 0; k < A.stupci; k++) {
					sum += A.podatci[i][k] * B.podatci[k][j];
				}
				rezultat.podatci[i][j] = sum;
			}
		}
		return rezultat;
	}

	static matrica transponirana(const matrica& m) {
		matrica rezultat;
		rezultat.redci = m.stupci;
		rezultat.stupci = m.redci;
		rezultat.podatci = new float* [m.stupci];
		for (int i = 0; i < m.stupci; i++) {
			rezultat.podatci[i] = new float[m.redci];
			for (int j = 0; j < m.redci; j++) {
				rezultat.podatci[i][j] = m.podatci[j][i];
			}
		}
		return rezultat;
	}

	static void ispis(const matrica& m) {
		for (int i = 0; i < m.redci; i++) {
			for (int j = 0; j < m.stupci; j++) {
				cout << m.podatci[i][j] << " ";
			}
			cout << endl;
		}
	}

	static void izbrisi(matrica& m) {
		for (int i = 0; i < m.redci; i++) {
			delete[] m.podatci[i];
		}
		delete[] m.podatci;
	}
};

void zad1(int n, int arr[], int& a, int& b)
{
	int i;
	a = arr[0];
	b = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] < a)
		{
			a = arr[i];
		}
		if (arr[i] < b)
		{
			b = arr[i];
		}
	}
}

int& zad2(int arr[], int& a)
{
	arr[a] += 1;
	return arr[a];
}


int main()
{
	/*int i, n;
	int arr[100];
	int max, min;
	cout << "unesite velicinu niza: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Unesite elemente niza: ";
		cin >> arr[i];
	}
	zad1(n, arr, max, min);
	cout << "Najmanji broj u nizu je: " << min;
	cout << "Najveci broj u nizu je: " << max;*/

	//int arr[] = { 12,15,33,42,13 };
	//int a;
	//int referenca;
	//cout << "Koji element u nizu zelite povecati";
	//cin >> a;
	//zad2(arr, a) = referenca;
	//cout << "uvecani element je: " << referenca;

	//vektor v;
	//v.vector_push_back(v, 1);
	//v.vector_push_back(v, 2);
	//v.vector_push_back(v, 3);
	//cout << "Prvi element: " << v.vector_front(v) << "\n";
	//cout << "Zadnji element: " << v.vector_back(v) << "\n";
	//cout << "Velicina: " << v.vector_size(v) << "\n";
	//v.vector_pop_back(v);
	//cout << "Posljednji element nakon uklanjanja: " << v.vector_back(v) << "\n";
	//v.vector_delete(v);

	int m, n;
	cout << "Unesite broj redaka i stupaca: ";
	cin >> m >> n;

	matrica A;
	A.redci = m;
	A.stupci = n;
	A.podatci = new float* [m];
	for (int i = 0; i < m; i++) {
		A.podatci[i] = new float[n];
	}
	matrica::unos_matrice(A);
	cout << "Matrica A:\n";
	matrica::ispis(A);

	matrica B;
	B.redci = m;
	B.stupci = n;
	B.podatci = new float* [m];
	for (int i = 0; i < m; i++) {
		B.podatci[i] = new float[n];
	}
	matrica::generiranje_matrice(B, 1.0, 10.0);
	cout << "Generirana matrica B:\n";
	matrica::ispis(B);

	matrica C = matrica::zbrajanje(A, B);
	cout << "Zbroj matrica:\n";
	matrica::ispis(C);

	matrica D = matrica::oduzimanje(A, B);
	cout << "Oduzimanje matrica:\n";
	matrica::ispis(D);

	matrica E = matrica::mnozenje(A, B);
	cout << "Mnozenje matrica:\n";
	matrica::ispis(E);

	matrica F = matrica::transponirana(A);
	cout << "Transponirana matrica A:\n";
	matrica::ispis(F);

	matrica::izbrisi(A);
	matrica::izbrisi(B);
	matrica::izbrisi(C);
	matrica::izbrisi(D);
	matrica::izbrisi(E);
	matrica::izbrisi(F);

}
