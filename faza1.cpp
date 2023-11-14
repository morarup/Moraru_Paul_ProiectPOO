#include <iostream>

using namespace std;

//Am ales domeniul : Metropola

class Parc {
private:
	string nume;
	float suprafata;
	const int anInfiintare;
	static int capacitateMaxima;
	int numarStalpiIluminat;
	float* curentConsumat;
public:

    string getNume(){
        return this->nume;
    }

    float getSuprafata(){
        return this->suprafata;
    }

     int getAnInfiintare(){
        return this->anInfiintare;
    }

    int getCapacitateMaxima() {
        return this->capacitateMaxima;
    }

    int getNumarStalpiIluminat(){
        return this->numarStalpiIluminat;
    }

    float* getCurentConsumat(){
        return this->curentConsumat;
    }

    void setNume(string numeNou){
        this->nume=numeNou;
    }

    void setSuprafata(float suprafataNoua){
        this->suprafata=suprafataNoua;
    }

    static void setCapacitateMaxima(int capacitateMaximaNou){
        capacitateMaxima=capacitateMaximaNou;
    }

    void setCurentConsumat(int numarStalpiIluminatNou, float* curentConsumat){
        this->numarStalpiIluminat=numarStalpiIluminatNou;
        if(this->curentConsumat!=NULL){
            delete[]this->curentConsumat;
        }
        this->curentConsumat=new float[this->numarStalpiIluminat];
        for (int i=0; i<this->numarStalpiIluminat; i++){
            this->curentConsumat[i]=curentConsumat[i];
        }
    }

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

