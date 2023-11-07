#include <iostream>

using namespace std;

//Am ales domeniul : Metropola

class Parc {
public:
	string nume;
	float suprafata;
	const int anInfiintare;
	static int capacitateMaxima;
	int numarStalpiIluminat;
	float* curentConsumat;

	Parc() :anInfiintare(2005) {
		this->nume = "Cismigiu";
		this->suprafata = 1000;
		this->numarStalpiIluminat = 2;
		this->curentConsumat = new float[this->numarStalpiIluminat];
		for (int i = 0; i < this->numarStalpiIluminat; i++)
			this->curentConsumat[i]=1000+i;
	}

	Parc(string nume) :anInfiintare(2005) {
		this->nume = nume;
		this->suprafata = 1000;
		this->numarStalpiIluminat = 2;
		this->curentConsumat = new float[this->numarStalpiIluminat];
		for (int i = 0; i < this->numarStalpiIluminat; i++)
			this->curentConsumat[i] = 1000 + i;
	}
	

	Parc(string nume, float suprafata, const int anInfiintare, int numarStalpiIluminat, float* curentConsumat) :anInfiintare(anInfiintare) {
		this->nume = nume;
		this->suprafata = suprafata;
		this->numarStalpiIluminat = numarStalpiIluminat;
		this->curentConsumat = new float[numarStalpiIluminat];
		for (int i = 0; i < numarStalpiIluminat; i++) {
			this->curentConsumat[i] = curentConsumat[i];
		}
	}

	void afisare()
	{
		cout << "Nume: " << this->nume << "\nSuprafata: " << this->suprafata << "\nAn infiintare: " << this->anInfiintare << "\nCapacitate parc: " << this->capacitateMaxima << "\nNumar stalpi iluminat: " << this->numarStalpiIluminat << "\nCurent consumat: ";
		for (int i = 0; i < this->numarStalpiIluminat ; i++) {
			cout << this->curentConsumat[i] << " ";
		}
		cout << endl;
	}

	static void afiseazaNumarParcuri() {
		cout << "\nCapacitatea parcului: " << capacitateMaxima << endl;
	}

	~Parc() {
		if (this->curentConsumat != NULL) {
			delete[]this->curentConsumat;
			this->curentConsumat = NULL;
		}
	}
};
int Parc::capacitateMaxima = 1000;

class Cladire {
public:
	string nume;
	const int anConstructie;
	static int numarEtaje;
	int numarCamere;
	float* suprafataCamere;

	Cladire() :anConstructie(2000) {
		this->nume = "Palatul Parlamentului";
		this->numarCamere = 12;
		this->suprafataCamere = new float[this->numarCamere];
		for (int i = 0; i < this->numarCamere; i++) {
			this->suprafataCamere[i] = 1;
		}
	}

	Cladire(int numarCamere) :anConstructie(2000) {
		this->nume = "Palatul Parlamentului";
		this->numarCamere = numarCamere;
		this->suprafataCamere = new float[this->numarCamere];
		for (int i = 0; i < this->numarCamere; i++) {
			this->suprafataCamere[i] = 1;
		}
	}

	Cladire(string nume, const int anConstructie, int numarCamere, float* suprafataCamere) :anConstructie(anConstructie) {
		this->nume = nume;
		this->numarCamere = numarCamere;
		this->suprafataCamere = new float[numarCamere];
		for (int i = 0; i < numarCamere; i++) {
			this->suprafataCamere[i] = suprafataCamere[i];
		}
	}

	void afisare()
	{
		cout << "Nume: " << this->nume <<"\nAn constructie: " << this->anConstructie << "\nNumar etaje: " << this->numarEtaje << "\nNumar camere: " << this->numarCamere << "\nSuprafata camera: ";
		for (int i = 0; i < this->numarCamere; i++) {
			cout << this->suprafataCamere[i] << " ";
		}
		cout << endl;
	}

	static void afiseazaNumarEtaje() {
		cout << "Numarul de etaje este: " << numarEtaje << endl;
	}

	~Cladire() {
		if (this->suprafataCamere != NULL) {
			delete[]this->suprafataCamere;
			this->suprafataCamere = NULL;
		}
	}
};
int Cladire::numarEtaje = 5;

class Metrou {
public:
	string nume;
	const int anInfiintare;
	static int pretBilet;
	int numarLinii;
	float* distantaLinii;

	Metrou() : anInfiintare(2009) {
		this->nume = "Metrorex";
		this->numarLinii = 4;
		this->distantaLinii = new float[this->numarLinii];
		for (int i = 0; i < this->numarLinii; i++) {
			this->distantaLinii[i] = 1;
		}
	}

	Metrou(string nume) : anInfiintare(2009) {
		this->nume = nume;
		this->numarLinii = 4;
		this->distantaLinii = new float[this->numarLinii];
		for (int i = 0; i < this->numarLinii; i++) {
			this->distantaLinii[i] = 1;
		}
	}

	Metrou(string nume, const int anInfiintare, int numarLinii, float* distantaLinii) : anInfiintare(anInfiintare) {
		this->nume = nume;
		this->numarLinii = numarLinii;
		this->distantaLinii = new float[numarLinii];
		for (int i = 0; i < numarLinii; i++) {
			this->distantaLinii[i] = distantaLinii[i];
		}
	}

	void afisare()
	{
		cout << "Nume: " << this->nume << "\nAn infiintare: " << this->anInfiintare << "\nPret bilet: " << this->pretBilet << "\nNumar linii: " << this->numarLinii << "\nDistanta linii: ";
		for (int i = 0; i < this->numarLinii; i++) {
			cout << this->distantaLinii[i] << " ";
		}
		cout << endl;
	}

	static void afiseazaPretBilet() {
		cout << "Pretul unui bilet este: " << pretBilet << endl;
	}
	
	~Metrou() {
		if (this->distantaLinii != NULL) {
			delete[]this->distantaLinii;
			this->distantaLinii = NULL;
		}
	}
};
int Metrou::pretBilet = 3;

void main() {
	Parc p1;
	p1.afisare(); cout << endl;
	
	Parc p2("Herastrau");
	p2.afisare(); cout << endl;

	float* curentConsumat = new float[11];
	for (int i = 0; i < 11; i++) {
		curentConsumat[i] = (i * i) * i;
	}
	Parc p3("Floreasca", 2801.3, 2008, 11, curentConsumat);
	p3.afisare(); cout << endl;


	Cladire c1;
	c1.afisare(); cout << endl;

	Cladire c2(3);
	c2.afisare(); cout << endl;

	float* suprafataCamere = new float[11];
	for (int i = 0; i < 11; i++) {
		suprafataCamere[i] = (i * i) * i;
	}
	Cladire c3("Ateneu", 1970, 7, suprafataCamere);
	c3.afisare(); cout << endl;

	Metrou m1;
	m1.afisare(); cout << endl;

	Metrou m2("Metromania");
	m2.afisare(); cout << endl;

	float* distantaLinii = new float[11];
	for (int i = 0; i < 11; i++) {
		distantaLinii[i] = (i * i) * i;
	}
	Metrou m3("Metroline", 2024, 5, distantaLinii);
	m3.afisare();
}