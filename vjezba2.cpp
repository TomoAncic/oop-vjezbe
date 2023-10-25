#include<iostream>
#include<iomanip>
using namespace std;


struct vector {
	int* podatak;
	int velicina;
	int kapacitet;
};

struct matrica {
	int stupci;
	int redci;
	float** podatci;
};

void unos_matrice(matrica& m)
{
	cout << "Unesite matricu: " << m.redci << m.stupci;
	for (int i = 0; i < m.redci; i++)
	{
		for (int j = 0; j < m.stupci; j++)
		{
			cin >> m.podatci[i][j];
		}
	}
}

void generiranje_matrice(matrica &m, float a, float b)
{
	for (int i = 0; i < m.redci; i++)
	{
		for (int j = 0; j < m.stupci; j++)
		{
			m.podatci[i][j] = a + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (b - a));

		}
	}
}

matrica zbrajanje(const matrica& A, const matrica& B)
{
	if (A.redci != B.redci || A.stupci != B.redci)
	{
		cout << "Matrice nemaju iste dimenzije.";
	}
	matrica rezultat;
	rezultat.redci = A.redci;
	rezultat.stupci = A.stupci;
	rezultat.podatci= new float* [A.redci];
	for (int i = 0; i < A.redci; i++) {
		rezultat.podatci[i] = new float[A.stupci];
		for (int j = 0; j < A.stupci; j++) {
			rezultat.podatci[i][j] = A.podatci[i][j] + B.podatci[i][j];
		}
	}
	return rezultat;
}

matrica oduzimanje(const matrica& A, const matrica& B)
{
	if (A.redci != B.redci || A.stupci != B.stupci)
	{
		cout << "Matrice nisu iste dimenzije.";
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

matrica mnozenje(const matrica& A, const matrica& B)
{
	if (A.stupci != B.redci)
	{
		cout << "Matice se ne mogu mnoziti";
	}
	matrica rezultat;
	rezultat.redci = A.redci;
	rezultat.redci = B.stupci;
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

matrica transponirana(const matrica m)
{
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

void ispis(const matrica& m) {
	for (int i = 0; i < m.redci; i++) 
	{
		for (int j = 0; j < m.stupci; j++)
		{
			cout << fixed << setprecision(4) << setw(10) << m.podatci[i][j];
		}
		cout << endl;
	}
}

void izbrisi(matrica& m) {
	for (int i = 0; i < m.redci; i++) {
		delete[] m.podatci[i];
	}
	delete[] m.podatci;
}

vector vector_new()
{
	vector v;
	v.podatak = new int[1];
	v.velicina = 0;
	v.kapacitet = 1;
	return v;
}

void vector_delete(vector& v)
{
	delete[] v.podatak;
	v.podatak = nullptr;
	v.velicina = 0;
	v.kapacitet = 0;
}

void vector_push_back(vector& v, int a)
{
	if (v.velicina >= v.kapacitet)
	{
		v.kapacitet = v.kapacitet * 2;
		int* novi_podatak = new int[v.kapacitet];
		for (int i = 0; i < v.velicina; i++)
		{
			novi_podatak[i] = v.podatak[i];
		}
		delete[] v.podatak;
		v.podatak = novi_podatak;
	}
	v.podatak[v.velicina] = a;
	v.velicina++;
}

void vector_pop_back(vector& v)
{
	if (v.velicina > 0)
	{
		v.velicina--;
	}
}

int vector_front(vector& v)
{
	if (v.velicina > 0)
	{
		return v.podatak[0];
	}
}

int vector_back(vector& v)
{
	if (v.velicina > 0)
	{
		return v.podatak[v.velicina - 1];
	}
}

int vector_size(vector& v)
{
	return v.velicina;
}

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

	/*vector v = vector_new();
	vector_push_back(v, 1);
	vector_push_back(v, 2);
	vector_push_back(v, 3);
	cout << "Prvi element: " << vector_front(v) << "\n";
	cout << "Zadnji element: " << vector_back(v) << "\n";
	cout << "Velicina: " << vector_size(v) << "\n";
	vector_pop_back(v);
	cout << "Posljednji element nakon uklanjanja: " << vector_back(v) << "\n";
	vector_delete(v);*/

	int m, n;
	cout << "Unesite broj redaka i stupaca: ";
	cin >> m >> n;
	matrica A;
	A.redci = m;
	A.stupci = n;
	A.podatci = new float* [m];
	for (int i = 0; i < m; i++)
	{
		A.podatci[i] = new float[n];
	}
	unos_matrice(A);
	cout << "Matrica A:\n";
	ispis(A);
	matrica B;
	B.redci = m;
	B.stupci = n;
	B.podatci = new float* [m];
	for (int i = 0; i < m; i++)
	{
		B.podatci[i] = new float[n];
	}
	generiranje_matrice(B, 1.0, 10.0);
	cout << "Generirana matrica B:\n";
	ispis(B);
	matrica C = zbrajanje(A, B);
	cout << "Zbroj matrica:\n";
	ispis(C);
	matrica D = oduzimanje(A, B);
	cout << "Oduzimanje matrica:\n";
	ispis(D);
	matrica E = mnozenje(A, B);
	cout << "Mnozenje matrica:\n";
	ispis(E);
	matrica F = transponirana(A);
	cout << "transponirana matrica:\n";
	ispis(F);
	izbrisi(A);
	izbrisi(B);
	izbrisi(C);
	izbrisi(D);
	izbrisi(E);
	izbrisi(F);


}