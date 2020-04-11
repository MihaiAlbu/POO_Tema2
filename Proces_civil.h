class Proces_civil: public Proces
{
	// membri privati, ai clasei
private:
	double dauneMorale;
	double dauneMateriale;
	int nrMartori;
	bool stadiu;

public:
	// constructor de baza
	Proces_civil (){
	}

	// constructor parametrizat
	Proces_civil (double dauneMorale, double dauneMateriale,
		int nrMartori, bool stadiu):Proces(nrProces, reclamant, reclamat){
		this->dauneMorale = dauneMorale;
		this->dauneMateriale = dauneMateriale;
		this->nrMartori = nrMartori;
		if (this->nrMartori > 5)
			this->stadiu = 1;
		else
			this->stadiu = 0;
	}

	// destructor
	~Proces_civil (){
	}

	// metoda care calculeaza taxa de timbru a procesului civil curent
	float taxa_timbru (){
		return 0.1 * this->dauneMorale + 0.1 * this->dauneMateriale;
	}

	// metoda cu care modificam stadiul unui proces civil
	void modificare_stadiu (){
		this->stadiu = 1 - this->stadiu;
	}

    // metoda cu care obtinem stadiul unui proces civil
    virtual bool afisare_stadiu(){
    	return this->stadiu;
    }

	// citirea unui proces civil (bazata pe citirea unui proces in general,
	// plus alte cateva campuri)
    virtual void citire (istream &in){
    	Proces::citire(in);
		cout << "Daune morale: ";
		in >> this->dauneMorale;
		cout << "Daune Materiale: ";
		in >> this->dauneMateriale;
		cout << "Numar martori: ";
		in >> this->nrMartori;
		if (this->nrMartori > 5)
			this->stadiu = 1;
		else
			this->stadiu = 0;
    	cout << string(25, '-') << "\n";
    }

	// afisarea unui proces civil (bazata pe afisarea unui proces in general,
	// plus alte cateva campuri)
    virtual void afisare (ostream &out){
    	Proces::afisare(out);
		cout << "\tDaune morale: " << this->dauneMorale << "\n";
		cout << "\tDaune Materiale: " << this->dauneMateriale << "\n";
		cout << "\tNumar martori: " << this->nrMartori << "\n";
		cout << "\tStadiu: " << this->stadiu << "\n";
		cout << "\tTaxa de timbru: " << this->taxa_timbru() << "\n";
    	cout << string(40, '*') << "\n";
    }

    // supraincarcarea operatorului >>
	friend istream& operator>>(istream& in, Proces_civil& pc){
		pc.citire(in);
	    return in;
	}

    // supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& out, Proces_civil& pc){
		pc.afisare(out);
	    return out;
	}

    // supraincarcarea operatorului =
	Proces_civil& operator=(const Proces_civil &pc){
		this->nrProces = pc.nrProces;
		this->reclamant = pc.reclamant;
		this->reclamat = pc.reclamat;
		this->dauneMorale = pc.dauneMorale;
		this->dauneMateriale = pc.dauneMateriale;
		this->nrMartori = pc.nrMartori;
		this->stadiu = pc.stadiu;
	}
};
