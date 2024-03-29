#include <iostream>
#include <fstream>

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

    Parc& operator=(const Parc& p) {
        if (this != &p) {
            this->nume = p.nume;
            this->suprafata = p.suprafata;
            this->numarStalpiIluminat = p.numarStalpiIluminat;
            if (this->curentConsumat != NULL) {
                delete[]this->curentConsumat;
            }

            this->curentConsumat = new float[this->numarStalpiIluminat];
            for (int i = 0; i < this->numarStalpiIluminat; i++)
            {
                this->curentConsumat[i] = p.curentConsumat[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const Parc& p) {
        consola << "Nume: " << p.nume << "\nSuprafata: " << p.suprafata << "\nAn infiintare: " << p.anInfiintare << "\nCapacitate parc: " << p.capacitateMaxima << "\nNumar stalpi iluminat: " << p.numarStalpiIluminat << "\nCurent consumat: ";
        for (int i = 0; i < p.numarStalpiIluminat - 1; i++) {
            consola << p.curentConsumat[i] << ", ";
        }

        consola << p.curentConsumat[p.numarStalpiIluminat - 1] << endl;
        return consola;
    }

    friend ofstream& operator<<(ofstream& consola, const Parc& p) {
        consola << p.nume << "\n" << p.suprafata << "\n" << p.anInfiintare << "\n" << p.capacitateMaxima << "\n" << p.numarStalpiIluminat << "\n";
        for (int i = 0; i < p.numarStalpiIluminat - 1; i++) {
            consola << p.curentConsumat[i] << " ";
        }
        consola << p.curentConsumat[p.numarStalpiIluminat - 1] << endl;
        return consola;
    }

    friend istream& operator>>(istream& in, Parc& p) {
        cout << "Nume:"; in >> p.nume;
        cout << "Suprafata:"; in >> p.suprafata;
        cout << "Numar stalpi iluminat:"; in >> p.numarStalpiIluminat;
        if (p.curentConsumat) {
            delete[]p.curentConsumat;
        }
        p.curentConsumat = new float[p.numarStalpiIluminat];
        cout << "Curent consumat: ";
        for (int i = 0; i < p.numarStalpiIluminat; i++) {
            in >> p.curentConsumat[i];
        }
        return in;
    }

    friend ifstream& operator>>(ifstream& in, Parc& p) {
        in >> p.nume;
        in >> p.suprafata;
        float val = 0;
        in >> val;
        in >> val;

        in >> p.numarStalpiIluminat;
        if (p.curentConsumat) {
            delete[]p.curentConsumat;
        }
        p.curentConsumat = new float[p.numarStalpiIluminat];
        for (int i = 0; i < p.numarStalpiIluminat; i++) {
            in >> p.curentConsumat[i];
        }
        return in;
    }

    bool operator ==(int capacitateParc)
    {
        if (this->capacitateMaxima == capacitateParc)
        {
            cout<<"Este egal";
        }
        else
        {
            cout<<"Este diferit";
        }
    }

    Parc& operator++()
    {
        this->numarStalpiIluminat++;
        return *this;
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

class ParcDeDistractii: public Parc{
private:
    int numarAtractii;
public:
    ParcDeDistractii():Parc() {
     this->numarAtractii = 5;
    }

    ParcDeDistractii(int numarAtractii): Parc(){
        this->numarAtractii = numarAtractii;
    }

    ParcDeDistractii(string nume, float suprafata, const int anInfiintare, int numarStalpiIluminat, float* curentConsumat, int numarAtractii):
        Parc(nume,suprafata,anInfiintare,numarStalpiIluminat,curentConsumat){
        this->numarAtractii = numarAtractii;
    }

    int getNumarAtractii() {
        return this->numarAtractii;
    }

    void setNumarAtractii(int numarAtractiiNou) {
        this->numarAtractii = numarAtractiiNou;
    }

    ParcDeDistractii& operator=(const ParcDeDistractii& pdd) {
        if (this != &pdd) {
            Parc::operator=(pdd);
            this->numarAtractii = pdd.numarAtractii;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const ParcDeDistractii& pdd) {
        cout<<(Parc)pdd;
        cout << "Numar atractii: " << pdd.numarAtractii<<endl;
        return consola;
    }

    friend istream& operator>>(istream& in, ParcDeDistractii& pdd) {
        cout << "Numar atractii:"; in >> pdd.numarAtractii;
        return in;
    }

    ~ParcDeDistractii() {

    }
};

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

    Cladire& operator=(const Cladire& c) {
        if (this != &c) {
            this->nume = c.nume;
            this->numarCamere=c.numarCamere;
            if (this->suprafataCamere != NULL) {
                delete[]this->suprafataCamere;
            }

            this->suprafataCamere = new float[this->numarCamere];
            for (int i = 0; i < this->numarCamere; i++)
            {
                this->suprafataCamere[i] = c.suprafataCamere[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const Cladire& c) {
        cout << "Nume: " << c.nume <<"\nAn constructie: " << c.anConstructie << "\nNumar etaje: " << c.numarEtaje << "\nNumar camere: " << c.numarCamere << "\nSuprafata camera: ";
        for (int i = 0; i < c.numarCamere - 1; i++) {
            cout << c.suprafataCamere[i] << ", ";
        }

        cout << c.suprafataCamere[c.numarCamere - 1] << endl;
        return consola;
    }

    friend istream& operator>>(istream& in, Cladire& c) {
        cout << "Nume:"; in >> c.nume;
        cout << "Numar camere:"; in >> c.numarCamere;
        if (c.suprafataCamere) {
            delete[]c.suprafataCamere;
        }
        c.suprafataCamere = new float[c.numarCamere];
        cout << "Suprafata camere: ";
        for (int i = 0; i < c.numarCamere; i++) {
            in >> c.suprafataCamere[i];
        }
        return in;
    }

    bool operator ==(int numarCamere)
    {
        if (this->numarCamere == numarCamere)
        {
            cout<<"Este egal";
        }
        else
        {
            cout<<"Este diferit";
        }
    }

    Cladire& operator++()
    {
        this->numarCamere++;
        return *this;
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

    Metrou& operator=(const Metrou& m) {
        if (this != &m) {
            this->nume = m.nume;
            this->numarLinii = m.numarLinii;
            if (this->distantaLinii != NULL) {
                delete[]this->distantaLinii;
            }

            this->distantaLinii = new float[this->numarLinii];
            for (int i = 0; i < this->numarLinii; i++)
            {
                this->distantaLinii[i] = m.distantaLinii[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const Metrou& m) {
        cout << "Nume: " << m.nume << "\nAn infiintare: " << m.anInfiintare<< "\nPret bilet: " << m.pretBilet << "\nNumar linii: " << m.numarLinii << "\nDistanta linii: ";
        for (int i = 0; i < m.numarLinii - 1; i++) {
            cout << m.distantaLinii[i] << ", ";
        }

        cout << m.distantaLinii[m.numarLinii - 1] << endl;
        return consola;
    }

    friend ofstream& operator<<(ofstream& consola, const Metrou& p) {
        consola << p.nume << "\n" << p.anInfiintare << "\n" << p.pretBilet << "\n" << p.numarLinii << "\n";
        for (int i = 0; i < p.numarLinii - 1; i++) {
            consola << p.distantaLinii[i] << " ";
        }
        consola << p.distantaLinii[p.numarLinii - 1] << endl;
        return consola;
    }

    friend istream& operator>>(istream& in, Metrou& m) {
        cout << "Nume:"; in >> m.nume;
        cout << "Numar linii:"; in >> m.numarLinii;
        if (m.distantaLinii) {
            delete[]m.distantaLinii;
        }
        m.distantaLinii = new float[m.numarLinii];
        cout << "Disanta linii: ";
        for (int i = 0; i < m.numarLinii; i++) {
            in >> m.distantaLinii[i];
        }
        return in;
    }

    friend ifstream& operator>>(ifstream& in, Metrou& p) {
        in >> p.nume;

        float val = 0;
        in >> val;
        in >> val;

        in >> p.numarLinii;
        if (p.distantaLinii) {
            delete[]p.distantaLinii;
        }
        p.distantaLinii = new float[p.numarLinii];
        for (int i = 0; i < p.numarLinii; i++) {
            in >> p.distantaLinii[i];
        }
        return in;
    }

    bool operator ==(int numarLinii)
    {
        if (this->numarLinii == numarLinii)
        {
            cout<<"Este egal";
        }
        else
        {
            cout<<"Este diferit";
        }
    }

    Metrou& operator++()
    {
        this->numarLinii++;
        return *this;
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

class StatieDeMetrou: public Metrou{
private:
    int numarIntrari;
public:
    StatieDeMetrou():Metrou() {
        this->numarIntrari = 5;
    }

    StatieDeMetrou(int numarIntrari): Metrou(){
        this->numarIntrari = numarIntrari;
    }

    StatieDeMetrou(string nume, const int anInfiintare, int numarLinii, float* distantaLinii, int numarIntrari):
            Metrou(nume, anInfiintare, numarLinii, distantaLinii){
        this->numarIntrari = numarIntrari;
    }

    int getNumarIntrari() {
        return this->numarIntrari;
    }

    void setNumarIntrari(int numarIntrariNou) {
        this->numarIntrari = numarIntrariNou;
    }

    StatieDeMetrou& operator=(const StatieDeMetrou& sdm) {
        if (this != &sdm) {
            Metrou::operator=(sdm);
            this->numarIntrari = sdm.numarIntrari;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const StatieDeMetrou& sdm) {
        cout<<(Metrou &) sdm;
        cout << "Numar intrari: " << sdm.numarIntrari<<endl;
        return consola;
    }

    friend istream& operator>>(istream& in, StatieDeMetrou& sdm) {
        cout << "Numar intrari:"; in >> sdm.numarIntrari;
        return in;
    }

    ~StatieDeMetrou() {

    }
};

class TransportInComun{
private:
    string numeTransport;
    int capacitate;
    Metrou metrou;
public:
    TransportInComun()
    {
        this->numeTransport = "Metrou";
        this->capacitate = 250;
        this->metrou=Metrou();
    }

    TransportInComun(string numeTransport, int capacitate, Metrou metrou){
        this->numeTransport=numeTransport;
        this->capacitate=capacitate;
        this->metrou=metrou;
    }

    ~TransportInComun() {

    }

    string getNumeTransport(){
        return this->numeTransport;
    }

    int getCapacitate(){
        return this->capacitate;
    }

    Metrou getMetrou(){
        return this->metrou;
    }

    void setNumeTransport(string numeTransportNou){
        this->numeTransport=numeTransportNou;
    }

    void setCapacitate(int capacitateNoua){
        this->capacitate=capacitateNoua;
    }

    void setMetrou(Metrou metrou){
        this->metrou=metrou;
    }

    TransportInComun& operator=(const TransportInComun& tic) {
        if (this != &tic) {
            this->numeTransport = tic.numeTransport;
            this->capacitate = tic.capacitate;
            this->metrou=tic.metrou;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const TransportInComun& tic) {
        cout << "Nume transport: " << tic.numeTransport << "\nCapacitate maxima: " << tic.capacitate<< "\nMetrou: " <<endl<< tic.metrou;
        return consola;
    }

    friend istream& operator>>(istream& in, TransportInComun& tic) {
        cout << "Nume transport:"; in >> tic.numeTransport;
        cout << "Capacitate maxima:"; in >> tic.capacitate;
        cout << "Metrou:"; in >> tic.metrou;
        return in;
    }
};

int main() {
	/*Parc p1;
	p1.afisare(); cout << endl;
	
	Parc p2("Herastrau");
	p2.afisare(); cout << endl;

	float* curentConsumat = new float[11];
	for (int i = 0; i < 11; i++) {
		curentConsumat[i] = (i * i) * i;
	}
	Parc p3("Floreasca", 2801.3, 2008, 11, curentConsumat);
	p3.afisare(); cout << endl;

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
	Cladire c2(3);
	c2.afisare(); cout << endl;

	float* suprafataCamere = new float[11];
	for (int i = 0; i < 11; i++) {
		suprafataCamere[i] = (i * i) * i;
	}

	Cladire c3("Ateneu", 1970, 7, suprafataCamere);
	c3.afisare(); cout << endl;

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
	Metrou m2("Metromania");
	m2.afisare(); cout << endl;

	float* distantaLinii = new float[11];
	for (int i = 0; i < 11; i++) {
		distantaLinii[i] = (i * i) * i;
	}

	Metrou m3("Metroline", 2024, 5, distantaLinii);
	m3.afisare(); */

    /*Parc p1;
    cin>>p1;
    cout<<p1;

    Parc p2;
    cin>>p2;
    cout<<p2;

    p1=p2;
    p1.operator++();
    cout<<p1;

    Cladire c1;
    cin>>c1;
    c1.operator++();
    cout<<c1;

    Cladire c2;
    cin>>c2;
    c2=c1;
    cout<<c2;

    Metrou m1;
    cin>>m1;
    m1.operator++();
    cout<<m1;

    Metrou m2;
    cin>>m2;
    m2=m1;
    cout<<m2; */

    /*const int numarParcuri = 3;
    Parc vectorParcuri[numarParcuri];

    const int numarCladiri = 3;
    Cladire vectorCladiri[numarCladiri];

    const int numarMetrouri = 3;
    Metrou vectorMetrouri[numarMetrouri];

    for (int i = 0; i < numarParcuri; ++i) {
        cin >> vectorParcuri[i];
    }

    for (int i = 0; i < numarCladiri; ++i) {
        cin >> vectorCladiri[i];
    }

    for (int i = 0; i < numarMetrouri; ++i) {
        cin >> vectorMetrouri[i];
    }

    cout << "Vectorul de parcuri:" << endl;
    for (int i = 0; i < numarParcuri; ++i) {
        cout << vectorParcuri[i] << endl;
    }

    cout << "Vectorul de cladiri:" << endl;
    for (int i = 0; i < numarCladiri; ++i) {
        cout << vectorCladiri[i] << endl;
    }

    cout << "Vectorul de metrouri:" << endl;
    for (int i = 0; i < numarMetrouri; ++i) {
        cout << vectorMetrouri[i] << endl;
    }

    const int numarLiniiMatrice = 2;
    const int numarColoaneMatrice = 2;
    Parc matriceParcuri[numarLiniiMatrice][numarColoaneMatrice];

    for (int i = 0; i < numarLiniiMatrice; ++i) {
        for (int j = 0; j < numarColoaneMatrice; ++j) {
            cin >> matriceParcuri[i][j];
        }
    }

    cout << "Matricea de parcuri:" << endl;
    for (int i = 0; i < numarLiniiMatrice; ++i) {
        for (int j = 0; j < numarColoaneMatrice; ++j) {
            cout << matriceParcuri[i][j] << endl;
        }
    }
    return 0;*/

    //TransportInComun tic1;
    //cout<<tic1;

    /*Parc p1;
    ofstream fisier("fisier.txt",ios::out);
    fisier<<p1;

    ifstream citeste("fisier.txt",ios::in);
    Parc p2; citeste>>p2;
    cout<<p2;

    cout<<endl;

    Metrou m1;
    ofstream fisierMetrou("fisierMetrou.txt",ios::out);
    fisierMetrou<<m1;

    ifstream citesteMetrou("fisierMetrou.txt",ios::in);
    Metrou m2; citesteMetrou>>m2;
    cout<<m2;
    */

    ParcDeDistractii pd1;
    cout<<pd1<<endl;

    ParcDeDistractii pd2(2);
    cout<<pd2<<endl;

    float* curentConsumat = new float[6];
    for (int i = 0; i < 6; i++) {
        curentConsumat[i] = (i * i) * i;
    }
    ParcDeDistractii pd3("Herastrau",5300,1990,6,curentConsumat,10);
    cout<<pd3<<endl;

    pd3=pd1;
    cout<<pd3<<endl;

    StatieDeMetrou sdm1;
    cout<<sdm1<<endl;

    StatieDeMetrou sdm2(3);
    cout<<sdm2<<endl;

    float* distantaLinii = new float[3];
    for (int i = 0; i < 3; i++) {
        distantaLinii[i] = (10 * i) + i;
    }
    StatieDeMetrou sdm3("Universitate", 2001, 5, distantaLinii, 2);
    cout<<sdm3<<endl;

    sdm3=sdm1;
    cout<<sdm1<<endl;

    return 0;
}