    Parc(const Parc& parc): anInfiintare(parc.anInfiintare){
        this->nume=parc.nume;
        this->suprafata=parc.suprafata;
        this->numarStalpiIluminat=parc.numarStalpiIluminat;
        this->curentConsumat=new float(this->numarStalpiIluminat);
        for(int i=0;i<this->numarStalpiIluminat;i++){
            this->curentConsumat[i]=parc.curentConsumat[i];
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

	~Parc() {
		if (this->curentConsumat != NULL) {
			delete[]this->curentConsumat;
			this->curentConsumat = NULL;
		}
	}
};
int Parc::capacitateMaxima = 1000;

class Cladire {
private:
	string nume;
	const int anConstructie;
	static int numarEtaje;
	int numarCamere;
	float* suprafataCamere;
public:
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

    Cladire(Cladire& cladire): anConstructie(cladire.anConstructie){
        this->nume=cladire.nume;
        this->numarCamere=cladire.numarCamere;
        this->suprafataCamere=new float[this->numarCamere];
        for(int i=0;i<numarCamere;i++){
            this->suprafataCamere[i]=cladire.suprafataCamere[i];
        }
    }

    string getNume(){
        return this->nume;
    }

    int getAnConstructie(){
        return this->anConstructie;
    }

    int getNumarEtaje(){
        return this->numarEtaje;
    }

    int getNumarCamere() {
        return this->numarCamere;
    }

    float* getSuprafataCamere(){
        return this->suprafataCamere;
    }

    void setNume(string nume){
        this->nume=nume;
    }

    static void setNumarEtaje(int numarEtajeNou){
        numarEtaje=numarEtajeNou;
    }

    void setSuprafataCamere(int numarCamere, float* suprafataCamere){
        this->numarCamere=numarCamere;
        if(this->suprafataCamere!=NULL){
            delete[]this->suprafataCamere;
        }
        this->suprafataCamere=new float[this->numarCamere];
        for (int i=0; i<this->numarCamere; i++){
            this->suprafataCamere[i]=suprafataCamere[i];
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

	~Cladire() {
		if (this->suprafataCamere != NULL) {
			delete[]this->suprafataCamere;
			this->suprafataCamere = NULL;
		}
	}
};
int Cladire::numarEtaje = 5;

class Metrou {
private:
	string nume;
	const int anInfiintare;
	static int pretBilet;
	int numarLinii;
	float* distantaLinii;
public:
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

    Metrou(Metrou& metrou) : anInfiintare(metrou.anInfiintare){
        this->nume=metrou.nume;
        this->numarLinii=metrou.numarLinii;
        this->distantaLinii=new float[this->numarLinii];
        for(int i=0;i<this->numarLinii;i++){
            this->distantaLinii[i]=metrou.distantaLinii[i];
        }

    }

    string getNume(){
        return this->nume;
    }

    int getAnInfiintare(){
        return this->anInfiintare;
    }

    int getPretBilet(){
        return this->pretBilet;
    }

    int getNumarLinii() {
        return this->numarLinii;
    }

    float* getDistantaLinii(){
        return this->distantaLinii;
    }

    void setNume(string nume){
        this->nume=nume;
    }

    static void setPretBilet(int pretBiletNou){
        pretBilet=pretBiletNou;
    }

    void setDistantaLinii(int numarLinii, float* distantaLinii){
        this->numarLinii=numarLinii;
        if(this->distantaLinii!=NULL){
            delete[]this->distantaLinii;
        }
        this->distantaLinii=new float[this->numarLinii];
        for (int i=0; i<this->numarLinii; i++){
            this->distantaLinii[i]=distantaLinii[i];
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
	
	~Metrou() {
		if (this->distantaLinii != NULL) {
			delete[]this->distantaLinii;
			this->distantaLinii = NULL;
		}
	}
};
int Metrou::pretBilet = 3;

int main() {
	Parc p1;
	p1.afisare(); cout << endl;
	
	/*Parc p2("Herastrau");
	p2.afisare(); cout << endl;

	float* curentConsumat = new float[11];
	for (int i = 0; i < 11; i++) {
		curentConsumat[i] = (i * i) * i;
	}
	Parc p3("Floreasca", 2801.3, 2008, 11, curentConsumat);
	p3.afisare(); cout << endl; */

    cout<<"Afisare nume parc: "<<p1.getNume()<<endl;
    cout<<"Afisare suprafata: "<<p1.getSuprafata()<<endl;
    cout<<"Afisare anul infiintarii: "<<p1.getAnInfiintare()<<endl;
    cout<<"Afisare numarul stalpilor de iluminat"<<p1.getNumarStalpiIluminat()<<endl;
    for ( int i=0; i<p1.getNumarStalpiIluminat();i++)
        cout<<"Curent consumat: "<<p1.getCurentConsumat()[i]<<endl;

    cout<<endl;
	Cladire c1;
	c1.afisare(); cout << endl;

    cout<<"Afisare nume parc: "<<c1.getNume()<<endl;
    cout<<"Afisare an constructie: "<<c1.getAnConstructie()<<endl;
    cout<<"Afisare numar etaje: "<<c1.getNumarEtaje()<<endl;
    cout<<"Afisare numar camere: "<<c1.getNumarCamere()<<endl;
    for ( int i=0; i<c1.getNumarCamere();i++)
        cout<<"Suprafata: "<<c1.getSuprafataCamere()[i]<<endl;
	/*Cladire c2(3);
	c2.afisare(); cout << endl;

	float* suprafataCamere = new float[11];
	for (int i = 0; i < 11; i++) {
		suprafataCamere[i] = (i * i) * i;
	}

	Cladire c3("Ateneu", 1970, 7, suprafataCamere);
	c3.afisare(); cout << endl; */

    cout<<endl;

	Metrou m1;
	m1.afisare(); cout << endl;

    cout<<"Afisare nume : "<<m1.getNume()<<endl;
    cout<<"Afisare an infiintare: "<<m1.getAnInfiintare()<<endl;
    cout<<"Afisare pret bilet: "<<m1.getPretBilet()<<endl;
    cout<<"Afisare numar linii: "<<m1.getNumarLinii()<<endl;
    for ( int i=0; i<m1.getNumarLinii();i++)
        cout<<"Distanta linii: "<<m1.getDistantaLinii()[i]<<endl;
    cout<<endl;
	/*Metrou m2("Metromania");
	m2.afisare(); cout << endl;

	float* distantaLinii = new float[11];
	for (int i = 0; i < 11; i++) {
		distantaLinii[i] = (i * i) * i;
	}

	Metrou m3("Metroline", 2024, 5, distantaLinii);
	m3.afisare(); */

    return 0;
}